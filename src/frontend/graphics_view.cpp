#include "graphics_view.h"
#include "graphics_scene.h"
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>

GraphicsView::GraphicsView(GraphicsScene* scene, QWidget* parent) : QGraphicsView(scene, parent)
{
    setViewportUpdateMode(QGraphicsView::NoViewportUpdate);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setRenderHint(QPainter::Antialiasing, true);

    connect(&fpsTimer_, &QTimer::timeout, this, &GraphicsView::updateFPS);

    /* Update FPS every 500m */
    fpsTimer_.start(500);
    frameTimeTimer_.start();

    initializePainterData();

    viewport()->installEventFilter(this);

    QPoint screenCenter = screen()->geometry().center();
    QCursor::setPos(screenCenter);

    lastMousePositionOnScreen_ = QCursor::pos();

    qDebug() << "Placing cursor initially on " << screenCenter;
}

void GraphicsView::mouseMoveEvent(QMouseEvent* event)
{
    //    QPoint mousePosition = event->pos();
    QPoint mousePosition = event->pos();
    QPoint mouseGlobalPosition = QCursor::pos();// event->globalPosition();

//    qDebug() << "Mouse position: " << mousePosition;

    lastMousePositionOnScreen_ = mouseGlobalPosition;

    emit(mouseMovedEvent(event->pos().x()));
}

void GraphicsView::leaveEvent(QEvent* event)
{
    /* Restrict cursor movement */
    QCursor::setPos(lastMousePositionOnScreen_);
}

void GraphicsView::drawForeground(QPainter* painter, const QRectF& rect)
{
    QGraphicsView::drawForeground(painter, rect);
    ++frameCount_;
}

void GraphicsView::updateFPS()
{
    qint64 elapsed = frameTimeTimer_.elapsed();
    currentFPS_ = (frameCount_ * 1000.0) / elapsed;

    emit fpsCountUpdateEvent(qRound(currentFPS_));

    frameCount_ = 0;
    frameTimeTimer_.restart();
}

bool GraphicsView::eventFilter(QObject* obj, QEvent* event)
{
    if(event->type() == QEvent::Wheel)
    {
        /* Ignore mouse wheel events to disable scene scrolling */
        return true;
    }

    return QGraphicsView::eventFilter(obj, event);
}

void GraphicsView::initializePainterData()
{
    fpsCounterFont_.setFamily("Arial");
    fpsCounterFont_.setPointSize(20);
    fpsCounterFont_.setBold(true);

    fpsCounterPen_.setColor(Qt::red);
}

void GraphicsView::updateViewport()
{
    viewport()->update();
}

//void GraphicsView::updateViewport(const QList<QRectF>& dirtyRegions)
//{
//    for(const QRectF& rect : dirtyRegions)
//    {
//        viewport()->update(rect.toRect());
//    }
//}
