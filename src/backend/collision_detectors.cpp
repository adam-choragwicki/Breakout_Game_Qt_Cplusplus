#include "collision_detectors.h"
#include "config_prod.h"

bool ArenaEdgeCollisionDetector::checkCollisionWithArenaBottomEdge(const QRect& ballRect)
{
    return ballRect.bottom() == ConfigProd::Arena::BOTTOM_EDGE;
}

bool ArenaEdgeCollisionDetector::checkCollisionWithArenaTopEdge(const QRect& ballRect)
{
    return ballRect.top() == ConfigProd::Arena::TOP_EDGE;
}

bool ArenaEdgeCollisionDetector::checkCollisionWithArenaLeftEdge(const QRect& ballRect)
{
    return ballRect.left() == ConfigProd::Arena::LEFT_EDGE;
}

bool ArenaEdgeCollisionDetector::checkCollisionWithArenaRightEdge(const QRect& ballRect)
{
    return ballRect.right() == ConfigProd::Arena::RIGHT_EDGE;
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
