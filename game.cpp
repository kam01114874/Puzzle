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
Game::Game(int size) : board(size), emptyR(0), emptyC(0) {}

/**
 * @brief The method shuffles n x n board.
 */
void Game::reset() {
    auto& tiles = board.getTiles();
    ShuffleAlgorithm<std::shared_ptr<Tile>> shuffler;
    shuffler.shuffle(tiles, board.getSize() * 5, emptyR, emptyC);
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
