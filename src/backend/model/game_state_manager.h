#pragma once

#include "game_result_manager.h"
#include <QTimer>

class GameStateManager
{
    enum class State
    {
        STOPPED, PAUSED, RUNNING
    } state_;

public:
    explicit GameStateManager(QTimer& gameTickTimer);
    void startGame();
    void endGame(GameResult gameResult);
    void togglePause();
    bool isStopped();

    [[nodiscard]] QString getGameEndMessage() const
    { return gameResultManager_.getGameEndMessage(); }

    [[nodiscard]] bool isGameFinished() const;

private:
    QTimer& gameTickTimer_;
    GameResultManager gameResultManager_;
};
