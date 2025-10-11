#include "listitem.h"
#include "editingwidget.h"
#include "approvedwidget.h"

#include <QListWidgetItem>
#include <QDate>
#include <QVector>
#include <QVBoxLayout>
#include <QFile>
#include <QTimer>





ListItem::ListItem() :
    icons {
    QIcon(":/icons/icon-status-actual.png"),
    QIcon(":/icons/icon-status-overdue.png"),
    QIcon(":/icons/icon-status-planned.png"),
    QIcon(":/icons/icon-status-complete.png")}
{
    load();

    QTimer::singleShot(0, this, [this](){ scrollToBottom(); });

    setStyleSheet(R"(ListItem
        {
            background: transparent;
            border: none;
        }
        QListWidget::item
        {
            background: transparent;
            border: none;
        }
        QListWidget:focus {
            outline: none;
        }
        QScrollBar
        {
            width: 12px;
            margin-left: 2px;
            background: transparent;
            border: none;
        }
        QScrollBar::add-page,
        QScrollBar::sub-page,
        QScrollBar::add-line,
        QScrollBar::sub-line
        {
            background: transparent;
            border: none;
        }
        QScrollBar::handle
        {
            background: #555555;
            border-radius: 5px;
        }

        )");
}





void ListItem::newItem()
{
    QListWidgetItem* item {new QListWidgetItem};

    addItem(item);

    item->setSizeHint(QSize(0, itemHeight + itemSpacing));
    item->setBackground(Qt::transparent);
    item->setData(toInt(Role::F_STATUS), toInt(Status::QUEUE));
    item->setData(toInt(Role::DATE), QDate::currentDate().toString(dateFormat()));

    EditingWidget* editWidget {new EditingWidget(this, item)};

    setItemWidget(item, editWidget);
    setCurrentItem(item);
}






void ListItem::setSelectedStyle(QListWidgetItem* item, bool selected)
{
    if(!item) return;

    const QString style = selected ? "ApprovedWidget {background: #555555; border-radius: 5px;}" : "ApprovedWidget {background: #444; border-radius: 5px;}";

    ApprovedWidget* widget {getItemWidget<ApprovedWidget*>(this, item)};

    if (widget) widget->setStyleSheet(style);
}





void ListItem::filter(QString text, Status status)
{
    for (int i{}; i < count(); ++i)
    {
        QListWidgetItem* iItem {item(i)};
        QWidget* iWidget {itemWidget(iItem)};

        iItem->setHidden(false);

        Status iStatus {static_cast<Status>(iItem->data(toInt(Role::F_STATUS)).toInt())};
        QString title {iItem->data(toInt(Role::TITLE)).toString()};

        if (title.trimmed().isEmpty())
        {
            removeItemWidget(iItem);

            delete iWidget;
            delete iItem;

            --i;
        }
        else
        {
            iItem->setHidden(!((iStatus == status || toInt(status) == -1) &&
                            (text.isEmpty() || title.startsWith(text, Qt::CaseInsensitive))));
        }
    }
}





