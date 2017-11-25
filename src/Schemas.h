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
        { 20 * FBM_X_POLYA / 800 , 300 * FBM_Y_POLYA / 600},
        {120 * FBM_X_POLYA / 800 ,  50 * FBM_Y_POLYA / 600},
        {100 * FBM_X_POLYA / 800 , 250 * FBM_Y_POLYA / 600},
        {100 * FBM_X_POLYA / 800 , 400 * FBM_Y_POLYA / 600},
        {120 * FBM_X_POLYA / 800 , 550 * FBM_Y_POLYA / 600},
        {200 * FBM_X_POLYA / 800 , 100 * FBM_Y_POLYA / 600},
        {200 * FBM_X_POLYA / 800 , 300 * FBM_Y_POLYA / 600},
        {200 * FBM_X_POLYA / 800 , 500 * FBM_Y_POLYA / 600},
        {325 * FBM_X_POLYA / 800 ,  50 * FBM_Y_POLYA / 600},
        {365 * FBM_X_POLYA / 800 , 300 * FBM_Y_POLYA / 600},
        {325 * FBM_X_POLYA / 800 , 550 * FBM_Y_POLYA / 600}
};
std::vector<sf::Vector2f> SCHEME532 = {
        { 20 * FBM_X_POLYA / 800 , 300 * FBM_Y_POLYA / 600},
        {175 * FBM_X_POLYA / 800 ,  50 * FBM_Y_POLYA / 600},
        {100 * FBM_X_POLYA / 800 , 150 * FBM_Y_POLYA / 600},
        {100 * FBM_X_POLYA / 800 , 300 * FBM_Y_POLYA / 600},
        {100 * FBM_X_POLYA / 800 , 450 * FBM_Y_POLYA / 600},
        {175 * FBM_X_POLYA / 800 , 550 * FBM_Y_POLYA / 600},
        {275 * FBM_X_POLYA / 800 , 100 * FBM_Y_POLYA / 600},
        {275 * FBM_X_POLYA / 800 , 300 * FBM_Y_POLYA / 600},
        {275 * FBM_X_POLYA / 800 , 500 * FBM_Y_POLYA / 600},
        {365 * FBM_X_POLYA / 800 , 250 * FBM_Y_POLYA / 600},
        {365 * FBM_X_POLYA / 800 , 350 * FBM_Y_POLYA / 600}
};

std::vector<sf::Vector2f> SCHEME451 = {
        { 20 * FBM_X_POLYA / 800 , 300 * FBM_Y_POLYA / 600},
        {120 * FBM_X_POLYA / 800 ,  50 * FBM_Y_POLYA / 600},
        {100 * FBM_X_POLYA / 800 , 250 * FBM_Y_POLYA / 600},
        {100 * FBM_X_POLYA / 800 , 400 * FBM_Y_POLYA / 600},
        {120 * FBM_X_POLYA / 800 , 550 * FBM_Y_POLYA / 600},
        {260 * FBM_X_POLYA / 800 ,  50 * FBM_Y_POLYA / 600},
        {260 * FBM_X_POLYA / 800 , 175 * FBM_Y_POLYA / 600},
        {260 * FBM_X_POLYA / 800 , 300 * FBM_Y_POLYA / 600},
        {260 * FBM_X_POLYA / 800 , 425 * FBM_Y_POLYA / 600},
        {260 * FBM_X_POLYA / 800 , 550 * FBM_Y_POLYA / 600},
        {365 * FBM_X_POLYA / 800 , 300 * FBM_Y_POLYA / 600}
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
