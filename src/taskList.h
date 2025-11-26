#ifndef TASKLIST_H
#define TASKLIST_H

#include <QWidget>

#include "model/taskListModel.h"
#include "view/taskListView.h"
#include "controller/taskListController.h"





class TaskList : public QWidget
{
    Q_OBJECT
public:
    TaskList(QWidget* parent = nullptr);

private:
    TaskListModel* model;
    TaskListView* view;
    TaskListController* controller;
};





#endif // TASKLIST_H
