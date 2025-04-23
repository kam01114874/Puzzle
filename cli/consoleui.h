#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "game.h"
#include <iostream>
#include <memory>

/**
* @class ConsoleUI
* @brief A text-based user interface for playing the puzzle in console mode.
*
* The class allows you to play the game in a terminal.
*/
class ConsoleUI {
public:
    ConsoleUI();
    /**
    * @brief Starts the main loop of the text interface.
    */
    void run();

private:
    TileType tileType;
    int size;
    std::unique_ptr<Game> game;

    /**
    * @brief Configures the tile type and board size before starting the game.
    */
    void configureGame();

    /**
    * @brief Draws the current state of the board in the terminal.
    */
    void drawBoard() const;

    /**
    * @brief Handles user input: moves, reset, end game.
    */
    void handleInput();

    /**
    * @brief Clears the terminal screen (system compatible).
    */
    void clearScreen() const;
};

#endif // CONSOLEUI_H
