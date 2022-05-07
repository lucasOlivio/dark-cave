/**
 * @file map.cpp
 * @author Lucas Olivio (lucas27_olivio@hotmail.com)
 * @brief Map class implementation
 * @version 0.1
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * Class for the game map
 */

#include <iostream>
#include <vector>
#include <assert.h>
#include <ctime>
#include "map.hpp"
#include "../common.hpp"
#include "../player/player.hpp"

using namespace std;


// Construct a new Map:: Map object
Map::Map(Player* player){
    this->pPath_undiscovered = new Element(
        0, 0, 
        elements_types::PATH, 
        elements_outputs::UNDISCOVERED
    );
    this->pPath_cleared = new Element(
        0,  0,
        elements_types::PATH,
        elements_outputs::CLEARED
    );
    this->map = createMap(MAP_WIDTH, MAP_HEIGHT);
    // Creates the treasure object and randomly places it on the map
    int treasure_locations[3][2] = {
        {0, MAP_HEIGHT / 2},
        {MAP_WIDTH / 2, 0},
        {MAP_WIDTH, MAP_HEIGHT / 2}
    };
    srand((unsigned) time(0));
    int treasure_location = (rand() % 3) + 1;
    this->pTreasure = new Element(
        treasure_locations[treasure_location][0],
        treasure_locations[treasure_location][1],
        elements_types::TREASURE,
        elements_outputs::UNDISCOVERED
    );
    const int* treasurePosition = this->pTreasure->getPosition();
    this->setElement(treasurePosition[0], treasurePosition[1], this->pTreasure);
    // Set the player's initial position
    const int* playerPosition = player->getPosition();
    this->setElement(playerPosition[0], playerPosition[1], player);

    // Initiates the gameplay
    this->game_state = PLAYING;
}

// Create a new map randomizing the tiles to create enemies and set the player position
vector<vector<Element*>> Map::createMap(int width, int height) {
    vector<vector<Element*>> map(height + 1, vector<Element*>(width + 1));

    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= width; j++) {
            map[i][j] = this->pPath_undiscovered;
        }
    }

    return map;
}

// Display the map on terminal screen
void Map::displayMap() {
    cout << endl;
    for (int i = 0; i < this->map.size(); i++) {
        cout << CENTER_TEXT;
        for (int j = 0; j < this->map[i].size(); j++) {
            cout << this->map[i][j]->getOutput() << " ";
        }
        cout << endl;
    }
}

// Move the player 1 step in the map to the given direction
bool Map::movePlayer(string direction, Player* player) {
    const int* old_position = player->getPosition();
    int x = old_position[0];
    int y = old_position[1];

    if (direction == "up") {
        y--;
    } else if (direction == "right") {
        x++;
    } else if (direction == "down") {
        y++;
    } else if (direction == "left") {
        x--;
    }

    if (this->setElement(x, y, player)) {
        // If the new position is valid for the player, 
        // then set the old position to clear and set the new position to the player object
        this->setElement(old_position[0], old_position[1], pPath_cleared);
        player->setPosition(x, y);
        return true;
    }

    return false;
}

// Set a new element to the map position
bool Map::setElement(int x, int y, Element* element) {
    if (!this->isValidPosition(x, y)) {
        return false;
    }

    // If the element in the new position is not a path reveals it.
    elements_types type = this->map[y][x]->getType();
    switch(type) {
        case PATH: case PLAYER: // If the element is a path or player, just set the new element
            this->map[y][x] = element;
            return true;
        case TREASURE: // If is a treasure the game is won, reveals the treasure
            this->map[y][x]->setOutput(type);
            this->game_state = WON;
            return false;
        default:
            assert(!"Not a valid Element type!");
            return false;
    }
}

// Validate if the position is a valid map position
bool Map::isValidPosition(int x, int y) {
    return (x >= 0 && x <= MAP_WIDTH && y >= 0 && y <= MAP_HEIGHT);
}

// Return the actual state of the game
game_states Map::getState() {
    return this->game_state;
}

// Set new game state
void Map::setState(game_states state) {
    this->game_state = state;
}