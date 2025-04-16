/**
 * @file board.cpp
 * @brief Implementation of the Board class.
 *
 * Contains definitions of member functions of the Board class.
 */
#include <iostream>
#include "board.h"
#include "animatedtile.h"
#include "movingtile.h"
#include "selectabletile.h"


Board::Board(int n, TileType type) : size(n), emptyR(0), emptyC(0) {
    tiles.resize(size);
    int number = 0;

    for (int r = 0; r < size; ++r) {
        tiles[r].reserve(size);
        for (int c = 0; c < size; ++c) {
            bool isEmpty = (number == 0);
            std::shared_ptr<Tile> tile;

            switch (type) {
            case TileType::Moving:
                tile = std::make_shared<MovingTile>(number, isEmpty);
                break;
            case TileType::Selectable:
                tile = std::make_shared<SelectableTile>(number, isEmpty);
                break;
            case TileType::Animated:
            default:
                tile = std::make_shared<AnimatedTile>(number, isEmpty);
                break;
            }

            if (isEmpty) {
                emptyR = r;
                emptyC = c;
            }

            tiles[r].emplace_back(tile);
            ++number;
        }
    }
    updateActiveTiles();
}

int Board::getSize() const{
    return size;
}

int Board::getEmptyR() const { return emptyR; }
int Board::getEmptyC() const { return emptyC; }
int& Board::getEmptyR() { return emptyR; }
int& Board::getEmptyC() { return emptyC; }

void Board::setEmptyPosition(int r, int c) {
    emptyR = r;
    emptyC = c;
}

bool Board::move(Direction dir) {
    // Specify the direction of the offset relative to the empty field
    int dr = 0, dc = 0;
    switch (dir) {
    case Direction::Up:    dr = -1; break;
    case Direction::Down:  dr = 1; break;
    case Direction::Left:  dc = -1; break;
    case Direction::Right: dc = 1; break;
    }

    int newR = emptyR + dr;
    int newC = emptyC + dc;

    // Check if neighbor tile exists (move within board boundaries)
    if (newR >= 0 && newR < size && newC >= 0 && newC < size) {
        auto movedTile = tiles[newR][newC];
        // Swap a tile with an empty field
        std::swap(tiles[emptyR][emptyC], tiles[newR][newC]);
        emptyR = newR;
        emptyC = newC;

        updateActiveTiles();

        // Mark tile thats going to replace empty tile as just moved.
        if (auto moving = std::dynamic_pointer_cast<MovingTile>(movedTile)) {
            moving->setMoved(true);
        }
        return true;
    }

    // Movement impossible
    return false;
};

void Board::draw() const {
    const int fieldWidth = 5;

    auto printHorizontalLine = [&]() {
        for (int i = 0; i < size; ++i) {
            std::cout << "+" << std::string(fieldWidth, '-');
        }
        std::cout << "+\n";
    };

    for (int r = 0; r < size; ++r) {
        printHorizontalLine();
        for (int c = 0; c < size; ++c) {
            tiles[r][c]->drawConsole();
        }
        std::cout << "|\n";
    }

    printHorizontalLine();
    std::cout << std::endl;
}

bool Board::isSolved() {
    // The empty file should be in the first position
    int expected = 0;

    // Check if the tile number is expected row by row, column by column, expected increases by 1
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            if (tiles[r][c]->getNumber() != expected++)
                return false;
        }
    }
    return true;
}

void Board::updateActiveTiles() {
    // Set all tiles as inactive.
    for (auto& row : tiles) {
        for (auto& tile : row) {
            if (auto animated = std::dynamic_pointer_cast<AnimatedTile>(tile)) {
                animated->setActive(false);
            }
            if (auto moving = std::dynamic_pointer_cast<MovingTile>(tile)) {
                moving->setMoved(false);
            }
        }
    }

    // Check adjacent tiles.
    std::vector<std::pair<int, int>> directions = {
        { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
    };

    for (const auto& [dr, dc] : directions) {
        int nr = emptyR + dr;
        int nc = emptyC + dc;

        if (nr >= 0 && nr < size && nc >= 0 && nc < size) {
            if (auto animated = std::dynamic_pointer_cast<AnimatedTile>(tiles[nr][nc])) {
                animated->setActive(true);
            }
        }
    }
}




