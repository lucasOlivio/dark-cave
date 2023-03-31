# Dark Cave

Welcome to Dark Cave, a simple C++ command-line game where you play as a player represented by the character 'P' and must find the treasure 'T' on an 8x8 map while avoiding enemies 'E'. The hidden part of the map is represented by the character 'X'.

## Build Instructions

### Required Tools

To build the game, you will need the following tools installed on your system:

- CMake version 3.22.1 or later
- Make version 4.3 or later

### Building the Game

To build the game, follow these steps:

1. Clone the repository to your local machine.
2. Navigate to the root directory of the repository.
3. Create a new directory called "build" in the root directory.
4. Navigate to the "build" directory.
5. Run the following command to generate the Makefile using CMake:

    ```shell
    cmake ..
    ```

6. Run the following command to build the game using Make:

    ```shell
    make
    ```

    The built executable file will be located in the "build" directory. You can run the game by executing this file in the terminal:

    ```bash
    .\DarkCave
    ```

That's it! You should now be able to build and run the Dark Cave game on your system.

## How to Play

1. To start the game, compile and run the DarkCave file.
2. You will be placed in the botton center of the map. The treasure will be randomly placed on the map.
3. Use the arrow keys to move around the map and try to find the treasure.
4. Be careful, if you encounter an enemy, you will die and the game will be over.
5. If you find the treasure, you win the game!

### Controls

- Use the up arrow key to move up
- Use the down arrow key to move down
- Use the left arrow key to move left
- Use the right arrow key to move right

## Development

This game was developed in C++ and utilizes basic control flow and logic. The game logic is stored in the main.cpp file, which contains the main game loop. The positions of the treasure and enemies are randomly generated in the beginning of the game using a two-dimensional array.

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
