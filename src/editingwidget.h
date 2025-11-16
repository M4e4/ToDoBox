#ifndef EDITINGWIDGET_H
#define EDITINGWIDGET_H

#include "listTask.h"

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>





class EditingWidget : public QWidget
{
    Q_OBJECT
public:
    EditingWidget(ListTask *list, QListWidgetItem *item, QWidget* parent = nullptr);
};





#endif // EDITINGWIDGET_H
