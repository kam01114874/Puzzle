/**
 * @file tile.cpp
 * @brief Implementation of the Tile class.
 *
 * Contains definitions of member functions of the abstract Tile class.
 */

#include "tile.h"

/**
 * @brief Constructs a Tile with given number and empty flag.
 * @param num Numeric value of the tile.
 * @param empty Boolean indicating whether the tile is empty.
 */
Tile::Tile(int num, bool empty) : number(num), isEmptyTile(empty) {}

/**
 * @brief Retrieves the numeric value of the tile.
 * @return Integer number assigned to the tile.
 */
int Tile::getNumber() const {
    return number;
}

/**
 * @brief Checks if the tile is marked as empty.
 * @return True if the tile is empty, false otherwise.
 */
bool Tile::isEmpty() const {
    return isEmptyTile;
}
