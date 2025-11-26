#include "backgroundWidgetController.h"





BackgroundWidgetController::BackgroundWidgetController(BackgroundWidgetView *view, QObject *parent)
    :   QObject{parent},
        view{view}
{
    setupConnections();
}





void BackgroundWidgetController::setupConnections()
{
    connect(view->title, &TitleWidget::clickedMaximize, this, [this]()
    {
        view->setMaximizeStyle();
    });
}
