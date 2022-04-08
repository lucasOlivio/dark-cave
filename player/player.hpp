#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

using namespace std;

class Player {
    public:
        /**
         * @brief Construct a new Player:: Player object
         * 
         * @param position Player's coordinate position in the map
         */
        Player();

        /**
         * @brief Get the player's position (x, y) in the map
         */
        const int* getPosition() const;

        /**
         * @brief Set the player's new position (x, y) in the map
         */
        void setPosition(int x, int y);

    protected:
        int position[2];
};

#endif // PLAYER_HPP