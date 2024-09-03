#include "collision_detectors.h"
#include "arena_boundary.h"
#include "model/ball.h"
#include "config_prod.h"

//bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaBottomEdge(const QRect& ballRect)
//{
//    return ballRect.bottom() == ConfigProd::Arena::BOTTOM_EDGE;
//}
//
//bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaTopEdge(const QRect& ballRect)
//{
//    return ballRect.top() == ConfigProd::Arena::TOP_EDGE;
//}
//
//bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaLeftEdge(const QRect& ballRect)
//{
//    return ballRect.left() == ConfigProd::Arena::LEFT_EDGE;
//}
//
//bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaRightEdge(const QRect& ballRect)
//{
//    return ballRect.right() == ConfigProd::Arena::RIGHT_EDGE;
//}

bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaBottomBoundary(const Ball& ball, ArenaBoundary* bottomArenaBoundary)
{
    const MovementVector& originalMovementVector = ball.getMovementVector();

    MovementVector adjustedMovementVector = ball.getMovementVector();
    const QRectF newBoundingRectAfterMove = ball.sceneBoundingRect().translated(adjustedMovementVector.toQPointF());

    const QRectF worldBoundaryRect = bottomArenaBoundary->sceneBoundingRect();

    if(newBoundingRectAfterMove.intersects(worldBoundaryRect))
    {
        return true;
    }

    return false;
}

bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaTopBoundary(const Ball& ball, ArenaBoundary* topArenaBoundary)
{
    const MovementVector& originalMovementVector = ball.getMovementVector();

    MovementVector adjustedMovementVector = ball.getMovementVector();
    const QRectF newBoundingRectAfterMove = ball.sceneBoundingRect().translated(adjustedMovementVector.toQPointF());

    const QRectF worldBoundaryRect = topArenaBoundary->sceneBoundingRect();

    if(newBoundingRectAfterMove.intersects(worldBoundaryRect))
    {
        return true;
    }

    return false;
}

bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaLeftBoundary(const Ball& ball, ArenaBoundary* leftArenaBoundary)
{
    const MovementVector& originalMovementVector = ball.getMovementVector();

    MovementVector adjustedMovementVector = ball.getMovementVector();
    const QRectF newBoundingRectAfterMove = ball.sceneBoundingRect().translated(adjustedMovementVector.toQPointF());

    const QRectF worldBoundaryRect = leftArenaBoundary->sceneBoundingRect();

    if(newBoundingRectAfterMove.intersects(worldBoundaryRect))
    {
        return true;
    }

    return false;
}

bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaRightBoundary(const Ball& ball, ArenaBoundary* rightArenaBoundary)
{
    const MovementVector& originalMovementVector = ball.getMovementVector();

    MovementVector adjustedMovementVector = ball.getMovementVector();
    const QRectF newBoundingRectAfterMove = ball.sceneBoundingRect().translated(adjustedMovementVector.toQPointF());

    const QRectF worldBoundaryRect = rightArenaBoundary->sceneBoundingRect();

    if(newBoundingRectAfterMove.intersects(worldBoundaryRect))
    {
        return true;
    }

    return false;
}


bool BrickCollisionDetector::checkBallCollisionWithBrickFromBrickBottomSide(const QPoint& ballRectCenter, const QPoint& brickRectCenter)
{
    return ballRectCenter.y() >= (brickRectCenter.y() + calculateHalfBrickHeight());
}

bool BrickCollisionDetector::checkBallCollisionWithBrickFromBrickTopSide(const QPoint& ballRectCenter, const QPoint& brickRectCenter)
{
    return ballRectCenter.y() <= (brickRectCenter.y() - calculateHalfBrickHeight());
}

bool BrickCollisionDetector::checkBallCollisionWithBrickFromBrickLeftSide(const QPoint& ballRectCenter, const QPoint& brickRectCenter)
{
    return ballRectCenter.x() < brickRectCenter.x();
}

bool BrickCollisionDetector::checkBallCollisionWithBrickFromBrickRightSide(const QPoint& ballRectCenter, const QPoint& brickRectCenter)
{
    return ballRectCenter.x() > brickRectCenter.x();
}

constexpr int BrickCollisionDetector::calculateHalfBrickHeight()
{
    return ConfigProd::Brick::HEIGHT / 2;
}

bool PaddleCollisionDetector::checkBallCollisionWithPaddleFromPaddleTopSide(const QRect& ballRect, const QRect& paddleRect)
{
    return ballRect.center().y() <= paddleRect.center().y();
}
