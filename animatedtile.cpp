/**
 * @file animatedtile.cpp
 * @brief Implementation of the AnimatedTile class.
 */
#include "animatedtile.h"
#include <iomanip>
#include <iostream>

void AnimatedTile::setActive(bool isActive)
{
    active = isActive;
}

bool AnimatedTile::isActive() const
{
    return active;
}

void AnimatedTile::drawConsole() const
{
    std::ostringstream out;

    if (isEmpty()) {
        out << "     ";
    } else if (active) {
        out << ">" << std::setw(2) << number << "<";
    } else {
        out << " " << std::setw(2) << number << " ";
    }

    std::cout << "|" << std::setw(5) << std::left << out.str();
}
