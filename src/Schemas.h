//
// Created by Admin on 11.11.2017.
//

#ifndef FOOTBALLMANAGER_SCHEMAS_H
#define FOOTBALLMANAGER_SCHEMAS_H
#endif //FOOTBALLMANAGER_SCHEMAS_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <map>

//std::vector<sf::Vector2> schemaPervoiKomandy = SCHEME433;
int vysota_polya = 600;
int xScreen = 800;

std::vector<sf::Vector2f> SCHEME433 = {
        {20 / 800 * xScreen,  150 * 2},
        {120 / 800 * xScreen, 25 * 2},
        {100 / 800 * xScreen, 125 * 2},
        {100 / 800 * xScreen, 200 * 2},
        {120 / 800 * xScreen, 275 * 2},
        {200 / 800 * xScreen, 50 * 2},
        {200 / 800 * xScreen, 150 * 2},
        {200 / 800 * xScreen, 250 * 2},
        {325 / 800 * xScreen, 25 * 2},
        {365 / 800 * xScreen, 150 * 2},
        {325 / 800 * xScreen, 275 * 2}
};
std::vector<sf::Vector2f> SCHEME532 = {

        {10 / 800 * xScreen,  300 * 2},
        {175 / 800 * xScreen, 50 * 2},
        {100 / 800 * xScreen, 250 * 2},
        {100 / 800 * xScreen, 400 * 2},
        {100 / 800 * xScreen, 550 * 2},
        {175 / 800 * xScreen, 300 * 2},
        {175 / 800 * xScreen, 500 * 2},
        {325 / 800 * xScreen, 45 * 2},
        {325 / 800 * xScreen, 50 * 2},
        {365 / 800 * xScreen, 300 * 2},
        {325 / 800 * xScreen, 275 * 2}
};

std::vector<sf::Vector2f> SCHEME451 = {

        {20 / 800 * xScreen,  150 * 2},
        {120 / 800 * xScreen, 25 * 2},
        {100 / 800 * xScreen, 125 * 2},
        {100 / 800 * xScreen, 200 * 2},
        {120 / 800 * xScreen, 275 * 2},
        {125 / 800 * xScreen, 100 * 2},
        {125 / 800 * xScreen, 200 * 2},
        {275 / 800 * xScreen, 50 * 2},
        {275 / 800 * xScreen, 300 * 2},
        {275 / 800 * xScreen, 275 * 2},
        {325 / 800 * xScreen, 275 * 2}
};

std::map<std::string, std::vector<sf::Vector2f> *> mapScheme = {
        {"SCHEME433", &SCHEME433},
        {"SCHEME532", &SCHEME532},
        {"SCHEME451", &SCHEME451}
};