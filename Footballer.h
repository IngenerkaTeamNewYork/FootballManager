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
    int radius;
public:
    Footballer(const sf::Vector2f pos, int radius, sf::Texture player) {
        this->radius = radius;
        this->footballer.setFillColor(sf::Color(0,0,255,100));
        this->footballer.setTexture(&player, true); // not working
        this->footballer.setPosition(pos);
        this->footballer.setRadius(this->radius);
    }

    int getRadius() {
        return this->radius;
    }

    void mouseMove(int x, int y) {
        this->footballer.setPosition(x, y);
    }

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        target.draw(footballer, states);
    }
};


#endif //FOOTBALLMANAGER_FOOTBALLER_H
