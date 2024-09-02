#include "model.h"
#include "spdlog/spdlog.h"
#include "config_prod.h"

Model::Model()
{
    spdlog::debug("Initializing model");

    scene_ = std::make_unique<GraphicsScene>();

    paddle_ = std::make_unique<Paddle>(ConfigProd::Paddle::POSITION_X, ConfigProd::Paddle::POSITION_Y);
    ball_ = std::make_unique<Ball>(ConfigProd::Ball::POSITION_X, ConfigProd::Ball::POSITION_Y);
    bricksManager_ = std::make_unique<BricksManager>();

    screenTextDisplay_ = std::make_unique<ScreenTextDisplay>();

    addItemsToScene();

    spdlog::debug("Items on scene: {}", scene_->items().size());
}

void Model::reset()
{
    spdlog::debug("Resetting model");

    paddle_->reset();
    ball_->reset();
    bricksManager_->reset();

    addBricksToScene();
}

void Model::addItemsToScene()
{
    scene_->addItem(paddle_.get());
    scene_->addItem(ball_.get());

    addBricksToScene();

    scene_->addItem(screenTextDisplay_.get());
}

void Model::addBricksToScene()
{
    for(const Brick& brick : *bricksManager_)
    {
        scene_->addItem(&(const_cast<Brick&>(brick)));
    }
}
