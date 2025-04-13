#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>
#include "tile.h"

/**
 * @class Direction
 * @brief Class representing four directions.
 *
 * This class represents the direction in which the tile can be moved.
 */
enum class Direction {
    Up,
    Down,
    Left,
    Right
};

/**
 * @class Board
 * @brief Class representing board of tiles.
 *
 * This class represents board in a tile-based game.
 * It stores size of two-dimensional board and tile grid.
 * Provides methods for moving tiles, drawing the board, checking the game state and updating possible moves.
 */
class Board
{
private:
    /**
     * @brief Represents size of the board.
     */
    int size;
    /**
     * @brief Two-dimensional container representing the tile grid using the coordinates [row][column].
     */
    std::vector<std::vector<std::shared_ptr<Tile>>> tiles;
public:
    /**
     * @brief Constructor initializing board with a number.
     * @param n Size of the board.
     */
    Board(int n);

    /**
     * @brief Moves the tiles.
     */
    bool move(Direction dir);

    /**
     * @brief Draws the board.
     */
    void draw() const;

    /**
     * @brief Updates possible moves.
     */
    void updateActiveTiles();

    /**
     * @brief Checks whether puzzle is solved.
     * @return True if the tiles are in correct order, otherwise false.
     */
    bool isSolved();
};

#endif // BOARD_H
