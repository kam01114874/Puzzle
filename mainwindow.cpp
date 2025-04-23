#include "mainwindow.h"
#include "newgamedialog.h"
#include "boardwidget.h"

#include <ui_mainwindow.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newGameButton_clicked()
{
    NewGameDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        int size = dialog.getBoardSize();
        TileType type = dialog.getTileType();

        game = std::make_unique<Game>(size, type);
        game->start();
        ui->boardWidget->setBoard(&game->getBoard());

    }
}
