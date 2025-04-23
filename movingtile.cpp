/**
 * @file movingtile.cpp
 * @brief Implementation of the MovingTile class.
 */
#include "movingtile.h"
#include <iomanip>
#include <iostream>

void MovingTile::setMoved(bool moved)
{
    wasMoved = moved;
}

bool MovingTile::wasRecentlyMoved() const
{
    return wasMoved;
}

void MovingTile::drawConsole() const
{
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

void MovingTile::drawGraphics(QPainter* painter, const QRect& rect) const {
    //Save current painting style.
    painter->save();

    painter->fillRect(rect, Qt::white);
    painter->setBrush(Qt::NoBrush);

    //Blue frame - tile next to empty tile.
    if (active) {
        QPen bluePen(QColor("#007FFF"));
        bluePen.setWidth(4);
        painter->setPen(bluePen);
        painter->drawRect(rect);
    }

    //Green frame - last moved tile.
    if (wasMoved) {
        QPen greenPen(QColor("#32CD32"));
        greenPen.setWidth(2);
        painter->setPen(greenPen);
        QRect inner = rect.adjusted(3, 3, -3, -3); // Nachodząca
        painter->drawRect(inner);
    }

    //Number in the middle.
    if (!isEmpty()) {
        painter->setPen(Qt::darkGray);
        painter->setFont(QFont("Arial", 16, QFont::Bold));
        painter->drawText(rect, Qt::AlignCenter, QString::number(getNumber()));
    }

    //Restore saved style.
    painter->restore();
}
