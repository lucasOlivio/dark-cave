/**
 * @file main.cpp
 * @author Lucas Olivio (lucas27_olivio@hotmail.com)
 * @brief Main controller of the program
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <string>
#include "map/map.hpp"

using namespace std;

const int MAP_HEIGHT = 9;
const int MAP_WIDTH = 9;

// Title screen display
void mainTitle();

// Main menu display and controller
void mainMenu();

// Main game loop
void gameLoop();

// Main controller of the program
int main() {
    system("cls");
    mainTitle();
    system("pause");
    mainMenu();
    return 0;
}

// Title screen display
void mainTitle() {
    cout << "==========================================================================================================================================" << endl;
    cout << "|    ----------         -------      ----------      |  |     /  /       ------------      -------      \\  \\     /  /    ------------    |" << endl;
    cout << "|    --------\\  \\     -----------    --------\\  \\    |  |    /  /       -------------    -----------     \\  \\   /  /    -------------    |" << endl;
    cout << "|    |  |     |  |   |  |     |  |   |  |     |  |   |  |---/  /        |  |            |  |     |  |     \\  \\ /  /     |  |-------      |" << endl;
    cout << "|    |  |     |  |   |  |-----|  |   |  |----/  /    |  |---\\  \\        |  |            |  |-----|  |      \\  -  /      |  |-------      |" << endl;
    cout << "|    --------/  /    |  |-----|  |   |  |----\\  \\    |  |    \\  \\       -------------   |  |-----|  |       \\   /       -------------    |" << endl;
    cout << "|    ----------      |  |     |  |   |  |     \\  \\   |  |     \\  \\       ------------   |  |     |  |        \\-/         ------------    |" << endl;
    cout << "==========================================================================================================================================" << endl;
}

// Main menu display and controller
void mainMenu() {
    int option;
    do {
        system("cls");
        mainTitle();
        cout << endl;
        cout << "                                                        MAIN MENU" << endl;
        cout << "                                                            1 - Start game" << endl;
        cout << "                                                            2 - Exit game" << endl;
        cout << "                                                        Choose an option: ";
        cin >> option;
    } while (option < 1 || option > 2);

    cout << endl;
    switch (option) {
        case 1:
            cout << "                                                        Starting game..." << endl;
            gameLoop();
            break;
        case 2:
            cout << "                                                        Bye bye..." << endl;
            cout << " " << endl;
            system("pause");
            break;
    }
}

// Main game loop
void gameLoop() {
    system("cls");
    mainTitle();
    Map map(MAP_HEIGHT, MAP_WIDTH);
    map.displayMap();
}