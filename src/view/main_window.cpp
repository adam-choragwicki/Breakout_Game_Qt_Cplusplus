#include "view/main_window.h"

#include <QPainter>

MainWindow::MainWindow(Model* model) : model_(model)
{
    setFixedSize(240, 300);

    int bricksCounter = 0;

    for(int row = 0; row < GameParameters::ROWS_COUNT; row++)
    {
        for(int column = 0; column < GameParameters::COLUMNS_COUNT; column++)
        {
            bricks_[bricksCounter] = new Brick(column * GameParameters::BRICK_WIDTH, row * GameParameters::BRICK_HEIGHT);
            ++bricksCounter;
        }
    }
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
}

MainWindow::~MainWindow()
{
    for(const auto& brick : bricks_)
    {
        delete brick;
    }
}
