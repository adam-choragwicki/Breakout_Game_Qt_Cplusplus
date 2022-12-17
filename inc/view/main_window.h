#pragma once

#include "model.h"
#include "brick.h"
#include "common.h"
#include "paddle.h"

#include <QMainWindow>

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(Model* model);
    ~MainWindow() override;

private:
    void closeEvent(QCloseEvent*) override;
    void paintEvent(QPaintEvent*) override;

    Model* model_;

    Brick* bricks_[GameParameters::BRICKS_COUNT];
    Paddle* paddle_;
};
