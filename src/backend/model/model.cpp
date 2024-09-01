#include "model.h"
#include "spdlog/spdlog.h"
#include "config_prod.h"

Model::Model()
{
    spdlog::debug("Initializing model");

    scene_ = std::make_unique<GraphicsScene>();

    //    gameTickTimer_.setInterval(Config::Timing::GAME_TICK_INTERVAL);

    paddle_ = std::make_unique<Paddle>(ConfigProd::Paddle::POSITION_X, ConfigProd::Paddle::POSITION_Y);
    ball_ = std::make_unique<Ball>(ConfigProd::Ball::POSITION_X, ConfigProd::Ball::POSITION_Y);
    bricksContainer_ = std::make_unique<BricksContainer>();

    addItemsToScene();

    spdlog::debug("Items on scene: {}", scene_->items().size());
}

void Model::reset()
{
    paddle_ = std::make_unique<Paddle>(ConfigProd::Paddle::POSITION_X, ConfigProd::Paddle::POSITION_Y);
    ball_ = std::make_unique<Ball>(ConfigProd::Ball::POSITION_X, ConfigProd::Ball::POSITION_Y);
    //    gameStateManager_ = std::make_unique<GameStateManager>(gameTickTimer_);
    bricksContainer_ = std::make_unique<BricksContainer>();
}

void Model::addItemsToScene()
{
    scene_->addItem(paddle_.get());
    scene_->addItem(ball_.get());

    addBricksToScene();
}

void Model::addBricksToScene()
{
    for(const Brick& brick : *bricksContainer_)
    {
        scene_->addItem(&(const_cast<Brick&>(brick)));
    }
}
