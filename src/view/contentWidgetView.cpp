#include "contentWidgetView.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTimer>

#include "../utils/utils.h"





ContentWidgetView::ContentWidgetView(QWidget *parent)
    :   QWidget{parent}
{
    setupView();
    setMouseTracking(true);

    QTimer::singleShot(0, this, [this](){ setFocus(); });
}





void ContentWidgetView::setupView()
{
    // Layouts.
    QVBoxLayout* mainVLayout   {new QVBoxLayout(this)};
    QHBoxLayout* toolHLayout   {new QHBoxLayout};
    QHBoxLayout* filterHLayout {new QHBoxLayout};
    QHBoxLayout* sortHLayout   {new QHBoxLayout};

    // Search.
    lSearch = new QLineEdit;
    lSearch->addAction(QIcon(":/icons/icon-search.png"), QLineEdit::LeadingPosition);
    lSearch->setStyleSheet("background: #555555; color: white; border-radius: 5px;");
    lSearch->setPlaceholderText("Поиск");
    lSearch->setMinimumHeight(itemHeight);
    lSearch->setMaxLength(100);

    // List item.
    // listTask = new TaskList;
    // listTask->setDragDropMode(QAbstractItemView::InternalMove);

    // Filter|Sort style.
    // QString comboBoxStyle {
    // R"(
    //     QComboBox
    //     {
    //         color: white;
    //         background: #555555;
    //         border-radius: 5px;
    //         padding-left: 15px;
    //     }
    //     QComboBox::drop-down
    //     {
    //         border: none;
    //     }
    //     QComboBox QAbstractItemView
    //     {
    //         background: #555555;
    //         color: white;
    //         border-radius: 5px;
    //         padding: 5px;
    //     }
    // )"};

    // Filter.
    // cFilter = new QComboBox;
    // cFilter->setAttribute(Qt::WA_StyledBackground, true);
    // cFilter->setMinimumHeight(itemHeight);
    // cFilter->setStyleSheet(comboBoxStyle);
    // cFilter->addItem(QIcon(":/icons/icon-status-all.png"), "Все");
    // cFilter->addItem(listTask->getIcon(Status::ACTUAL),   QString("Сегодня"));
    // cFilter->addItem(listTask->getIcon(Status::OVERDUE),  QString("Просрочено"));
    // cFilter->addItem(listTask->getIcon(Status::QUEUE),    QString("Запланировано"));
    // cFilter->addItem(listTask->getIcon(Status::COMPLETE), QString("Выполнено"));
    // cFilter->setItemData(0, -1);
    // cFilter->setItemData(1, toInt(Status::ACTUAL));
    // cFilter->setItemData(2, toInt(Status::OVERDUE));
    // cFilter->setItemData(3, toInt(Status::QUEUE));
    // cFilter->setItemData(4, toInt(Status::COMPLETE));

    // Sort.
    // cSort = new QComboBox;
    // cSort->setMinimumHeight(itemHeight);
    // cSort->setStyleSheet(comboBoxStyle);
    // cSort->addItem(QIcon(":/icons/icon-sort-date.png"),"Дата");
    // cSort->addItem(listTask->getIcon(Status::COMPLETE),"Статус");
    // cSort->addItem(QIcon(":/icons/icon-sort-alphabet.png"),"Алфавит");

    // Button add (+).
    QPushButton* bAdd = new QPushButton(QIcon(":/icons/icon-button-add.png"), "");
    bAdd->setStyleSheet(
    R"(
        QPushButton
        {
            background: #555555; border-radius: 5px;
        }
        QPushButton:hover
        {
            background: #666666;
        }
    )");
    bAdd->setMinimumHeight(itemHeight);
    connect(bAdd, &QPushButton::clicked, this, &ContentWidgetView::clickedAdd);





    mainVLayout->setContentsMargins(5,0,5,5);
    mainVLayout->addLayout(toolHLayout);
    // mainVLayout->addWidget(listTask);
    mainVLayout->addWidget(bAdd);

    toolHLayout->addLayout(filterHLayout);
    toolHLayout->addLayout(sortHLayout);
    toolHLayout->setStretch(0,1);
    toolHLayout->setStretch(1,1);

    filterHLayout->addWidget(lSearch);

    sortHLayout->addWidget(cFilter);
    sortHLayout->addWidget(cSort);
}





void ContentWidgetView::keyPressEvent(QKeyEvent *event)
{
    emit clickedkeyPressEvent(event);
}
