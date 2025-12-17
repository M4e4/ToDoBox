#include "taskDelegate.h"
#include "../utils/utils.h"
#include "../model/task.h"

#include <QMouseEvent>





TaskDelegate::TaskDelegate(QObject* parent)
    : QStyledItemDelegate{parent}
{
    statusIcons.resize(toInt(Status::COUNT));
    statusIcons[toInt(Status::ACTUAL)] = QPixmap(":/icons/icon-status-actual.png");
    statusIcons[toInt(Status::OVERDUE)] = QPixmap(":/icons/icon-status-overdue.png");
    statusIcons[toInt(Status::QUEUE)] = QPixmap(":/icons/icon-status-queue.png");
    statusIcons[toInt(Status::COMPLETE)] = QPixmap(":/icons/icon-status-complete.png");
}





void TaskDelegate::paint(QPainter* painter, const QStyleOptionViewItem& options, const QModelIndex& index) const
{
    painter->save();

    QColor color(72,72,72);

    QRect bgRect = options.rect.adjusted(0,1,0,-1);

    if ((options.state & QStyle::State_MouseOver) || (options.state & QStyle::State_Selected))
    {
        color = color.lighter(85);
    }

    painter->setBrush(color);
    painter->setPen(Qt::NoPen);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawRoundedRect(bgRect, 5,5);

    Status status = static_cast<Status>(index.data(toInt(Role::F_STATUS)).toInt());
    QPixmap pix = statusIcons[toInt(status)];
    QString title = index.data(toInt(Role::TITLE)).toString();
    QString date = index.data(toInt(Role::DATE)).toString();

    QFontMetrics fm(options.font);

    int iconSize = 16;
    int gap = (bgRect.height() - iconSize) / 2;
    int spacing = 10;
    int dateWidth = fm.horizontalAdvance(date);

    QRect statusRect(bgRect.left() + gap, bgRect.top() + gap, iconSize, iconSize);
    QRect textRect = options.rect.adjusted(bgRect.height(), 0, - spacing, 0);
    QRect dateRect = options.rect.adjusted(textRect.right() - dateWidth, 0, - spacing, 0);
    QRect titleRect = options.rect.adjusted(textRect.left(), 0, - dateWidth - (spacing * 2), 0);

    QString elidedTitle = fm.elidedText(title, Qt::ElideRight, titleRect.width());

    painter->setPen(Qt::white);
    painter->drawText(titleRect, Qt::AlignLeft | Qt::AlignVCenter, elidedTitle);
    painter->drawText(dateRect, Qt::AlignRight | Qt::AlignVCenter, date);
    painter->drawPixmap(statusRect, pix);

    painter->restore();
}





QSize TaskDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(0, 32);
}





bool TaskDelegate::editorEvent(QEvent *event,
                               QAbstractItemModel *model,
                               const QStyleOptionViewItem &option,
                               const QModelIndex &index
                               )
{
    if (event->type() != QEvent::MouseButtonRelease)
    {
        return false;
    }

    auto* mouseEvent = static_cast<QMouseEvent*>(event);
    QRect rect = option.rect.adjusted(0, 0, - option.rect.width() + option.rect.height(), 0);

    if (rect.contains(mouseEvent->pos()))
    {
        Status bStatus = static_cast<Status>(index.data(toInt(Role::B_STATUS)).toInt());
        Status fStatus = static_cast<Status>(index.data(toInt(Role::F_STATUS)).toInt());

        fStatus = (fStatus != Status::ACTUAL) ? Status::ACTUAL : bStatus;

        model->setData(index, toInt(fStatus), toInt(Role::F_STATUS));

        return true;
    }

    return false;
}
