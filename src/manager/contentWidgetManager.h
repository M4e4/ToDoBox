#ifndef CONTENTWIDGETMANAGER_H
#define CONTENTWIDGETMANAGER_H

#include <QObject>
#include <QCloseEvent>
#include <QKeyEvent>

#include "../ui/contentWidgetUI.h"





class ContentWidgetManager : public QObject
{
    Q_OBJECT
public:
    ContentWidgetManager(ContentWidgetUI* ui, QObject *parent = nullptr);

private:
    void setupConnections();
    void handleCloseEvent(QCloseEvent* event);
    void handleKeyPressEvent(QKeyEvent* event);

private:
    ContentWidgetUI* ui;
};





#endif // CONTENTWIDGETMANAGER_H
