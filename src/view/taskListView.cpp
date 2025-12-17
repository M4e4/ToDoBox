#include "taskListView.h"
#include "taskDelegate.h"





TaskListView::TaskListView(QWidget *parent)
    :   QListView{parent}
{
    setItemDelegate(new TaskDelegate(this));

    setupView();
}





void TaskListView::setupView()
{
    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
    setDefaultDropAction(Qt::MoveAction);
    setStyleSheet(
    R"(
        TaskListView
        {
            background: transparent;
            border: none;
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
            border: none;
        }
        QScrollBar::handle:hover
        {
            background: #666666;
            border: none;
        }
    )");
}
