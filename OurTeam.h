#ifndef FOOTBALLMANAGER_OURTEAM_H
#define FOOTBALLMANAGER_OURTEAM_H

#include <vector>
#include "src/Footballer.h"

const std::string mainFolder = "../assets/";

std::vector<Footballer> PlayersRed = {
        Footballer({5, 5}  , 20, "Rudy", sf::Color::Black),
        Footballer({50, 50}, 20, "Hazard", sf::Color::Red),
        Footballer({56, 56}, 20, "Isco", sf::Color::Red),
        Footballer({56, 56}, 20, "Kante", sf::Color::Red),
        Footballer({56, 56}, 20, "Luiz", sf::Color::Red),
        Footballer({56, 56}, 20, "Kroos", sf::Color::Red),
        Footballer({56, 56}, 20, "Neuer", sf::Color::Red),
        Footballer({56, 56}, 20, "Modric", sf::Color::Red),
        Footballer({56, 56}, 20, "Hummels", sf::Color::Red),
        Footballer({56, 56}, 20, "Fruchtl", sf::Color::Red)
};

std::vector<Footballer> PlayersBlue = {
        Footballer({5, 5}  , 20, "Gotze", sf::Color::Blue),
        Footballer({50, 50}, 20, "Gotze", sf::Color::Blue),
        Footballer({5, 5}  , 20, "Gotze", sf::Color::Blue),
        Footballer({5, 5}  , 20, "Gotze", sf::Color::Blue),
        Footballer({5, 5}  , 20, "Gotze", sf::Color::Blue),
        Footballer({5, 5}  , 20, "Gotze", sf::Color::Blue),
        Footballer({5, 5}  , 20, "Gotze", sf::Color::Blue),
        Footballer({5, 5}  , 20, "Gotze", sf::Color::Blue),
        Footballer({5, 5}  , 20, "Gotze", sf::Color::Blue),
        Footballer({5, 5}  , 20, "Gotze", sf::Color::Blue)
};

#endif //FOOTBALLMANAGER_OURTEAM_H
