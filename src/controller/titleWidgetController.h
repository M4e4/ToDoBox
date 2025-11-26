#ifndef TITLEWIDGETCONTROLLER_H
#define TITLEWIDGETCONTROLLER_H

#include <QObject>

#include "../view/titleWidgetView.h"





class TitleWidgetController : public QObject
{
    Q_OBJECT
public:
    TitleWidgetController(TitleWidgetView *view, QObject* parent = nullptr);

private:
    void setupConnections();

private:
    TitleWidgetView* view;
};





#endif // TITLEWIDGETCONTROLLER_H
