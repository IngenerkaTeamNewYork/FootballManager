#ifndef FOOTBALLMANAGER_OURTEAM_H
#define FOOTBALLMANAGER_OURTEAM_H

#include <vector>
#include "src/Footballer.h"

const std::string mainFolder = "../assets/";

std::vector<Footballer> PlayersRed = {
        Footballer({5, 5}  , 20, Icon(mainFolder + "Alaba.png"), sf::Color::Black),
        Footballer({50, 50}, 20, Icon(),sf::Color::Red),
        Footballer({56, 56}, 20, Icon(),sf::Color::Red),
        Footballer({56, 56}, 20, Icon(),sf::Color::Red),
        Footballer({56, 56}, 20, Icon(),sf::Color::Red),
        Footballer({56, 56}, 20, Icon(),sf::Color::Red),
        Footballer({56, 56}, 20, Icon(),sf::Color::Red),
        Footballer({56, 56}, 20, Icon(),sf::Color::Red),
        Footballer({56, 56}, 20, Icon(),sf::Color::Red),
        Footballer({56, 56}, 20, Icon(),sf::Color::Red)
};

std::vector<Footballer> PlayersBlue = {
        Footballer({5, 5}  , 20, Icon(), sf::Color::Blue),
        Footballer({50, 50}, 20, Icon(), sf::Color::Blue),
        Footballer({5, 5}  , 20, Icon(), sf::Color::Blue),
        Footballer({5, 5}  , 20, Icon(), sf::Color::Blue),
        Footballer({5, 5}  , 20, Icon(), sf::Color::Blue),
        Footballer({5, 5}  , 20, Icon(), sf::Color::Blue),
        Footballer({5, 5}  , 20, Icon(), sf::Color::Blue),
        Footballer({5, 5}  , 20, Icon(), sf::Color::Blue),
        Footballer({5, 5}  , 20, Icon(), sf::Color::Blue),
        Footballer({5, 5}  , 20, Icon(), sf::Color::Blue)
};

#endif //FOOTBALLMANAGER_OURTEAM_H
