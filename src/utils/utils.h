#ifndef UTILS_H
#define UTILS_H

#include <QListWidget>
#include <QListWidgetItem>

template<typename T>
constexpr int toInt(const T cast)
{
    return static_cast<int>(cast);
}

template<typename T = QWidget*>
T getItemWidget(QListWidget* list, QListWidgetItem* item)
{
    return qobject_cast<T>(list->itemWidget(item));
}

constexpr int itemHeight {30};
constexpr int itemSpacing {2};
inline const QString& dateFormat()
{
    static const QString format {"dd.MM.yyyy"};
    return format;
}

#endif // UTILS_H
