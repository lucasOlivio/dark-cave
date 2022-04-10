/**
 * @file map.cpp
 * @author Lucas Olivio (lucas27_olivio@hotmail.com)
 * @brief Map class definition
 * @version 0.1
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * Class for the game map
 */

#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include "../element/element.hpp"
#include "../player/player.hpp"

using namespace std;

class Map {
    public:
        /**
         * @brief Construct a new Map:: Map object
         * 
         * @param player Player element object
         */
        Map(Player* player);

        /**
         * @brief Display the map on terminal screen
         * 
         */
        void displayMap();

        /**
         * @brief Move the player 1 step in the map 
         * to the given direction
         * 
         * @param direction Direction to move (up, right, down, left)
         * @param player Reference to the player object
         * 
         * @return true If the player moved
         * @return false If the player couldn't move
         */
        bool movePlayer(string direction, Player* player);

    private:
        vector<vector<Element*>> map;
        Element *pPath_undiscovered;
        Element *pPath_cleared;

        /**
         * @brief Create a new map randomizing the tiles 
         * to create enemies and set the player position
         * 
         * @param width Map X size
         * @param height Map Y size
         * 
         * @return vector<vector<int>> Map
         */
        vector<vector<Element*>> createMap(int width, int height);

        /**
         * @brief Validate if the position is a valid map position
         * 
         * @return true If the position is valid
         */
        bool isValidPosition(int x, int y);

        /**
         * @brief Set a new element to the map position
         * 
         * @param x X position
         * @param y Y position
         * @param element Element to set
         * 
         * @return true If the position is valid
         */
        bool setElement(int x, int y, Element* element);
};

#endif // MAP_HPP