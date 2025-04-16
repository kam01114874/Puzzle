/**
 * @file tile.cpp
 * @brief Implementation of the Tile class.
 *
 * Contains definitions of member functions of the abstract Tile class.
 */

#include "tile.h"


Tile::Tile(int num, bool empty) : number(num), isEmptyTile(empty) {}

int Tile::getNumber() const {
    return number;
}

bool Tile::isEmpty() const {
    return isEmptyTile;
}
