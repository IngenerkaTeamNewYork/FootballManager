#include <iostream>
#include <SFML/Graphics.hpp>
#include "Footballer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Window");
    window.setVerticalSyncEnabled(true);

    sf::Image ballText;
    ballText.loadFromFile("../ball.png");

    sf::Texture ball;
    ball.loadFromImage(ballText);

    Footballer Player({5,5}, 60, ball);
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
                Player.mouseMove(event.mouseMove.x - Player.getRadius(), event.mouseMove.y - Player.getRadius());
            }
        }

        // Очистка
        window.clear();
        window.draw(Player);
        // Тут будут вызываться функции обновления и отрисовки объектов
        // Отрисовка
        window.display();
    }
    window.close();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}