#include "TaskListController.h"
#include "../model/taskListProxyModel.h"





TaskListController::TaskListController(TaskListModel* model, TaskListView* view, QObject* parent)
    :   QObject{parent},
        model{model},
        view{view},
        proxy{new TaskListProxyModel(this)}
{
    proxy->setSourceModel(model);

    view->setModel(proxy);

    setupConnections();
}





void TaskListController::setupConnections()
{

}
