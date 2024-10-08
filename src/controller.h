#pragma once

#include "model/model.h"
#include "frontend/main_window.h"
#include "game_loop.h"
#include "game_manager.h"

class Controller : public QObject
{
Q_OBJECT

public:
    Controller(Model& model, MainWindow& view);

private slots:
    void processMouseClickedEvent();
    void processMouseMovedEvent(int mousePositionX);
    void processKeyPressedEvent(QKeyEvent* keyEvent);
    void processApplicationTerminationRequest();

private:
    void subscribeToFrontendEvents();

    Model& model_;
    MainWindow& view_;

    std::unique_ptr<GameLoop> gameLoop_;
    std::unique_ptr<GameManager> gameManager_;
};
