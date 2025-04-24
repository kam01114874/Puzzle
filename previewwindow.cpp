/**
 * @file previewwindow.cpp
 * @brief Implementation of the PreviewWindow class.
 *
 * This file contains the logic for creating and displaying a non-blocking, resizable image preview window.
 */

#include "previewwindow.h"
#include <QLabel>
#include <QVBoxLayout>

//Setting parent enables later automatic cleanup.
PreviewWindow::PreviewWindow(const QPixmap &pixmap, QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Podgląd obrazka");

    imageLabel = new QLabel(this);
    //max 400x400, keep proportions + antyaliasing
    imageLabel->setPixmap(pixmap.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    //layout for better arrangment of elements
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(imageLabel);

    setLayout(layout);
    resize(420, 420);
}
