#include "game_manager.h"
#include "spdlog/spdlog.h"
#include "model/model.h"
#include "game_loop.h"

GameManager::GameManager(Model& model) : model_(model)
{
    gameState_ = GameState::BEFORE_FIRST_RUN;
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

    if(gameState_ != GameState::BEFORE_FIRST_RUN)
    {
        model_.reset();
    }

    model_.getPaddle().show();
    model_.getBall().show();

    model_.getBricksManager().showAllBricks();

    gameState_ = GameState::READY_TO_START;

    model_.getScene()->invalidate();
}

void GameManager::endGame(GameResult gameResult)
{
    qDebug() << "GameManager received endGame signal";

    gameState_ = GameState::STOPPED;
    gameLoop_->stop();

    model_.getPaddle().hide();
    model_.getBall().hide();

    model_.getBricksManager().hideAllBricks();

    gameResult_ = gameResult;

    model_.getScene()->invalidate();
}

void GameManager::startGame()
{
    spdlog::debug("Starting game");

    gameState_ = GameState::RUNNING;

    gameLoop_->start();

    model_.getScene()->invalidate();
}
