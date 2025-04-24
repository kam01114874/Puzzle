#include "mainwindow.h"
#include "newgamedialog.h"
#include "boardwidget.h"

#include <ui_mainwindow.h>
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newGameButton_clicked()
{
    //Mainwindow = parent
    NewGameDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        int size = dialog.getBoardSize();
        TileType type = dialog.getTileType();

        //game = std::make_unique<Game>(size, type); <=> std::unique_ptr<Game>(new Game(size, type));
        game = std::make_unique<Game>(size, type);

        QString imagePath = dialog.getImagePath();
        QPixmap pixmap(imagePath);
        if (!pixmap.isNull()) {
            game->setImage(pixmap);
        }

        // QPixmap test(":/images/img1.png");
        // qDebug() << "img1 loaded?" << !test.isNull();

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

void MainWindow::on_previewButton_clicked()
{
    if (!game) return;

    //Getter for image
    QPixmap fullImage = game->getFullImage();

    if (fullImage.isNull()) return;

    //Close previous preview window
    if (previewWindow) {
        previewWindow->close();
        delete previewWindow;
        previewWindow = nullptr;
    }

    //Create new window
    previewWindow = new PreviewWindow(fullImage);
    previewWindow->setAttribute(Qt::WA_DeleteOnClose);
    //Open in new window
    previewWindow->setWindowFlag(Qt::Window);
    previewWindow->show();
}
