cmake_minimum_required(VERSION 3.8)
project(FootballManager)

set(CMAKE_CXX_STANDARD 11)
link_libraries(sfml-graphics sfml-window sfml-system)

set(SOURCE_FILES Footballer.h main.cpp)
add_executable(FootballManager ${SOURCE_FILES})