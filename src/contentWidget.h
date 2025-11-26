#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include <QWidget>

#include "model/TaskListModel.h"
#include "view/contentWidgetView.h"
#include "controller/contentWidgetController.h"





class ContentWidget : public QWidget
{
    Q_OBJECT
public:
    ContentWidget(QWidget* parent = nullptr);

private:
    ContentWidgetModel* model;
    ContentWidgetView* view;
    ContentWidgetController* controller;
};





#endif // CONTENTWIDGET_H
