#ifndef TOPWIDGET_H
#define TOPWIDGET_H

#include <QWidget>
#include <QPushButton>





class TopWidget : public QWidget
{
    Q_OBJECT
public:
    TopWidget();

signals:
    void buttonClose();
    void buttonMinimize();
    void buttonMaximize();
};

#endif // TOPWIDGET_H
