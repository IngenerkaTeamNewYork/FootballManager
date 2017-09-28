#include <iostream>
#include <SFML/Graphics.hpp>
#include "Footballer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window");
    window.setVerticalSyncEnabled(true);

    std::array<Footballer, 5> Players = {
            Footballer({5, 5}, 20, sf::Color::Red),
            Footballer({5, 5}, 20, sf::Color::Red),
            Footballer({5, 5}, 20, sf::Color::Red),
            Footballer({5, 5}, 20, sf::Color::Red),
            Footballer({5, 5}, 20, sf::Color::Red)
    };

    // Главный цикл приложения
    while (window.isOpen()) {
        // Обрабатываем события в цикле
        sf::Event event;
        while (window.pollEvent(event)) {
            // Кроме обычного способа наше окно будет закрываться по нажатию на Escape
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
            std::for_each(std::begin(Players), std::begin(Players) + 10, [&](Footballer a) {
                if (event.type == sf::Event::MouseMoved and a.following) {
                    a.mouseMove(event.mouseMove.x - a.getRadius(), event.mouseMove.y - a.getRadius());
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    a.mouseClick();
                }
            });
        }

        // Очистка
        window.clear();
        std::for_each(std::begin(Players), std::begin(Players) + 10, [&](Footballer a) {
            window.draw(a);
        });
        // Тут будут вызываться функции обновления и отрисовки объектов
        // Отрисовка
        window.display();
    }
    window.close();
    return 0;
}