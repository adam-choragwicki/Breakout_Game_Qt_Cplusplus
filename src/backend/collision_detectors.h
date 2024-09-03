#pragma once

#include <QRect>

class ArenaBoundary;
class Ball;

class ArenaBoundaryCollisionDetector
{
public:
    static bool checkCollisionWithArenaBottomEdge(const QRect& ballRect);
    static bool checkCollisionWithArenaTopEdge(const QRect& ballRect);
    static bool checkCollisionWithArenaLeftEdge(const QRect& ballRect);
    static bool checkCollisionWithArenaRightEdge(const QRect& ballRect);

    //    static bool checkCollisionWithArenaBottomBoundary(const QRect& ballRect, const std::vector<ArenaBoundary*>& arenaBoundaries);
    //    static bool checkCollisionWithArenaTopBoundary(const QRect& ballRect, const std::vector<ArenaBoundary*>& arenaBoundaries);
    //    static bool checkCollisionWithArenaLeftBoundary(const QRect& ballRect, const std::vector<ArenaBoundary*>& arenaBoundaries);
    //    static bool checkCollisionWithArenaRightBoundary(const QRect& ballRect, const std::vector<ArenaBoundary*>& arenaBoundaries);

    static bool checkCollisionWithArenaBottomBoundary(const Ball& ball, ArenaBoundary* bottomArenaBoundary);
    static bool checkCollisionWithArenaTopBoundary(const Ball& ball, ArenaBoundary* topArenaBoundary);
    static bool checkCollisionWithArenaLeftBoundary(const Ball& ball, ArenaBoundary* leftArenaBoundary);
    static bool checkCollisionWithArenaRightBoundary(const Ball& ball, ArenaBoundary* rightArenaBoundary);
};

//bool CollisionDetector::checkProjectileCollisionWithWorldBoundary(const AbstractProjectile& projectile, const std::vector<WorldBoundary*>& worldBoundaries)
//{
//    const MovementVector& originalMovementVector = projectile.getMovementVector();
//
//    MovementVector adjustedMovementVector = projectile.getMovementVector();
//    const QRectF newBoundingRectAfterMove = projectile.sceneBoundingRect().translated(adjustedMovementVector.toQPointF());
//
//    for(const WorldBoundary* worldBoundary : worldBoundaries)
//    {
//        const QRectF worldBoundaryRect = worldBoundary->sceneBoundingRect();
//
//        if(newBoundingRectAfterMove.intersects(worldBoundaryRect))
//        {
//            return true;
//        }
//    }
//
//    return false;
//}

class BrickCollisionDetector
{
public:
    static bool checkBallCollisionWithBrickFromBrickBottomSide(const QPoint& ballRectCenter, const QPoint& brickRectCenter);
    static bool checkBallCollisionWithBrickFromBrickTopSide(const QPoint& ballRectCenter, const QPoint& brickRectCenter);
    static bool checkBallCollisionWithBrickFromBrickLeftSide(const QPoint& ballRectCenter, const QPoint& brickRectCenter);
    static bool checkBallCollisionWithBrickFromBrickRightSide(const QPoint& ballRectCenter, const QPoint& brickRectCenter);
    inline static constexpr int calculateHalfBrickHeight();
};

class PaddleCollisionDetector
{
public:
    static bool checkBallCollisionWithPaddleFromPaddleTopSide(const QRect& ballRect, const QRect& paddleRect);
};
