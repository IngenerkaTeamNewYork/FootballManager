//@formatter:off
#include <random>
#include "../RoundObj.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::mt19937 random_gen(static_cast<unsigned long>(time(nullptr)));
std::uniform_int_distribution<unsigned int> rl(0, 100);

#define rlg() rl(random_gen);

TEST_CASE("move() test") {
    RoundObj obj({5, 5}, 20, "Rudy", sf::Color::Black);
    unsigned int rand_pos = rlg();
    obj.move({rand_pos + 10, rand_pos});
    CHECK(obj.pos.x == rand_pos + 10);
    CHECK(obj.pos.y == rand_pos);
}

TEST_CASE("radius() test") {
    RoundObj obj({5, 5}, 20, "Rudy", sf::Color::Black);
    CHECK(obj.radius == 20);
    SUBCASE("setRadius() test") {
        unsigned int rand_radius = rlg();
        obj.setRadius(rand_radius);
        CHECK(obj.radius == rand_radius);
    }
}

TEST_CASE("isNear() test") {
    RoundObj obj({5, 5}, 20, "Rudy", sf::Color::Black);
    SUBCASE("testing if obj is near itself") {
        CHECK(obj.isNear(obj));
    }
    SUBCASE("testing if `obj.radius / 2` is near") {
        CHECK(obj.isNear({obj.radius / 2, obj.radius / 2}));
    }
    SUBCASE("testing if {6, 6} is near {5, 5}") {
        CHECK(obj.isNear({6, 6}));
    }
    SUBCASE("testing if NOT near values near {5, 5}") {
        CHECK_FALSE(obj.isNear({100, 100}));
        CHECK_FALSE(obj.isNear({50, 50}));
        CHECK_FALSE(obj.isNear({5, 500}));
    }
    SUBCASE("testing if `obj.radius` is near") {
        CHECK(obj.isNear({obj.radius + obj.pos.x, obj.radius + obj.pos.y}));
        CHECK(obj.isNear({obj.radius * 2 + obj.pos.x, obj.radius * 2 + obj.pos.y}));
        CHECK_FALSE(obj.isNear({obj.radius * 2 + 1 + obj.pos.x, obj.radius * 2 + 1 + obj.pos.y}));
    }
}

TEST_CASE("test picture detection") {
    CHECK_THROWS_MESSAGE(RoundObj obj({5, 5}, 20, "qwertyuiop", sf::Color::Black), "Failed to load image");
    RoundObj obj({5, 5}, 20, "-", sf::Color::Black);
    CHECK_FALSE(obj.pic());
}