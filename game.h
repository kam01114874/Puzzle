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
     * @brief Constructor initializing game with a board of set size.
     * @param size Size of the board.
     */
    Game(int size);

    /**
    * @brief Starts the game by shuffling the board and resetting the move counter.
    * @details Uses the ShuffleAlgorithm template to perform a sequence of legal random moves.
    * The number of moves equals 6 * board size. The empty tile's position is updated accordingly.
    * The initial shuffled board state is saved to allow game reset.
    */
    void start();

    /**
    * @brief Resets game by returning board state to right after shuffling and reseting moveCount.
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
     * @brief Counts moves made by player.
     * @return Previous moveCount increased by 1.
     */
    void incrementMoveCount();

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
