#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/RoundObj.h"
#include "OurTeam.h"
#include <fstream>
#include <cmath>

void setSkills(RoundObj *player, skills *skill) {
    if (player->name == skill->player) {
        player->setSkills(skill->skill_goalkeeper, skill->skill_defender, skill->skill_midfielder,
                         skill->skill_striker);
    }
}

void totalskill(RoundObj *player, unsigned int *totalskill) {
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

int main() {
    unsigned int a = 0;
    std::fstream sch1("../schema.txt");
    std::fstream sch2("../schema2.txt");
    std::fstream tea1("../team1.txt");

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
        totalskill(&player, &totalskill1);
    }
    for (RoundObj &player : Team2) {
        totalskill(&player, &totalskill2);
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
