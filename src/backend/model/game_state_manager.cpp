#include "game_state_manager.h"

GameStateManager::GameStateManager(QTimer& gameTickTimer) : gameTickTimer_(gameTickTimer), state_(State::STOPPED)
{}

void GameStateManager::startGame()
{
//    gameTickTimer_.start();
    state_ = State::RUNNING;
}

void GameStateManager::endGame(GameResult gameResult)
{
//    gameTickTimer_.stop();
    gameResultManager_.setGameResult(gameResult);
    state_ = State::STOPPED;
}

void GameStateManager::togglePause()
{
    if(state_ == State::PAUSED)
    {
        gameTickTimer_.start();
        state_ = State::RUNNING;
    }
    else if(state_ == State::RUNNING)
    {
        gameTickTimer_.stop();
        state_ = State::PAUSED;
    }
}

bool GameStateManager::isStopped()
{
    return state_ == State::STOPPED;
}

bool GameStateManager::isGameFinished() const
{
    return gameResultManager_.isGameFinished();
}
