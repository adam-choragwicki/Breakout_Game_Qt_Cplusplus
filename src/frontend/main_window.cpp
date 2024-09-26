#include "main_window.h"
#include "model/model.h"
#include "spdlog/spdlog.h"
#include "config_prod.h"
#include <QPainter>
#include <QKeyEvent>
#include <QGuiApplication>

MainWindow::MainWindow(const Model& model) : model_(model)
{
    spdlog::debug("Initializing view");

    setWindowTitle("Breakout");

    graphicsView_ = std::make_unique<GraphicsView>(model_.getScene(), this);

    setMinimumSize(ConfigProd::Arena::WIDTH, ConfigProd::Arena::HEIGHT);

    setCentralWidget(graphicsView_.get());

    setPalette(QPalette(Qt::black));

    connect(graphicsView_.get(), &GraphicsView::mouseMovedEvent, this, &MainWindow::mouseMovedEvent);

    centerOnPrimaryScreen();
    setMousePositionAtScreenCenter();

    connect(graphicsView_.get(), &GraphicsView::fpsCountUpdateEvent, this, &MainWindow::updateFPSDisplay);
}

void MainWindow::centerOnPrimaryScreen()
{
    QScreen* primaryScreen = QGuiApplication::primaryScreen();
    centerOnScreen(primaryScreen);
}

void MainWindow::centerOnScreen(QScreen* screen)
{
    setScreen(screen);
    const QRect screenRect = screen->availableGeometry();
    const QRect widgetRect({}, frameSize().boundedTo(screenRect.size()));
    move(screenRect.center() - widgetRect.center());
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    emit mouseClickedEvent();
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    emit keyPressedEvent(event);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    event->ignore();
    emit applicationTerminationRequest();
}

void MainWindow::updateFPSDisplay(int fpsCount)
{
    setWindowTitle(QString("Breakout (%1 FPS)").arg(fpsCount));
}

void MainWindow::setMousePositionAtScreenCenter()
{
    QPoint screenCenter = screen()->geometry().center();
    QCursor::setPos(screenCenter);

    //qDebug() << "Placing cursor initially on " << screenCenter;
}
