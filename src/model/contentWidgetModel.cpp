#include "contentWidgetModel.h"

ContentWidgetModel::ContentWidgetModel(QObject* parent)
    :   QObject{parent},
        taskListModel{new TaskListModel()}
{

}
