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
    sf::Vector2f pos = {0, 0};

    Footballer(const sf::Texture *player = nullptr, const sf::Vector2f &pos, const int &radius, const sf::Color &fillColor,
               const sf::Color &outlineColor = sf::Color::White) {
        this->radius = radius;
        this->pos = pos;

        this->footballer.setFillColor(fillColor);
        this->footballer.setOutlineColor(outlineColor);
        this->footballer.setOutlineThickness(5);
        this->footballer.setPosition(pos);
        this->footballer.setRadius(this->radius);
        if (player != nullptr) {
            this->footballer.setTexture(player);
        }
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
