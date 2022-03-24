#include <iostream>
#include "player.hpp"
#include "../map/map.hpp"


// Construct a new Player:: Player object
Player::Player(int map_width, int map_height) {
    this->position[0] = (map_width - 1) / 2;
    this->position[1] = map_height - 1;
}

// Get the player X, Y coordinates in the map
int * Player::getPosition() {
    return this->position;
}

// Move the player 1 step in the map to the given direction
bool Player::move(string direction, Map& map) {
    int width = this->position[0];
    int height = this->position[1];
    if (direction == "up") {
        height--;
    } else if (direction == "down") {
        height++;
    } else if (direction == "right") {
        width++;
    } else if (direction == "left") {
        width--;
    }

    // If the position is not valid the player can't move there
    if (!map.isValidPosition(width, height)) {
        return false;
    }

    this->position[0] = width;
    this->position[1] = height;
    return true;
}
