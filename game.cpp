/**
 * @file game.cpp
 * @brief Implementation of the Game class.
 *
 * Contains definitions of member functions of the Game class.
 */

#include "game.h"

Game::Game(int size, TileType type)
    : board(size, type)
    , startState(size, type)
{}

void Game::start()
{
    moveCount = 0;
    auto &tiles = board.getTiles();
    ShuffleAlgorithm<std::shared_ptr<Tile>> shuffler;
    shuffler.shuffle(tiles, board.getSize() * 10, board.getEmptyR(), board.getEmptyC());
    board.updateActiveTiles();
    // Save current shuffled board to enable reset later
    startState = board;
}

void Game::reset()
{
    board = startState;
    board.updateActiveTiles();
    moveCount = 0;
}

bool Game::isWon()
{
    return board.isSolved();
}

int Game::getMoveCount() const
{
    return moveCount;
}

void Game::incrementMoveCount()
{
    ++moveCount;
}

bool Game::move(Direction dir)
{
    bool moved = board.move(dir);
    if (moved) {
        incrementMoveCount();
    }
    return moved;
}

const Board &Game::getBoard() const
{
    return board;
}

Board &Game::getBoard()
{
    return board;
}
