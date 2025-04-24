/**
 * @file newgamedialog.cpp
 * @brief Implementation of the NewGameDialog class.
 *
 * This file contains the implementation of the NewGameDialog class, which presents a dialog window
 * for configuring a new puzzle game. The user can select the board size, tile type, and optionally
 * choose a puzzle image either from disk or randomly from Qt resources.
 */

#include "newgamedialog.h"
#include "ui_newgamedialog.h"

NewGameDialog::NewGameDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewGameDialog)
{
    ui->setupUi(this);
    //Default tile type (Animated)
    ui->radioAnimated->setChecked(true);
    //Block browse file button
    ui->browseButton->setEnabled(false);

    //lambda slot
    // [=,this] - capture list: copy all variables from outer scope, copy 'this' to have access to methods
    connect(ui->radioCustomImage, &QRadioButton::toggled, this, [=, this](bool checked) {
        ui->browseButton->setEnabled(checked);
        if (!checked) {
            ui->labelImagePath->clear();
        }
    });

    connect(ui->radioRandomImage, &QRadioButton::toggled, this, [=, this](bool checked) {
        if (!checked)
            return;

        //Images from Qt resources (resources.qrc)
        QStringList images = {":/images/img1.png",
                              ":/images/img2.png",
                              ":/images/img3.png",
                              ":/images/img4.png",
                              ":/images/img5.png",
                              ":/images/img6.png",
                              ":/images/img7.png",
                              ":/images/img8.png",
                              ":/images/img9.png"};

        //Pick random image from resources
        int index = QRandomGenerator::global()->bounded(images.size());
        QString imagePath = images[index];
        ui->labelImagePath->setText(imagePath);
    });

    connect(ui->browseButton, &QPushButton::clicked, this, [=, this]() {
        QString filePath = QFileDialog::getOpenFileName(this,
                                                        "Wybierz obraz PNG",
                                                        "",
                                                        "PNG Files (*.png)");
        if (!filePath.isEmpty()) {
            ui->labelImagePath->setText(filePath);
        }
    });
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

QString NewGameDialog::getImagePath() const
{
    return ui->labelImagePath->text();
}
