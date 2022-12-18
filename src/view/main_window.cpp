#include "view/main_window.h"

#include <QPainter>

MainWindow::MainWindow(Model* model) : model_(model)
{
    setFixedSize(GameParameters::Arena::WIDTH, GameParameters::Arena::HEIGHT);

    int bricksCounter = 0;

    for(int row = 0; row < GameParameters::ROWS_COUNT; row++)
    {
        for(int column = 0; column < GameParameters::COLUMNS_COUNT; column++)
        {
            bricks_[bricksCounter] = new Brick(column * GameParameters::Brick::WIDTH, row * GameParameters::Brick::HEIGHT);
            ++bricksCounter;
        }
    }

    paddle_ = new Paddle(90, 250);
    ball_ = new Ball(120, 245);

    timerId_ = startTimer(GameParameters::BALL_DELAY_MS);
}

MainWindow::~MainWindow()
{
    for(const auto& brick : bricks_)
    {
        delete brick;
    }

    delete paddle_;
}

void MainWindow::closeEvent(QCloseEvent*)
{
    exit(0);
}

void MainWindow::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);

    painter.setPen(Qt::black);
    painter.setBrush(Qt::red);

    for(const auto& brick : bricks_)
    {
        painter.drawRect(brick->getRect());
    }

    painter.setPen(Qt::black);
    painter.setBrush(Qt::blue);
    painter.drawRect(paddle_->getRect());

    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    painter.drawEllipse(ball_->getRect());
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
        case Qt::Key_Left:
        case Qt::Key_A:
            paddle_->moveLeft();
            break;

        case Qt::Key_Right:
        case Qt::Key_D:
            paddle_->moveRight();
            break;
    }

    update();
}

void MainWindow::timerEvent(QTimerEvent* e)
{
    ball_->move();
    update();
}
