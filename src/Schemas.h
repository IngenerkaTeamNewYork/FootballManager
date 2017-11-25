//
// Created by Admin on 11.11.2017.
//
#pragma once
#ifndef FOOTBALLMANAGER_SCHEMAS_H
#define FOOTBALLMANAGER_SCHEMAS_H
#endif //FOOTBALLMANAGER_SCHEMAS_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <list>
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

std::list<std::string> REAL_SQUAD = {
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
std::list<std::string> BAYERN_SQUAD = {
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
std::list<std::string> ARSENAL_SQUAD = {
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
std::list<std::string> CHELSEA_SQUAD = {
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

std::map<std::string, std::list<std::string> *> mapSquad = {
        {"REAL", &REAL_SQUAD},
        {"BAYERN", &BAYERN_SQUAD},
        {"ARSENAL", &ARSENAL_SQUAD},
        {"CHELSEA", &CHELSEA_SQUAD}
};

struct skills {
    std::string player;
    unsigned int skill_goalkeeper = 0;
    unsigned int skill_defender = 0;
    unsigned int skill_midfielder = 0;
    unsigned int skill_striker = 0;

    skills(std::string player, unsigned int skill_goalkeeper, unsigned int skill_defender,
           unsigned int skill_midfielder, unsigned int skill_striker) {
        this->player = player;
        this->skill_goalkeeper = skill_goalkeeper;
        this->skill_defender = skill_defender;
        this->skill_midfielder = skill_midfielder;
        this->skill_striker = skill_striker;
    }

};

std::list<skills> skillsArray = {
        {"Navas",       85, 67, 40, 30},
        {"Marcelo",     20, 87, 75, 81},
        {"Varane",      34, 85, 59, 56},
        {"Ramos",       43, 86, 62, 72},
        {"Carvajal",    47, 84, 71, 69},
        {"Modric",      23, 72, 90, 68},
        {"Casemiro",    44, 81, 88, 68},
        {"Kroos",       21, 70, 87, 43},
        {"Ronaldo",     36, 20, 76, 95},
        {"Benzema",     15, 20, 63, 81},
        {"Bale",        30, 66, 63, 83},


        {"Courtois",    87, 67, 46, 31},
        {"Alonso",      15, 82, 75, 57},
        {"Azpilicueta", 36, 84, 59, 30},
        {"Luiz",        43, 86, 62, 25},
        {"Cahill",      61, 80, 42, 23},
        {"Moses",       21, 79, 54, 34},
        {"Fabregas",    12, 56, 85, 35},
        {"Kante",       21, 76, 85, 43},
        {"Hazard",      36, 20, 54, 92},
        {"Morata",      15, 20, 63, 84},
        {"Pedro",       10, 32, 45, 83},

        {"Neuer",       92, 67, 46, 31},
        {"Alaba",       15, 85, 75, 57},
        {"Hummels",     36, 84, 59, 30},
        {"Boateng",     43, 86, 62, 25},
        {"Kimmich",     61, 80, 42, 23},
        {"Vidal",       21, 79, 54, 34},
        {"Thiago",      12, 56, 85, 35},
        {"Ribery",      21, 76, 85, 43},
        {"Rodriguez",   36, 20, 54, 92},
        {"Robben",      15, 20, 63, 84},
        {"Lewa",        10, 32, 45, 83},

        {"Cech",        85, 67, 46, 31},
        {"Kolasinac",   15, 85, 75, 57},
        {"Monreal",     36, 84, 59, 30},
        {"Mustafi",     43, 86, 62, 25},
        {"Koscielny",   61, 80, 42, 23},
        {"Bellerin",    21, 79, 54, 34},
        {"Xhaka",       12, 56, 85, 35},
        {"Ramsey",      21, 76, 85, 43},
        {"Alexis",      36, 20, 54, 92},
        {"Lacazette",   15, 20, 63, 84},
        {"Ozil",        10, 32, 45, 83},




};
