#pragma once

#include <QRect>

class ArenaBoundary;
class Ball;

class ArenaBoundaryCollisionDetector
{
public:
//    static bool checkCollisionWithArenaBottomEdge(const QRect& ballRect);
//    static bool checkCollisionWithArenaTopEdge(const QRect& ballRect);
//    static bool checkCollisionWithArenaLeftEdge(const QRect& ballRect);
//    static bool checkCollisionWithArenaRightEdge(const QRect& ballRect);

    //    static bool checkCollisionWithArenaBottomBoundary(const QRect& ballRect, const std::vector<ArenaBoundary*>& arenaBoundaries);
    //    static bool checkCollisionWithArenaTopBoundary(const QRect& ballRect, const std::vector<ArenaBoundary*>& arenaBoundaries);
    //    static bool checkCollisionWithArenaLeftBoundary(const QRect& ballRect, const std::vector<ArenaBoundary*>& arenaBoundaries);
    //    static bool checkCollisionWithArenaRightBoundary(const QRect& ballRect, const std::vector<ArenaBoundary*>& arenaBoundaries);

    static bool checkCollisionWithArenaBottomBoundary(const Ball& ball, ArenaBoundary* bottomArenaBoundary);
    static bool checkCollisionWithArenaTopBoundary(const Ball& ball, ArenaBoundary* topArenaBoundary);
    static bool checkCollisionWithArenaLeftBoundary(const Ball& ball, ArenaBoundary* leftArenaBoundary);
    static bool checkCollisionWithArenaRightBoundary(const Ball& ball, ArenaBoundary* rightArenaBoundary);
};

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
