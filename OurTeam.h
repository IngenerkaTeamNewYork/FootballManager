/**
 * @file OurTeam.h
 * @brief Файл с обьектами футболистов
 * Название комманд зависит от текста в team1.txt и team2.txt
 */

#ifndef FOOTBALLMANAGER_OURTEAM_H
#define FOOTBALLMANAGER_OURTEAM_H

#include <vector>
#include "src/RoundObj.h"
#include "src/Schemas.h"

unsigned int goalsRed = 0;
/**
 * @brief Первая комманда
 * По умолчанию UBOGIE
 */
std::vector<RoundObj> Team1 = {
        RoundObj(20, "Navas"   , 0,sf::Color::Black,sf::Color::White),
        RoundObj(20, "Marcelo" , 0,sf::Color::Blue ,sf::Color::White),
        RoundObj(20, "Varane"  , 0,sf::Color::Blue ,sf::Color::White),
        RoundObj(20, "Ramos"   , 0,sf::Color::Blue ,sf::Color::White),
        RoundObj(20, "Carvajal", 0,sf::Color::Blue ,sf::Color::White),
        RoundObj(20, "Modric"  , 0,sf::Color::Green,sf::Color::White),
        RoundObj(20, "Casemiro", 0,sf::Color::Green,sf::Color::White),
        RoundObj(20, "Kroos"   , 0,sf::Color::Green,sf::Color::White),
        RoundObj(20, "Ronaldo" , 0,sf::Color::Red  ,sf::Color::White),
        RoundObj(20, "Benzema" , 0,sf::Color::Red  ,sf::Color::White),
        RoundObj(20, "Bale"    , 0,sf::Color::Red  ,sf::Color::White)
};

unsigned int goalsBlue = 0;
/**
 * @brief Вторая комманда
 * По умолчанию NIGGAZ
 */
std::vector<RoundObj> Team2 = {
        RoundObj(20, "Rodriguez", 0, sf::Color::Blue, sf::Color::Red),
        RoundObj(20, "Alaba"    , 0,sf::Color::Blue  ,sf::Color::Red),
        RoundObj(20, "Boateng"  , 0,sf::Color::Blue  ,sf::Color::Red),
        RoundObj(20, "Hummels"  , 0,sf::Color::Blue  ,sf::Color::Red),
        RoundObj(20, "Kimmich"  , 0,sf::Color::Blue  ,sf::Color::Red),
        RoundObj(20, "Vidal"    , 0,sf::Color::Blue  ,sf::Color::Red),
        RoundObj(20, "Thiago"   , 0,sf::Color::Blue  ,sf::Color::Red),
        RoundObj(20, "Ribery"   , 0,sf::Color::Blue  ,sf::Color::Red),
        RoundObj(20, "Neuer", 0, sf::Color::Blue, sf::Color::Red),
        RoundObj(20, "Robben"   , 0,sf::Color::Blue  ,sf::Color::Red),
        RoundObj(20, "Lewa"     , 0,sf::Color::Blue  ,sf::Color::Red)
};

#endif //FOOTBALLMANAGER_OURTEAM_H
