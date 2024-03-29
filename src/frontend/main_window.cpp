#include "main_window.h"
#include "gui_config.h"
#include <QPainter>
#include <QKeyEvent>
#include <QGuiApplication>

MainWindow::MainWindow(const Model& model) : model_(model)
{
    setFixedSize(Config::Arena::WIDTH, Config::Arena::HEIGHT);
    setPalette(QPalette(Qt::black));
    setMouseTracking(true);
    setCursor(QCursor{Qt::BlankCursor});
    centerOnScreen();
}

void MainWindow::centerOnScreen()
{
    const QRect screenRect = QWidget::screen()->availableGeometry();
    const QRect widgetRect({}, frameSize().boundedTo(screenRect.size()));

    move(screenRect.center() - widgetRect.center());
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    event->ignore();
    emit applicationTerminationRequest();
}

void MainWindow::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if(model_.getGameStateManager().isGameFinished())
    {
        displayResult(painter);
    }
    else
    {
        drawBricks(painter);
        drawPaddle(painter);
        drawBall(painter);
    }
}

void MainWindow::drawBall(QPainter& painter) const
{
    painter.setPen(GuiConfig::Ball::PEN_OUTLINE);
    painter.setBrush(GuiConfig::Ball::COLOR);
    painter.drawEllipse(model_.getBall().getRect());
}

void MainWindow::drawPaddle(QPainter& painter) const
{
    painter.setPen(GuiConfig::Paddle::PEN_OUTLINE);
    painter.setBrush(GuiConfig::Paddle::COLOR);

    painter.drawRoundedRect(model_.getPaddle().getRect(), GuiConfig::Paddle::ROUNDED_RECT_WIDTH_RATIO_PERCENTAGE, GuiConfig::Paddle::ROUNDED_RECT_HEIGHT_RATIO_PERCENTAGE, Qt::RelativeSize);
}

void MainWindow::drawBricks(QPainter& painter) const
{
    painter.setPen(Qt::black);

    for(const Brick& brick : model_.getBricksContainer())
    {
        painter.setBrush(brick.getColor());
        painter.drawRect(brick.getRect());
    }
}

void MainWindow::displayResult(QPainter& painter)
{
    QFont font("Console", 20, QFont::Bold);
    painter.setFont(font);

    int height = this->height();
    int width = this->width();

    painter.translate(QPoint(width / 2, height / 2));

    QFontMetrics fontMetrics(font);
    QString gameEndMessage = model_.getGameStateManager().getGameEndMessage();
    int textWidth = fontMetrics.horizontalAdvance(gameEndMessage);
    painter.drawText(-textWidth / 2, 0, gameEndMessage);
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    emit(mouseMovedEvent(event->pos().x()));
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    emit mouseClickedEvent();
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    emit keyPressedEvent(event);
}
