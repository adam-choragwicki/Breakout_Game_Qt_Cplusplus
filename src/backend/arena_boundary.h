#pragma once

#include "model/custom_graphics_item.h"

class ArenaBoundary : public CustomGraphicsItem
{
public:
    ArenaBoundary(int x, int y, int width, int height);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
    bool displayArenaBoundary_{};
};
