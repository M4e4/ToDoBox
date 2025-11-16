#include "contentWidget.h"

#include <QVBoxLayout>

#include "ui/contentWidgetUI.h"
#include "manager/contentWidgetManager.h"





ContentWidget::ContentWidget(QWidget *parent)
    : QWidget{parent}
{
    setMouseTracking(true);

    ui = new ContentWidgetUI(this);
    manager = new ContentWidgetManager(ui, this);

    setLayout(new QVBoxLayout(this));

    layout()->setContentsMargins(0,0,0,0);

    layout()->addWidget(ui);
}
