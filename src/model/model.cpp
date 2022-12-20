#include "model/model.h"

Model::Model()
{
    reset();
}

void Model::reset()
{
    gameState_ = GameState::STOPPED;
    gameResult_ = GameResult::NO_RESULT_YET;

    paddle_ = std::make_unique<Paddle>(GameParameters::Paddle::POSITION_X, GameParameters::Paddle::POSITION_Y);
    ball_ = std::make_unique<Ball>(GameParameters::Ball::POSITION_X, GameParameters::Ball::POSITION_Y);

    createBricks();
}

void Model::createBricks()
{
    const std::vector<QColor> colors{Qt::red, QColor{"orange"}, Qt::green, Qt::yellow, Qt::cyan};

    bricks_.clear();

    for(int row = 0; row < GameParameters::ROWS_COUNT; row++)
    {
        QColor color = colors.at(row % colors.size());

        for(int column = 0; column < GameParameters::COLUMNS_COUNT; column++)
        {
            bricks_.emplace(std::make_unique<Brick>(column * GameParameters::Brick::WIDTH, row * GameParameters::Brick::HEIGHT, color));
        }
    }
}
