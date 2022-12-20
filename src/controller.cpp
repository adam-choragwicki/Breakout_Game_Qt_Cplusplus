#include "controller.h"
#include "log_manager.h"

Controller::Controller(Model* model, MainWindow* view)
{
    model_ = model;
    view_ = view;

    connect(&gameTickTimer_, &QTimer::timeout, this, &Controller::processGameTickEvent);
    connect(view, &MainWindow::mouseClickedEvent, this, &Controller::processMouseClickedEvent);
    connect(view, &MainWindow::mouseMovedEvent, this, &Controller::processMouseMovedEvent);

    gameTickTimer_.setInterval(GameParameters::GAME_TICK_MS);

    startGame();
}

void Controller::startGame()
{
    model_->reset();
    model_->setGameState(GameState::RUNNING);
    gameTickTimer_.start();
}

void Controller::endGame(GameResult gameResult)
{
    gameTickTimer_.stop();
    model_->setGameState(GameState::STOPPED);
    model_->setGameResult(gameResult);
    view_->update();
}

void Controller::processGameTickEvent()
{
    if(model_->getGameState() == GameState::RUNNING)
    {
        model_->getBall()->move();
        checkAndProcessCollisions();
        view_->update();
    }
}

void Controller::checkAndProcessCollisions()
{
    const QRect& ballRect = model_->getBall()->getRect();

    checkAndProcessCollisionWithArenaEdges(ballRect);
    checkAndProcessCollisionWithBrick(ballRect);
    checkAndProcessCollisionWithPaddle(ballRect);
}

void Controller::checkAndProcessCollisionWithArenaEdges(const QRect& ballRect)
{
    if(ballRect.bottom() == GameParameters::Arena::BOTTOM_EDGE)
    {
        endGame(GameResult::LOSE);
    }
    else if(ballRect.left() == GameParameters::Arena::LEFT_EDGE)
    {
        model_->getBall()->setHorizontalDirection(HorizontalDirection::EAST);
    }
    else if(ballRect.right() == GameParameters::Arena::RIGHT_EDGE)
    {
        model_->getBall()->setHorizontalDirection(HorizontalDirection::WEST);
    }
    else if(ballRect.top() == GameParameters::Arena::TOP_EDGE)
    {
        model_->getBall()->setVerticalDirection(VerticalDirection::SOUTH);
    }
}

void Controller::checkAndProcessCollisionWithBrick(const QRect& ballRect)
{
    const QPoint& ballRectCenter = ballRect.center();

    for(const auto& brick : model_->getBricks())
    {
        const QRect& brickRect = brick->getRect();
        const QPoint& brickRectCenter = brickRect.center();
        constexpr int halfBrickHeight = GameParameters::Brick::HEIGHT / 2;

        if(ballRect.intersects(brickRect))
        {
            if(ballRectCenter.y() >= (brickRectCenter.y() + halfBrickHeight))
            {
                model_->getBall()->setVerticalDirection(VerticalDirection::SOUTH);
            }
            else if(ballRectCenter.y() <= (brickRectCenter.y() - halfBrickHeight))
            {
                model_->getBall()->setVerticalDirection(VerticalDirection::NORTH);
            }
            else if(ballRectCenter.x() < brickRectCenter.x())
            {
                model_->getBall()->setHorizontalDirection(HorizontalDirection::WEST);
            }
            else if(ballRectCenter.x() > brickRectCenter.x())
            {
                model_->getBall()->setHorizontalDirection(HorizontalDirection::EAST);
            }

            model_->getBricks().erase(brick);

            if(model_->getBricks().empty())
            {
                endGame(GameResult::WIN);
            }

            return;
        }
    }
}

void Controller::checkAndProcessCollisionWithPaddle(const QRect& ballRect)
{
    const QRect& paddleRect = model_->getPaddle()->getRect();

    if(ballRect.intersects(paddleRect))
    {
        if(ballRect.center().y() <= paddleRect.center().y())
        {
            model_->getBall()->setVerticalDirection(VerticalDirection::NORTH);
        }
    }
}

void Controller::processMouseClickedEvent()
{
    if(model_->getGameState() == GameState::STOPPED)
    {
        startGame();
    }
}

void Controller::processMouseMovedEvent(int mousePositionX)
{
    if(mousePositionX > GameParameters::Paddle::WIDTH / 2 && mousePositionX < GameParameters::Arena::WIDTH - GameParameters::Paddle::WIDTH / 2)
    {
        model_->getPaddle()->setHorizontalPosition(mousePositionX);
    }
}
