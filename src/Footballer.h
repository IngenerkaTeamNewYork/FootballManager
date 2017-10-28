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
    sf::Texture texture;
public:
    unsigned int radius = 0;
    sf::Vector2f pos;
    sf::Vector2f posv;

    Footballer(const sf::Vector2f &pos, const unsigned int &radius, const std::string &footballerName,
               const sf::Color &fillColor,
               const sf::Color &outlineColor = sf::Color::White) {
        this->radius = radius;
        this->pos = pos;
        this->posv = {122, 133};

        sf::Image heroimage; //создаем объект Image (изображение)
        heroimage.loadFromFile("../assets/" + footballerName + ".png");//загружаем в него файл
        if (!texture.loadFromImage(heroimage)) {
            throw std::runtime_error("Image not found.");
        }

        this->texture.setSmooth(true);
        this->footballer.setOutlineColor(outlineColor);
        this->footballer.setOutlineThickness(5);
        this->footballer.setPosition(pos);
        this->footballer.setRadius(this->radius);
    }

    Footballer(const Footballer &f) {
        this->radius = f.radius;
        this->footballer = f.footballer;
        this->texture = f.texture;
        this->footballer.setTexture(&this->texture);
        this->footballer.setPosition(f.pos.x, f.pos.y);
        this->posv = f.posv;
    }

    void move(const sf::Vector2f &pos) {
        //this->pos = this->footballer.getPosition();
        this->footballer.setPosition(pos.x, pos.y);
        this->pos = this->footballer.getPosition();
    }

    void setRadius(unsigned int radius) {
        this->radius = radius;
        this->footballer.setRadius(radius);
    }

    bool isInRange(const sf::Vector2f &pos) {
        return ((pos.x >= this->pos.x and pos.x <= (this->radius * 2)) and
                (pos.y >= this->pos.y and pos.y <= (this->radius * 2)));
    }

    bool isInRange(const Footballer &player) {
        return isInRange(player.pos);
    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(this->footballer, states);
    }
};


#endif //FOOTBALLMANAGER_FOOTBALLER_H
