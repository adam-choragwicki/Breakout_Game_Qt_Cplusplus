#pragma once

#include "model/model.h"
#include "frontend/main_window.h"
#include "backend/config.h"

class Controller : public QObject
{
Q_OBJECT

public:
    Controller(Model& model, MainWindow& view);

private slots:
    void processGameTickEvent();
    void processMouseClickedEvent();
    void processMouseMovedEvent(int mousePositionX);
    void processKeyPressedEvent(QKeyEvent* keyEvent);
    void processApplicationTerminationRequest();

private:
    void startGame();
    void endGame(GameResult gameResult);
    void checkAndProcessBallCollisions();
    void checkAndProcessBallCollisionWithArenaEdges(const QRect& ballRect);
    void checkAndProcessBallCollisionWithBrick(const QRect& ballRect);
    void checkAndProcessBallCollisionWithPaddle(const QRect& ballRect);

    Model& model_;
    MainWindow& view_;
};
