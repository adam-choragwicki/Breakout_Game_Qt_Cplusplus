#include "model.h"

Model::Model()
{
    gameTickTimer_.setInterval(Config::Timing::GAME_TICK_INTERVAL);
    reset();
}

void Model::reset()
{
    paddle_ = std::make_unique<Paddle>(Config::Paddle::POSITION_X, Config::Paddle::POSITION_Y);
    ball_ = std::make_unique<Ball>(Config::Ball::POSITION_X, Config::Ball::POSITION_Y);
    gameStateManager_ = std::make_unique<GameStateManager>(gameTickTimer_);
    bricksContainer_ = std::make_unique<BricksContainer>();
}
