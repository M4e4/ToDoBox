#include "contentWidget.h"

#include <QVBoxLayout>
#include <QTimer>

#include "model/taskListModel.h"
#include "view/contentWidgetView.h"
#include "controller/contentWidgetController.h"





ContentWidget::ContentWidget(QWidget *parent)
    :   QWidget{parent},
        model{new ContentWidgetModel(this)},
        view{new ContentWidgetView(this)},
        controller{new ContentWidgetController(model, view, this)}
{
    setMouseTracking(true);
    setLayout(new QVBoxLayout(this));

    layout()->setContentsMargins(0,0,0,0);
    layout()->addWidget(view);
}
