/**
 * @file mainwindow.h
 * @brief Declares the MainWindow class which acts as the main GUI controller.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "previewwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Main application window that controls the game and UI elements.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the main window.
     * @param parent The parent widget.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor.
     */
    ~MainWindow();

    /**
     * @brief Updates the move count label with the current move count.
     */
    void updateMoveCount();

private slots:
    /**
     * @brief Triggered when the 'Nowa Gra' button is clicked.
     */
    void on_newGameButton_clicked();

    /**
     * @brief Triggered when the 'Reset' button is clicked.
     */
    void on_resetButton_clicked();

    /**
     * @brief Triggered when the 'Tasuj' button is clicked.
     */
    void on_shuffleButton_clicked();

    /**
     * @brief Handles the signal that a tile has benn moved.
     */
    void onTileMoved();

    /**
     * @brief Handles the signal that the puzzle has been solved.
     */
    void onPuzzleSolved();

    /**
     * @brief Opens a preview window displaying the full puzzle image.
     */
    void on_previewButton_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Game> game;
    PreviewWindow *previewWindow = nullptr;
};

#endif // MAINWINDOW_H
