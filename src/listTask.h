#ifndef LISTTASK_H
#define LISTTASK_H

#include <QListWidget>
#include <QString>
#include <QIcon>
#include <QColor>
#include <QLabel>
#include <QVector>

constexpr int itemHeight {30};
constexpr int itemSpacing {2};
inline const QString& dateFormat()
{
    static const QString format {"dd.MM.yyyy"};
    return format;
}




enum class Status
{
    ACTUAL,
    OVERDUE,
    QUEUE,
    COMPLETE,
    COUNT
};

enum class Sort
{
    DATE,
    STATUS,
    ALPHABET,
    COUNT
};

enum class Role
{
    B_STATUS = Qt::UserRole,
    F_STATUS,
    TITLE,
    DATE,
    COUNT
};





class ListTask : public QListWidget
{
    Q_OBJECT
public:
    ListTask();

    void newTask();
    void setSelectedStyle(QListWidgetItem* item, bool selected);
    void filter(QString text, Status status);
    void sort(int type);
    void save();
    void load();

    QIcon getIcon(Status status);

private:
    QVector<QIcon> icons;
};





template<typename T>
T getItemWidget(QListWidget* list, QListWidgetItem* item)
{
    return qobject_cast<T>(list->itemWidget(item));
}





#endif // LISTTASK_H
