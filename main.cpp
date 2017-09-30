#include <iostream>
#include <SFML/Graphics.hpp>
#include "Footballer.h"
#include "OurTeam.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    int currentPlayer = 0; // max = 20

    // Главный цикл приложения
    auto current = PlayersRed.begin();
    while (window.isOpen()) {
        // Обрабатываем события в цикле
        sf::Event event;
        while (window.pollEvent(event)) {
            if (currentPlayer == 20) { window.close(); }
            // Кроме обычного способа наше окно будет закрываться по нажатию на Escape
            if (event.type == sf::Event::Closed or
                (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
            if (event.type == sf::Event::MouseMoved and event.MouseEntered) {
                current->mouseMove({static_cast<float>(event.mouseMove.x - current->radius),
                                    static_cast<float>(event.mouseMove.y - current->radius)}
                );
            }
            if (event.type == sf::Event::MouseButtonPressed and event.MouseEntered) {
                //current->mouseClick(); // Be warned! Something may-be wrong here!
                currentPlayer++;
                current++;
            }
            if (currentPlayer == 10) {
                current = PlayersBlue.begin();
            }
        }
        // Очистка
        window.clear();
        for (auto b : PlayersRed) {
            window.draw(b);
        }
        for (auto b : PlayersBlue) {
            window.draw(b);
        }
        // Тут будут вызываться функции обновления и отрисовки объектов
        // Отрисовка
        window.display();
    }

    window.close();
    return 0;
}