#include "taskListProxyModel.h"
#include "../utils/utils.h"





TaskListProxyModel::TaskListProxyModel(QObject *parent)
    :   QSortFilterProxyModel{parent}
{

}





void TaskListProxyModel::setFilterText(const QString &text)
{
    if (filterText == text)
    {
        return;
    }

    filterText = text;

    invalidateFilter();
}





void TaskListProxyModel::setFilterStatus(Status status)
{
    filterStatus = status;
    useStatusFilter = true;
    invalidateFilter();
}





bool TaskListProxyModel::filterAcceptsRow(int row, const QModelIndex &parent) const
{
    QModelIndex item {sourceModel()->index(row, 0, parent)};
    QString title {sourceModel()->data(item, toInt(Role::TITLE)).toString()};
    Status status {static_cast<Status>(sourceModel()->data(item, toInt(Role::F_STATUS)).toInt())};

    if (!filterText.isEmpty() && !title.contains(filterText, Qt::CaseInsensitive))
    {
        return false;
    }

    if (useStatusFilter && status != filterStatus)
    {
        return false;
    }

    return true;
}
