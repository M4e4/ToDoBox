#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>

#include "ui/titleWidgetUI.h"
#include "manager/titleWidgetManager.h"





class TitleWidget : public QWidget
{
    Q_OBJECT
public:
    TitleWidget(QWidget* parent = nullptr);

private:
    TitleWidgetUI* ui;
    TitleWidgetManager* manager;

signals:
    void clickedMaximize();
};





#endif // TITLEWIDGET_H
