//
// Created by danil on 28.09.17.
//

#ifndef FOOTBALLMANAGER_FOOTBALLER_H
#define FOOTBALLMANAGER_FOOTBALLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Icon.h"

class Footballer : public sf::Drawable {
private:
    sf::CircleShape footballer;
    Icon *icon;
    sf::Sprite s;
public:
    int radius = 0;
    sf::Vector2f pos = {0, 0};

    Footballer(const sf::Vector2f &pos, const int &radius, Icon icon, const sf::Color &fillColor,
               const sf::Color &outlineColor = sf::Color::White) {
        this->radius = radius;
        this->pos = pos;

        this->icon = &icon;

        this->footballer.setTexture(&icon.getTexture());
        this->footballer.setOutlineColor(outlineColor);
        this->footballer.setOutlineThickness(5);
        this->footballer.setPosition(pos);
        this->footballer.setRadius(this->radius);

        this->s.setTexture(icon.getTexture()); //загружаем в него эту текстуру
        this->s.setPosition(this->pos.x, this->pos.y); //указываем в какие координаты мы будем его рисовать
    }

    void move(const sf::Vector2f &pos) {
        this->pos = this->footballer.getPosition();
        this->footballer.setPosition(pos.x, pos.y);
    }

    bool isInRange(const sf::Vector2f &pos) {
        return this->pos.x >= pos.x and this->pos.x <= pos.x + this->radius * 2 and this->pos.y >= pos.y and
               this->pos.y <= pos.y + this->radius * 2;
    }

    bool isInRange(const Footballer &player) {
        return isInRange(player.pos);
    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(this->footballer, states);
    }
};


#endif //FOOTBALLMANAGER_FOOTBALLER_H
