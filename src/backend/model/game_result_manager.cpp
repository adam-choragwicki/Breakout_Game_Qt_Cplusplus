#include "game_result_manager.h"

GameResultManager::GameResultManager() : gameResult_(GameResult::NO_RESULT_YET)
{}

QString GameResultManager::getGameEndMessage() const
{
    QString victoryMessage = "Victory, press LMB to restart";
    QString gameOverMessage = "Game over, press LMB to restart";

    if(gameResult_ == GameResult::WIN)
    {
        return victoryMessage;
    }
    else if(gameResult_ == GameResult::LOST)
    {
        return gameOverMessage;
    }
    else
    {
        throw std::runtime_error("Error, trying to get a src end message but src has not ended yet");
    }
}

bool GameResultManager::isGameFinished() const
{
    return gameResult_ != GameResult::NO_RESULT_YET;
}
