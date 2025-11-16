#include "mainWidgetUI.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>

#include "../titleWidget.h"
#include "../contentWidget.h"





MainWidgetUI::MainWidgetUI(QWidget *parent)
    : QWidget{parent}
{
    setupUI();
}





void MainWidgetUI::setupUI()
{
    setMouseTracking(true);
    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet("MainWidgetUI {background: #2a2a2a; border-radius: 10px;}");

    // Layouts.
    QVBoxLayout* vLayout = new QVBoxLayout(this);

    title = new TitleWidget(this);
    content = new ContentWidget(this);





    vLayout->setContentsMargins(0,0,0,0);

    vLayout->addWidget(title);
    vLayout->addWidget(content);
}
