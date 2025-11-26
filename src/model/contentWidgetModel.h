#ifndef CONTENTWIDGETMODEL_H
#define CONTENTWIDGETMODEL_H

#include <QObject>

#include "taskListModel.h"





class ContentWidgetModel : public QObject
{
    Q_OBJECT
public:
    ContentWidgetModel(QObject *parent = nullptr);

private:
    TaskListModel* taskListModel;
};





#endif // CONTENTWIDGETMODEL_H
