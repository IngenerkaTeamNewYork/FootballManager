//@formatter:off
#include <random>
#include "../Footballer.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::mt19937 random_gen;
std::uniform_int_distribution<unsigned int> rl(0, 100);

#define rlg() rl(random_gen);

TEST_CASE("move() test") {
    Footballer obj({5, 5}, 20, "Rudy", sf::Color::Black);
    unsigned int rand_pos = rlg();
    obj.move({rand_pos + 10, rand_pos});
    CHECK(obj.pos.x == (rand_pos + 10));
    CHECK(obj.pos.y == rand_pos);
}

TEST_CASE("radius() test") {
    Footballer obj({5, 5}, 20, "Rudy", sf::Color::Black);
    CHECK(obj.radius == 20);
    SUBCASE("setRadius() test") {
        unsigned int rand_radius = rlg();
        obj.setRadius(rand_radius);
        CHECK(obj.radius == rand_radius);
    }
}

TEST_CASE("isInRange() test") {
    Footballer obj({5, 5}, 20, "Rudy", sf::Color::Black);
    SUBCASE("testing if obj is near itself") {
        CHECK(obj.isInRange(obj));
    }
    SUBCASE("testing if `obj.radius / 2` is near") {
        CHECK(obj.isInRange({obj.radius / 2, obj.radius / 2}));
    }
    SUBCASE("testing if {6, 6} is near {5, 5}") {
        CHECK(obj.isInRange({6, 6}));
    }
    SUBCASE("testing if NOT near values near {5, 5}") {
        CHECK_FALSE(obj.isInRange({100, 100}));
        CHECK_FALSE(obj.isInRange({50, 50}));
    }
    SUBCASE("testing if `obj.radius` is near") {
        CHECK(obj.isInRange({obj.radius, obj.radius}));
    }
}

TEST_CASE("test picture detection") {
    CHECK_THROWS(Footballer obj({5, 5}, 20, "qwertyuiop", sf::Color::Black));
}