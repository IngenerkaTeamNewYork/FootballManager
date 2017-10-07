//
// Created by Student on 04.10.2017.
//

#ifndef FOOTBALLMANAGER_ICON_H
#define FOOTBALLMANAGER_ICON_H


#include <SFML/Graphics.hpp>

class fileError : public std::exception {
    const char* what() const throw() override {
        return "Bad filename!";
    }
};

class Icon {
private:
    sf::Texture texture;
    sf::Sprite spr;
public:
    Icon() = default;

    explicit Icon(const std::string &fileName) {
        sf::Texture texture;
        if (!texture.loadFromFile(fileName)) {
            throw fileError();
        }
        this->texture = texture;
        this->spr.setTexture(this->texture);
    }
    const sf::Sprite &getSprite() {
        return this->spr;
    }
    const sf::Texture &getTexture() {
        return this->texture;
    }
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) {
        target.draw(this->spr, states);
    }
};


#endif //FOOTBALLMANAGER_ICON_H
