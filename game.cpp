/**
 * @file game.cpp
 * @brief Implementation of the Game class.
 *
 * Contains definitions of member functions of the Game class.
 */

#include "game.h"

/**
 * @brief Constructor initializing game with a board of set size and empty file set to [0][0] coordinates.
 *
 * @param size Size of the board.
 */
Game::Game(int size) : board(size), startState(size), emptyR(0), emptyC(0) {}

/**
 * @brief The method shuffles n x n board.
 */
void Game::start() {
    moveCount = 0;
    auto& tiles = board.getTiles();
    ShuffleAlgorithm<std::shared_ptr<Tile>> shuffler;
    shuffler.shuffle(tiles, board.getSize() * 6, emptyR, emptyC);
    // Save current shuffled board to enable reset later
    startState = board;
}

/**
 * @brief The method resets game by returning board state created in start() method.
 */
void Game::reset() {
    board = startState;
}

/**
 * @brief Checks whether the current game state is a winning state.
 * @return True if the board is correctly solved.
 */
bool Game::isWon() {
    return board.isSolved();
}

/**
 * @brief Gets number of tiles moved in a single game.
 * @return number of moves made by user.
 */
int Game::getMoveCount() const {
    return moveCount;
}

/**
 * @brief Counts moves made by player.
 * @return Previous moveCount increased by 1.
 */
void Game::incrementMoveCount() {
    ++moveCount;
}

/**
 * @brief Returns a reference to the board (read-only).
 * @return Const reference to the board.
 */
const Board& Game::getBoard() const {
    return board;
}

/**
 * @brief Returns a reference to the board (modifiable).
 * @return Reference to the board.
 */
Board& Game::getBoard() {
    return board;
}
