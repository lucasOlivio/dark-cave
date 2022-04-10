/**
 * @file element.hpp
 * @author Lucas Olivio (lucas27_olivio@hotmail.com)
 * @brief Element class implementation
 * @version 0.1
 * @date 2022-04-09
 * 
 * @copyright Copyright (c) 2022
 * 
 * Class for all elements in the game.
 */

#include <iostream>
#include "element.hpp"

using namespace std;

// Constructor
Element::Element(
    int x, 
    int y, 
    elements_types type, 
    elements_outputs output
) {
    this->position[0] = x;
    this->position[1] = y;
    this->type = type;
    this->output = output;
}

// Set the element new position (x, y) in the map
void Element::setPosition(int x, int y) {
    throw "You can't set a position for this element!";
}

// Get the element's position (x, y) in the map
int* Element::getPosition() {
    return this->position;
}

// Set a new output for the element
void Element::setOutput(elements_outputs output) {
    this->output = output;
}

// Get the output of the element
char Element::getOutput() {
    return static_cast<char>(this->output);
}