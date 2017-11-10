#ifndef FOOTBALLMANAGER_OURTEAM_H
#define FOOTBALLMANAGER_OURTEAM_H

#include <vector>
#include "src/RoundObj.h"

const std::string mainFolder = "../assets/";

unsigned int goalsRed = 0;
std::vector<RoundObj> Real = {
        RoundObj({20, 300}  , 20, "Navas", sf::Color::Black  ,sf::Color::White),
        RoundObj({250, 50}  , 20, "Marcelo", sf::Color::Blue ,sf::Color::White),
        RoundObj({200, 250}, 20, "Varane", sf::Color::Blue   ,sf::Color::White),
        /*RoundObj({200, 400}, 20, "Ramos", sf::Color::Blue    ,sf::Color::White),
        RoundObj({250, 550}, 20, "Carvajal", sf::Color::Blue ,sf::Color::White),
        RoundObj({400, 100}, 20, "Modric", sf::Color::Green  ,sf::Color::White),
        RoundObj({400, 300}, 20, "Casemiro", sf::Color::Green,sf::Color::White),
        RoundObj({400, 500}, 20, "Kroos", sf::Color::Green   ,sf::Color::White),
        RoundObj({650, 50}, 20, "Ronaldo", sf::Color::Red    ,sf::Color::White),
        RoundObj({730, 300}, 20, "Benzema", sf::Color::Red   ,sf::Color::White),
        RoundObj({650, 550}, 20, "Bale", sf::Color::Red      ,sf::Color::White)*/
};

unsigned int goalsBlue = 0;
std::vector<RoundObj> Bayern = {
        RoundObj({5, 5}  , 20, "Neuer", sf::Color::Blue    ,sf::Color::Red),
        RoundObj({50, 50}, 20, "Alaba", sf::Color::Blue    ,sf::Color::Red),
        RoundObj({100, 25}  , 20, "Boateng", sf::Color::Blue  ,sf::Color::Red)/*,
        /*RoundObj({5, 5}  , 20, "Hummels", sf::Color::Blue  ,sf::Color::Red),
        RoundObj({5, 5}  , 20, "Kimmich", sf::Color::Blue  ,sf::Color::Red),
        RoundObj({5, 5}  , 20, "Vidal", sf::Color::Blue    ,sf::Color::Red),
        RoundObj({5, 5}  , 20, "Thiago", sf::Color::Blue   ,sf::Color::Red),
        RoundObj({5, 5}  , 20, "Ribery", sf::Color::Blue   ,sf::Color::Red),
        RoundObj({5, 5}  , 20, "Rodriguez", sf::Color::Blue,sf::Color::Red),
        RoundObj({5, 5}  , 20, "Robben", sf::Color::Blue   ,sf::Color::Red),
        RoundObj({5, 5}  , 20, "Lewa", sf::Color::Blue     ,sf::Color::Red)*/
};

#endif //FOOTBALLMANAGER_OURTEAM_H
