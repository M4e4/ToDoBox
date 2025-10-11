#ifndef EDITINGWIDGET_H
#define EDITINGWIDGET_H

#include "listitem.h"

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>





class EditingWidget : public QWidget
{
    Q_OBJECT
public:
    EditingWidget(ListItem *list, QListWidgetItem *item, QWidget* parent = nullptr);
};

#endif // EDITINGWIDGET_H
