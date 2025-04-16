/**
 * @file movingtile.cpp
 * @brief Implementation of the MovingTile class.
 */
#include "movingtile.h"
#include <iostream>
#include <iomanip>


void MovingTile::setMoved (bool moved) {
    wasMoved = moved;
}

bool MovingTile::wasRecentlyMoved() const {
    return wasMoved;
}

void MovingTile::drawConsole() const {
    std::ostringstream out;

    if (isEmpty()) {
        out << "     ";
    } else if (wasMoved) {
        out << "[*" << std::setw(1) << number << "]";
    } else if (active) {
        out << ">" << std::setw(2) << number << "<";
    } else {
        out << " " << std::setw(2) << number << " ";
    }

    std::cout << "|" << std::setw(5) << std::left << out.str();
}
