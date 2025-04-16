/**
 * @file game.h
 * @brief Declaration of the Game class, responsible for managing game state and board shuffling.
 */
#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "ShuffleAlgorithm.h"

/**
 * @class Game
 * @brief Manages the core game logic.
 *
 * Holds an instance of the board, handles board initialization, shuffling,
 * and exposes interface for accessing the current board state.
 *
 * @note The board is not shuffled automatically on creation – call reset() explicitly.
 */
class Game {
private:
    Board board;

    /**
    * @brief Number of tile moves from beginning to the end of the game.
    * This value is updated after every player move.
    */
    int moveCount;

    /**
    * @brief Creates copy of the board right after shuffling.
    * Needed for reset() method.
    */
    Board startState;
public:
    /**
    * @brief Constructs a new Game with a board of given size and tile type.
    * @param size Board size (e.g. 3 = 3x3).
    * @param type Tile type to initialize the board with.
    */
    Game(int size, TileType type);

    /**
    * @brief Starts a new game by shuffling the board and resetting the move counter.
    *
    * The shuffle is done via ShuffleAlgorithm using legal tile moves.
    * Stores the initial shuffled state to enable future resets.
    */
    void start();

    /**
    * @brief Resets the game to the state right after the most recent shuffle.
    *
    * Restores the board to its stored shuffled state and resets the move counter.
    */
    void reset();

    /**
     * @brief Checks whether game is won.
     * @return True if the tiles are in correct order, otherwise false.
     */
    bool isWon();

    /**
     * @brief Returns the current move count.
     * @return Integer number of moves made since game start.
     */
    int getMoveCount() const;

    /**
    * @brief Increments the move counter after a successful move.
    */
    void incrementMoveCount();

    /**
    * @brief Attempts to move a tile in the given direction and updates move counter.
    *
    * Calls Board::move to perform the move. If successful, increments the move counter.
    * @param dir Direction in which to move the tile.
    * @return True if the tile was moved successfully.
    */
    bool move(Direction dir);

    /**
     * @brief Returns a reference to the board (read-only).
     * @return Const reference to the board.
     */
    const Board& getBoard() const;

    /**
     * @brief Returns a reference to the board (modifiable).
     * @return Reference to the board.
     */
    Board& getBoard();
};

#endif // GAME_H
