/**
 * @file boardwidget.h
 * @brief Contains the BoardWidget class responsible for generating and displaying the game board.
 */

#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include "game.h"

/**
 * @class BoardWidget
 * @brief Widget responsible for displaying the puzzle board and mouse pressing events.
 */
class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Constructor.
     * @param parent The parent QWidget.
     */
    explicit BoardWidget(QWidget *parent = nullptr);

    /**
     * @brief Sets the current Game object.
     * @param g Pointer to the game object.
     */
    void setGame(Game* g);

    /**
     * @brief Enables or disables user interaction depending on game state.
     * @param started true if the game has started, false otherwise.
     */
    void setGameStarted(bool started);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    Game* game = nullptr;
    Board* board = nullptr;
    bool gameStarted = false;

signals:
    /**
     * @brief Emitted when a tile has been moved successfully.
     */
    void tileMoved();
    /**
     * @brief Emitted when the puzzle has been solved.
     */
    void puzzleSolved();
};

#endif // BOARDWIDGET_H
