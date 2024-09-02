#include <QtGui/QPainter>
#include "screen_text_display.h"
#include "game_manager.h"
#include "config_prod.h"

ScreenTextDisplay::ScreenTextDisplay()
{
    const int FONT_POINT_SIZE = 30;

    font_.setPointSize(FONT_POINT_SIZE);
}

void ScreenTextDisplay::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QGraphicsTextItem::paint(painter, option, widget);

    static const int WIDTH = ConfigProd::Arena::WIDTH;
    static const int HEIGHT = ConfigProd::Arena::HEIGHT / 4;
    static const int X = WIDTH / 2 - WIDTH / 2;
    static const int Y = HEIGHT / 2 + HEIGHT / 2;

    QRect screenTextDisplayBoundingRect(X, Y, WIDTH, HEIGHT);
    painter->setFont(font_);

    bool isReadyToStart = gameManager_->isReadyToStart();
    bool isRunning = gameManager_->isRunning();
    bool isStopped = gameManager_->isStopped();

    if(isReadyToStart)
    {
        painter->setPen(penWhite_);
        painter->drawText(screenTextDisplayBoundingRect, Qt::AlignCenter, "CLICK LMB TO CONTINUE");
    }
    else if(isRunning)
    {
        /*Draw nothing*/
    }
    else if(isStopped)
    {
        if(gameManager_->isGameWin())
        {
            painter->setPen(penYellow_);
            painter->drawText(screenTextDisplayBoundingRect, Qt::AlignTop | Qt::AlignHCenter, "CONGRATULATIONS");
            painter->setPen(penWhite_);
            painter->drawText(screenTextDisplayBoundingRect, Qt::AlignBottom | Qt::AlignHCenter, "CLICK LMB TO CONTINUE");
        }
        else if(gameManager_->isGameLost())
        {
            painter->setPen(penRed_);
            painter->drawText(screenTextDisplayBoundingRect, Qt::AlignTop | Qt::AlignHCenter, "GAME OVER");
            painter->setPen(penWhite_);
            painter->drawText(screenTextDisplayBoundingRect, Qt::AlignBottom | Qt::AlignHCenter, "CLICK LMB TO CONTINUE");
        }
        else
        {
            throw std::runtime_error("Unsupported game state, game stopped but no game result set");
        }
    }
    else
    {
        throw std::runtime_error("Unsupported game state");
    }
}
