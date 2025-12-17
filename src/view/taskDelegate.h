#ifndef TASKDELEGATE_H
#define TASKDELEGATE_H

#include <QStyledItemDelegate>
#include <QObject>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QSize>
#include <QEvent>
#include <QAbstractItemModel>
#include <QVector>
#include <QPixmap>





class TaskDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    TaskDelegate(QObject* parent = nullptr);

private:
    void paint(QPainter* painter,
               const QStyleOptionViewItem& options,
               const QModelIndex& index
               ) const override;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index
                   ) const override;

    bool editorEvent(QEvent *event,
                     QAbstractItemModel *model,
                     const QStyleOptionViewItem &option,
                     const QModelIndex &index
                     ) override;

private:
    QVector<QPixmap> statusIcons;
};





#endif // TASKDELEGATE_H
