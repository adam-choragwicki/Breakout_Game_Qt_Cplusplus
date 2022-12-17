#pragma once

#include "model.h"
#include "view/main_window.h"

class Controller
{
public:
    Controller(Model* model, MainWindow* view);

private:
    Model* model_;
    MainWindow* view_;
};
