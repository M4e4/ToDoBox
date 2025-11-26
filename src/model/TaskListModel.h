#ifndef TASKLISTMODEL_H
#define TASKLISTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QVariant>
#include <QVector>

#include "task.h"





class TaskListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    TaskListModel(QObject* parent = nullptr);

private:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void addTask(const QString& title);
    void removeTask(int row);

private:
    QVector<Task> tasks;
};





#endif // TASKLISTMODEL_H
