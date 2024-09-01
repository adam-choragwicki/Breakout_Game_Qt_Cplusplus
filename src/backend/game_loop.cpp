#include "game_loop.h"
#include "model/model.h"
#include "collision_detectors.h"
#include <QTimer>
#include "spdlog/spdlog.h"

GameLoop::GameLoop(Model& model) : model_(model)
{
    gameLoopTimer_ = std::make_unique<QTimer>();
    gameLoopTimer_->setTimerType(Qt::PreciseTimer);
    gameLoopTimer_->setInterval(GAME_LOOP_INTERVAL);
    connect(gameLoopTimer_.get(), &QTimer::timeout, this, &GameLoop::execute);
}

void GameLoop::start()
{
    gameLoopTimer_->start();
}

void GameLoop::stop()
{
    gameLoopTimer_->stop();
}

void GameLoop::execute()
{
    model_.getBall().move();
    checkAndProcessBallCollisions();
    //    view_.update();
}

void GameLoop::checkAndProcessBallCollisions()
{
    const QRect ballRect = model_.getBall().getRect();

    checkAndProcessBallCollisionWithArenaEdges(ballRect);
    checkAndProcessBallCollisionWithBrick(ballRect);
    checkAndProcessBallCollisionWithPaddle(ballRect);
}

void GameLoop::checkAndProcessBallCollisionWithArenaEdges(const QRect& ballRect)
{
    if(ArenaEdgeCollisionDetector::checkCollisionWithArenaBottomEdge(ballRect))
    {
        endGame(GameResult::LOST);
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

void GameLoop::checkAndProcessBallCollisionWithBrick(const QRect& ballRect)
{
    for(const auto& brick : model_.getBricksContainer())
    {
        const QRect brickRect = brick.getRect();

        if(ballRect.intersects(brickRect))
        {
            const QPoint ballRectCenter = ballRect.center();
            const QPoint brickRectCenter = brickRect.center();

            if(BrickCollisionDetector::checkBallCollisionWithBrickFromBrickBottomSide(ballRectCenter, brickRectCenter) || BrickCollisionDetector::checkBallCollisionWithBrickFromBrickTopSide(ballRectCenter, brickRectCenter))
            {
                model_.getBall().bounceHorizontally();
            }
            else if(BrickCollisionDetector::checkBallCollisionWithBrickFromBrickLeftSide(ballRectCenter, brickRectCenter) || BrickCollisionDetector::checkBallCollisionWithBrickFromBrickRightSide(ballRectCenter, brickRectCenter))
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

void GameLoop::checkAndProcessBallCollisionWithPaddle(const QRect& ballRect)
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