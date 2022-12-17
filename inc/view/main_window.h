#pragma once

#include "model.h"

#include <QMainWindow>

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(Model* model);

private:
    void closeEvent(QCloseEvent*) override;

    Model* model_;
};
