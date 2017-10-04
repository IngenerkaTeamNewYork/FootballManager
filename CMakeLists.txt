cmake_minimum_required(VERSION 3.0)
project(FootballManager)

set(CMAKE_CXX_STANDARD 11)
link_libraries(sfml-graphics sfml-window sfml-system)

add_definitions("-g")

set(SOURCE_FILES src/Footballer.h main.cpp OurTeam.h src/Icon.h)
add_executable(FootballManager ${SOURCE_FILES})
