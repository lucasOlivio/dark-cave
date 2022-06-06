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
#include "../include/map.hpp"
#include "../include/common.hpp"
#include "../include/utils.hpp"
#include "../include/player.hpp"

using namespace std;


// Construct a new Map:: Map object
Map::Map(Player* player){
    this->map = createMap(MAP_WIDTH, MAP_HEIGHT);

    // Creates the treasure object and randomly places it on the map
    this->pTreasure = createTreasure();

    // Set the player's initial position
    const int* playerPosition = player->getPosition();
    this->setElement(playerPosition[0], playerPosition[1], player);

    // Creates the list of enemies randomly placed on the map
    for(int i = 0; i < ENEMY_NUMBER; i++){
        this->enemies[i] = createEnemy();
    }

    // Initiates the gameplay
    this->game_state = PLAYING;
}

// Create a new map randomizing the tiles to create enemies and set the player position
vector<vector<Element*>> Map::createMap(int width, int height) {
    // Default path elements for the hole map
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
    // Initialize the map with the default path element
    vector<vector<Element*>> map(height + 1, vector<Element*>(width + 1));

    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= width; j++) {
            map[i][j] = this->pPath_undiscovered;
        }
    }

    return map;
}

// Creates the treasure, randomizing its position
Element* Map::createTreasure() {
    // Treasure only possible locations are in the middle of the sides of the map
    int treasure_locations[3][2] = {
        {0, MAP_HEIGHT / 2},
        {MAP_WIDTH / 2, 0},
        {MAP_WIDTH, MAP_HEIGHT / 2}
    };
    int treasure_location = randomNumber(0, 3);
    Element *pTreasure = new Element(
        treasure_locations[treasure_location][0],
        treasure_locations[treasure_location][1],
        elements_types::TREASURE,
        elements_outputs::UNDISCOVERED
    );
    const int* treasurePosition = pTreasure->getPosition();
    this->setElement(
        treasure_locations[treasure_location][0], 
        treasure_locations[treasure_location][1], 
        pTreasure
    );
    return pTreasure;
}

// Creates a new enemy, randomizing its position
Element* Map::createEnemy() {
    int enemy_x = randomNumber(0, MAP_WIDTH);
    int enemy_y = randomNumber(0, MAP_HEIGHT);

    // Validate if the position is a valid map position
    while (!this->isValidPosition(enemy_x, enemy_y)) {
        enemy_x = randomNumber(0, MAP_WIDTH);
        enemy_y = randomNumber(0, MAP_HEIGHT);
    }
    Element *enemy = new Element(
        enemy_x,
        enemy_y,
        elements_types::ENEMY,
        elements_outputs::UNDISCOVERED
    );
    this->setElement(enemy_x, enemy_y, enemy);

    return enemy;
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
        case TREASURE: // If is a treasure the game is won, reveals the treasure and the enemies
            this->map[y][x]->setOutput(type);
            for(int i = 0; i < ENEMY_NUMBER; i++){
                this->enemies[i]->setOutput(elements_types::ENEMY);
            }
            this->game_state = WON;
            return false;
        case ENEMY: // If is an enemy the game is lost, reveals the enemy and the treasure
            this->map[y][x]->setOutput(type);
            this->pTreasure->setOutput(elements_types::TREASURE);
            this->game_state = LOST;
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