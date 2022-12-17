#pragma once

#include <QColor>

class BrickFactory
{
public:
    struct Parameters
    {
        int x_{};
        int y_{};
        QColor color_;
    };

    Parameters generateBrickConstructorParameters(int column, int row);

private:
    const std::vector<QColor> COLORS = {Qt::red, QColor{"orange"}, Qt::green, Qt::yellow, Qt::cyan};
};
