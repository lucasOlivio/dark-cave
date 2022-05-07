/**
 * @file common.hpp
 * @author Lucas Olivio (lucas27_olivio@hotmail.com)
 * @brief Common functions and constants
 * @version 0.1
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022
 */

#ifndef COMMON_HPP
#define COMMON_HPP

#include <string>
#include <vector>

using namespace std;

const string CENTER_TEXT = "                                                        ";

const int MAP_HEIGHT = 8;
const int MAP_WIDTH = 8;

enum class elements_outputs: char {
    PLAYER = 'P',
    ENEMY = (char)6,
    CLEARED = (char)250,
    UNDISCOVERED = (char)176,
    TREASURE = (char)4
};

enum elements_types {
    PLAYER,
    ENEMY,
    PATH,
    TREASURE
};

enum game_states {
    PLAYING,
    WON,
    LOST,
    QUIT
};

#endif // COMMON_HPP