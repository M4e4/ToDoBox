#include "framewidget.h"
#include "mainwidget.h"





FrameWidget::FrameWidget(QWidget* parent) : QWidget{parent}
{
    setAttribute(Qt::WA_MouseTracking, true);
}





void FrameWidget::mousePressEvent(QMouseEvent *event)
{
    if (isMaximized()) return;

    if (event->button() == Qt::LeftButton)
    {
        currentRegion = getRegion(event->pos());

        if (toInt(currentRegion))
        {
            resizing = true;
            resizePos = event->globalPosition().toPoint();
            return;
        }

        dragging = true;
        offsetPos = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}





void FrameWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (isMaximized()) return;

    if (resizing)
    {
        resizeWindow(event->globalPosition().toPoint());
        event->accept();
        return;
    }

    updateCursor(event->pos());

    if (dragging && (event->buttons() & Qt::LeftButton))
    {
        move(event->globalPosition().toPoint() - offsetPos);
        event->accept();
    }
}





void FrameWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    dragging = false;
    resizing = false;
}





void FrameWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);

    unsetCursor();
}





ResizeRegion FrameWidget::getRegion(const QPoint &pos)
{
    int x {pos.x()};
    int y {pos.y()};
    int w {width()};
    int h {height()};

    bool left = x <= EDGE_MARGIN;
    bool right = x >= w - EDGE_MARGIN;
    bool top = y <= EDGE_MARGIN;
    bool bot = y >= h - EDGE_MARGIN;

    if (top && left)  return ResizeRegion::TOPLEFT;
    if (top && right) return ResizeRegion::TOPRIGHT;
    if (bot && left)  return ResizeRegion::BOTTOMLEFT;
    if (bot && right) return ResizeRegion::BOTTOMRIGHT;
    if (left)  return ResizeRegion::LEFT;
    if (right) return ResizeRegion::RIGHT;
    if (top)   return ResizeRegion::TOP;
    if (bot)   return ResizeRegion::BOTTOM;

    return ResizeRegion::NONE;
}





void FrameWidget::updateCursor(const QPoint &pos)
{
    ResizeRegion region {getRegion(pos)};

    switch (toInt(region))
    {
    case toInt(ResizeRegion::LEFT):
    case toInt(ResizeRegion::RIGHT):
        setCursor(Qt::SizeHorCursor);
        break;
    case toInt(ResizeRegion::TOP):
    case toInt(ResizeRegion::BOTTOM):
        setCursor(Qt::SizeVerCursor);
        break;
    case toInt(ResizeRegion::TOPLEFT):
    case toInt(ResizeRegion::BOTTOMRIGHT):
        setCursor(Qt::SizeFDiagCursor);
        break;
    case toInt(ResizeRegion::TOPRIGHT):
    case toInt(ResizeRegion::BOTTOMLEFT):
        setCursor(Qt::SizeBDiagCursor);
        break;
    default:
        unsetCursor();
        break;
    }
}





void FrameWidget::resizeWindow(const QPoint &position)
{
    QRect geom {geometry()};
    QPoint delta {position - resizePos};
    resizePos = position;

    switch (toInt(currentRegion))
    {
    case toInt(ResizeRegion::LEFT):
        geom.setLeft(geom.left() + delta.x());
        break;
    case toInt(ResizeRegion::RIGHT):
        geom.setRight(geom.right() + delta.x());
        break;
    case toInt(ResizeRegion::TOP):
        geom.setTop(geom.top() + delta.y());
        break;
    case toInt(ResizeRegion::BOTTOM):
        geom.setBottom(geom.bottom() + delta.y());
        break;
    case toInt(ResizeRegion::TOPLEFT):
        geom.setTopLeft(geom.topLeft() + delta);
        break;
    case toInt(ResizeRegion::TOPRIGHT):
        geom.setTopRight(geom.topRight() + delta);
        break;
    case toInt(ResizeRegion::BOTTOMLEFT):
        geom.setBottomLeft(geom.bottomLeft() + delta);
        break;
    case toInt(ResizeRegion::BOTTOMRIGHT):
        geom.setBottomRight(geom.bottomRight() + delta);
        break;
    }

    setGeometry(geom);
}
