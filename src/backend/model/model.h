#pragma once

#include "graphics_scene.h"
#include "brick.h"
#include "paddle.h"
#include "ball.h"
#include "bricks_manager.h"
#include "screen_text_display.h"
#include "arena_boundary.h"
#include <memory>
#include <QTimer>

class Model
{
public:
    Model();
    void reset();

    [[nodiscard]] GraphicsScene* getScene() const
    { return scene_.get(); }

    [[nodiscard]] const BricksManager& getBricksManager() const
    { return *bricksManager_; }

    [[nodiscard]] BricksManager& getBricksManager()
    { return *bricksManager_; }

    [[nodiscard]] const Paddle& getPaddle() const
    { return *paddle_; }

    [[nodiscard]] Paddle& getPaddle()
    { return *paddle_; }

    [[nodiscard]] const Ball& getBall() const
    { return *ball_; }

    [[nodiscard]] Ball& getBall()
    { return *ball_; }

    [[nodiscard]] const ScreenTextDisplay& getScreenTextDisplay() const
    { return *screenTextDisplay_; }

    [[nodiscard]] ScreenTextDisplay& getScreenTextDisplay()
    { return *screenTextDisplay_; }

    [[nodiscard]] const std::vector<ArenaBoundary*>& getWorldBoundaries() const
    { return worldBoundaries_; }

private:
    void addItemsToScene();
    void addBricksToScene();

    void initWorldBoundaries();

    std::unique_ptr<GraphicsScene> scene_;

    std::vector<ArenaBoundary*> worldBoundaries_{};
    std::unique_ptr<BricksManager> bricksManager_;
    std::unique_ptr<Paddle> paddle_;
    std::unique_ptr<Ball> ball_;

    std::unique_ptr<ScreenTextDisplay> screenTextDisplay_;
};
