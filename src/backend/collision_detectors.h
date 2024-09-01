#pragma once

#include <QRect>

class ArenaEdgeCollisionDetector
{
public:
    static bool checkCollisionWithArenaBottomEdge(const QRect& ballRect);
    static bool checkCollisionWithArenaTopEdge(const QRect& ballRect);
    static bool checkCollisionWithArenaLeftEdge(const QRect& ballRect);
    static bool checkCollisionWithArenaRightEdge(const QRect& ballRect);
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
