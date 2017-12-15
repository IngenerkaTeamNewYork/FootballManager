/**
 * @name Football Manager
 * @authors NeverMine17, sosiska2281337
 * @file main.cpp
 * @brief Главный файл всей программы.
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/RoundObj.h"
#include "OurTeam.h"
#include <fstream>
#include <cmath>

/**
 * Функция для указания скилла игрока.
 *
 * @param player[in,out] Игрок
 * @param skill[in,out]
 * @warning Эта функция использует указатели, т.е ничего не возвращает
 * @see totalSkill
 */
void setSkills(RoundObj *player, skills *skill) {
    if (player->name == skill->player) {
        player->setSkills(skill->skill_goalkeeper, skill->skill_defender, skill->skill_midfielder,
                         skill->skill_striker);
    }
}

/**
 * Функция для вычисления общего скилла.
 *
 * @param[in,out] player
 * @param[in,out] totalskill
 * @warning Эта функция использует указатели, т.е ничего не возвращает
 * @see setSkills
 */
void totalSkill(RoundObj *player, unsigned int *totalskill) {
    if (player->skill_goalkeeper >= player->skill_defender and
        player->skill_goalkeeper >= player->skill_midfielder and
        player->skill_goalkeeper >= player->skill_striker) {
        *totalskill += player->skill_goalkeeper;
    } else if (player->skill_defender >= player->skill_goalkeeper and
               player->skill_defender >= player->skill_midfielder and
               player->skill_defender >= player->skill_striker) {
        *totalskill += player->skill_defender;
    } else if (player->skill_midfielder >= player->skill_goalkeeper and
               player->skill_midfielder >= player->skill_defender and
               player->skill_midfielder >= player->skill_striker) {
        *totalskill += player->skill_midfielder;
    } else {
        *totalskill += player->skill_striker;
    }
}

/**
 * @brief Главная функция программы
 * Большинство кода находится здесь
 * @warning
 * Если схемы или комманды из файла
 * нету в памяти то программа закрывается
 */
