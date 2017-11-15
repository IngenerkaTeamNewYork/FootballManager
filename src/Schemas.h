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
int vysota_polya = 550;
int shirina_polya = 800;

std::vector<sf::Vector2f> SCHEME433 = {
        { 20 * shirina_polya / 800 , 300 * vysota_polya / 600},
        {120 * shirina_polya / 800 ,  50 * vysota_polya / 600},
        {100 * shirina_polya / 800 , 250 * vysota_polya / 600},
        {100 * shirina_polya / 800 , 400 * vysota_polya / 600},
        {120 * shirina_polya / 800 , 550 * vysota_polya / 600},
        {200 * shirina_polya / 800 , 100 * vysota_polya / 600},
        {200 * shirina_polya / 800 , 300 * vysota_polya / 600},
        {200 * shirina_polya / 800 , 500 * vysota_polya / 600},
        {325 * shirina_polya / 800 ,  50 * vysota_polya / 600},
        {365 * shirina_polya / 800 , 300 * vysota_polya / 600},
        {325 * shirina_polya / 800 , 550 * vysota_polya / 600}
};
std::vector<sf::Vector2f> SCHEME532 = {
        { 20 * shirina_polya / 800 , 300 * vysota_polya / 600},
        {175 * shirina_polya / 800 ,  50 * vysota_polya / 600},
        {100 * shirina_polya / 800 , 150 * vysota_polya / 600},
        {100 * shirina_polya / 800 , 300 * vysota_polya / 600},
        {100 * shirina_polya / 800 , 450 * vysota_polya / 600},
        {175 * shirina_polya / 800 , 550 * vysota_polya / 600},
        {275 * shirina_polya / 800 , 100 * vysota_polya / 600},
        {275 * shirina_polya / 800 , 300 * vysota_polya / 600},
        {275 * shirina_polya / 800 , 500 * vysota_polya / 600},
        {365 * shirina_polya / 800 , 250 * vysota_polya / 600},
        {365 * shirina_polya / 800 , 350 * vysota_polya / 600}
};

std::vector<sf::Vector2f> SCHEME451 = {
        { 20 * shirina_polya / 800 , 300 * vysota_polya / 600},
        {120 * shirina_polya / 800 ,  50 * vysota_polya / 600},
        {100 * shirina_polya / 800 , 250 * vysota_polya / 600},
        {100 * shirina_polya / 800 , 400 * vysota_polya / 600},
        {120 * shirina_polya / 800 , 550 * vysota_polya / 600},
        {260 * shirina_polya / 800 ,  50 * vysota_polya / 600},
        {260 * shirina_polya / 800 , 175 * vysota_polya / 600},
        {260 * shirina_polya / 800 , 300 * vysota_polya / 600},
        {260 * shirina_polya / 800 , 425 * vysota_polya / 600},
        {260 * shirina_polya / 800 , 550 * vysota_polya / 600},
        {365 * shirina_polya / 800 , 300 * vysota_polya / 600}
};

std::map<std::string, std::vector<sf::Vector2f> *> mapScheme = {
        {"SCHEME433", &SCHEME433},
        {"SCHEME532", &SCHEME532},
        {"SCHEME451", &SCHEME451}
};
