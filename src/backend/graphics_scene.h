#pragma once

#include <QtWidgets/QGraphicsScene>

class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene();

    [[nodiscard]] QList<QRectF>& getDirtyRegions()
    { return dirtyRegions_; }

private slots:
    void updateDirtyRegion(const QList<QRectF>& dirtyRegion);

private:
    QList<QRectF> dirtyRegions_;
};
