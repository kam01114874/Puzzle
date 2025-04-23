#include "newgamedialog.h"
#include "ui_newgamedialog.h"

NewGameDialog::NewGameDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewGameDialog)
{
    ui->setupUi(this);
    //Default tile type (Animated)
    ui->radioAnimated->setChecked(true);
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}

int NewGameDialog::getBoardSize() const
{
    //Returns the selected board size from combo box (3-7)
    return ui->comboBoxSize->currentText().toInt();
}

TileType NewGameDialog::getTileType() const
{
    //Returns selected tile type: Moving or Animated
    if (ui->radioMoving->isChecked())
        return TileType::Moving;
    else
        return TileType::Animated;
}
