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
std::vector<std::string> NIGGAZ_SQUAD = {
        "Alaba",
        "Boateng",
        "Lacazette",
        "Lacazette",
        "Boateng",
        "Alaba",
        "Kante",
        "Kante",
        "Kante",
        "Boateng",
        "Boateng"
};
std::vector<std::string> UBOGIE_SQUAD = {
        "Fruchtl",
        "Fruchtl",
        "Fruchtl",
        "Fruchtl",
        "Fruchtl",
        "Fruchtl",
        "judge3",
        "judge3",
        "judge3",
        "judge3",
        "judge3"
};


std::map<std::string, std::vector<sf::Vector2f> *> mapScheme = {
        {"SCHEME433", &SCHEME433},
        {"SCHEME532", &SCHEME532},
        {"SCHEME451", &SCHEME451}
};

std::map<std::string, std::vector<std::string> *> mapSquad = {
        {"REAL",    &REAL_SQUAD},
        {"BAYERN",  &BAYERN_SQUAD},
        {"ARSENAL", &ARSENAL_SQUAD},
        {"CHELSEA", &CHELSEA_SQUAD},
        {"NIGGAZ",  &NIGGAZ_SQUAD},
        {"UBOGIE",  &UBOGIE_SQUAD}

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

std::vector<skills> skillsArray = {
        {"Alaba",     85, 55, 19, 10},
        {"Marcelo",   20, 87, 70, 57},
        {"Varane",    34, 85, 40, 26},
        {"Ramos",     43, 86, 62, 72},
        {"Carvajal",  47, 84, 71, 23},
        {"Modric",    23, 72, 90, 35},
        {"Casemiro",  24, 81, 88, 17},
        {"Kroos",     21, 70, 87, 43},
        {"Ronaldo",   36, 20, 75, 95},
        {"Benzema",   15, 20, 63, 85},
        {"Bale",      30, 66, 63, 84},


        {"Courtois",  87, 43, 25, 18},
        {"Alonso",    15, 82, 66, 36},
        {"Azpilicueta", 36, 84, 48, 30},
        {"Luiz",        43, 86, 81, 25},
        {"Cahill",      61, 80, 42, 23},
        {"Moses",       21, 78, 46, 34},
        {"Fabregas",    12, 56, 85, 72},
        {"Kante",       21, 77, 85, 11},
        {"Hazard",      36, 20, 88, 92},
        {"Morata",      15, 20, 63, 85},
        {"Pedro",       10, 32, 41, 83},

        {"Neuer",       92, 57, 40, 30},
        {"Alaba",       16, 85, 67, 47},
        {"Hummels",     50, 89, 59, 30},
        {"Boateng",     43, 87, 62, 25},
        {"Kimmich",     65, 78, 42, 23},
        {"Vidal",       30, 79, 88, 34},
        {"Thiago",      33, 34, 87, 35},
        {"Ribery",      21, 13, 81, 86},
        {"Rodriguez",   22, 20, 81, 85},
        {"Robben",    20, 20, 86, 90},
        {"Lewa",      32, 32, 80, 93},

        {"Cech",      85, 57, 46, 31},
        {"Kolasinac", 15, 84, 75, 40},
        {"Monreal",   36, 76, 55, 32},
        {"Mustafi",   40, 85, 61, 27},
        {"Koscielny", 37, 85, 42, 23},
        {"Bellerin",  20, 78, 43, 33},
        {"Xhaka",     14, 48, 82, 26},
        {"Ramsey",    21, 49, 85, 50},
        {"Alexis",    10, 49, 84, 92},
        {"Lacazette", 27, 25, 66, 85},
        {"Ozil",      10, 32, 87, 83},

        {"Fruchtl",   10, 10, 10, 10},
        {"judge3",    20, 20, 15, 10}


};
