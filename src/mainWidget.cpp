#include "mainWIdget.h"

#include <QVBoxLayout>

#include "titleWidget.h"
#include "contentWidget.h"





MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    setMouseTracking(true);

    ui = new MainWidgetUI(this);
    manager = new MainWidgetManager(ui, this);

    setLayout(new QVBoxLayout(this));

    layout()->setContentsMargins(0,0,0,0);

    layout()->addWidget(ui);
}
