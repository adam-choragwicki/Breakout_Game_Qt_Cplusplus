#pragma once

#include "model.h"
#include "brick.h"
#include "common.h"
#include "paddle.h"
#include "ball.h"
#include <set>

#include <QMainWindow>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(Model* model);

private:
    void closeEvent(QCloseEvent*) override;
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent*) override;
    void mousePressEvent(QMouseEvent* event) override;
    void timerEvent(QTimerEvent*) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void checkAndProcessCollisions();
    void checkAndProcessCollisionWithArenaEdges(const QRect& ballRect);
    void checkAndProcessCollisionWithBrick(const QRect& ballRect);
    void checkAndProcessCollisionWithPaddle(const QRect& ballRect);

    void startGame();
    void endGame(GameResult gameResult);
    void displayResult(QPainter* painter);

    Model* model_;

    std::set<std::unique_ptr<Brick>> bricks_;
    std::unique_ptr<Paddle> paddle_;
    std::unique_ptr<Ball> ball_;

    int timerId_;

    GameState gameState_{GameState::STOPPED};
    GameResult gameResult_{GameResult::NO_RESULT_YET};
    void createBricks();
};
