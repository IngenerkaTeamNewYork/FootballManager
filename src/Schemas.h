//
// Created by Admin on 11.11.2017.
//

#ifndef FOOTBALLMANAGER_SCHEMAS_H
#define FOOTBALLMANAGER_SCHEMAS_H
#endif //FOOTBALLMANAGER_SCHEMAS_H
#include <vector>
#include <SFML/System/Vector2.hpp>

//std::vector<sf::Vector2> schemaPervoiKomandy = SCHEME433;
int vysota_polya  = 600;
int shirina_polya = 800;

std::vector<sf::Vector2f> SCHEME433 = {
    { 20/800*shirina_polya, 150*2}  ,
    {120/800*shirina_polya, 25*2 }  ,
    {100/800*shirina_polya, 125*2},
    {100/800*shirina_polya, 200*2},
    {120/800*shirina_polya, 275*2},
    {200/800*shirina_polya, 50*2 },
    {200/800*shirina_polya, 150*2},
    {200/800*shirina_polya, 250*2},
    {325/800*shirina_polya, 25*2 },
    {365/800*shirina_polya, 150*2},
    {325/800*shirina_polya, 275*2}
};
std::vector<sf::Vector2f> SCHEME532 = {

        {10/800*shirina_polya,  300*2 }  ,
        {175/800*shirina_polya, 50*2  },
        {100/800*shirina_polya, 250*2 },
        {100/800*shirina_polya, 400*2 }  ,
        {100/800*shirina_polya, 550*2 }  ,
        {175/800*shirina_polya, 300*2 }  ,
        {175/800*shirina_polya, 500*2 }  ,
        {325/800*shirina_polya, 45*2  }  ,
        {325/800*shirina_polya, 50*2  }  ,
        {365/800*shirina_polya, 300*2 }  ,
        {325/800*shirina_polya, 275*2 }
};

std::vector<sf::Vector2f> SCHEME451 = {

        { 20/800*shirina_polya, 150*2}  ,
        {120/800*shirina_polya, 25*2}  ,
        {100/800*shirina_polya, 125*2},
        {100/800*shirina_polya, 200*2},
        {120/800*shirina_polya, 275*2},
        {125/800*shirina_polya, 100*2}  ,
        {125/800*shirina_polya, 200*2}  ,
        {275/800*shirina_polya, 50*2}   ,
        {275/800*shirina_polya, 300*2}    ,
        {275/800*shirina_polya, 275*2}  ,
        {325/800*shirina_polya, 275*2}
};



