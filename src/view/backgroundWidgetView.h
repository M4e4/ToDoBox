#ifndef BACKGROUNDWIDGETVIEW_H
#define BACKGROUNDWIDGETVIEW_H

#include <QWidget>

#include "../titleWidget.h"
#include "../contentWidget.h"





class BackgroundWidgetView : public QWidget
{
    Q_OBJECT
public:
    BackgroundWidgetView(QWidget* parent = nullptr);

public:
    TitleWidget* title;
    ContentWidget* content;

public slots:
    void setMaximizeStyle();

private:
    void setupView();
};





#endif // BACKGROUNDWIDGETVIEW_H
