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
    * @brief Current row and column coordinates of the empty tile.
    * These values are updated during shuffling.
    */
    int emptyR, emptyC;

public:
    /**
     * @brief Constructor initializing game with a board of set size.
     * @param size Size of the board.
     */
    Game(int size);

    /**
    * @brief Resets game by shuffling the board.
    * @details Uses the ShuffleAlgorithm template to perform a sequence of legal random moves.
    * The number of moves equals 5 * board size. The empty tile's position is updated accordingly.
    */
    void reset();

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
