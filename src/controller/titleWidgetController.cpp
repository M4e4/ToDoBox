#include "titleWidgetController.h"





TitleWidgetController::TitleWidgetController(TitleWidgetView *view, QObject *parent)
    :   QObject{parent},
        view{view}
{
    setupConnections();
}





void TitleWidgetController::setupConnections()
{
    // Minimize.
    connect(view, &TitleWidgetView::clickedMinimize, this, [this]()
    {
        view->window()->showMinimized();
    });

    // Maximize.
    connect(view, &TitleWidgetView::clickedMaximize, this, [this]()
    {
        view->setMaximizeStyle(view->window()->isMaximized());
    });

    // Close.
    connect(view, &TitleWidgetView::clickedClose, this, [this]()
    {
        view->window()->close();
    });
}
