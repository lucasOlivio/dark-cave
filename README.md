# Dark Cave

Welcome to Dark Cave, a simple C++ command-line game where you play as a player represented by the character 'P' and must find the treasure 'T' on an 8x8 map while avoiding enemies 'E'. The hidden part of the map is represented by the character 'X'.

## Build Instructions

### Required Tools

To build the game, you will need the following tools installed on your system:

- Windows 10 or later
- CMake version 3.22.1 or later
- Make version 4.3 or later

### Building the Game

To build the game, follow these steps:

1. Clone the repository to your local machine.
2. Navigate to the root directory of the repository.
3. Run the build command:

    ```shell
    build.bat
    ```

4. The built executable file will be located in the "build/Debug" directory. You can run the game by executing this file in the terminal:

    ```bash
    cd Debug
    DarkCave.exe
    ```

That's it! You should now be able to build and run the Dark Cave game on your system.

## How to Play

1. To start the game, compile and run the DarkCave file.
2. You will be placed in the botton center of the map. The treasure will be randomly placed on the map.
3. Use the numbers to move around the map and try to find the treasure.
4. Be careful, if you encounter an enemy, you will die and the game will be over.
5. If you find the treasure, you win the game!

## Development

This game was developed in C++ and utilizes basic control flow and logic. The game logic is stored in the main.cpp file, which contains the main game loop. The positions of the treasure and enemies are randomly generated in the beginning of the game using a two-dimensional array.

## Screenshots

![DarkCave](https://github.com/lucasOlivio/dark-cave/blob/main/images/darkcave.png)

### Project structure

The project must follow this basic structure:

``` sh
DarkCave/
│
├── build/                 # Build files
│
├── include/               # Public header files
│
├── src/                   # Source files
│
└── README.md              # Project README
│
└── CMakeLists.txt         # Project CMake
│
└── main.cpp               # Main code
```
