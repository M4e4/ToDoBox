#include "mainWidget.h"

#include "utils/utils.h"





MainWidget::MainWidget(QWidget *parent)
    :   QWidget{parent}
{
    setFocusPolicy(Qt::NoFocus);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_MouseTracking, true);
    setAttribute(Qt::WA_TranslucentBackground);

    updateNormalSize();
    updateNormalPosition();
}





ResizeRegion MainWidget::getRegion(const QPoint &pos)
{
    int x {pos.x()};
    int y {pos.y()};
    int w {width()};
    int h {height()};

    bool left  = x <= EDGE_MARGIN;
    bool right = x >= w - EDGE_MARGIN;
    bool top   = y <= EDGE_MARGIN;
    bool bot   = y >= h - EDGE_MARGIN;

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





void MainWidget::updateCursor(const QPoint &pos)
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





void MainWidget::resizeWindow(const QPoint &position)
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

    updateNormalSize();
}





void MainWidget::mousePressEvent(QMouseEvent *event)
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





void MainWidget::mouseMoveEvent(QMouseEvent *event)
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

    updateNormalPosition();
}





void MainWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    dragging = false;
    resizing = false;
}





void MainWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);

    unsetCursor();
}




void MainWidget::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::WindowStateChange)
    {
        QWindowStateChangeEvent *stateEvent = static_cast<QWindowStateChangeEvent *>(event);

        Qt::WindowStates oldState = stateEvent->oldState();
        Qt::WindowStates newState = windowState();

        if ((oldState & Qt::WindowMaximized) && (newState & Qt::WindowMinimized))
        {
            wasMaximized = true;
        }

        else if ((oldState & Qt::WindowMinimized) && !(newState & Qt::WindowMinimized) && wasMaximized)
        {
            showMaximized();
        }

        else if ((oldState & Qt::WindowMaximized) &&
                 !(newState & Qt::WindowMaximized) &&
                 !(newState & Qt::WindowMinimized))
        {
            resize(normalSize);
            move(normalPosition);
            wasMaximized = false;
        }
    }

    QWidget::changeEvent(event);
}





void MainWidget::closeEvent(QCloseEvent *event)
{
    emit aboutToClose();

    QWidget::closeEvent(event);
}





void MainWidget::updateNormalPosition()
{
    normalPosition = pos();
}

void MainWidget::updateNormalSize()
{
    normalSize = size();
}

QPoint MainWidget::getNormalPosition()
{
    return normalPosition;
}

QSize MainWidget::getNormalSize()
{
    return normalSize;
}
