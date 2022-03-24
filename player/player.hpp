#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "../map/map.hpp"

using namespace std;

class Player {
    public:
        /**
         * @brief Construct a new Player:: Player object
         * 
         * @param map_height Map X size
         * @param map_width Map Y size
         */
        Player(int map_width, int map_height);

        /**
         * @brief Get the player X, Y coordinates in the map
         * 
         * @return player coordinates inside the map
         */
        int * getPosition();

        /**
         * @brief Move the player 1 step in the map 
         * to the given direction
         * 
         * @param direction Direction to move (up, right, down, left)
         * @param map Map to move the player
         * 
         * @return true If the player can move
         * @return false If the player can't move
         */
        bool move(string direction, Map& map);

    private:
        int position[2];
};

#endif // PLAYER_HPP