#pragma once

#include <QGraphicsView>
#include <QTimer>
#include <QElapsedTimer>

class QTimer;
class GraphicsScene;

class GraphicsView : public QGraphicsView
{
Q_OBJECT
signals:
    void mouseMovedEvent(int mousePositionX);

public:
    explicit GraphicsView(GraphicsScene* scene, QWidget* parent = nullptr);

    void drawBackground(QPainter* painter, const QRectF& rect) override;
    void drawForeground(QPainter* painter, const QRectF& rect) override;
    bool eventFilter(QObject* obj, QEvent* event) override;

    //    void updateViewport(const QList<QRectF>& dirtyRegions);
    void updateViewport();

private slots:
    void updateFPS();

private:
    void initializePainterData();

    void mouseMoveEvent(QMouseEvent* event) override;

    QTimer fpsTimer_;
    QElapsedTimer frameTimeTimer_;
    int frameCount_{};
    double currentFPS_{};

    QFont fpsCounterFont_;
    QPen fpsCounterPen_;
};
