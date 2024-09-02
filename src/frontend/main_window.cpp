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
    setFocus(Qt::ActiveWindowFocusReason);

    graphicsView_ = std::make_unique<GraphicsView>(model_.getScene(), this);

    //setFixedSize(1000, 800);
    setFixedSize(ConfigProd::Arena::WIDTH, ConfigProd::Arena::HEIGHT);

    setCentralWidget(graphicsView_.get());

    setPalette(QPalette(Qt::black));
    setCursor(QCursor{Qt::BlankCursor});

    connect(graphicsView_.get(), &GraphicsView::mouseMovedEvent, this, &MainWindow::mouseMovedEvent);

    centerOnPrimaryScreen();

    viewportUpdateTimer_ = std::make_unique<QTimer>(this);
    viewportUpdateTimer_->setTimerType(Qt::PreciseTimer);
    viewportUpdateTimer_->setInterval(VIEWPORT_UPDATE_INTERVAL);

    connect(viewportUpdateTimer_.get(), &QTimer::timeout, this, &MainWindow::updateViewport);
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

void MainWindow::closeEvent(QCloseEvent* event)
{
    event->ignore();
    emit applicationTerminationRequest();
}

//void MainWindow::displayResult(QPainter& painter)
//{
//    QFont font("Console", 20, QFont::Bold);
//    painter.setFont(font);
//
//    int height = this->height();
//    int width = this->width();
//
//    painter.translate(QPoint(width / 2, height / 2));
//
//    QFontMetrics fontMetrics(font);
//    //    QString gameEndMessage = model_.getGameStateManager().getGameEndMessage();
//    //    int textWidth = fontMetrics.horizontalAdvance(gameEndMessage);
//    //    painter.drawText(-textWidth / 2, 0, gameEndMessage);
//}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    emit mouseClickedEvent();
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    emit keyPressedEvent(event);
}

void MainWindow::updateViewport()
{
    //    QList<QRectF>& dirtyRegions = model_.getScene()->getDirtyRegions();
    //
    //    if(!dirtyRegions.isEmpty())
    //    {
    //        view_.updateViewport(dirtyRegions);
    //        dirtyRegions.clear();
    //    }

    graphicsView_->updateViewport();
}

void MainWindow::startRendering()
{
    viewportUpdateTimer_->start();
}

void MainWindow::updateFPSDisplay(int fpsCount)
{
    setWindowTitle(QString("Breakout (%1 FPS)").arg(fpsCount));
}
