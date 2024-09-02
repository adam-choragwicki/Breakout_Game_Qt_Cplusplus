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
    void fpsCountUpdateEvent(int fpsCount);

public:
    explicit GraphicsView(GraphicsScene* scene, QWidget* parent = nullptr);

    void drawForeground(QPainter* painter, const QRectF& rect) override;
    bool eventFilter(QObject* obj, QEvent* event) override;

    //    void updateViewport(const QList<QRectF>& dirtyRegions);
    void updateViewport();

    void leaveEvent(QEvent* event) override;

private slots:
    void updateFPS();

private:
    void mouseMoveEvent(QMouseEvent* event) override;

    QTimer fpsTimer_;
    QElapsedTimer frameTimeTimer_;
    int frameCount_{};
    double currentFPS_{};

    QPoint lastMousePositionOnScreen_;
};
