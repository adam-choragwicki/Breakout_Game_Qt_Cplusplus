#pragma once

#include "model.h"
#include "brick.h"
#include "common.h"
#include "paddle.h"
#include "ball.h"

#include <QMainWindow>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(Model* model);
    ~MainWindow() override;

private:
    void closeEvent(QCloseEvent*) override;
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent*) override;
    void timerEvent(QTimerEvent*) override;
    void checkAndProcessCollisions();
    void checkAndProcessCollisionWithArenaEdges(const QRect& ballRect);
    void checkAndProcessCollisionWithBrick(const QRect& ballRect);

    Model* model_;

    Brick* bricks_[GameParameters::BRICKS_COUNT];
    Paddle* paddle_;
    Ball* ball_;

    int timerId_;
};
