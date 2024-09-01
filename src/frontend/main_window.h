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

    [[nodiscard]] QTimer* getViewportUpdateTimer() const
    { return viewportUpdateTimer_.get(); }

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

    std::unique_ptr<GraphicsView> graphicsView_;

    std::unique_ptr<QTimer> viewportUpdateTimer_;

    static constexpr auto VIEWPORT_UPDATE_INTERVAL = std::chrono::milliseconds(17);
};
