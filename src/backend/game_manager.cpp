#include "game_manager.h"
#include "spdlog/spdlog.h"
#include "model/model.h"
#include "game_loop.h"

GameManager::GameManager(Model& model) : model_(model)
{
    gameState_ = GameState::STOPPED;
}

void GameManager::processStartOrRestartGameRequest()
{
    spdlog::debug("Processing start or restart game request");

    if(gameState_ == GameState::READY_TO_START)
    {
        startGame();
    }
    else if(gameState_ == GameState::STOPPED)
    {
        prepareGameToStart();
    }
    else
    {
        spdlog::debug("Game is not in READY_TO_START state. Start or restart game request rejected");
    }
}

void GameManager::prepareGameToStart()
{
    spdlog::debug("Prepare game to start");
    model_.reset();

    gameState_ = GameState::READY_TO_START;

    //    model_.getScene()->invalidate();
}

void GameManager::endGame(GameResult gameResult)
{
//    gameTickTimer_.stop();
//    gameResultManager_.setGameResult(gameResult);
    gameState_ = GameState::STOPPED;

//    gameResult_ = gameResult;
    gameLoop_->stop();

    //    model_.getWhatToDrawManager()->drawBackground_ = false;

    //    model_.getScene()->invalidate();
}

void GameManager::startGame()
{
    spdlog::debug("Starting game");

    gameState_ = GameState::RUNNING;

    gameLoop_->start();

    //    model_.getScene()->invalidate();
}