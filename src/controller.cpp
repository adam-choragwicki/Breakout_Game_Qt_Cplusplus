#include "controller.h"
#include "spdlog/spdlog.h"
#include "config_prod.h"
#include <QCoreApplication>

Controller::Controller(Model& model, MainWindow& view) : model_(model), view_(view)
{
    spdlog::debug("Initializing controller");

    //    inputHandler_ = std::make_unique<InputHandler>(model_);
    gameLoop_ = std::make_unique<GameLoop>(model_);
    gameManager_ = std::make_unique<GameManager>(model_);

    gameManager_->setGameLoop(gameLoop_.get());

    connect(gameLoop_.get(), &GameLoop::endGame, gameManager_.get(), &GameManager::endGame);

    model_.getScreenTextDisplay().setGameManager(gameManager_.get());

    subscribeToFrontendEvents();

    gameManager_->prepareGameToStart();

    view_.startRendering();
}

void Controller::subscribeToFrontendEvents()
{
    connect(&view_, &MainWindow::mouseClickedEvent, this, &Controller::processMouseClickedEvent);
    connect(&view_, &MainWindow::mouseMovedEvent, this, &Controller::processMouseMovedEvent);
    connect(&view_, &MainWindow::keyPressedEvent, this, &Controller::processKeyPressedEvent);
    connect(&view_, &MainWindow::applicationTerminationRequest, this, &Controller::processApplicationTerminationRequest);
}

void Controller::processMouseClickedEvent()
{
    //    qDebug() << "Mouse clicked";

    if(gameManager_->isReadyToStart())
    {
        gameManager_->startGame();
    }
    else if(gameManager_->isStopped())
    {
        gameManager_->prepareGameToStart();
    }
    else
    {
        spdlog::warn("Mouse clicked but game is not in READY_TO_START or STOPPED state");
    }
}

void Controller::processMouseMovedEvent(int mousePositionX)
{
    //    qDebug() << "Mouse moved event";

    if(mousePositionX > ConfigProd::Paddle::WIDTH / 2 && mousePositionX < ConfigProd::Arena::WIDTH - ConfigProd::Paddle::WIDTH / 2)
    {
        model_.getPaddle().setHorizontalPosition(mousePositionX);

        if(!gameManager_->isRunning())
        {
            model_.getBall().setHorizontalPosition(mousePositionX);
        }
    }
}

void Controller::processKeyPressedEvent(QKeyEvent* keyEvent)
{
    //    if(keyEvent->key() == Qt::Key_P)
    //    {
    //        model_.getGameStateManager().togglePause();
    //    }
}

void Controller::processApplicationTerminationRequest()
{
    QCoreApplication::exit(0);
}
