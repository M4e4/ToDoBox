#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>

#include "view/titleWidgetView.h"
#include "controller/titleWidgetController.h"





class TitleWidget : public QWidget
{
    Q_OBJECT
public:
    TitleWidget(QWidget* parent = nullptr);

private:
    TitleWidgetView* view;
    TitleWidgetController* controller;

signals:
    void clickedMaximize();
};





#endif // TITLEWIDGET_H
