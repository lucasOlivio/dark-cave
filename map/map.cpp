#include <iostream>
#include <vector>
#include "map.hpp"

using namespace std;


/**
 * @brief Construct a new Map:: Map object
 * 
 * @param height Map X size
 * @param width Map Y size
 */
Map::Map(int height, int width) {
    map = createMap(height, width);
    half_width = width / 2;
    half_height = height / 2;
}

/**
 * @brief Create a new map randomizing the tiles 
 * to create enemies and set the player position
 * 
 * @param height Map X size
 * @param width Map Y size
 * 
 * @return vector<vector<int>> Map
 */
vector<vector<int>> Map::createMap(int height, int width) {
    vector<vector<int>> map(height, vector<int>(width));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = 0;
        }
    }
    return map;
}

/**
 * @brief Display the map on terminal screen
 * 
 */
void Map::displayMap() {
    cout << endl;
    for (int i = 0; i < map.size(); i++) {
        cout << "                                                        ";
        if (half_height != i) {
            cout << "| ";
        } else {
            cout << "  ";
        }
        for (int j = 0; j < map[i].size(); j++) {
            cout << "X" << " ";
        }
        if(half_height != i) {
            cout << "|";
        }
        cout << endl;
    }
}