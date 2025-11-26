#ifndef TASKLISTPROXYMODEL_H
#define TASKLISTPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QString>

#include "taskListModel.h"





class TaskListProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    TaskListProxyModel(QObject* parent = nullptr);

public:
    void setFilterText(const QString& text);
    void setFilterStatus(Status status);

protected:
    bool filterAcceptsRow(int row, const QModelIndex &source_parent) const override;

private:
    QString filterText;
    Status filterStatus{Status::QUEUE};
    bool useStatusFilter{false};
};





#endif // TASKLISTPROXYMODEL_H
