//@formatter:off
#include "../Footballer.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("move() test") {
    Footballer obj({5, 5}, 20, "Rudy", sf::Color::Black);
    obj.move({10, 10});
    CHECK(obj.pos.x == 10);
    CHECK(obj.pos.y == 10);
}

TEST_CASE("radius() test") {
    Footballer obj({5, 5}, 20, "Rudy", sf::Color::Black);
    CHECK(obj.radius == 20);
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
    SUBCASE("testing if {100, 100} is NOT near {5, 5}") {
        CHECK_FALSE(obj.isInRange({5, 100}));
    }
}