#ifndef TASKLISTVIEW_H
#define TASKLISTVIEW_H

#include <QListView>





class TaskListView : public QListView
{
    Q_OBJECT
public:
    TaskListView(QWidget* parent);

public:
    void setupView();
};





#endif // TASKLISTVIEW_H
