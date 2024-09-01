#include "controller.h"
#include "backend/collision_detectors.h"
#include "spdlog/spdlog.h"
#include <QCoreApplication>

Controller::Controller(Model& model, MainWindow& view) : model_(model), view_(view)
{
    spdlog::debug("Initializing controller");

    //    inputHandler_ = std::make_unique<InputHandler>(model_);
    gameLoop_ = std::make_unique<GameLoop>(model_);
    gameManager_ = std::make_unique<GameManager>(model_);

    gameManager_->setGameLoop(gameLoop_.get());

    //    connect(gameLoop_.get(), &GameLoop::endGame, gameManager_.get(), &GameManager::endGame);

    subscribeToFrontendEvents();
    initializeFrontendEvents();

    //    connect(&model_.getGameTickTimer(), &QTimer::timeout, this, &Controller::processGameTickEvent);

    gameManager_->prepareGameToStart();

    view_.getViewportUpdateTimer()->start();
}

void Controller::subscribeToFrontendEvents()
{
    connect(&view_, &MainWindow::mouseClickedEvent, this, &Controller::processMouseClickedEvent);
    connect(&view_, &MainWindow::mouseMovedEvent, this, &Controller::processMouseMovedEvent);
    connect(&view_, &MainWindow::keyPressedEvent, this, &Controller::processKeyPressedEvent);
    connect(&view_, &MainWindow::applicationTerminationRequest, this, &Controller::processApplicationTerminationRequest);
}

void Controller::initializeFrontendEvents()
{
    connect(view_.getViewportUpdateTimer(), &QTimer::timeout, this, &Controller::viewportUpdateHandler);
}

void Controller::viewportUpdateHandler()
{
    view_.update();

    //    QList<QRectF>& dirtyRegions = model_.getScene()->getDirtyRegions();
    //
    //    if(!dirtyRegions.isEmpty())
    //    {
    //        view_.updateViewport(dirtyRegions);
    //        dirtyRegions.clear();
    //    }
}

void Controller::startGame()
{
    //    model_.reset();
    //    model_.getGameStateManager().startGame();
}

void Controller::endGame(GameResult gameResult)
{
    //    model_.getGameStateManager().endGame(gameResult);
    //    view_.update();
}

//void Controller::processGameTickEvent()
//{
//    model_.getBall().move();
//    checkAndProcessBallCollisions();
//    view_.update();
//}

void Controller::processMouseClickedEvent()
{
    //    if(model_.getGameStateManager().isStopped())
    //    {
    //        startGame();
    //    }
}

void Controller::processMouseMovedEvent(int mousePositionX)
{
    if(mousePositionX > Config::Paddle::WIDTH / 2 && mousePositionX < Config::Arena::WIDTH - Config::Paddle::WIDTH / 2)
    {
        model_.getPaddle().setHorizontalPosition(mousePositionX);
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
