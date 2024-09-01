#include "model.h"
#include "spdlog/spdlog.h"
#include "config.h"

Model::Model()
{
    spdlog::debug("Initializing model");

    scene_ = std::make_unique<GraphicsScene>();

    //    gameTickTimer_.setInterval(Config::Timing::GAME_TICK_INTERVAL);

    paddle_ = std::make_unique<Paddle>(Config::Paddle::POSITION_X, Config::Paddle::POSITION_Y);
    ball_ = std::make_unique<Ball>(Config::Ball::POSITION_X, Config::Ball::POSITION_Y);
    bricksContainer_ = std::make_unique<BricksContainer>();

    addItemsToScene();

    spdlog::debug("Items on scene: {}", scene_->items().size());
}

void Model::reset()
{
    paddle_ = std::make_unique<Paddle>(Config::Paddle::POSITION_X, Config::Paddle::POSITION_Y);
    ball_ = std::make_unique<Ball>(Config::Ball::POSITION_X, Config::Ball::POSITION_Y);
    //    gameStateManager_ = std::make_unique<GameStateManager>(gameTickTimer_);
    bricksContainer_ = std::make_unique<BricksContainer>();
}

void Model::addItemsToScene()
{
    scene_->addItem(paddle_.get());
    scene_->addItem(ball_.get());

    addBricksToScene();

    //    scene_->addItem(pacman_.get());
    //    scene_->addItem(blueGhost_.get());
    //    scene_->addItem(orangeGhost_.get());
    //    scene_->addItem(purpleGhost_.get());
    //    scene_->addItem(redGhost_.get());
    //
    //    scene_->addItem(screenTextDisplay_.get());
    //
    //    scene_->addItem(scoreDisplay_.get());
}

void Model::addBricksToScene()
{
    for(const Brick& brick : *bricksContainer_)
    {
        scene_->addItem(&(const_cast<Brick&>(brick)));
    }
}
