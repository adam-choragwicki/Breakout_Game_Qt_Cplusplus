#pragma once

#include "model/custom_graphics_item.h"

class WorldBoundary : public CustomGraphicsItem
{
public:
    WorldBoundary(int x, int y, int width, int height);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
    bool displayWorldBoundary_{};
};
