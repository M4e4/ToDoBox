#include "contentWidgetUI.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "../utils/toInt.h"





ContentWidgetUI::ContentWidgetUI(QWidget *parent)
    : QWidget{parent}
{
    setupUI();
}





void ContentWidgetUI::setupUI()
{
    setMouseTracking(true);

    // Layouts.
    QVBoxLayout* rootVLayout {new QVBoxLayout(this)};
    QHBoxLayout* titleHLayout {new QHBoxLayout};
    QVBoxLayout* mainVLayout {new QVBoxLayout};
    QHBoxLayout* toolHLayout {new QHBoxLayout};
    QHBoxLayout* filterHLayout {new QHBoxLayout};
    QHBoxLayout* SortHLayout {new QHBoxLayout};

    // Search.
    QIcon icon = QIcon(":/icons/icon-search.png");

    lSearch = new QLineEdit;
    lSearch->addAction(icon, QLineEdit::LeadingPosition);
    lSearch->setStyleSheet("background: #555555; color: white; border-radius: 5px;");


    // lSearch->setPlaceholderText("Search");
    lSearch->setPlaceholderText("Поиск");
    lSearch->setMinimumHeight(itemHeight);
    lSearch->setMaxLength(100);

    // List item.
    listTask = new ListTask;
    listTask->setDragDropMode(QAbstractItemView::InternalMove);

    // Filter|Sort style.
    QString comboBoxStyle {
    R"(
    QComboBox
    {
        color: white;
        background: #555555;
        border-radius: 5px;
        padding-left: 15px;
    }
    QComboBox::drop-down
    {
        border: none;
    }
    QComboBox QAbstractItemView
    {
        background: #555555;
        color: white;
        border-radius: 5px;
        padding: 5px;
    }
    )"};

    // Filter.
    cFilter = new QComboBox;
    cFilter->setAttribute(Qt::WA_StyledBackground, true);
    cFilter->setMinimumHeight(itemHeight);
    cFilter->setStyleSheet(comboBoxStyle);
    cFilter->addItem(QIcon(":/icons/icon-status-all.png"), "Все");
    cFilter->addItem(listTask->getIcon(Status::ACTUAL),     QString("Сегодня"));
    cFilter->addItem(listTask->getIcon(Status::OVERDUE),    QString("Просрочено"));
    cFilter->addItem(listTask->getIcon(Status::QUEUE),      QString("Запланировано"));
    cFilter->addItem(listTask->getIcon(Status::COMPLETE),   QString("Выполнено"));
    cFilter->setItemData(0, -1);
    cFilter->setItemData(1, toInt(Status::ACTUAL));
    cFilter->setItemData(2, toInt(Status::OVERDUE));
    cFilter->setItemData(3, toInt(Status::QUEUE));
    cFilter->setItemData(4, toInt(Status::COMPLETE));

    // Sort.
    cSort = new QComboBox;
    cSort->setMinimumHeight(itemHeight);
    cSort->setStyleSheet(comboBoxStyle);
    cSort->addItem(QIcon(":/icons/icon-sort-date.png"),"Дата");
    cSort->addItem(listTask->getIcon(Status::COMPLETE),"Статус");
    cSort->addItem(QIcon(":/icons/icon-sort-alphabet.png"),"Алфавит");

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
    connect(bAdd, &QPushButton::clicked, this, &ContentWidgetUI::clickedAdd);





    rootVLayout->setContentsMargins(0,0,0,0);
    rootVLayout->addLayout(titleHLayout);
    rootVLayout->addLayout(mainVLayout);

    mainVLayout->setContentsMargins(10,0,10,10);
    mainVLayout->addLayout(toolHLayout);
    mainVLayout->addWidget(listTask);
    mainVLayout->addWidget(bAdd);

    toolHLayout->addLayout(filterHLayout);
    toolHLayout->addLayout(SortHLayout);
    toolHLayout->setStretch(0,1);
    toolHLayout->setStretch(1,1);

    filterHLayout->addWidget(lSearch);

    SortHLayout->addWidget(cFilter);
    SortHLayout->addWidget(cSort);
}





void ContentWidgetUI::keyPressEvent(QKeyEvent *event)
{
    emit clickedkeyPressEvent(event);
}





void ContentWidgetUI::closeEvent(QCloseEvent* event)
{
    emit clickedCloseEvent(event);
}
