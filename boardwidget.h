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
    void setGame(Game *g);

    /**
     * @brief Enables or disables user interaction depending on game state.
     * @param started true if the game has started, false otherwise.
     */
    void setGameStarted(bool started);

    /**
     * @brief Retrieves a cropped tile image based on tile number.
     * @param number Unique tile's number.
     * @return QPixmap representing the image for the tile.
     */
    QPixmap getTileImageByNumber(int number) const;

    /**
     * @brief Sets the image used to display tile content.
     * @param img QPixmap representing the full puzzle image.
     */
    void setImage(const QPixmap &img);

    /**
     * @brief Checks if the game is in image mode.
     * @return True if image mode is active, otherwise false.
     */
    bool isImageMode() const { return imageMode; }

    /**
     * @brief Returns the full image used for tile rendering.
     * @return The current image as QPixmap.
     */
    QPixmap getFullImage() const { return fullImage; }

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    Game *game = nullptr;
    Board *board = nullptr;
    bool gameStarted = false;
    QPixmap fullImage;
    bool imageMode = false;

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
