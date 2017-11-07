#ifndef FOOTBALLMANAGER_OURTEAM_H
#define FOOTBALLMANAGER_OURTEAM_H

#include <vector>
#include "src/RoundObj.h"

const std::string mainFolder = "../assets/";

unsigned int goalsRed = 0;
std::vector<RoundObj> PlayersRed = {
        RoundObj({5, 5}  , 20, "Rudy", sf::Color::Black),
        RoundObj({50, 50}, 20, "Hazard", sf::Color::Red),
        RoundObj({56, 56}, 20, "Isco", sf::Color::Red),
        RoundObj({56, 56}, 20, "Kante", sf::Color::Red),
        RoundObj({56, 56}, 20, "Luiz", sf::Color::Red),
        RoundObj({56, 56}, 20, "Kroos", sf::Color::Red),
        RoundObj({56, 56}, 20, "Neuer", sf::Color::Red),
        RoundObj({56, 56}, 20, "Modric", sf::Color::Red),
        RoundObj({56, 56}, 20, "Hummels", sf::Color::Red),
        RoundObj({56, 56}, 20, "Fruchtl", sf::Color::Red)
};

unsigned int goalsBlue = 0;
std::vector<RoundObj> PlayersBlue = {
        RoundObj({5, 5}  , 20, "Gotze", sf::Color::Blue),
        RoundObj({50, 50}, 20, "Gotze", sf::Color::Blue),
        RoundObj({5, 5}  , 20, "Gotze", sf::Color::Blue),
        RoundObj({5, 5}  , 20, "Gotze", sf::Color::Blue),
        RoundObj({5, 5}  , 20, "Gotze", sf::Color::Blue),
        RoundObj({5, 5}  , 20, "Gotze", sf::Color::Blue),
        RoundObj({5, 5}  , 20, "Gotze", sf::Color::Blue),
        RoundObj({5, 5}  , 20, "Gotze", sf::Color::Blue),
        RoundObj({5, 5}  , 20, "Gotze", sf::Color::Blue),
        RoundObj({5, 5}  , 20, "Gotze", sf::Color::Blue)
};

#endif //FOOTBALLMANAGER_OURTEAM_H
