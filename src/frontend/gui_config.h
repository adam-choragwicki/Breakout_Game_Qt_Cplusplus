#pragma once

#include <QColor>

namespace GuiConfig
{
    namespace Paddle
    {
        const QColor PEN_OUTLINE(Qt::black);
        const QColor COLOR(Qt::blue);

        const int ROUNDED_RECT_WIDTH_RATIO_PERCENTAGE = 25;
        const int ROUNDED_RECT_HEIGHT_RATIO_PERCENTAGE = 75;
    }

    namespace Ball
    {
        const QColor PEN_OUTLINE(Qt::black);
        const QColor COLOR(Qt::white);
    }
}
