#ifndef LISTITEM_H
#define LISTITEM_H

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

class ListItem : public QListWidget
{
    Q_OBJECT
public:
    ListItem();

    void newItem();
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
constexpr int toInt(const T cast)
{
    return static_cast<int>(cast);
}

template<typename T>
T getItemWidget(QListWidget* list, QListWidgetItem* item)
{
    return qobject_cast<T>(list->itemWidget(item));
}

#endif // LISTITEM_H
