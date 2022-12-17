#pragma once

#include "model/model.h"

#include <QMainWindow>
#include <QMouseEvent>

class MainWindow : public QMainWindow
{
Q_OBJECT

signals:
    void mouseClickedEvent();
    void mouseMovedEvent(int mousePositionX);
    void keyPressedEvent(QKeyEvent* event);
    void applicationTerminationRequest();

public:
    explicit MainWindow(const Model& model);

private:
    void closeEvent(QCloseEvent*) override;
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void centerOnScreen(QScreen* screen);
    void centerOnPrimaryScreen();

    void drawBricks(QPainter& painter) const;
    void drawPaddle(QPainter& painter) const;
    void drawBall(QPainter& painter) const;
    void displayResult(QPainter& painter);

    const Model& model_;
};
