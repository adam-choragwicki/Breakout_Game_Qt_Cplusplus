#include "breakout.h"
#include "model.h"

Breakout::Breakout()
{
    model_ = std::make_unique<Model>();
    view_ = std::make_unique<MainWindow>(model_.get());
    controller_ = std::make_unique<Controller>(model_.get(), view_.get());

    view_->show();
}
