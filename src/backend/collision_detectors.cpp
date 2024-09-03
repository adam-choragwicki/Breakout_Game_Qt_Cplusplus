#include "collision_detectors.h"
#include "arena_boundary.h"
#include "model/ball.h"
#include "config_prod.h"

bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaBoundary(const Ball& ball, ArenaBoundary* arenaBoundary)
{
    const MovementVector& originalMovementVector = ball.getMovementVector();

    MovementVector adjustedMovementVector = originalMovementVector;
    const QRectF newBoundingRectAfterMove = ball.sceneBoundingRect().translated(adjustedMovementVector.toQPointF());

    const QRectF worldBoundaryRect = arenaBoundary->sceneBoundingRect();

    return newBoundingRectAfterMove.intersects(worldBoundaryRect);
}

bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaBottomBoundary(const Ball& ball, ArenaBoundary* bottomArenaBoundary)
{
    return checkCollisionWithArenaBoundary(ball, bottomArenaBoundary);
}

bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaTopBoundary(const Ball& ball, ArenaBoundary* topArenaBoundary)
{
    return checkCollisionWithArenaBoundary(ball, topArenaBoundary);
}

bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaLeftBoundary(const Ball& ball, ArenaBoundary* leftArenaBoundary)
{
    return checkCollisionWithArenaBoundary(ball, leftArenaBoundary);
}

bool ArenaBoundaryCollisionDetector::checkCollisionWithArenaRightBoundary(const Ball& ball, ArenaBoundary* rightArenaBoundary)
{
    return checkCollisionWithArenaBoundary(ball, rightArenaBoundary);
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
