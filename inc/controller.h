#pragma once

#include "model/model.h"
#include "view/main_window.h"
#include "common.h"

#include <QTimer>

class Controller : public QObject
{
Q_OBJECT

public:
    Controller(Model* model, MainWindow* view);

    void startGame();
    void endGame(GameResult gameResult);

private slots:
    void processGameTickEvent();
    void processMouseClickedEvent();
    void processMouseMovedEvent(int mousePositionX);

private:
    void checkAndProcessCollisions();
    void checkAndProcessCollisionWithArenaEdges(const QRect& ballRect);
    void checkAndProcessCollisionWithBrick(const QRect& ballRect);
    void checkAndProcessCollisionWithPaddle(const QRect& ballRect);

    Model* model_;
    MainWindow* view_;
    QTimer gameTickTimer_;
};
