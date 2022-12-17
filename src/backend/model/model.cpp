#include "model.h"
#include "spdlog/spdlog.h"
#include "config_prod.h"

Model::Model()
{
    spdlog::debug("Initializing model");

    scene_ = std::make_unique<GraphicsScene>();

    initWorldBoundaries();

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

void Model::initWorldBoundaries()
{
    const int sceneWidth = ConfigProd::Arena::WIDTH;
    const int sceneHeight = ConfigProd::Arena::HEIGHT;

    leftArenaBoundary_ = new ArenaBoundary(-1, 0, 1, sceneHeight); // Left boundary
    rightArenaBoundary_ = new ArenaBoundary(sceneWidth, 0, 1, sceneHeight); // Right boundary
    topArenaBoundary_ = new ArenaBoundary(0, -1, sceneWidth, 1); // Top boundary
    bottomArenaBoundary_ = new ArenaBoundary(0, sceneHeight, sceneWidth, 1); // Bottom boundary
}

void Model::addItemsToScene()
{
    scene_->addItem(leftArenaBoundary_);
    scene_->addItem(rightArenaBoundary_);
    scene_->addItem(topArenaBoundary_);
    scene_->addItem(bottomArenaBoundary_);

    scene_->addItem(paddle_.get());
    scene_->addItem(ball_.get());

    addBricksToScene();

    scene_->addItem(screenTextDisplay_.get());
}

void Model::addBricksToScene()
{
    for(const auto&[_, brick] : bricksManager_->getCoordinatesToBricksMapping())
    {
        scene_->addItem(brick.get());
    }
}
