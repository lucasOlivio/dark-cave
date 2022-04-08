#include <iostream>
#include "player.hpp"
#include "../common.hpp"


// Construct a new Player:: Player object
Player::Player() {
    // Set the player in the bottom middle of the map
    position[0] = (MAP_WIDTH - 1)/2;
    position[1] = MAP_HEIGHT - 1;
}

// Get the player's position (x, y) in the map
const int* Player::getPosition() const {
    return position;
}

// Set the player new position (x, y) in the map
void Player::setPosition(int x, int y) {
    position[0] = x;
    position[1] = y;
}
