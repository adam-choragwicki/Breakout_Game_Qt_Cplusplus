#pragma once

#include "model/model.h"
#include "view/main_window.h"
#include "controller.h"

#include <memory>

class Breakout
{
public:
    Breakout();

private:
    std::unique_ptr<Model> model_;
    std::unique_ptr<MainWindow> view_;
    std::unique_ptr<Controller> controller_;
};
