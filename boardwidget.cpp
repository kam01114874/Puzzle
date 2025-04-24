/**
 * @file boardwidget.cpp
 * @brief Implementation of the BoardWidget class.
 */

#include "boardwidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <cmath>

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget(parent)
{}

void BoardWidget::setGame(Game* g) {
    game = g;
    board = &(g->getBoard());
    gameStarted = false;
    update();
}

void BoardWidget::setGameStarted(bool started) {
    gameStarted = started;
    update();
}

void BoardWidget::paintEvent(QPaintEvent *)
{
    if (!board || !game) return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const int size = board->getSize();
    const auto& tiles = board->getTiles();

    int boardSize = std::min(width(), height());
    int tileW = boardSize / size;
    int tileH = boardSize / size;

    //Adds spacing between tiles.
    const int spacing = 2;

    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            const auto& tile = tiles[r][c];
            //Basic tile rectangle.
            QRect rect(c * tileW, r * tileH, tileW, tileH);
            //Make sure to draw in the middle
            int offsetX = (width() - boardSize) / 2;
            int offsetY = (height() - boardSize) / 2;
            //Reduce rect by spacing for a gap
            QRect padded(offsetX + c * tileW, offsetY + r * tileH, tileW, tileH);

            //Get fragment for tile
            QPixmap fragment;
            if (game && !tile->isEmpty()) {
                fragment = game->getTileImageByNumber(tile->getNumber());
            }

            tile->drawGraphics(&painter, padded, fragment);
        }
    }
}

void BoardWidget::mousePressEvent(QMouseEvent* event) {
    if (!game) return;
    if (!gameStarted) return;

    const int size = board->getSize();
    int tileW = width() / size;
    int tileH = height() / size;

    //Mose press position
    int col = event->position().x() / tileW;
    int row = event->position().y() / tileH;

    int emptyR = board->getEmptyR();
    int emptyC = board->getEmptyC();

    //Position difference
    int dr = row - emptyR;
    int dc = col - emptyC;

    //Check if clicked tile is next to emty tile
    if (std::abs(dr) + std::abs(dc) != 1)
        return;

    Direction dir;

    //Determine movement direction (clicked tile -> empty tile)
    if (dr == 1 && dc == 0) dir = Direction::Down;       //clicked over empty tile
    else if (dr == -1 && dc == 0) dir = Direction::Up;   //clicked under empty tile
    else if (dr == 0 && dc == 1) dir = Direction::Right; //clicked on the left
    else if (dr == 0 && dc == -1) dir = Direction::Left; //clicked on the right
    else return;

    if (game->move(dir)) {
        //Notify MainWindow to update move count
        emit tileMoved();
        update();

        //Check win condition
        if (game->isWon()) {
            //Notify MainWindow to pop up window
            emit puzzleSolved();
            //Lock board
            setEnabled(false);
        }
    }
}

void BoardWidget::resizeEvent(QResizeEvent* event){
    update();
    QWidget::resizeEvent(event);
}
