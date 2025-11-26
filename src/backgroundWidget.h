#ifndef NAMEWIDGER_H
#define NAMEWIDGER_H

#include <QWidget>

#include "view/backgroundWidgetView.h"
#include "controller/backgroundWidgetController.h"





class BackgroundWidget : public QWidget
{
    Q_OBJECT
public:
    BackgroundWidget(QWidget* parent = nullptr);

private:
    BackgroundWidgetView* view;
    BackgroundWidgetController* controller;
};





#endif // NAMEWIDGER_H
