/**
 * @file newgamedialog.h
 * @brief Defines the NewGameDialog class used to configure new game.
 */

#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>
#include <QDir>
#include <QFileDialog>
#include <QPixmap>
#include <QRandomGenerator>
#include <ui_newgamedialog.h>

#include "game.h"

namespace Ui {
class NewGameDialog;
}

/**
 * @class NewGameDialog
 * @brief Dialog window to configure board size, tile type and picture for a new game.
 */
class NewGameDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the dialog.
     * @param parent The parent widget.
     */
    explicit NewGameDialog(QWidget *parent = nullptr);

    /**
     * @brief Destructor.
     */
    ~NewGameDialog();

    /**
     * @brief Gets the selected board size.
     * @return The board size.
     */
    int getBoardSize() const;

    /**
     * @brief Gets the selected tile type.
     * @return The TileType enum value selected by the user.
     */
    TileType getTileType() const;

    /**
     * @brief Retrieves the path of the selected puzzle image.
     * @return QString representing the image file path or resource URL (e.g. ":/images/assets/img1.png").
     */
    QString getImagePath() const;

private:
    Ui::NewGameDialog *ui;
    QString selectedImagePath;
};

#endif // NEWGAMEDIALOG_H
