#ifndef COMMON_HPP
#define COMMON_HPP

#include <string>
#include <vector>

using namespace std;

const string CENTER_TEXT = "                                                        ";

const int MAP_HEIGHT = 9;
const int MAP_WIDTH = 9;

enum class elements_outputs : char {
    PLAYER = 'P',
    ENEMY = 'X',
    CLEARED = (char)250,
    UNDISCOVERED = (char)176
};
enum elements_types {
    PLAYER,
    ENEMY,
    PATH
};

#endif // COMMON_HPP