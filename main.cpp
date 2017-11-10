#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/RoundObj.h"
#include "OurTeam.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Window");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);  // Do not remove!

    RoundObj ball({400, 300}, 20, "-", sf::Color::White);

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
            currentb.move(currentb.pos);

            if (currentb.pos.x > window.getSize().x or currentb.pos.x < 0) {
                currentb.posv.x *= -1;
            }
            if (currentb.pos.y > window.getSize().y or currentb.pos.y < 0) {
                currentb.posv.y *= -1;
            }
            if (ball.isInRange(currentb)) {
                ball.move(ball.pos + currentb.posv);
            }
        }
        for (auto &currentb : Bayern) {
            currentb.pos += currentb.posv;
            currentb.move(currentb.pos);

            if (currentb.pos.x > window.getSize().x or currentb.pos.x < 0) {
                currentb.posv.x *= -1;
            }
            if (currentb.pos.y > window.getSize().y or currentb.pos.y < 0) {
                currentb.posv.y *= -1;
            }
            if (ball.isInRange(currentb)) {
                ball.move(ball.pos + currentb.posv);
            }
        }

        for (auto &currentb : Bayern) {
            for (auto &opp : Real) {
                if (!opp.isOutOf(window.getSize()) or !currentb.isOutOf(window.getSize())) {
                    while (currentb.isInRange(opp)) {
                        currentb.move(currentb.pos - currentb.posv + sf::Vector2f(rand() % 10, rand() % 10));
                        opp.move(opp.pos - opp.posv + sf::Vector2f(rand() % 10, rand() % 10));
                    }
                } else {
                    opp.move({rand() % window.getSize().x, rand() % window.getSize().y});
                }
            }
        }

        for (auto &currentb : Bayern) {
            for (auto &opp : Real) {
                if (opp.isOutOf(window.getSize()) or currentb.isOutOf(window.getSize())) {
                    opp.move({rand() % (window.getSize().x - 100),
                              rand() % (window.getSize().y - 100)});
                    currentb.move({rand() % (window.getSize().x - 100),
                                   rand() % (window.getSize().y - 100)});
                }
            }
        }

        if (ball.isInRange({0, window.getSize().y / 2})) {
            goalsRed++;
        }
        if (ball.isInRange({window.getSize().x, window.getSize().y / 2})) {
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