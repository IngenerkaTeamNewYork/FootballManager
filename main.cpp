#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/RoundObj.h"
#include "OurTeam.h"

int main() {
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
                    current->move({(event.mouseMove.x - current->radius),
                                   (event.mouseMove.y - current->radius)}
                    );
                } else if (currentPlayer < 10 and event.mouseMove.x <= 400) {
                    current->move({event.mouseMove.x - current->radius,
                                   event.mouseMove.y - current->radius}
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
            for (auto &currentb : PlayersRed) {
                currentb.pos += currentb.posv;
                currentb.move({currentb.pos.x, currentb.pos.y});

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
            for (auto &currentb : PlayersBlue) {
                currentb.pos += currentb.posv;
                currentb.move({currentb.pos.x, currentb.pos.y});

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
        }
        if (ball.isInRange({0, window.getSize().y/2})) {
            goalsRed++;
        }
        if (ball.isInRange({window.getSize().x, window.getSize().y/2})) {
            goalsBlue++;
        }
        for (const auto &b : PlayersRed) {
            window.draw(b);
        }
        for (const auto &b : PlayersBlue) {
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