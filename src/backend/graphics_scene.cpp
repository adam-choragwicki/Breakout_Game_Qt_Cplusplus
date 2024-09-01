#include "graphics_scene.h"
#include "config_prod.h"

GraphicsScene::GraphicsScene() : QGraphicsScene(0, 0, ConfigProd::Arena::WIDTH, ConfigProd::Arena::HEIGHT)
{
    connect(this, &GraphicsScene::changed, this, &GraphicsScene::updateDirtyRegion);
}

void GraphicsScene::updateDirtyRegion(const QList<QRectF>& dirtyRegion)
{
    for(const QRectF& rect : dirtyRegion)
    {
        dirtyRegions_.append(rect);
    }
}
