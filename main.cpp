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
#include <windows.h>
#include "map/map.hpp"
#include "player/player.hpp"
#include "common.hpp"

using namespace std;

// Title screen display
void mainTitle();

// Main menu display and controller
void mainMenu();

// Main game loop
void gameLoop();

// Main controller of the program
int main() {
    SetConsoleOutputCP(437);
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
    Player player;
    Map map(&player);
    int option;
    bool moved = true;

    do {
        system("cls");
        mainTitle();
        map.displayMap();
        cout << endl;
        cout << CENTER_TEXT << "8 - Move up" << endl;
        cout << CENTER_TEXT << "6 - Move right" << endl;
        cout << CENTER_TEXT << "2 - Move down" << endl;
        cout << CENTER_TEXT << "4 - Move left" << endl;
        cout << CENTER_TEXT << "5 - Exit game" << endl;
        if (!moved) {
            cout << endl;
            cout << CENTER_TEXT << "You can't move there!" << endl;
            cout << endl;
        }
        cout << CENTER_TEXT << "Choose an action: ";
        cin >> option;

        cout << endl;
        switch (option) {
            case 8:
                cout << CENTER_TEXT << "Move up" << endl;
                moved = map.movePlayer("up", &player);
                break;
            case 6:
                cout << CENTER_TEXT << "Move right" << endl;
                moved = map.movePlayer("right", &player);
                break;
            case 2:
                cout << CENTER_TEXT << "Move down" << endl;
                moved = map.movePlayer("down", &player);
                break;
            case 4:
                cout << CENTER_TEXT << "Move left" << endl;
                moved = map.movePlayer("left", &player);
                break;
            case 5:
                char exit;
                cout << CENTER_TEXT << "Are you sure you want to exit? <y/n>: ";
                cin >> exit;
                if (exit == 'n') {
                    option = 0;
                } else if(exit == 'y') {
                    cout << CENTER_TEXT << "Bye bye..." << endl;
                    cout << " " << endl;
                    system("pause");
                    system("exit");
                }
                break;
        }
    } while (option != 5);
}