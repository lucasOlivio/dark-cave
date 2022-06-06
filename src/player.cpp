#include "../include/player.hpp"
#include "../include/common.hpp"


// Construct a new Player:: Player object
Player::Player(): Element(
    MAP_WIDTH/2, MAP_HEIGHT, // Set the player in the middle of the bottom of the map
    elements_types::PLAYER, 
    elements_outputs::PLAYER
) {}

// Set a new position (x, y) for the player object in the map
void Player::setPosition(int x, int y) {
    this->position[0] = x;
    this->position[1] = y;
}
