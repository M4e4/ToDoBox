#ifndef EDITINGWIDGET_H
#define EDITINGWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>

#include "taskList.h"





class EditingWidget : public QWidget
{
    Q_OBJECT
public:
    EditingWidget(TaskList *list, QListWidgetItem *item, QWidget* parent = nullptr);
};





#endif // EDITINGWIDGET_H
