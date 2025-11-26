#include "taskListModel.h"
#include "task.h"
#include "../utils/utils.h"





TaskListModel::TaskListModel(QObject* parent)
    :   QAbstractListModel{parent}
{

}





int TaskListModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
    {
        return 0;
    }

    return tasks.size();
}





QVariant TaskListModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    int row{index.row()};

    if (row < 0 || row >= tasks.size())
    {
        return QVariant();
    }

    const Task& task{tasks[row]};

    switch (role)
    {
    case toInt(Role::B_STATUS) :
        return static_cast<int>(task.bStatus);

    case toInt(Role::F_STATUS) :
        return static_cast<int>(task.fStatus);

    case toInt(Role::TITLE) :
        return task.title;

    case toInt(Role::DATE) :
        return task.date.toString("dd.MM.yyyy");
    }

    return QVariant();
}





bool TaskListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
    {
        return false;
    }

    int row{index.row()};

    if (row < 0 || row >= tasks.size())
    {
        return false;
    }

    Task& task{tasks[row]};

    switch (role)
    {
    case toInt(Role::B_STATUS) :
        task.bStatus = static_cast<Status>(value.toInt());
        break;

    case toInt(Role::F_STATUS) :
        task.fStatus = static_cast<Status>(value.toInt());
        break;

    case toInt(Role::TITLE) :
        task.title = value.toString();
        break;

    case toInt(Role::DATE) :
        task.date = QDate::fromString(value.toString(), "dd.MM.yyyy");
        break;

    default:
        return false;
    }

    emit dataChanged(index, index, {role});

    return true;
}





Qt::ItemFlags TaskListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::NoItemFlags;
    }

    return Qt::ItemIsEnabled |
           Qt::ItemIsSelectable |
           Qt::ItemIsEditable;
}





void TaskListModel::addTask(const QString &title)
{
    int row = tasks.size();

    beginInsertRows(QModelIndex(), row, row);

    tasks.push_back(
    {
        Status::QUEUE,
        Status::QUEUE,
        title,
        QDate::currentDate()
    });

    endInsertRows();
}





void TaskListModel::removeTask(int row)
{
    if (row < 0 || row >= tasks.size())
    {
        return;
    }

    beginRemoveRows(QModelIndex(), row, row);

    tasks.removeAt(row);

    endRemoveRows();
}
