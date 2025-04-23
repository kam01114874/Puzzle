#include "mainwindow.h"
#include "newgamedialog.h"
#include "boardwidget.h"

#include <ui_mainwindow.h>
#include <QMessageBox>



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

        ui->boardWidget->setGame(game.get());
        ui->boardWidget->update();

        //Connect boardWidget signals to main window slots (once per game)
        connect(ui->boardWidget, &BoardWidget::tileMoved, this, &MainWindow::onTileMoved);
        connect(ui->boardWidget, &BoardWidget::puzzleSolved, this, &MainWindow::onPuzzleSolved);
    }
}

void MainWindow::on_resetButton_clicked()
{
    if (game) {
        game->reset();
        //re-enable if it was locked after win
        ui->boardWidget->setEnabled(true);
        //reset counter to 0
        updateMoveCount();
        ui->boardWidget->update();
    }
}

void MainWindow::on_shuffleButton_clicked()
{
    if (game) {
        //shuffle the board and start game
        game->start();
        //enable interactions
        ui->boardWidget->setGameStarted(true);
        //enable in case it was locked
        ui->boardWidget->setEnabled(true);
        //reset move count
        updateMoveCount();
        ui->boardWidget->update();
    }
}

void MainWindow::updateMoveCount() {
    if (game) {
        ui->moveCountLabel->setText("Licznik ruchów: " + QString::number(game->getMoveCount()));
    }
}

void MainWindow::onTileMoved() {
    //update counter after every tile move
    updateMoveCount();
}

void MainWindow::onPuzzleSolved() {
    //Show message when puzzle is successfully solved
    QMessageBox::information(this, "Gratulacje", "Układanka została ułożona poprawnie!");
}
