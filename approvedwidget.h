#ifndef APPROVEDWIDGET_H
#define APPROVEDWIDGET_H

#include "listitem.h"

#include <QWidget>
#include <QListWidgetItem>





class ApprovedWidget : public QWidget
{
    Q_OBJECT
public:
    ApprovedWidget(ListItem* list, QListWidgetItem* item, QWidget* parent = nullptr);
};

#endif // APPROVEDWIDGET_H
