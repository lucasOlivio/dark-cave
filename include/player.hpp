/**
 * @file player.hpp
 * @author Lucas Olivio (lucas27_olivio@hotmail.com)
 * @brief Player class definition
 * @version 0.1
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * Class for the player object
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "element.hpp"

using namespace std;

class Player: public Element {
    public:
        /**
         * @brief Construct a new Player:: Player object setting the default position, type and output.
         * 
         */
        Player();

        /**
         * @brief Set a new position (x, y) for the player object in the map.
         * 
         * @param x X position
         * @param y Y position
         */
        void setPosition(int x, int y);
};

#endif // PLAYER_HPP