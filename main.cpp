#include <iostream>
#include <SFML/Graphics.hpp>
#include "Footballer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    std::vector<Footballer> Players = {
            Footballer({5, 5}, 20, sf::Color::Red),
            Footballer({6, 6}, 20, sf::Color::Red),
            Footballer({7, 7}, 20, sf::Color::Red)
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
            if (event.type == sf::Event::MouseMoved) {
                for (auto a : Players) {
                    a.mouseMove(event.mouseMove.x - a.getRadius(), event.mouseMove.y - a.getRadius());
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                for (auto a : Players) {
                    a.mouseClick();
                }
            }
        }
        // Очистка
        window.clear();
        for (auto b : Players) {
            window.draw(b);
        }
        // Тут будут вызываться функции обновления и отрисовки объектов
        // Отрисовка
        window.display();
    }

    window.close();
    return 0;
}