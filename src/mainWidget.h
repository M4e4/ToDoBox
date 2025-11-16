#ifndef NAMEWIDGER_H
#define NAMEWIDGER_H

#include <QWidget>

#include "ui/mainWidgetUI.h"
#include "manager/mainWidgetManager.h"





class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget* parent = nullptr);

private:
    MainWidgetUI* ui;
    MainWidgetManager* manager;
};





#endif // NAMEWIDGER_H
