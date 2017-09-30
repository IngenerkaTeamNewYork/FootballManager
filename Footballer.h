//
// Created by danil on 28.09.17.
//

#ifndef FOOTBALLMANAGER_FOOTBALLER_H
#define FOOTBALLMANAGER_FOOTBALLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Footballer : public sf::Drawable {
private:
    sf::CircleShape footballer;
public:
    int radius = 0;

    Footballer(const sf::Vector2f pos, int radius, sf::Color fillColor, sf::Color outlineColor = sf::Color::White) {
        this->radius = radius;

        this->footballer.setFillColor(fillColor);
        this->footballer.setOutlineColor(outlineColor);
        this->footballer.setOutlineThickness(5);
        this->footballer.setPosition(pos);
        this->footballer.setRadius(this->radius);
    }

    void mouseMove(sf::Vector2f pos) {
        this->footballer.setPosition(pos.x, pos.y);
    }

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        target.draw(this->footballer, states);
    }
};


#endif //FOOTBALLMANAGER_FOOTBALLER_H
