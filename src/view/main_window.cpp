#include "view/main_window.h"
#include "log_manager.h"

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

    paddle_ = new Paddle(90, GameParameters::Paddle::ELEVATION);
    ball_ = new Ball(120, GameParameters::Ball::STARTING_ELEVATION);

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
        if(!brick->isDestroyed())
        {
            painter.drawRect(brick->getRect());
        }
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
    checkAndProcessCollisions();
    update();
}

void MainWindow::checkAndProcessCollisions()
{
    const QRect& ballRect = ball_->getRect();

    checkAndProcessCollisionWithArenaEdges(ballRect);
    checkAndProcessCollisionWithBrick(ballRect);
}

void MainWindow::checkAndProcessCollisionWithArenaEdges(const QRect& ballRect)
{
    if(ballRect.left() == GameParameters::Arena::LEFT_EDGE)
    {
        ball_->setHorizontalDirection(+1);
    }

    if(ballRect.right() == GameParameters::Arena::RIGHT_EDGE)
    {
        ball_->setHorizontalDirection(-1);
    }

    if(ballRect.top() == GameParameters::Arena::TOP_EDGE)
    {
        ball_->setVerticalDirection(+1);
    }

    if(ballRect.bottom() == GameParameters::Arena::BOTTOM_EDGE)
    {
        ball_->setVerticalDirection(-1);
    }
}

void MainWindow::checkAndProcessCollisionWithBrick(const QRect& ballRect)
{
    const QPoint& ballRectCenter = ballRect.center();

    for(Brick* brick : bricks_)
    {
        if(!brick->isDestroyed())
        {
            const QRect& brickRect = brick->getRect();
            const QPoint& brickRectCenter = brickRect.center();
            constexpr int halfBrickHeight = GameParameters::Brick::HEIGHT / 2;

            if(ballRect.intersects(brickRect))
            {
                if(ballRectCenter.y() >= (brickRectCenter.y() + halfBrickHeight))
                {
                    LOG(INFO) << "Hit from below";
                    ball_->setVerticalDirection(+1);
                }
                else if(ballRectCenter.y() <= (brickRectCenter.y() - halfBrickHeight))
                {
                    LOG(INFO) << "Hit from above";
                    ball_->setVerticalDirection(-1);
                }
                else if(ballRectCenter.x() < brickRectCenter.x())
                {
                    LOG(INFO) << "Hit from left";
                    ball_->setHorizontalDirection(-1);
                }
                else if(ballRectCenter.x() > brickRectCenter.x())
                {
                    LOG(INFO) << "Hit from right";
                    ball_->setHorizontalDirection(+1);
                }

                brick->setDestroyed(true);
            }
        }
    }
}
