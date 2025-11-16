#ifndef MAINWIDGETMANAGER_H
#define MAINWIDGETMANAGER_H

#include <QObject>
#include <QEvent>

#include "../ui/mainWidgetUI.h"





class MainWidgetManager : public QObject
{
public:
    MainWidgetManager(MainWidgetUI* ui, QObject* parent = nullptr);

private:
    void setupConnection();

private:
    MainWidgetUI* ui;
};





#endif // MAINWIDGETMANAGER_H
