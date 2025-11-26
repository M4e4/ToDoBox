#ifndef APPROVEDWIDGET_H
#define APPROVEDWIDGET_H

#include "taskList.h"

#include <QWidget>
#include <QListWidgetItem>





class ApprovedWidget : public QWidget
{
    Q_OBJECT
public:
    ApprovedWidget(TaskList* list, QListWidgetItem* item, QWidget* parent = nullptr);
};





#endif // APPROVEDWIDGET_H
