#ifndef CONTENTWIDGETCONTROLLER_H
#define CONTENTWIDGETCONTROLLER_H

#include <QObject>
#include <QKeyEvent>

#include "../model/contentWidgetModel.h"
#include "../view/contentWidgetView.h"





class ContentWidgetController : public QObject
{
    Q_OBJECT
public:
    ContentWidgetController(ContentWidgetModel* model, ContentWidgetView* view, QObject *parent = nullptr);

private:
    void setupConnections();

private:
    ContentWidgetModel* model;
    ContentWidgetView* view;
};





#endif // CONTENTWIDGETCONTROLLER_H
