/**
 * @file previewwindow.h
 * @brief Declaration of the PreviewWindow class.
 *
 * This widget displays a preview of the full puzzle image used in the game.
 * It is designed to be a separate, non-blocking window user can move.
 */

#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QWidget>
#include <QPixmap>

/**
 * @class PreviewWindow
 * @brief Preview window to display the full puzzle image.
 *
 * The PreviewWindow displays a scaled version of the image inside a QLabel.
 * This window is shown independently of the main window and does not block interaction.
 */
class QLabel;

class PreviewWindow : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Constructs a PreviewWindow and displays the given image.
     * @param pixmap The full puzzle image to be shown.
     * @param parent Optional parent widget (nullptr for independent window).
     */
    explicit PreviewWindow(const QPixmap& pixmap, QWidget *parent = nullptr);

private:
    QLabel* imageLabel;
};

#endif // PREVIEWWINDOW_H
