//
// Created by danil on 28.09.17.
//

#ifndef FOOTBALLMANAGER_FOOTBALLER_H
#define FOOTBALLMANAGER_FOOTBALLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class RoundObj : public sf::Drawable {
private:
    sf::CircleShape obj;
    sf::Texture texture;
    bool havePic;
public:
    unsigned int radius = 0;
    sf::Vector2f pos;
    sf::Vector2f posv;

    unsigned int skill_goalkeeper = 0;
    unsigned int skill_defender = 0;
    unsigned int skill_midfielder = 0;
    unsigned int skill_striker = 0;


    RoundObj(const unsigned int &radius, const std::string &footballerName, const std::uint8_t skill,
               const sf::Color &fillColor,
               const sf::Color &outlineColor = sf::Color::White) {
        this->radius = radius;
        this->pos = pos;
        this->posv = {10 + skill, 10 + skill};

        if (footballerName != "-") {
            sf::Image heroimage; //создаем объект Image (изображение)
            if (!heroimage.loadFromFile("../assets/" + footballerName + ".png")) {
                throw std::runtime_error("Image not found.");
            } //загружаем в него файл
            if (!this->texture.loadFromImage(heroimage)) {
                throw std::runtime_error("Image not found.");
            }
            this->havePic = true;
        } else {
            this->havePic = false;
        }

        this->texture.setSmooth(true);
        this->obj.setOutlineColor(outlineColor);
        this->obj.setOutlineThickness(5);
        this->obj.setPosition({0, 0});
        this->obj.setRadius(this->radius);
    }

    RoundObj(const RoundObj &f) {
        this->radius = f.radius;
        this->obj = f.obj;
        this->texture = f.texture;
        this->obj.setTexture(&this->texture);
        this->pos = f.pos;


        this->posv = f.posv;
        this->havePic = f.havePic;
    }

    void move(const sf::Vector2f &pos) {
        //this->pos = this->obj.getPosition();
        this->obj.setPosition(pos.x, pos.y);
        this->pos = this->obj.getPosition();
    }

    void setRadius(unsigned int radius) {
        this->radius = radius;
        this->obj.setRadius(radius);
    }

    bool isNear(const sf::Vector2f &pos) {
        return abs(static_cast<int>(pos.x - this->pos.x)) <= 2 * this->radius and
               abs(static_cast<int>(pos.y - this->pos.y)) <= 2 * this->radius;
    }

    bool isNear(const RoundObj &player) {
        return isNear(player.pos);
    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(this->obj, states);
    }

    bool pic() {
        return this->havePic;
    }

    bool isOutOf(sf::Vector2u bounds) {
        return this->pos.x <= 0 or this->pos.y <= 0 or this->pos.x >= bounds.x or this->pos.y >= bounds.y;
    }
};


#endif //FOOTBALLMANAGER_FOOTBALLER_H