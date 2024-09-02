//#pragma once
//
//#include "direction.h"
//
//class QString;
//class QPointF;
//
//class MovementVector
//{
//public:
//    MovementVector() = default;
//    MovementVector(double horizontalSpeed, double verticalSpeed);
//
//    [[nodiscard]] double getHorizontalSpeed() const
//    { return horizontalSpeed_; }
//
//    [[nodiscard]] double getVerticalSpeed() const
//    { return verticalSpeed_; }
//
//    void setHorizontalSpeed(double horizontalSpeed)
//    { horizontalSpeed_ = horizontalSpeed; }
//
//    void setVerticalSpeed(double verticalSpeed)
//    { verticalSpeed_ = verticalSpeed; }
//
//    [[nodiscard]] Direction getHorizontalDirection() const;
//
//    void increaseX();
//
//    void decreaseX();
//
//    void increaseY();
//
//    void decreaseY();
//
//    void jump();
//
//    void applyAirFriction();
//
//    void applyRopeFriction();
//
//    void applyGravity();
//
//    [[nodiscard]] bool isZero() const;
//
//    [[nodiscard]] QString toString() const;
//
//    [[nodiscard]] QPointF toQPointF() const;
//
//private:
//    double horizontalSpeed_{};
//    double verticalSpeed_{};
//};
