#pragma once

#include "brick.h"
#include "paddle.h"
#include "ball.h"
#include "game_state_manager.h"
#include "bricks_container.h"
#include "game_result_manager.h"

#include <memory>
#include <QTimer>

class Model
{
public:
    Model();
    void reset();

    [[nodiscard]] const QTimer& getGameTickTimer() const
    { return gameTickTimer_; }

    [[nodiscard]] const BricksContainer& getBricksContainer() const
    { return *bricksContainer_; }

    [[nodiscard]] BricksContainer& getBricksContainer()
    { return *bricksContainer_; }

    [[nodiscard]] const Paddle& getPaddle() const
    { return *paddle_; }

    [[nodiscard]] Paddle& getPaddle()
    { return *paddle_; }

    [[nodiscard]] const Ball& getBall() const
    { return *ball_; }

    [[nodiscard]] Ball& getBall()
    { return *ball_; }

    [[nodiscard]] const GameStateManager& getGameStateManager() const
    { return *gameStateManager_; }

    [[nodiscard]] GameStateManager& getGameStateManager()
    { return *gameStateManager_; }

private:
    QTimer gameTickTimer_;

    std::unique_ptr<BricksContainer> bricksContainer_;
    std::unique_ptr<Paddle> paddle_;
    std::unique_ptr<Ball> ball_;
    std::unique_ptr<GameStateManager> gameStateManager_;
};
