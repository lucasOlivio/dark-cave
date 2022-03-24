#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>

using namespace std;

class Player;

class Map {
    public:
        /**
         * @brief Construct a new Map:: Map object
         * 
         * @param width Map X size
         * @param height Map Y size
         */
        Map(int width, int height);

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
        vector<vector<int>> getMap();

        /**
         * @brief Get the map x size
         * 
         */
        int getWidth();

        /**
         * @brief Get the map y size
         * 
         */
        int getHeight();

        /**
         * @brief Validate if the position is a valid map position
         * 
         * @return true If the position is valid
         */
        bool isValidPosition(int x, int y);

    private:
        int width;
        int height;
        vector<vector<int>> map;

        /**
         * @brief Create a new map randomizing the tiles 
         * to create enemies and set the player position
         * 
         * @param width Map X size
         * @param height Map Y size
         * 
         * @return vector<vector<int>> Map
         */
        vector<vector<int>> createMap(int width, int height);
};

#endif // MAP_HPP