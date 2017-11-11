#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/RoundObj.h"
#include "OurTeam.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(840, 720), "Window");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);  // Do not remove!

    RoundObj ball({400, 300}, 20, "-", sf::Color::White);

    int currentPlayer = 0; // max = 20
    sf::Texture footballpole;
    sf::Image footballpoleI;
    footballpoleI.loadFromFile("../field.png");
    footballpole.loadFromImage(footballpoleI);

    sf::Sprite fbp(footballpole);
    fbp.setPosition(0, 0);

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

            if (currentb.pos.x > window.getSize().x - 2*currentb.radius or currentb.pos.x < 0) {
                currentb.posv.x *= -1;
                b = true;
            }
            if (currentb.pos.y > 600 - 2*currentb.radius or currentb.pos.y < 0) {
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

            if (currentb.pos.x > window.getSize().x - 2*currentb.radius or currentb.pos.x < 0) {
                currentb.posv.x *= -1;
                b = true;
            }
            if (currentb.pos.y > 600 - 2*currentb.radius or currentb.pos.y < 0) {
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

        /*for (auto &currentb : Bayern) {
            for (auto &opp : Real) {
                if (opp.isOutOf(window.getSize()) or currentb.isOutOf(window.getSize())) {
                    opp.move({rand() % (window.getSize().x - 100),
                              rand() % (window.getSize().y - 100)});
                    currentb.move({rand() % (window.getSize().x - 100),
                                   rand() % (window.getSize().y - 100)});
                }
            }
        }*/

        if (ball.isNear({0, 400 / 2})) {
            goalsRed++;
        }
        if (ball.isNear({window.getSize().x, 400 / 2})) {
            goalsBlue++;
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
    window.close();
    return 0;
}