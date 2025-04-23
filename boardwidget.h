#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include "board.h"

class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = nullptr);

    void setBoard(const Board* board);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    const Board* board = nullptr;
};

#endif // BOARDWIDGET_H
