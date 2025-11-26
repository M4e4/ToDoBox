#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDateTime>





enum class Status
{
    ACTUAL,
    OVERDUE,
    QUEUE,
    COMPLETE
};





enum class Role
{
    B_STATUS = Qt::UserRole,
    F_STATUS,
    TITLE,
    DATE,
    COUNT
};





struct Task
{
    Status bStatus;
    Status fStatus;
    QString title;
    QDate date;
};





#endif // TASK_H
