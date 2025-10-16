#ifndef TOPWIDGET_H
#define TOPWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>





class TopWidget : public QWidget
{
    Q_OBJECT
public:
    TopWidget();

    QPushButton* buttonClose;

private:
    void mouseDoubleClickEvent(QMouseEvent* event) override;

signals:
    void pushClose();
    void pushMinimize();
    void pushMaximize();

};

#endif // TOPWIDGET_H
