#include "game_loop.h"
#include "model/model.h"
#include "collision_detectors.h"
#include "spdlog/spdlog.h"
#include "common.h"
#include "coordinates.h"
#include "config_prod.h"
#include <QTimer>

GameLoop::GameLoop(Model& model) : model_(model)
{
    gameLoopTimer_ = std::make_unique<QTimer>();
    gameLoopTimer_->setTimerType(Qt::PreciseTimer);
    gameLoopTimer_->setInterval(ConfigProd::GAME_LOOP_INTERVAL_MS);
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
    //    spdlog::debug("Loop {}: ", loopCounter_);

    model_.getBall().move();
    checkAndProcessBallCollisions();

    ++loopCounter_;
}

void GameLoop::checkAndProcessBallCollisions()
{
    const QRect ballRect = model_.getBall().sceneBoundingRect().toRect();

    checkAndProcessBallCollisionWithArenaEdges(ballRect);
    checkAndProcessBallCollisionWithBrick(ballRect);
    checkAndProcessBallCollisionWithPaddle(ballRect);
}

void GameLoop::checkAndProcessBallCollisionWithArenaEdges(const QRect& ballRect)
{
    if(ArenaBoundaryCollisionDetector::checkCollisionWithArenaBottomBoundary(model_.getBall(), model_.getBottomArenaBoundary()))
    {
        emit endGame(GameResult::LOST);
        return;
    }

    if(ArenaBoundaryCollisionDetector::checkCollisionWithArenaTopBoundary(model_.getBall(), model_.getTopArenaBoundary()))
    {
        model_.getBall().bounceHorizontally();
    }

    if(ArenaBoundaryCollisionDetector::checkCollisionWithArenaLeftBoundary(model_.getBall(), model_.getLeftArenaBoundary()) || ArenaBoundaryCollisionDetector::checkCollisionWithArenaRightBoundary(model_.getBall(), model_.getRightArenaBoundary()))
    {
        model_.getBall().bounceVertically();
    }
}

void GameLoop::checkAndProcessBallCollisionWithBrick(const QRect& ballRect)
{
    for(const auto&[coordinates, brick] : model_.getBricksManager().getCoordinatesToBricksMapping())
    {
        const QRect brickRect = brick->sceneBoundingRect().toRect();

        if(ballRect.intersects(brickRect))
        {
            qDebug() << "Collision with brick";

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

            model_.getBricksManager().removeBrickAtCoordinates(coordinates);

            if(model_.getBricksManager().isEmpty())
            {
                emit endGame(GameResult::WIN);
                return;
            }

            return;
        }
    }
}

void GameLoop::checkAndProcessBallCollisionWithPaddle(const QRect& ballRect)
{
    if(model_.getBall().isFallingDown())
    {
        const QRect paddleRect = model_.getPaddle().sceneBoundingRect().toRect();

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
