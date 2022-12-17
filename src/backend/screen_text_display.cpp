#include <QtGui/QPainter>
#include "screen_text_display.h"
#include "game_manager.h"
#include "config_prod.h"

ScreenTextDisplay::ScreenTextDisplay()
{
    initializePainterData();
}

void ScreenTextDisplay::initializePainterData()
{
    const int FONT_POINT_SIZE = 30;

    font_.setPointSize(FONT_POINT_SIZE);
    font_.setBold(true);
    font_.setFamily("Console");
}

void ScreenTextDisplay::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QGraphicsTextItem::paint(painter, option, widget);

    static const int RECT_WIDTH = ConfigProd::Arena::WIDTH;
    static const int RECT_HEIGHT = ConfigProd::Arena::HEIGHT / 3;

    QRect screenTextDisplayBoundingRect(0, 0, RECT_WIDTH, RECT_HEIGHT);
    screenTextDisplayBoundingRect.moveCenter({ConfigProd::Arena::WIDTH / 2, ConfigProd::Arena::HEIGHT / 2});

    painter->setFont(font_);

    if(bool drawDebugRect = false; drawDebugRect)
    {
        QPen debugPen(Qt::red, 5);
        painter->setPen(debugPen);
        painter->drawRect(screenTextDisplayBoundingRect);
    }

    bool isReadyToStart = gameManager_->isReadyToStart();
    bool isRunning = gameManager_->isRunning();
    bool isStopped = gameManager_->isStopped();

    if(isReadyToStart)
    {
        painter->setPen(penWhite_);
        painter->drawText(screenTextDisplayBoundingRect, Qt::AlignCenter, "PRESS LMB TO CONTINUE");
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
            painter->drawText(screenTextDisplayBoundingRect, Qt::AlignTop | Qt::AlignHCenter, "VICTORY");
            painter->setPen(penWhite_);
            painter->drawText(screenTextDisplayBoundingRect, Qt::AlignBottom | Qt::AlignHCenter, "PRESS LMB TO CONTINUE");
        }
        else if(gameManager_->isGameLost())
        {
            painter->setPen(penRed_);
            painter->drawText(screenTextDisplayBoundingRect, Qt::AlignTop | Qt::AlignHCenter, "GAME OVER");
            painter->setPen(penWhite_);
            painter->drawText(screenTextDisplayBoundingRect, Qt::AlignBottom | Qt::AlignHCenter, "PRESS LMB TO CONTINUE");
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
