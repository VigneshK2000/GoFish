cmake_minimum_required(VERSION 3.14)
project(GoFish)

set(CMAKE_CXX_STANDARD 11)

add_executable(GoFish go_fish.cpp
                        card.h
                        deck.h
                        player.h
                        card.cpp
                        deck.cpp
                        player.cpp)