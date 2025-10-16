#ifndef FRAMEWIDGET_H
#define FRAMEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QSize>
#include <QPoint>





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

    void updateNormalSize();

    QSize getNormalSize();
    QPoint getNormalPosition();

private:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void changeEvent(QEvent* event) override;

    void updateCursor(const QPoint& pos);
    void resizeWindow(const QPoint& position);

    int EDGE_MARGIN {20};

    bool dragging {false};
    bool resizing {false};
    bool wasMaximized {false};

    ResizeRegion currentRegion {ResizeRegion::NONE};
    ResizeRegion getRegion(const QPoint& pos);

    QPoint offsetPos;
    QPoint resizePos;

    QSize normalSize;
    QPoint normalPosition;
};

#endif // FRAMEWIDGET_H
