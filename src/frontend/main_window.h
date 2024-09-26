#pragma once

#include "graphics_view.h"
#include <QMainWindow>
#include <QMouseEvent>

class Model;

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

    void setMousePositionAtScreenCenter();

private slots:
    void updateFPSDisplay(int fpsCount);

private:
    void closeEvent(QCloseEvent*) override;
    void mousePressEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void centerOnScreen(QScreen* screen);
    void centerOnPrimaryScreen();

    const Model& model_;

    std::unique_ptr<GraphicsView> graphicsView_;
};
