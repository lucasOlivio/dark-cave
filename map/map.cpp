#include <iostream>
#include <vector>
#include "map.hpp"
#include "../common.hpp"
#include "../player/player.hpp"

using namespace std;


// Construct a new Map:: Map object
Map::Map(Player& player) {
    this->map = createMap(MAP_WIDTH, MAP_HEIGHT, player);
    cout << "SIZE MAP: " << this->map.size() << endl;

    // Set the player position
    const int* playerPosition = player.getPosition();
    this->setCoordinates(playerPosition[0], playerPosition[1], Elements::PLAYER);
}

// Create a new map randomizing the tiles to create enemies and set the player position
vector<vector<char>> Map::createMap(int width, int height, Player& player) {
    vector<vector<char>> map(height, vector<char>(width));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = '-';
        }
    }

    return map;
}

// Display the map on terminal screen
void Map::displayMap(Player& player) {
    cout << endl;
    for (int i = 0; i < this->map.size(); i++) {
        cout << CENTER_TEXT;
        for (int j = 0; j < this->map[i].size(); j++) {
            cout << this->map[i][j] << " ";
        }
        cout << endl;
    }
}

// Get the map vector
vector<vector<char>> Map::getMap() {
    return this->map;
}

// Move the player 1 step in the map to the given direction
bool Map::movePlayer(string direction, Player& player) {
    const int* old_position = player.getPosition();
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

    if (this->setCoordinates(x, y, Elements::PLAYER)) {
        // If the new position is valid for the player, 
        // then set the old position to clear and move the player
        this->setCoordinates(old_position[0], old_position[1], Elements::CLEARED);
        player.setPosition(x, y);
        return true;
    }

    return false;
}

// Set a new character to the map
bool Map::setCoordinates(int x, int y, Elements element) {
    if (!this->isValidPosition(x, y)) {
        return false;
    }

    cout << "ELEMENT: " << static_cast<char>(element) << endl;
    cout << "SIZE 1: " << this->map.size() << endl;
    cout << "SIZE 2: " << this->map[y].size() << endl;
    this->map[y][x] = static_cast<char>(element);

    return true;
}

// Validate if the position is a valid map position
bool Map::isValidPosition(int x, int y) {
    return (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT);
}
