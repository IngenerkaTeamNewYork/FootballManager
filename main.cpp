#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/Footballer.h"
#include "OurTeam.h"

void bounce(const sf::Vector2u &posLim, const std::vector<Footballer> &a, const std::vector<Footballer> &b) {
    for (auto ccc : a, b) {
        ccc.pos.x += ccc.posv.x;
        ccc.pos.y += ccc.posv.y;
        if (ccc.pos.x > posLim.x or ccc.pos.x < 0) {
            ccc.posv.x *= -1;
        }
        if (ccc.pos.y > posLim.y or ccc.pos.y < 0) {
            ccc.posv.y *= -1;
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Window");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    int currentPlayer = 0; // max = 20
    sf::Texture footballpole;
    sf::Image footballpoleI;
    footballpoleI.loadFromFile("../field.png");
    footballpole.loadFromImage(footballpoleI);

    sf::Sprite fbp(footballpole);

    // Главный цикл приложения
    auto current = PlayersRed.begin();
    bool nope = false;
    while (window.isOpen()) {
        // Обрабатываем события в цикле
        sf::Event event = sf::Event();
        while (window.pollEvent(event)) {
            // Кроме обычного способа наше окно будет закрываться по нажатию на Escape
            if (event.type == sf::Event::Closed or
                (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape) and !nope) {
                window.close();
            }
            if (event.type == sf::Event::MouseMoved and event.MouseEntered and !nope) {
                if (currentPlayer >= 10 and event.mouseMove.x >= 400) {
                    current->move({static_cast<float>(event.mouseMove.x - current->radius),
                                   static_cast<float>(event.mouseMove.y - current->radius)}
                    );
                } else if (currentPlayer < 10 and event.mouseMove.x <= 400) {
                    current->move({static_cast<float>(event.mouseMove.x - current->radius),
                                   static_cast<float>(event.mouseMove.y - current->radius)}
                    );
                }
            }
            if (event.type == sf::Event::MouseButtonPressed and event.MouseEntered and
                event.mouseButton.button == sf::Mouse::Button::Left and !nope) {
                //current->mouseClick(); // Be warned! Something may-be wrong here!
                if (currentPlayer <= 20 and currentPlayer >= 0) {
                    currentPlayer++;
                    current++;
                }
            } else if (event.type == sf::Event::MouseButtonPressed and event.MouseEntered and
                       event.mouseButton.button == sf::Mouse::Button::Right and !nope) {
                //current->mouseClick(); // Be warned! Something may-be wrong here!
                if (currentPlayer <= 20 and currentPlayer >= 0) {
                    currentPlayer--;
                    current--;
                }
            }
            if (currentPlayer == 10) {
                current = PlayersBlue.begin();
            }
            if (currentPlayer == 20) {
                //current->
                nope = true;
            }
        }
        // Очистка
        window.clear();
        window.draw(fbp);

        if (nope) {
            bounce(window.getSize(), PlayersRed, PlayersBlue);
        }
        for (const auto &b : PlayersRed) {
            window.draw(b);
        }
        for (const auto &b : PlayersBlue) {
            window.draw(b);
        }
        // Тут будут вызываться функции обновления и отрисовки объектов
        // Отрисовка
        window.display();
    }

    window.close();
    return 0;
}