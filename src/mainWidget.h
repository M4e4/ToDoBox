#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QCloseEvent>
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





class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget* parent = nullptr);

public:
    void updateNormalPosition();
    void updateNormalSize();

    QPoint getNormalPosition();
    QSize getNormalSize();

private:
    ResizeRegion getRegion(const QPoint& pos);

    void updateCursor(const QPoint& pos);
    void resizeWindow(const QPoint& position);

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void changeEvent(QEvent* event) override;
    void closeEvent(QCloseEvent* event) override;

private:
    ResizeRegion currentRegion {ResizeRegion::NONE};

    bool dragging {false};
    bool resizing {false};
    bool wasMaximized {false};
    int EDGE_MARGIN {20};

    QPoint offsetPos;
    QPoint resizePos;
    QPoint normalPosition;
    QSize normalSize;

signals:
    void aboutToClose();
};





#endif // MAINWIDGET_H
