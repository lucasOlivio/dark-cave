#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../element/element.hpp"

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