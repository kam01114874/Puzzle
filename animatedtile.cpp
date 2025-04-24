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

void AnimatedTile::drawGraphics(QPainter *painter, const QRect &rect, const QPixmap &tileImage) const
{
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
        QPen pen(QColor("#0059b3"));
        pen.setWidth(4);
        painter->setPen(pen);
        painter->drawRect(rect);
    }

    //Number in the middle.
    if (!isEmpty()) {
        painter->setPen(QColor(50, 50, 50));
        painter->setFont(QFont("Arial", 12, QFont::Bold));
        painter->drawText(rect, Qt::AlignCenter, QString::number(getNumber()));
    }

    painter->restore();
}
