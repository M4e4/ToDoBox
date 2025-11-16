#ifndef MAINWIDGETUI_H
#define MAINWIDGETUI_H

#include <QWidget>
#include <QEvent>

#include "../titleWidget.h"
#include "../contentWidget.h"





class MainWidgetUI : public QWidget
{
    Q_OBJECT
public:
    MainWidgetUI(QWidget* parent = nullptr);

public:
    TitleWidget* title;
    ContentWidget* content;

private:
    void setupUI();
};





#endif // MAINWIDGETUI_H
