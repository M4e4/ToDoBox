#ifndef TITLEWIDGETMANAGER_H
#define TITLEWIDGETMANAGER_H

#include <QObject>
#include <QMouseEvent>

#include "../ui/titleWidgetUI.h"





class TitleWidgetManager : public QObject
{
    Q_OBJECT
public:
    TitleWidgetManager(TitleWidgetUI *ui, QObject* parent = nullptr);

private:
    void setupConnection();
    void handleMouseDoubleClickEvent(QMouseEvent* event);

private:
    TitleWidgetUI* ui;
};





#endif // TITLEWIDGETMANAGER_H
