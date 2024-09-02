//#include "movement_vector.h"
//#include "config.h"
//#include <QPointF>
//
//MovementVector::MovementVector(double horizontalSpeed, double verticalSpeed) : horizontalSpeed_(horizontalSpeed), verticalSpeed_(verticalSpeed)
//{}
//
//void MovementVector::increaseX()
//{
//    horizontalSpeed_ += Config::instance().physics.MINIMUM_DISPLACEMENT;
//
//    if(horizontalSpeed_ > Config::instance().physics.MAX_HORIZONTAL_SPEED)
//    {
//        horizontalSpeed_ = Config::instance().physics.MAX_HORIZONTAL_SPEED;
//    }
//}
//
//void MovementVector::decreaseX()
//{
//    horizontalSpeed_ -= Config::instance().physics.MINIMUM_DISPLACEMENT;
//
//    if(std::abs(horizontalSpeed_) > Config::instance().physics.MAX_HORIZONTAL_SPEED)
//    {
//        horizontalSpeed_ = -Config::instance().physics.MAX_HORIZONTAL_SPEED;
//    }
//}
//
//void MovementVector::increaseY()
//{
//    verticalSpeed_ += Config::instance().physics.MINIMUM_DISPLACEMENT;
//
//    if(verticalSpeed_ > Config::instance().physics.MAX_ROPE_SPEED)
//    {
//        verticalSpeed_ = Config::instance().physics.MAX_ROPE_SPEED;
//    }
//}
//
//void MovementVector::decreaseY()
//{
//    verticalSpeed_ -= Config::instance().physics.MINIMUM_DISPLACEMENT;
//
//    if(verticalSpeed_ < Config::instance().physics.NEGATIVE_MAX_ROPE_SPEED)
//    {
//        verticalSpeed_ = Config::instance().physics.NEGATIVE_MAX_ROPE_SPEED;
//    }
//}
//
//void MovementVector::jump()
//{
//    verticalSpeed_ += Config::instance().physics.JUMP_SPEED;
//}
//
//void MovementVector::applyAirFriction()
//{
//    if(horizontalSpeed_ > 0)
//    {
//        horizontalSpeed_ -= Config::instance().physics.AIR_FRICTION;
//
//        if(horizontalSpeed_ < 0)
//        {
//            horizontalSpeed_ = 0;
//        }
//    }
//    else if(horizontalSpeed_ < 0)
//    {
//        horizontalSpeed_ += Config::instance().physics.AIR_FRICTION;
//
//        if(horizontalSpeed_ > 0)
//        {
//            horizontalSpeed_ = 0;
//        }
//    }
//}
//
//void MovementVector::applyRopeFriction()
//{
//    if(verticalSpeed_ > 0)
//    {
//        verticalSpeed_ -= Config::instance().physics.ROPE_FRICTION;
//
//        if(verticalSpeed_ < 0)
//        {
//            verticalSpeed_ = 0;
//        }
//    }
//    else if(verticalSpeed_ < 0)
//    {
//        verticalSpeed_ += Config::instance().physics.ROPE_FRICTION;
//
//        if(verticalSpeed_ > 0)
//        {
//            verticalSpeed_ = 0;
//        }
//    }
//}
//
//void MovementVector::applyGravity()
//{
//    verticalSpeed_ += Config::instance().physics.GRAVITY;
//
//    if(verticalSpeed_ > Config::instance().physics.MAX_FALLING_SPEED)
//    {
//        verticalSpeed_ = Config::instance().physics.MAX_FALLING_SPEED;
//    }
//}
//
//bool MovementVector::isZero() const
//{
//    return horizontalSpeed_ == 0 && verticalSpeed_ == 0;
//}
//
//QPointF MovementVector::toQPointF() const
//{
//    return {horizontalSpeed_, verticalSpeed_};
//}
//
//QString MovementVector::toString() const
//{
//    return QString("Vector: (%1, %2)").arg(horizontalSpeed_).arg(verticalSpeed_);
//}
//
//Direction MovementVector::getHorizontalDirection() const
//{
//    if(horizontalSpeed_ > 0)
//    {
//        return Direction::RIGHT;
//    }
//    else if(horizontalSpeed_ < 0)
//    {
//        return Direction::LEFT;
//    }
//    else
//    {
//        return Direction::NONE;
//    }
//}
