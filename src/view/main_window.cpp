#include "view/main_window.h"
#include "log_manager.h"

#include <QPainter>

MainWindow::MainWindow(Model* model) : model_(model)
{
    setFixedSize(GameParameters::Arena::WIDTH, GameParameters::Arena::HEIGHT);
    setPalette(QPalette(Qt::black));
    setMouseTracking(true);
    setCursor(QCursor{Qt::BlankCursor});
}

void MainWindow::closeEvent(QCloseEvent*)
{
    exit(0);
}

void MainWindow::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);

    GameResult gameResult = model_->getGameResult();

    if(gameResult == GameResult::NO_RESULT_YET)
    {
        drawObjects(&painter);
    }
    else if(gameResult == GameResult::WIN)
    {
        displayResult(&painter);
    }
    else if(gameResult == GameResult::LOSE)
    {
        displayResult(&painter);
    }
}

void MainWindow::drawObjects(QPainter* painter)
{
    painter->setPen(Qt::black);

    for(const auto& brick : model_->getBricks())
    {
        painter->setBrush(brick->getColor());
        painter->drawRect(brick->getRect());
    }

    painter->setPen(Qt::black);
    painter->setBrush(Qt::blue);
    painter->drawRect(model_->getPaddle()->getRect());

    painter->setPen(Qt::black);
    painter->setBrush(Qt::white);
    painter->drawEllipse(model_->getBall()->getRect());
}

void MainWindow::displayResult(QPainter* painter)
{
    QFont font("Console", 20, QFont::Bold);
    QFontMetrics fontMetrics(font);

    QString message;

    if(model_->getGameResult() == GameResult::WIN)
    {
        message = "Victory";
    }
    else if(model_->getGameResult() == GameResult::LOSE)
    {
        message = "Game over";
    }

    message += ", press LMB to restart";

    painter->setFont(font);

    int height = this->height();
    int width = this->width();

    painter->translate(QPoint(width / 2, height / 2));

    int textWidth = fontMetrics.horizontalAdvance(message);
    painter->drawText(-textWidth / 2, 0, message);
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    emit(mouseMovedEvent(event->pos().x()));
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    emit mouseClickedEvent();
}
