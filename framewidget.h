#ifndef FRAMEWIDGET_H
#define FRAMEWIDGET_H

#include <QWidget>
#include <QMouseEvent>





enum class ResizeRegion
{
    NONE,
    LEFT,
    RIGHT,
    TOP,
    BOTTOM,
    TOPLEFT,
    TOPRIGHT,
    BOTTOMLEFT,
    BOTTOMRIGHT,
    COUNT
};

class FrameWidget : public QWidget
{
    Q_OBJECT
public:
    FrameWidget(QWidget* parent = nullptr);

private:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void leaveEvent(QEvent* event) override;

    void updateCursor(const QPoint& pos);
    void resizeWindow(const QPoint& position);

    int EDGE_MARGIN {20};

    bool dragging {false};
    bool resizing {false};

    ResizeRegion currentRegion {ResizeRegion::NONE};
    ResizeRegion getRegion(const QPoint& pos);

    QPoint offsetPos;
    QPoint resizePos;
};

#endif // FRAMEWIDGET_H
