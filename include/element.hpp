/**
 * @file element.hpp
 * @author Lucas Olivio (lucas27_olivio@hotmail.com)
 * @brief Element class implementation
 * @version 0.1
 * @date 2022-04-09
 * 
 * @copyright Copyright (c) 2022
 * 
 * Base class for all elements in the game
 */

#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "../include/common.hpp"

class Element {
    public:
        /**
         * @brief Construct a new Element:: Element object
         * 
         * @param x X position
         * @param y Y position
         * @param type Element type
         * @param output Output to be displayed. Defaults to UNDISCOVERED
         * 
         * The element can have a type and an output different from the expected.
         * This is useful for the map, where the player can't see the enemies.
         * 
         * Ex: The element can be a type of ENEMY and the output can be a UNDISCOVERED.
         * Same thing for the PATH type, which can be an UNDISCOVERED or a CLEARED output.
         */
        Element(
            int x, 
            int y, 
            elements_types type, 
            elements_outputs output=elements_outputs::UNDISCOVERED
        );

        /**
         * @brief Set the element's new position (x, y) in the map
         */
        void setPosition(int x, int y);

        /**
         * @brief Get the element's position (x, y) in the map
         */
        int* getPosition();

        /**
         * @brief Set a new output for the element
         * 
         */
        void setOutput(elements_types element_type);

        /**
         * @brief Get the output of the element
         * 
         */
        char getOutput();

        /**
         * @brief Get the type of the element
         * 
         */
        elements_types getType();

    protected:
        int position[2];
        elements_outputs output;
        elements_types type;
};

#endif // ELEMENT_HPP