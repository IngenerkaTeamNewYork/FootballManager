cmake_minimum_required(VERSION 3.0)
project(FootballManager)

set(CMAKE_CXX_STANDARD 11)
link_libraries(sfml-graphics sfml-window sfml-system)

add_executable(testfb src/tests/test.cpp src/tests/doctest.h)

set(SOURCE_FILES
        src/RoundObj.h
        main.cpp
        OurTeam.h src/Schemas.h)

add_executable(FootballManager ${SOURCE_FILES})
