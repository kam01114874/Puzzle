/**
 * @file board.cpp
 * @brief Implementation of the Board class.
 *
 * Contains definitions of member functions of the Board class.
 */
#include <iostream>
#include <iomanip>
#include "board.h"

/**
 * @brief Constructs a Board with given size.
 * @param n Size of the board.
 */
Board::Board(int n) : size(n) {
    tiles.resize(size);

    int number = 0;
    for (int r = 0; r < size; ++r) {
        tiles[r].reserve(size);
        for (int c = 0; c < size; ++c) {
            bool isEmpty = (number == 0);
            tiles[r].emplace_back(std::make_shared<Tile>(number++, isEmpty));
        }
    }
}

/**
 * @brief Gets two-dimensional container representing the tile grid.
 * @return Tile grid reference.
 */
std::vector<std::vector<std::shared_ptr<Tile>>>& Board::getTiles() {
    return tiles;
}

/**
 * @brief Gets size of created board.
 * @return Size of the board.
 */
int Board::getSize() {
    return size;
}

/**
 * @brief The method tries to move a tile adjacent to an empty field in the specified direction.
 * If the movement is possible, it swaps the empty tile and the selected neighbor.
 * If not, nothing happens, the method returns false.
 * @return True if the tiles were swapped, false otherwise.
 */
bool Board::move(Direction dir) {
    // Variables store the position of an empty tile on the n x n board (sentinel value)
    int emptyR = -1, emptyC = -1;

    // Find empty tile (value 0)
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            if (tiles[r][c]->isEmpty()) {
                emptyR = r;
                emptyC = c;
                break;
            }
        }
        // Check if empty file was found
        if (emptyR != -1) break;
    }

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
        // Swap a tile with an empty field
        std::swap(tiles[emptyR][emptyC], tiles[newR][newC]);
        return true;
    }

    // Movement impossible
    return false;
};

/**
 * @brief The method displays the state of the n x n board.
 * Prints the number of each tile (1..n*n-1), and 0 for an empty field.
 * Formats the layout into a grid (e.g. 4×4 puzzle).
 */
void Board::draw() const {
    const int fieldWidth = 4;

    // Horizontal line (e.g. "+----+----+")
    auto printHorizontalLine = [&]() {
        for (int i = 0; i < size; ++i) {
            std::cout << "+";
            std::cout << std::string(fieldWidth, '-');
        }
        std::cout << "+\n";
    };

    // Main board
    for (int r = 0; r < size; ++r) {
        // Line above row
        printHorizontalLine();

        for (int c = 0; c < size; ++c) {
            int num = tiles[r][c]->getNumber();
            std::cout << "|";
            std::cout << std::setw(fieldWidth) << num;
        }
        std::cout << "|\n";
    }
    // Last line
    printHorizontalLine();
    std::cout << std::endl;
}

/**
 * @brief The method is responsible for checking if all tiles are in the correct order, i.e.: 0, 1, 2, 3, ..., n*n-1
 * 0 means an empty field, which should be at the first position
 * @return True if the tiles are in correct order, false otherwise.
 */
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




