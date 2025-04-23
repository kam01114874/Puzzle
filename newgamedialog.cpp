#include "newgamedialog.h"
#include "ui_newgamedialog.h"

NewGameDialog::NewGameDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewGameDialog)
{
    ui->setupUi(this);
    //Default tile type
    ui->radioAnimated->setChecked(true);
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}

int NewGameDialog::getBoardSize() const
{
    return ui->comboBoxSize->currentText().toInt();
}

TileType NewGameDialog::getTileType() const
{
    if (ui->radioMoving->isChecked())
        return TileType::Moving;
    else
        return TileType::Animated;
}
