#include <iostream>
#include <vector>
#include "map.hpp"
#include "../common.hpp"
#include "../player/player.hpp"

using namespace std;


// Construct a new Map:: Map object
Map::Map(int width, int height) {
    this->map = createMap(height, width);
    this->width = width;
    this->height = height;
}

// Create a new map randomizing the tiles to create enemies and set the player position
vector<vector<int>> Map::createMap(int width, int height) {
    vector<vector<int>> map(height, vector<int>(width));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = 0;
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
            if(i == player.getPosition()[1] && j == player.getPosition()[0]) {
                cout << "O";
            } else {
                cout << "-";
            }
            cout << " ";
        }
        cout << endl;
    }
}

// Get the map vector
vector<vector<int>> Map::getMap() {
    return this->map;
}

// Get the map x size
int Map::getWidth() {
    return this->width;
}

// Get the map y size
int Map::getHeight() {
    return this->height;
}

// Validate if the position is a valid map position
bool Map::isValidPosition(int x, int y) {
    return (x >= 0 && x < this->width && y >= 0 && y < this->height);
}
