#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include <QWidget>

#include "ui/contentWidgetUI.h"
#include "manager/contentWidgetManager.h"





class ContentWidget : public QWidget
{
    Q_OBJECT
public:
    ContentWidget(QWidget* parent = nullptr);

private:
    ContentWidgetUI* ui;
    ContentWidgetManager* manager;
};





#endif // CONTENTWIDGET_H
