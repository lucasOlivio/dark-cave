#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>
#include "../player/player.hpp"

using namespace std;

class Map {
    public:
        /**
         * @brief Construct a new Map:: Map object
         * 
         * @param player Player object
         */
        Map(Player& player);

        /**
         * @brief Display the map on terminal screen
         * 
         * @param player Player object
         */
        void displayMap(Player& player);

        /**
         * @brief Get the map vector
         * 
         * @return map vector
         */
        vector<vector<char>> getMap();

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
        bool movePlayer(string direction, Player& player);

    private:
        vector<vector<char>> map;
        enum class Elements : char {
            PLAYER = 'P',
            ENEMY = 'X',
            CLEARED = (char)250,
            UNDISCOVERED = (char)176
        };

        /**
         * @brief Create a new map randomizing the tiles 
         * to create enemies and set the player position
         * 
         * @param width Map X size
         * @param height Map Y size
         * 
         * @return vector<vector<int>> Map
         */
        vector<vector<char>> createMap(int width, int height, Player& player);

        /**
         * @brief Validate if the position is a valid map position
         * 
         * @return true If the position is valid
         */
        bool isValidPosition(int x, int y);

        /**
         * @brief Set a new character to the map position
         * 
         * @param x X position
         * @param y Y position
         * @param character Character to set
         * P - Player object
         * X - Defeated enemy object
         * O - Cleared path
         * 
         * @return true If the position is valid
         */
        bool setCoordinates(int x, int y, Elements element);
};

#endif // MAP_HPP