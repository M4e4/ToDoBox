#include "titleWidget.h"

#include <QVBoxLayout>

#include "ui/titleWidgetUI.h"
#include "manager/titleWidgetManager.h"





TitleWidget::TitleWidget(QWidget* parent)
    : QWidget{parent}
{
    setMouseTracking(true);

    ui = new TitleWidgetUI(this);
    manager = new TitleWidgetManager(ui, this);

    setLayout(new QVBoxLayout(this));

    layout()->setContentsMargins(0,0,0,0);

    layout()->addWidget(ui);

    connect(ui, &TitleWidgetUI::clickedMaximize, this, &TitleWidget::clickedMaximize);
}