int main() {
    unsigned int a = 0;
    std::fstream sch1("../schema1.txt");
    std::fstream sch2("../schema2.txt");
    std::fstream tea1("../team1.txt");

    std::fstream tea2("../team2.txt");

    //Читаем состав
    std::string fileContents3;
    tea1 >> fileContents3;
    std::vector<std::string> team1(11);
    try {
        team1 = *mapSquad.at(fileContents3);
    } catch (const std::out_of_range &exp) {
        std::cout << exp.what() << '\n';
        std::exit(EXIT_FAILURE);
    }

    tea2 >> fileContents3;
    std::vector<std::string> team2(11);
    try {
        team2 = *mapSquad.at(fileContents3);
    } catch (const std::out_of_range &exp) {
        std::cout << exp.what() << '\n';
        std::exit(EXIT_FAILURE);
    }

    a = 0;
    for (RoundObj &player : Team1) {
        try {
            sf::Image heroimage;
            sf::Texture texture;
            if (!heroimage.loadFromFile("../assets/" + team1[a] + ".png")) {
                throw std::runtime_error("Image not found.");
            }
            texture.loadFromImage(heroimage);
            player.setTexture(texture);
            player.name = team1[a];

        } catch (std::out_of_range &exp) {
            std::cout << exp.what();
            std::exit(EXIT_FAILURE);
        }
        a++;
    }

    a = 0;
    for (RoundObj &player : Team2) {
        try {
            sf::Image heroimage;
            sf::Texture texture;
            if (!heroimage.loadFromFile("../assets/" + team2[a] + ".png")) {
                throw std::runtime_error("Image not found.");
            }

            texture.loadFromImage(heroimage);
            player.setTexture(texture);
            player.name = team2[a];

        } catch (std::out_of_range &exp) {
            std::cout << exp.what();
            std::exit(EXIT_FAILURE);
        }
        a++;
    }


    //Уже не читаем состав

    std::string fileContents1;
    sch1 >> fileContents1;
    std::vector<sf::Vector2f> schema1(11);
    try {
        schema1 = *mapScheme.at(fileContents1);
    } catch (const std::out_of_range &exp) {
        std::cout << exp.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
    a = 0;
    for (RoundObj &tmp2 : Team1) {
        try {
            tmp2.move(schema1.at(a));
        } catch (const std::out_of_range &exp) {
            std::cout << exp.what() << '\n';
            std::exit(EXIT_FAILURE);
        }
        a++;
    }

    std::string fileContents2;
    sch2 >> fileContents2;
    std::vector<sf::Vector2f> schema2(11);
    try {
        schema2 = *mapScheme.at(fileContents2);
    } catch (const std::out_of_range &exp) {
        std::cout << exp.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
    a = 0;
    for (RoundObj &tmp2 : Team2) {
        try {
            tmp2.move({800 - schema2.at(a).x, schema2.at(a).y});
        } catch (std::out_of_range &exp) {
            std::cout << exp.what();
            std::exit(EXIT_FAILURE);
        }
        a++;
    }

    for (RoundObj &player : Team1) {
        for (skills &skill : skillsArray) {
            setSkills(&player, &skill);
        }
    }
    for (RoundObj &player : Team2) {
        for (skills &skill : skillsArray) {
            setSkills(&player, &skill);
        }
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(FBM_X_EKRANA, FBM_Y_EKRANA), "Window");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);  // Do not remove!

    RoundObj ball(20, "-", 0, sf::Color::White);
    ball.move({400, 300});

    int currentPlayer = 0; // max = 20
    sf::Texture footballpole;
    sf::Image footballpoleI;
    footballpoleI.loadFromFile("../field.png");
    footballpole.loadFromImage(footballpoleI);

    sf::Sprite fbp(footballpole);

    sf::Font font;
    font.loadFromFile("../Arial.ttf");
    sf::Text first("0", font);
    sf::Text second("0", font);

    unsigned int totalskill2 = 0;
    unsigned int totalskill1 = 0;


    for (RoundObj &player : Team1) {
        totalSkill(&player, &totalskill1);
    }

    for (RoundObj &player : Team2) {
        totalSkill(&player, &totalskill2);
    }


    first.setPosition({FBM_X_EKRANA / 4, FBM_Y_EKRANA / 4 + FBM_Y_EKRANA / 2});
    second.setPosition({FBM_X_EKRANA / 4, FBM_Y_EKRANA / 4 + FBM_Y_EKRANA / 2 + 25});

    sf::Text predictionfirst(std::to_string(int(totalskill1 / 20) - 43), font);
    sf::Text predictionsecond(std::to_string(int(totalskill2 / 20 - 43)), font);

    predictionfirst.setPosition({FBM_X_EKRANA / 4, FBM_Y_EKRANA / 4 + FBM_Y_EKRANA / 2 + 100});
    predictionsecond.setPosition({FBM_X_EKRANA / 4, FBM_Y_EKRANA / 4 + FBM_Y_EKRANA / 2 + 25 + 100});


    // Главный цикл приложения
    auto current = Team1.begin();
    while (window.isOpen()) {
        // Обрабатываем события в цикле
        sf::Event event = sf::Event();
        while (window.pollEvent(event)) {
            // Кроме обычного способа наше окно будет закрываться по нажатию на Escape
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        // Очистка
        window.clear();
        window.draw(fbp);

        for (auto &currentb : Team1) {
            currentb.pos += currentb.posv;
            bool b = false;

            if (currentb.pos.x > window.getSize().x - 2 * currentb.radius or currentb.pos.x < 0) {
                currentb.posv.x *= -1;
                b = true;
            }
            if (currentb.pos.y > 600 - 2 * currentb.radius or currentb.pos.y < 0) {
                currentb.posv.y *= -1;
                b = true;
            }
            if (b) {
                currentb.pos += currentb.posv;
            }

            if (ball.isNear(currentb)) {
                ball.move(ball.pos + currentb.posv);
            }
            currentb.move(currentb.pos);
        }
        for (auto &currentb : Team2) {
            currentb.pos += currentb.posv;

            bool b = false;

            if (currentb.pos.x > window.getSize().x - 2 * currentb.radius or currentb.pos.x < 0) {
                currentb.posv.x *= -1;
                b = true;
            }
            if (currentb.pos.y > 600 - 2 * currentb.radius or currentb.pos.y < 0) {
                currentb.posv.y *= -1;
                b = true;
            }
            if (b) {
                currentb.pos += currentb.posv;
            }
            if (ball.isNear(currentb)) {
                ball.move(ball.pos + currentb.posv);
            }
            currentb.move(currentb.pos);
        }

        if (ball.isOutOf({800, 600})) {
            ball.move({rand() % 200, rand() % 200});
        }


        if (ball.isNear({5, FBM_Y_POLYA / 2})) {
            goalsRed++;
            ball.move({(rand() % 700) + 100, (rand() % 700) + 100});
            first.setString(std::to_string(goalsRed));
        }
        if (ball.isNear({FBM_X_POLYA - 5, FBM_Y_POLYA / 2})) {
            goalsBlue++;
            ball.move({(rand() % 700) + 100, (rand() % 700) + 100});
            second.setString(std::to_string(goalsBlue));
        }
        for (const auto &b : Team1) {
            window.draw(b);
        }
        for (const auto &b : Team2) {
            window.draw(b);
        }
        window.draw(first);
        window.draw(second);
        window.draw(predictionfirst);
        window.draw(predictionsecond);
        window.draw(ball);
        // Тут будут вызываться функции обновления и отрисовки объектов
        // Отрисовка
        window.display();
    }
    window.close();

    return 0;
}
