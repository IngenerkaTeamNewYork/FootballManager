//
// Created by Admin on 11.11.2017.
//

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

std::map<std::string, std::vector<std::string> *> mapSquad = {
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
};

std::list<skills> skillsArrayRealMadrid = {
        {"Navas",    85, 67, 40, 30},
        {"Marcelo",  20, 87, 75, 81},
        {"Varane",   34, 85, 59, 56},
        {"Ramos",    43, 86, 62, 72},
        {"Carvajal", 47, 84, 71, 69},
        {"Modric",   23, 72, 90, 68},
        {"Casemiro", 44, 81, 88, 68},
        {"Kroos",    21, 70, 87, 43},
        {"Ronaldo",  36, 20, 76, 95},
        {"Benzema",  15, 20, 63, 81},
        {"Bale",     30, 66, 63, 83}
};
std::list<skills> skillsArrayRealMadrid = {
        {"Navas",    85, 67, 40, 30},
        {"Marcelo",  20, 87, 75, 81},
        {"Varane",   34, 85, 59, 56},
        {"Ramos",    43, 86, 62, 72},
        {"Carvajal", 47, 84, 71, 69},
        {"Modric",   23, 72, 90, 68},
        {"Casemiro", 44, 81, 88, 68},
        {"Kroos",    21, 70, 87, 43},
        {"Ronaldo",  36, 20, 76, 95},
        {"Benzema",  15, 20, 63, 81},
        {"Bale",     30, 66, 63, 83}
};
std::list<skills> skillsArrayRealMadrid = {
        {"Navas",    85, 67, 40, 30},
        {"Marcelo",  20, 87, 75, 57},
        {"Varane",   34, 85, 59, 56},
        {"Ramos",    43, 86, 62, 72},
        {"Carvajal", 47, 84, 71, 69},
        {"Modric",   23, 72, 90, 68},
        {"Casemiro", 44, 81, 88, 68},
        {"Kroos",    21, 70, 87, 43},
        {"Ronaldo",  36, 20, 76, 95},
        {"Benzema",  15, 20, 63, 81},
        {"Bale",     30, 66, 63, 83}
};
std::list<skills> skillsArrayChealsea = {
        {"Courtois", 89, 67, 46, 31},
        {"Alonso", 15, 83, 75, 57},
        {"Azpilicueta", 36, 85, 59, 30},
        {"Luiz", 43, 86, 62, 25},
        {"Cahill", 61, 80, 42, 23},
        {"Moses", 21, 79, 54, 34},
        {"Fabregas", 12, 56, 86, 35},
        {"Kante", 21, 76, 85, 43},
        {"Hazard", 36, 20, 54, 92},
        {"Morata", 15, 20, 63, 84},
        {"Pedro", 10, 32, 45, 83}
};
