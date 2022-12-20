#pragma once

#include "model/brick.h"
#include "model/paddle.h"
#include "model/ball.h"

#include <memory>
#include <set>

class Model
{
public:
    Model();
    void reset();

    std::set<std::unique_ptr<Brick>>& getBricks()
    { return bricks_; }

    [[nodiscard]] const std::unique_ptr<Paddle>& getPaddle() const
    { return paddle_; }

    [[nodiscard]] const std::unique_ptr<Ball>& getBall() const
    { return ball_; }

    [[nodiscard]] GameState getGameState() const
    { return gameState_; }

    void setGameState(GameState gameState)
    { gameState_ = gameState; }

    [[nodiscard]] GameResult getGameResult() const
    { return gameResult_; }

    void setGameResult(GameResult gameResult)
    { gameResult_ = gameResult; }

private:
    void createBricks();

    std::set<std::unique_ptr<Brick>> bricks_;
    std::unique_ptr<Paddle> paddle_;
    std::unique_ptr<Ball> ball_;

    GameState gameState_;
    GameResult gameResult_;
};
