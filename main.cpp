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
#include "player/player.hpp"
#include "common.hpp"

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
    // Main menu loop, will only exit when the user chooses the right options
    do {
        system("cls");
        mainTitle();
        cout << endl;
        cout << CENTER_TEXT << "MAIN MENU" << endl;
        cout << CENTER_TEXT << "1 - Start game" << endl;
        cout << CENTER_TEXT << "2 - Exit game" << endl;
        cout << CENTER_TEXT << "Choose an option: ";
        cin >> option;
    } while (option < 1 || option > 2);

    cout << endl;
    switch (option) {
        case 1:
            cout << CENTER_TEXT << "Starting game..." << endl;
            gameLoop();
            break;
        case 2:
            cout << CENTER_TEXT << "Bye bye..." << endl;
            cout << " " << endl;
            system("pause");
            break;
    }
}

// Main game loop
void gameLoop() {
    system("cls");
    Map map(MAP_WIDTH, MAP_HEIGHT);
    Player player(MAP_WIDTH, MAP_HEIGHT);
    int option;

    do {
        system("cls");
        mainTitle();
        map.displayMap(player);
        cout << endl;
        cout << CENTER_TEXT << "1 - Move up" << endl;
        cout << CENTER_TEXT << "2 - Move right" << endl;
        cout << CENTER_TEXT << "3 - Move down" << endl;
        cout << CENTER_TEXT << "4 - Move left" << endl;
        cout << CENTER_TEXT << "5 - Exit game" << endl;
        cout << CENTER_TEXT << "Choose an action: ";
        cin >> option;

        cout << endl;
        switch (option) {
            case 1:
                cout << CENTER_TEXT << "Move up" << endl;
                player.move("up", map);
                break;
            case 2:
                cout << CENTER_TEXT << "Move right" << endl;
                player.move("right", map);
                break;
            case 3:
                cout << CENTER_TEXT << "Move down" << endl;
                player.move("down", map);
                break;
            case 4:
                cout << CENTER_TEXT << "Move left" << endl;
                player.move("left", map);
                break;
            case 5:
                char exit;
                cout << CENTER_TEXT << "Are you sure you want to exit? <y/n>: ";
                cin >> exit;
                if (exit == 'n') {
                    option = 0;
                } else {
                    cout << CENTER_TEXT << "Bye bye..." << endl;
                    cout << " " << endl;
                    system("pause");
                }
                break;
        }
    } while (option != 5);
}