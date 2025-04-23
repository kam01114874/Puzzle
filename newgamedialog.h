#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>
#include "board.h"

namespace Ui {
class NewGameDialog;
}

class NewGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewGameDialog(QWidget *parent = nullptr);
    ~NewGameDialog();

    int getBoardSize() const;
    TileType getTileType() const;

private:
    Ui::NewGameDialog *ui;
};

#endif // NEWGAMEDIALOG_H
