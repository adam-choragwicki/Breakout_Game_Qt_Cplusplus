#include <QtGui/QPainter>
#include "screen_text_display.h"
#include "game_manager.h"
#include "config_prod.h"

ScreenTextDisplay::ScreenTextDisplay()
{
    const int FONT_POINT_SIZE = 30;

    font_.setPointSize(FONT_POINT_SIZE);
    font_.setBold(true);
    font_.setFamily("Console");

    //    qDebug() << "Style name: " << font_.styleName();
    //    qDebug() << "Family: " << font_.family();

    //        QFont font("Console", 20, QFont::Bold);
    //        painter.setFont(font);
    //
    //        int height = this->height();
    //        int width = this->width();
    //
    //        painter.translate(QPoint(width / 2, height / 2));
    //
    //        QFontMetrics fontMetrics(font);
    //    QString gameEndMessage = model_.getGameStateManager().getGameEndMessage();
    //    int textWidth = fontMetrics.horizontalAdvance(gameEndMessage);
    //    painter.drawText(-textWidth / 2, 0, gameEndMessage);
}

void ScreenTextDisplay::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{

    //
    //    painter.translate(QPoint(width / 2, height / 2));
    //
    //    QFontMetrics fontMetrics(font);
    //    //    QString gameEndMessage = model_.getGameStateManager().getGameEndMessage();
    //    //    int textWidth = fontMetrics.horizontalAdvance(gameEndMessage);
    //    //    painter.drawText(-textWidth / 2, 0, gameEndMessage);

    QGraphicsTextItem::paint(painter, option, widget);


    static const int WIDTH = ConfigProd::Arena::WIDTH;
    static const int HEIGHT = ConfigProd::Arena::HEIGHT / 3;
    static const int X = WIDTH / 2 - WIDTH / 2;
    //    static const int Y = HEIGHT / 2 + HEIGHT;
    static const int Y = HEIGHT;

    QRect screenTextDisplayBoundingRect(X, Y, WIDTH, HEIGHT);
    painter->setFont(font_);

    bool isReadyToStart = gameManager_->isReadyToStart();
    bool isRunning = gameManager_->isRunning();
    bool isStopped = gameManager_->isStopped();

    QPen debugPen(Qt::red, 5);
    painter->setPen(debugPen);
    painter->drawRect(screenTextDisplayBoundingRect);

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
