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

public:
    explicit MainWindow(Model* model);

private:
    void closeEvent(QCloseEvent*) override;
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void drawObjects(QPainter* painter);
    void displayResult(QPainter* painter);

    Model* model_;
};
