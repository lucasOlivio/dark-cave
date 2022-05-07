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

// Clear the console and draws again the map
void redraw(Map* map) {
    system("cls");
    mainTitle();
    map->displayMap();
}

// Main game menu
int mainGameMenu() {
    cout << endl;
    cout << CENTER_TEXT << "1 - Move up" << endl;
    cout << CENTER_TEXT << "2 - Move right" << endl;
    cout << CENTER_TEXT << "3 - Move down" << endl;
    cout << CENTER_TEXT << "4 - Move left" << endl;
    cout << CENTER_TEXT << "5 - Exit game" << endl;
    cout << endl;
}

// Get player input
void getPlayerInput(int* option) {
    do {
        cout << CENTER_TEXT << "Choose an action: ";
        cin >> *option;
        cout << endl;
    } while (*option < 1 || *option > 5);
}

// Check if game should continue
bool checkGameState(Map* map) {
    switch(map->getState()) {
        case WON: case LOST: case QUIT: return false;
        default: return true;
    }
}

// Execute the action chosen by the user
void executeAction(int option, Player* player, Map* map, bool* moved) {

    switch (option) {
        case 1:
            *moved = map->movePlayer("up", player);
            break;
        case 2:
            *moved = map->movePlayer("right", player);
            break;
        case 3:
            *moved = map->movePlayer("down", player);
            break;
        case 4:
            *moved = map->movePlayer("left", player);
            break;
        case 5:
            char exit;
            cout << CENTER_TEXT << "Are you sure you want to exit? <y/n>: ";
            cin >> exit;
            if(exit == 'y') {
                map->setState(QUIT);
                return;
            }
            option = 0;
            break;
    }
    if (!*moved && checkGameState(map)) {
        cout << CENTER_TEXT << "You can't move there!" << endl;
        cout << endl;
    }
}

// Finishe the game and display the result
void finishGame(Map* map) {
    redraw(map);

    cout << endl;
    switch(map->getState()) {
        case WON:
            cout << CENTER_TEXT << "Congratulations you found the treasure!" << endl;
            break;
        case LOST:
            cout << CENTER_TEXT << "You died! Try again next time!" << endl;
            break;
        case QUIT:
            cout << CENTER_TEXT << "Bye bye..." << endl;
            break;
    }
    cout << endl;
    system("pause");
}

// Main game loop
void gameLoop() {
    system("cls");
    Player player;
    Map map(&player);
    int option;
    bool moved = true;

    do {
        redraw(&map);
        mainGameMenu();
        do {
            getPlayerInput(&option);
            executeAction(option, &player, &map, &moved);
        } while (!moved && checkGameState(&map));
    } while (checkGameState(&map));

    finishGame(&map);
}