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

void MovingTile::drawGraphics(QPainter *painter, const QRect &rect, const QPixmap &tileImage) const
{
    //Save current painting style.
    painter->save();

    //Light gray color for empty tile, white for the rest
    QColor background = isEmpty() ? QColor(240, 240, 240) : Qt::white;
    painter->fillRect(rect, background);

    //Draw image
    if (!isEmpty() && !tileImage.isNull()) {
        painter->drawPixmap(rect, tileImage.scaled(rect.size(), Qt::KeepAspectRatioByExpanding));
    }

    //Blue frame - tile next to empty tile.
    if (active) {
        QPen bluePen(QColor("#0059b3"));
        bluePen.setWidth(4);
        painter->setPen(bluePen);
        painter->drawRect(rect);
    }

    //Yellow(ish) frame - last moved tile.
    if (wasMoved) {
        QPen greenPen(QColor("#FFD580"));
        greenPen.setWidth(2);
        painter->setPen(greenPen);
        //Don't replace all of blue frame
        QRect inner = rect.adjusted(3, 3, -3, -3);
        painter->drawRect(inner);
    }

    //Number in the middle.
    if (!isEmpty()) {
        painter->setPen(QColor(50, 50, 50));
        painter->setFont(QFont("Arial", 12, QFont::Bold));
        painter->drawText(rect, Qt::AlignCenter, QString::number(getNumber()));
    }

    //Restore saved style.
    painter->restore();
}