void ListItem::sort(int type)
{
    struct itemEntry
    {
        QListWidgetItem* item;

        bool hidden;
    };

    QVector<itemEntry> visibleItems{};
    QVector<itemEntry> hiddenItems{};

    while (count() > 0)
    {
        bool hidden {item(0)->isHidden()};

        QWidget* iWidget {itemWidget(item(0))};
        QListWidgetItem* iItem {takeItem(0)};
        QString title {iItem->data(toInt(Role::TITLE)).toString()};

        if (title.trimmed().isEmpty())
        {
            delete iItem;
        }
        else
        {
            (hidden ? hiddenItems : visibleItems).append({iItem, hidden});
        }

        if (iWidget) delete iWidget;
    }

    switch (toInt(type))
    {
    case toInt(Sort::DATE) :
    {
        std::sort(visibleItems.begin(), visibleItems.end(), [](const itemEntry& a, const itemEntry& b)
        {
            QDate dateA {QDate::fromString(a.item->data(toInt(Role::DATE)).toString(), dateFormat())};
            QDate dateB {QDate::fromString(b.item->data(toInt(Role::DATE)).toString(), dateFormat())};
            return dateA < dateB;
        });
        break;
    }
    case toInt(Sort::STATUS) :
    {
        std::sort(visibleItems.begin(), visibleItems.end(), [](const itemEntry& a, const itemEntry& b)
        {
            return a.item->data(toInt(Role::F_STATUS)).toInt() > b.item->data(toInt(Role::F_STATUS)).toInt();
        });
        break;
    }
    case toInt(Sort::ALPHABET) :
    {
        std::sort(visibleItems.begin(), visibleItems.end(), [](const itemEntry& a, const itemEntry& b)
        {
            return a.item->data(toInt(Role::TITLE)).toString().toLower() < b.item->data(toInt(Role::TITLE)).toString().toLower();
        });
        break;
    }
    }

    auto restoreEntry {[this](const itemEntry& iItem)
    {
        addItem(iItem.item);

        if (!iItem.item->data(toInt(Role::TITLE)).toString().isEmpty())
        {
            ApprovedWidget* approvedWidget {new ApprovedWidget(this, iItem.item)};

            setItemWidget(iItem.item, approvedWidget);
        }
        else
        {
            EditingWidget* editWidget {new EditingWidget(this, iItem.item)};

            setItemWidget(iItem.item, editWidget);
        }
        iItem.item->setHidden(iItem.hidden);
    }};

    for (const itemEntry& iItem : visibleItems) restoreEntry(iItem);
    for (const itemEntry& iItem : hiddenItems) restoreEntry(iItem);

    scrollToBottom();
}





void ListItem::save()
{
    QFile file("userData.bin");

    if (file.open(QIODevice::WriteOnly))
    {
        for (int i{}; i < count(); ++i)
        {
            QListWidgetItem* iItem {item(i)};

            QString status {iItem->data(toInt(Role::F_STATUS)).toString()};
            QString title {iItem->data(toInt(Role::TITLE)).toString()};
            QString date {iItem->data(toInt(Role::DATE)).toString()};
            QString line {status + '|' + title + '|' + date + '\n'};

            if (title.trimmed().isEmpty()) continue;

            file.write(line.toUtf8());
        }
    }
    file.close();
}





void ListItem::load()
{
    QFile file("userData.bin");

    if (file.open(QIODevice::ReadOnly))
    {
        while (!file.atEnd())
        {
            QString line {QString::fromUtf8(file.readLine())};
            QStringList list {line.split('|')};

            if (list.size() != 3) continue;

            QString status {list[0]};
            QString title {list[1]};
            QString date {list[2].trimmed()};

            QDate itemDate {QDate::fromString(date, dateFormat())};
            QDate currDate {QDate::currentDate()};

            Status actualStatus {itemDate == currDate ? Status::ACTUAL :
                                    itemDate >  currDate ? Status::QUEUE :
                                    Status::OVERDUE};

            QListWidgetItem* item {new QListWidgetItem};

            item->setSizeHint(QSize(0, itemHeight + itemSpacing));
            item->setBackground(Qt::transparent);
            item->setData(toInt(Role::F_STATUS), status);
            item->setData(toInt(Role::TITLE), title);
            item->setData(toInt(Role::DATE), date);
            item->setData(toInt(Role::B_STATUS), toInt(actualStatus));

            if (status.toInt() != toInt(Status::COMPLETE)) item->setData(toInt(Role::F_STATUS), toInt(actualStatus));

            addItem(item);

            ApprovedWidget* widget {new ApprovedWidget(this, item)};

            QTimer::singleShot(0, this, [this, item, widget](){ setItemWidget(item, widget); });
        }
    }
    file.close();
}





QIcon ListItem::getIcon(Status status) { return icons[toInt(status)]; }
