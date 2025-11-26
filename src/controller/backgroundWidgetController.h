#ifndef BACKGROUNDWIDGETCONTROLLER_H
#define BACKGROUNDWIDGETCONTROLLER_H

#include <QObject>

#include "../view/backgroundWidgetView.h"





class BackgroundWidgetController : public QObject
{
    Q_OBJECT
public:
    BackgroundWidgetController(BackgroundWidgetView* view, QObject* parent = nullptr);

private:
    void setupConnections();

private:
    BackgroundWidgetView* view;
};





#endif // BACKGROUNDWIDGETCONTROLLER_H
