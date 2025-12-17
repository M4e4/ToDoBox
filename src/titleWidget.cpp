#include "titleWidget.h"

#include <QVBoxLayout>

#include "view/titleWidgetView.h"
#include "controller/titleWidgetController.h"





TitleWidget::TitleWidget(QWidget *parent)
    :   QWidget{parent},
        view{new TitleWidgetView(this)},
        controller{new TitleWidgetController(view, this)}
{
    setMouseTracking(true);
    setLayout(new QVBoxLayout(this));

    layout()->setContentsMargins(0,0,0,0);
    layout()->addWidget(view);

    connect(view, &TitleWidgetView::clickedMaximize, this, &TitleWidget::clickedMaximize);
}
