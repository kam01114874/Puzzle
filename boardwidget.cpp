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
    const int tileSize = boardSize / size;

    //Adds spacing between tiles.
    const int spacing = 2;

    //Make sure to draw in the middle
    const int offsetX = (width() - boardSize) / 2;
    const int offsetY = (height() - boardSize) / 2;

    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            const auto& tile = tiles[r][c];

            //Tile size and position
            QRect padded(
                offsetX + c * tileSize + spacing / 2,
                offsetY + r * tileSize + spacing / 2,
                tileSize - spacing,
                tileSize - spacing
                );

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
    if (!game || !gameStarted) return;

    const int size = board->getSize();
    const int boardSize = std::min(width(), height());
    const int tileSize = boardSize / size;

    const int offsetX = (width() - boardSize) / 2;
    const int offsetY = (height() - boardSize) / 2;

    //Mouse click relative to center of the board
    int x = event->position().x() - offsetX;
    int y = event->position().y() - offsetY;

    if (x < 0 || y < 0 || x >= boardSize || y >= boardSize) return;

    //Mose press position
    int col = x / tileSize;
    int row = y / tileSize;

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
