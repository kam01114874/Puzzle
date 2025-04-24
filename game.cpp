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

void Game::setImage(const QPixmap& img) {
    fullImage = img;
    imageMode = !img.isNull();
}

QPixmap Game::getTileImageByNumber(int number) const {
    if (fullImage.isNull()) return QPixmap();

    int size = board.getSize();
    int row = number / size;
    int col = number % size;

    int w = fullImage.width() / size;
    int h = fullImage.height() / size;

    return fullImage.copy(col * w, row * h, w, h);
}
