#ifndef TASKLISTCONTROLLER_H
#define TASKLISTCONTROLLER_H

#include <QObject>
#include <QSortFilterProxyModel>

#include "../view/taskListView.h"
#include "../model/taskListModel.h"





class TaskListController : public QObject
{
    Q_OBJECT
public:
    TaskListController(TaskListModel* model, TaskListView* view, QObject *parent = nullptr);

private:
    void setupConnections();

private:
    TaskListModel* model;
    TaskListView* view;
    QSortFilterProxyModel* proxy;
};





#endif // TASKLISTCONTROLLER_H
