#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/RoundObj.h"
#include "OurTeam.h"
#include "src/const.h"
#include <fstream>
#include "src/Schemas.h"

int main() {
    unsigned int a = 0;
    std::fstream sch1("../schema.txt");
    std::fstream sch2("../schema2.txt");
    std::fstream tea1("../team1.txt");
    //std::fstream aa("../schema.txt"
    //Читаем состав);
    //std::find(skillsArrayRealMadrid.begin(), skillsArrayRealMadrid.end(), "alchash");
    std::string fileContents3;
    tea1 >> fileContents3;
    std::vector<std::string> team1(11);
    try {
        team1 = *mapSquad.at(fileContents3);
    } catch (const std::out_of_range &exp) {
        std::cout << exp.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
    /*a = 0;
    for (RoundObj &tmp2 : Bayern) {
        try {
            sf::Image heroimage;
            if (!heroimage.loadFromFile("../assets/" + team1[a] + ".png")) {
                throw std::runtime_error("Image not found.");
            }
            if (!tmp2.texture.loadFromImage(heroimage)) {
                throw std::runtime_error("Image not found.");
            }
        } catch (std::out_of_range &exp) {
            std::cout << exp.what();
            std::exit(EXIT_FAILURE);
        }
        a++;
    }*/
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
    for (RoundObj &tmp2 : Real) {
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
    for (RoundObj &tmp2 : Bayern) {
        try {
            tmp2.move({800 - schema2.at(a).x, schema2.at(a).y});
        } catch (std::out_of_range &exp) {
            std::cout << exp.what();
            std::exit(EXIT_FAILURE);
        }
        a++;
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(SHIRINA_EKRANA, VYSOTA_EKRANA), "Window");
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

    // Главный цикл приложения
    auto current = Real.begin();
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

        for (auto &currentb : Real) {
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
        for (auto &currentb : Bayern) {
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

        /*for (auto &currentb : Bayern) {
            for (auto &opp : Real) {
                sf::Vector2f oldPos = currentb.pos;
                sf::Vector2f oldPos2 = opp.pos;
                unsigned int shagi = 0;
                if (!opp.isOutOf({window.getSize().x, 400}) or !currentb.isOutOf({window.getSize().x, 400})) {
                    while (currentb.isNear(opp) && shagi < 100) {
                        currentb.move(oldPos - sf::Vector2f(rand() % 11 - 5, rand() % 11 - 5));
                        opp.move(oldPos2 - sf::Vector2f(rand() % 20 - 10, rand() % 20 - 10));
                        shagi++;
                    }



                    if (shagi == 100) {
                        opp.move({rand() % window.getSize().x, rand() % 400});
                    }
                } else {
                    opp.move({rand() % window.getSize().x, rand() % 400});
                }
            }
        }*/

        if (ball.isOutOf({800, 600})) {
            ball.move({rand() % 200, rand() % 200});
        }


        if (ball.isNear({0, 400 / 2})) {
            goalsRed++;
            ball.move({rand() % 700, rand() % 500});
        }
        if (ball.isNear({window.getSize().x, 400 / 2})) {
            goalsBlue++;
            ball.move({(rand() % 700) + 100, (rand() % 500) + 100});
        }
        for (const auto &b : Real) {
            window.draw(b);
        }
        for (const auto &b : Bayern) {
            window.draw(b);
        }
        window.draw(ball);
        // Тут будут вызываться функции обновления и отрисовки объектов
        // Отрисовка
        window.display();
    }

    std::cout << goalsRed << '\n';
    std::cout << goalsBlue << '\n';
    window.

            close();

    return 0;
}
