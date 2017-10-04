//
// Created by Student on 04.10.2017.
//

#ifndef FOOTBALLMANAGER_ICON_H
#define FOOTBALLMANAGER_ICON_H


#include <SFML/Graphics.hpp>

class fileError : public std::exception {
    virtual const char* what() const throw() {
        return "Bad filename!";
    }
};

class Icon {
private:
    sf::Sprite icon;
public:
    Icon(const std::string &fileName) {
        sf::Texture texture;
        if (!texture.loadFromFile("cute_image.jpg")) {
            throw fileError();
        }
        sf::Sprite sprite(texture);
        this->icon = sprite;
    }
    const sf::Sprite getIcon() {
        return this->icon;
    }
};


#endif //FOOTBALLMANAGER_ICON_H
