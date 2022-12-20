#pragma once

#include "model.h"
#include "model/brick.h"
#include "common.h"
#include "model/paddle.h"
#include "model/ball.h"

#include <set>
#include <QMainWindow>
#include <QMouseEvent>

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(Model* model);

private:
    void closeEvent(QCloseEvent*) override;
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent* event) override;
    void timerEvent(QTimerEvent*) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void checkAndProcessCollisions();
    void checkAndProcessCollisionWithArenaEdges(const QRect& ballRect);
    void checkAndProcessCollisionWithBrick(const QRect& ballRect);
    void checkAndProcessCollisionWithPaddle(const QRect& ballRect);

    void createBricks();
    void startGame();
    void endGame(GameResult gameResult);
    void displayResult(QPainter* painter);

    Model* model_;

    std::set<std::unique_ptr<Brick>> bricks_;
    std::unique_ptr<Paddle> paddle_;
    std::unique_ptr<Ball> ball_;

    int timerId_{};

    GameState gameState_{GameState::STOPPED};
    GameResult gameResult_{GameResult::NO_RESULT_YET};
};
