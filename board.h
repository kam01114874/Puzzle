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
 * @brief Represents a 2D board of movable tiles in a puzzle game.
 *
 * Stores a 2D grid of tiles and provides methods for interaction:
 * - Moving tiles
 * - Checking win condition
 * - Displaying the board
 * - Accessing internal tile grid
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
     * @brief Returns a reference to the 2D tile grid.
     * @warning Allows modification of internal tile structure.
     * @return Reference to vector of vector of shared_ptr<Tile>.
     */
    std::vector<std::vector<std::shared_ptr<Tile>>>& getTiles();

    /**
     * @brief Gets size of created board.
     * @return Size of the board.
     */
    int getSize();

    /**
     * @brief Attempts to move a tile in the given direction into the empty space.
     * @param dir Direction in which to attempt the move.
     * @return True if move was successful, false otherwise.
     */
    bool move(Direction dir);

    /**
     * @brief Displays the current board state.
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
