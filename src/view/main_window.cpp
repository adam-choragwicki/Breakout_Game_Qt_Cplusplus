#include "view/main_window.h"
#include "log_manager.h"

#include <QPainter>

MainWindow::MainWindow(Model* model) : model_(model)
{
    setFixedSize(GameParameters::Arena::WIDTH, GameParameters::Arena::HEIGHT);

    int bricksCounter = 0;

    std::vector<QColor> colors{Qt::red, QColor{"orange"}, Qt::green, Qt::yellow, Qt::cyan};

    for(int row = 0; row < GameParameters::ROWS_COUNT; row++)
    {
        QColor color = colors.at(row % colors.size());

        for(int column = 0; column < GameParameters::COLUMNS_COUNT; column++)
        {
            bricks_[bricksCounter] = new Brick(column * GameParameters::Brick::WIDTH, row * GameParameters::Brick::HEIGHT, color);
            ++bricksCounter;
        }
    }

    paddle_ = new Paddle(GameParameters::Paddle::POSITION_X, GameParameters::Paddle::POSITION_Y);
    ball_ = new Ball(GameParameters::Ball::POSITION_X, GameParameters::Ball::POSITION_Y);

    setPalette(QPalette(Qt::black));

    setMouseTracking(true);
    setCursor(QCursor{Qt::BlankCursor});
    startGame();
}

MainWindow::~MainWindow()
{
    for(const auto& brick : bricks_)
    {
        delete brick;
    }

    delete paddle_;
    delete ball_;
}

void MainWindow::closeEvent(QCloseEvent*)
{
    exit(0);
}

void MainWindow::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);

    if(gameResult_ == GameResult::NO_RESULT_YET)
    {
        painter.setPen(Qt::black);

        for(const auto& brick : bricks_)
        {
            painter.setBrush(brick->getColor());

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
    else if(gameResult_ == GameResult::WIN)
    {
        displayResult(&painter);
    }
    else if(gameResult_ == GameResult::LOSE)
    {
        displayResult(&painter);
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {

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
    checkAndProcessCollisionWithPaddle(ballRect);
}

void MainWindow::checkAndProcessCollisionWithArenaEdges(const QRect& ballRect)
{
    if(ballRect.bottom() == GameParameters::Arena::BOTTOM_EDGE)
    {
        endGame(GameResult::LOSE);
    }
    else if(ballRect.left() == GameParameters::Arena::LEFT_EDGE)
    {
        ball_->setHorizontalDirection(HorizontalDirection::EAST);
    }
    else if(ballRect.right() == GameParameters::Arena::RIGHT_EDGE)
    {
        ball_->setHorizontalDirection(HorizontalDirection::WEST);
    }
    else if(ballRect.top() == GameParameters::Arena::TOP_EDGE)
    {
        ball_->setVerticalDirection(VerticalDirection::SOUTH);
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
                    ball_->setVerticalDirection(VerticalDirection::SOUTH);
                }
                else if(ballRectCenter.y() <= (brickRectCenter.y() - halfBrickHeight))
                {
                    LOG(INFO) << "Hit from above";
                    ball_->setVerticalDirection(VerticalDirection::NORTH);
                }
                else if(ballRectCenter.x() < brickRectCenter.x())
                {
                    LOG(INFO) << "Hit from left";
                    ball_->setHorizontalDirection(HorizontalDirection::WEST);
                }
                else if(ballRectCenter.x() > brickRectCenter.x())
                {
                    LOG(INFO) << "Hit from right";
                    ball_->setHorizontalDirection(HorizontalDirection::EAST);
                }

                brick->setDestroyed(true);

                uint destroyedBricksCounter = std::count_if(std::begin(bricks_), std::end(bricks_), [](const Brick* brick)
                {
                    return brick->isDestroyed();
                });

                if(destroyedBricksCounter == GameParameters::BRICKS_COUNT)
                {
                    endGame(GameResult::WIN);
                }
            }
        }
    }
}

void MainWindow::checkAndProcessCollisionWithPaddle(const QRect& ballRect)
{
    const QRect& paddleRect = paddle_->getRect();

    if(ballRect.intersects(paddleRect))
    {
        if(ballRect.center().y() <= paddleRect.center().y())
        {
            LOG(INFO) << "Paddle hit from above";
            ball_->setVerticalDirection(VerticalDirection::NORTH);
        }
    }
}

void MainWindow::displayResult(QPainter* painter)
{
    QFont font("Console", 20, QFont::Bold);
    QFontMetrics fontMetrics(font);

    QString message;

    if(gameResult_ == GameResult::WIN)
    {
        message = "Victory";
    }
    else if(gameResult_ == GameResult::LOSE)
    {
        message = "Game over";
    }
    else
    {
        //todo
        throw std::runtime_error("Should not happen");
    }

    int textWidth = fontMetrics.horizontalAdvance(message);

    painter->setFont(font);
    int h = height();
    int w = width();

    painter->translate(QPoint(w / 2, h / 2));
    painter->drawText(-textWidth / 2, 0, message);
}

void MainWindow::startGame()
{
    timerId_ = startTimer(GameParameters::BALL_DELAY_MS);
    gameResult_ = GameResult::NO_RESULT_YET;
}

void MainWindow::endGame(GameResult gameResult)
{
    killTimer(timerId_);
    gameResult_ = gameResult;
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    int mousePositionX = event->pos().x();

    if(mousePositionX > GameParameters::Paddle::WIDTH / 2 && mousePositionX < GameParameters::Arena::WIDTH - GameParameters::Paddle::WIDTH / 2)
    {
        paddle_->setHorizontalPosition(event->pos().x());
    }
}
