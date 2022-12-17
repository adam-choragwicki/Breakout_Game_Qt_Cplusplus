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

    [[nodiscard]] BricksManager& getBricksManager()
    { return *bricksManager_; }

    [[nodiscard]] Paddle& getPaddle()
    { return *paddle_; }

    [[nodiscard]] Ball& getBall()
    { return *ball_; }

    [[nodiscard]] ScreenTextDisplay& getScreenTextDisplay()
    { return *screenTextDisplay_; }

    [[nodiscard]] ArenaBoundary* getLeftArenaBoundary() const
    { return leftArenaBoundary_; }

    [[nodiscard]] ArenaBoundary* getRightArenaBoundary() const
    { return rightArenaBoundary_; }

    [[nodiscard]] ArenaBoundary* getTopArenaBoundary() const
    { return topArenaBoundary_; }

    [[nodiscard]] ArenaBoundary* getBottomArenaBoundary() const
    { return bottomArenaBoundary_; }

private:
    void addItemsToScene();
    void addBricksToScene();

    void initWorldBoundaries();

    std::unique_ptr<GraphicsScene> scene_;

    ArenaBoundary* leftArenaBoundary_{};
    ArenaBoundary* rightArenaBoundary_{};
    ArenaBoundary* topArenaBoundary_{};
    ArenaBoundary* bottomArenaBoundary_{};

    std::unique_ptr<BricksManager> bricksManager_;
    std::unique_ptr<Paddle> paddle_;
    std::unique_ptr<Ball> ball_;

    std::unique_ptr<ScreenTextDisplay> screenTextDisplay_;
};
