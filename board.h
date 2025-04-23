#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include <memory>
#include <vector>

enum class TileType { Animated, Moving, Selectable };

/**
 * @class Direction
 * @brief Class representing four directions.
 *
 * This class represents the direction in which the tile can be moved.
 */
enum class Direction { Up, Down, Left, Right };

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
     * @brief Represents row coordinate of the empty tile.
     */
    int emptyR;

    /**
     * @brief Represents column coordinate of the empty tile.
     */
    int emptyC;

    /**
     * @brief Two-dimensional container representing the tile grid using the coordinates [row][column].
     */
    std::vector<std::vector<std::shared_ptr<Tile>>> tiles;

public:
    /**
     * @brief Constructs a square board with given tile type.
     * @param n Board size (n x n)
     * @param type Type of tile to populate the board with.
     */
    Board(int n, TileType type = TileType::Animated);

    /**
    * @brief Returns a reference to the tile grid.
    * @return Reference to a 2D vector of shared pointers to tiles.
    */
    std::vector<std::vector<std::shared_ptr<Tile>>> &getTiles() { return tiles; }

    /**
    * @brief Returns a const reference to the tile grid (read-only access).
    * @return Const reference to a 2D vector of shared pointers to tiles.
    */
    const std::vector<std::vector<std::shared_ptr<Tile>>> &getTiles() const { return tiles; }

    /**
     * @brief Gets size of created board.
     * @return Size of the board.
     */
    int getSize() const;

    /**
    * @brief Gets the row index of the empty tile.
    */
    int getEmptyR() const;
    /**
    * @brief Gets the column index of the empty tile.
    */
    int getEmptyC() const;
    /**
    * @brief Returns a reference to the empty tile's row index (modifiable).
    */
    int &getEmptyR();
    /**
    * @brief Returns a reference to the empty tile's column index (modifiable).
    */
    int &getEmptyC();

    /**
    * @brief Manually sets the empty tile coordinates.
    * @param r Row index of the empty tile.
    * @param c Column index of the empty tile.
    */
    void setEmptyPosition(int r, int c);

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
    * @brief Updates tile states based on proximity to the empty tile.
    *
    * Clears all 'active' and 'wasMoved' flags, then activates tiles adjacent
    * to the empty field using dynamic casting.
    */
    void updateActiveTiles();

    /**
    * @brief Checks whether the puzzle is in a solved state.
    *
    * The board is solved when all tiles are in ascending order and
    * the empty tile (0) is in the top-left corner.
    * @return True if puzzle is solved.
    */
    bool isSolved();
};

#endif // BOARD_H
