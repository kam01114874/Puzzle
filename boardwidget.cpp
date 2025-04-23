#include "boardwidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget(parent)
{}

void BoardWidget::setBoard(const Board *b)
{
    board = b;
    update();
}

void BoardWidget::paintEvent(QPaintEvent *)
{
    qDebug() << "paintEvent called";

    if (!board) return;

    qDebug() << "board exists";

    QPainter painter(this);
    qDebug() << "created painter";
    painter.setRenderHint(QPainter::Antialiasing);

    const int size = board->getSize();
    const auto& tiles = board->getTiles();

    qDebug() << "got board size and tiles";
    //Calculate width and height of single tile.
    int tileW = width() / size;

    qDebug() << "calculacted width";
    int tileH = height() / size;

    qDebug() << "calculated size";
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            auto tile = tiles[r][c];
            //Creates rectangle at location [r][c] with calculated width and height.
            QRect rect(c * tileW, r * tileH, tileW, tileH);

            //Use light gray on empty tiles and white for the rest of the tiles.
            if (tile->isEmpty()) {
                painter.setBrush(Qt::lightGray);
            } else {
                painter.setBrush(Qt::white);
            }

            //Sets black border and draws rectangle of the tile.
            painter.setPen(Qt::black);
            painter.drawRect(rect);

            //If it is not an empty field, draw a number inside it.
            if (!tile->isEmpty()) {
                painter.drawText(rect, Qt::AlignCenter, QString::number(tile->getNumber()));
            }
        }
    }
}
