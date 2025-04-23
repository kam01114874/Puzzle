/**
 * @file selectabletile.cpp
 * @brief Implementation of the SelectableTile class.
 */
#include "selectabletile.h"
#include <iomanip>
#include <iostream>

void SelectableTile::setSelected(bool select)
{
    selected = select;
}

bool SelectableTile::isSelected() const
{
    return selected;
}

void SelectableTile::toggleSelected()
{
    selected = !selected;
}

void SelectableTile::drawConsole() const
{
    std::ostringstream out;

    if (isEmpty()) {
        out << "     ";
    } else if (selected) {
        out << "[#" << std::setw(1) << number << "]";
    } else if (active) {
        out << ">" << std::setw(2) << number << "<";
    } else {
        out << " " << std::setw(2) << number << " ";
    }

    std::cout << "|" << std::setw(5) << std::left << out.str();
}
