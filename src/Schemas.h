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
#include "const.h"

//std::vector<sf::Vector2> schemaPervoiKomandy = SCHEME433;

std::vector<sf::Vector2f> SCHEME433 = {
        { 20 * SHIRINA_POLYA / 800 , 300 * VYSOTA_POLYA / 600},
        {120 * SHIRINA_POLYA / 800 ,  50 * VYSOTA_POLYA / 600},
        {100 * SHIRINA_POLYA / 800 , 250 * VYSOTA_POLYA / 600},
        {100 * SHIRINA_POLYA / 800 , 400 * VYSOTA_POLYA / 600},
        {120 * SHIRINA_POLYA / 800 , 550 * VYSOTA_POLYA / 600},
        {200 * SHIRINA_POLYA / 800 , 100 * VYSOTA_POLYA / 600},
        {200 * SHIRINA_POLYA / 800 , 300 * VYSOTA_POLYA / 600},
        {200 * SHIRINA_POLYA / 800 , 500 * VYSOTA_POLYA / 600},
        {325 * SHIRINA_POLYA / 800 ,  50 * VYSOTA_POLYA / 600},
        {365 * SHIRINA_POLYA / 800 , 300 * VYSOTA_POLYA / 600},
        {325 * SHIRINA_POLYA / 800 , 550 * VYSOTA_POLYA / 600}
};
std::vector<sf::Vector2f> SCHEME532 = {
        { 20 * SHIRINA_POLYA / 800 , 300 * VYSOTA_POLYA / 600},
        {175 * SHIRINA_POLYA / 800 ,  50 * VYSOTA_POLYA / 600},
        {100 * SHIRINA_POLYA / 800 , 150 * VYSOTA_POLYA / 600},
        {100 * SHIRINA_POLYA / 800 , 300 * VYSOTA_POLYA / 600},
        {100 * SHIRINA_POLYA / 800 , 450 * VYSOTA_POLYA / 600},
        {175 * SHIRINA_POLYA / 800 , 550 * VYSOTA_POLYA / 600},
        {275 * SHIRINA_POLYA / 800 , 100 * VYSOTA_POLYA / 600},
        {275 * SHIRINA_POLYA / 800 , 300 * VYSOTA_POLYA / 600},
        {275 * SHIRINA_POLYA / 800 , 500 * VYSOTA_POLYA / 600},
        {365 * SHIRINA_POLYA / 800 , 250 * VYSOTA_POLYA / 600},
        {365 * SHIRINA_POLYA / 800 , 350 * VYSOTA_POLYA / 600}
};

std::vector<sf::Vector2f> SCHEME451 = {
        { 20 * SHIRINA_POLYA / 800 , 300 * VYSOTA_POLYA / 600},
        {120 * SHIRINA_POLYA / 800 ,  50 * VYSOTA_POLYA / 600},
        {100 * SHIRINA_POLYA / 800 , 250 * VYSOTA_POLYA / 600},
        {100 * SHIRINA_POLYA / 800 , 400 * VYSOTA_POLYA / 600},
        {120 * SHIRINA_POLYA / 800 , 550 * VYSOTA_POLYA / 600},
        {260 * SHIRINA_POLYA / 800 ,  50 * VYSOTA_POLYA / 600},
        {260 * SHIRINA_POLYA / 800 , 175 * VYSOTA_POLYA / 600},
        {260 * SHIRINA_POLYA / 800 , 300 * VYSOTA_POLYA / 600},
        {260 * SHIRINA_POLYA / 800 , 425 * VYSOTA_POLYA / 600},
        {260 * SHIRINA_POLYA / 800 , 550 * VYSOTA_POLYA / 600},
        {365 * SHIRINA_POLYA / 800 , 300 * VYSOTA_POLYA / 600}
};

std::vector<std::string> REAL_SQUAD = {
        "Navas",
        "Marcelo",
        "Varane",
        "Ramos",
        "Carvajal",
        "Modric",
        "Casemiro",
        "Kroos",
        "Ronaldo",
        "Benzema",
        "Bale"
};
std::vector<std::string> BAYERN_SQUAD = {
        "Neuer",
        "Alaba",
        "Hummels",
        "Boateng",
        "Kimmich",
        "Vidal",
        "Thiago",
        "Ribery",
        "Muller",
        "Robben",
        "Lewa"
};
std::vector<std::string> ARSENAL_SQUAD = {
        "Cech",
        "Kolasinac",
        "Monreal",
        "Mustafi",
        "Koscielny",
        "Bellerin",
        "Xhaka",
        "Ramsey",
        "Alexis",
        "Lacazette",
        "Ozil"
};
std::vector<std::string> CHELSEA_SQUAD = {
        "Cortuois",
        "Alonso",
        "Azpilicueta",
        "Luiz",
        "Cahill",
        "Moses",
        "Fabregas",
        "Kante",
        "Hazard",
        "Morata",
        "Pedro"
};

std::map<std::string, std::vector<sf::Vector2f> *> mapScheme = {
        {"SCHEME433", &SCHEME433},
        {"SCHEME532", &SCHEME532},
        {"SCHEME451", &SCHEME451}
};

std::map<std::string, std::vector<std::string> *> mapSquad = {
        {"REAL", &REAL_SQUAD},
        {"BAYERN", &BAYERN_SQUAD},
        {"ARSENAL", &ARSENAL_SQUAD},
        {"CHELSEA", &CHELSEA_SQUAD}
};
