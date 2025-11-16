#ifndef APPROVEDWIDGET_H
#define APPROVEDWIDGET_H

#include "listTask.h"

#include <QWidget>
#include <QListWidgetItem>





class ApprovedWidget : public QWidget
{
    Q_OBJECT
public:
    ApprovedWidget(ListTask* list, QListWidgetItem* item, QWidget* parent = nullptr);
};





#endif // APPROVEDWIDGET_H
