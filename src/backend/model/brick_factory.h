#pragma once

#include <QColor>

class BrickFactory
{
public:
    struct Parameters
    {
        int x_{};
        int y_{};
        unsigned int id_{};
        QColor color_;
    };

    Parameters generateBrickConstructorParameters(int column, int row);

private:
    unsigned int count_ = 0;
};
