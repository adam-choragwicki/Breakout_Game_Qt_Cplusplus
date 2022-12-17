#include "controller.h"
#include "backend/collision_detectors.h"
#include <QCoreApplication>

Controller::Controller(Model& model, MainWindow& view) : model_(model), view_(view)
{
    connect(&model_.getGameTickTimer(), &QTimer::timeout, this, &Controller::processGameTickEvent);
    connect(&view_, &MainWindow::mouseClickedEvent, this, &Controller::processMouseClickedEvent);
    connect(&view_, &MainWindow::mouseMovedEvent, this, &Controller::processMouseMovedEvent);
    connect(&view_, &MainWindow::keyPressedEvent, this, &Controller::processKeyPressedEvent);
    connect(&view_, &MainWindow::applicationTerminationRequest, this, &Controller::processApplicationTerminationRequest);
}

void Controller::startGame()
{
    model_.reset();
    model_.getGameStateManager().startGame();
}

void Controller::endGame(GameResult gameResult)
{
    model_.getGameStateManager().endGame(gameResult);
    view_.update();
}

void Controller::processGameTickEvent()
{
    model_.getBall().move();
    checkAndProcessBallCollisions();
    view_.update();
}

void Controller::checkAndProcessBallCollisions()
{
    const QRect ballRect = model_.getBall().getRect();

    checkAndProcessBallCollisionWithArenaEdges(ballRect);
    checkAndProcessBallCollisionWithBrick(ballRect);
    checkAndProcessBallCollisionWithPaddle(ballRect);
}

void Controller::checkAndProcessBallCollisionWithArenaEdges(const QRect& ballRect)
{
    if(ArenaEdgeCollisionDetector::checkCollisionWithArenaBottomEdge(ballRect))
    {
        endGame(GameResult::LOSE);
    }

    if(ArenaEdgeCollisionDetector::checkCollisionWithArenaTopEdge(ballRect))
    {
        model_.getBall().bounceHorizontally();
    }

    if(ArenaEdgeCollisionDetector::checkCollisionWithArenaLeftEdge(ballRect) || ArenaEdgeCollisionDetector::checkCollisionWithArenaRightEdge(ballRect))
    {
        model_.getBall().bounceVertically();
    }
}

void Controller::checkAndProcessBallCollisionWithBrick(const QRect& ballRect)
{
    for(const auto& brick : model_.getBricksContainer())
    {
        const QRect brickRect = brick.getRect();

        if(ballRect.intersects(brickRect))
        {
            const QPoint ballRectCenter = ballRect.center();
            const QPoint brickRectCenter = brickRect.center();

            if(BrickCollisionDetector::checkBallCollisionWithBrickFromBrickBottomSide(ballRectCenter, brickRectCenter) ||
               BrickCollisionDetector::checkBallCollisionWithBrickFromBrickTopSide(ballRectCenter, brickRectCenter))
            {
                model_.getBall().bounceHorizontally();
            }
            else if(BrickCollisionDetector::checkBallCollisionWithBrickFromBrickLeftSide(ballRectCenter, brickRectCenter) ||
                    BrickCollisionDetector::checkBallCollisionWithBrickFromBrickRightSide(ballRectCenter, brickRectCenter))
            {
                model_.getBall().bounceVertically();
            }
            else
            {
                throw std::runtime_error("Error, ball collision with brick detected, but collision details processed incorrectly");
            }

            model_.getBricksContainer().removeBrick(brick);

            if(model_.getBricksContainer().isEmpty())
            {
                endGame(GameResult::WIN);
            }

            return;
        }
    }
}

void Controller::checkAndProcessBallCollisionWithPaddle(const QRect& ballRect)
{
    if(model_.getBall().isFallingDown())
    {
        const QRect paddleRect = model_.getPaddle().getRect();

        if(ballRect.intersects(paddleRect))
        {
            if(PaddleCollisionDetector::checkBallCollisionWithPaddleFromPaddleTopSide(ballRect, paddleRect))
            {
                /*Ball is above paddle*/
                model_.getBall().bounceHorizontally();
            }
            else
            {
                /*Ball is lateral to paddle*/
                model_.getBall().bounceVertically();
            }
        }
    }
}

void Controller::processMouseClickedEvent()
{
    if(model_.getGameStateManager().isStopped())
    {
        startGame();
    }
}

void Controller::processMouseMovedEvent(int mousePositionX)
{
    if(mousePositionX > Config::Paddle::WIDTH / 2 && mousePositionX < Config::Arena::WIDTH - Config::Paddle::WIDTH / 2)
    {
        model_.getPaddle().setHorizontalPosition(mousePositionX);
    }
}

void Controller::processKeyPressedEvent(QKeyEvent* keyEvent)
{
    if(keyEvent->key() == Qt::Key_P)
    {
        model_.getGameStateManager().togglePause();
    }
}

void Controller::processApplicationTerminationRequest()
{
    QCoreApplication::exit(0);
}
