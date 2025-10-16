#include "mainwidget.h"
#include "listitem.h"
#include "approvedwidget.h"
#include "editingwidget.h"
#include "topwidget.h"
#include "framewidget.h"

#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QMouseEvent>
#include <QTimer>





MainWidget::MainWidget(QWidget *parent) : QWidget{parent}
{
    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet("MainWidget {background: #2a2a2a; border-radius: 10px;}");

    setupUI();
    setupConnections();

    topWidget->setMouseTracking(true);
    this->setMouseTracking(true);
}





void MainWidget::setupUI()
{
    // Layouts.
    QVBoxLayout* rootVLayout {new QVBoxLayout(this)};
    QHBoxLayout* topHLayout {new QHBoxLayout};
    QVBoxLayout* mainVLayout {new QVBoxLayout};
    QHBoxLayout* toolHLayout {new QHBoxLayout};
    QHBoxLayout* filterHLayout {new QHBoxLayout};
    QHBoxLayout* SortHLayout {new QHBoxLayout};

    // Frame
    topWidget = new TopWidget;

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
    listItem = new ListItem;
    listItem->setDragDropMode(QAbstractItemView::InternalMove);

    // Filter|Sort style.
    QString comboBoxStyle {
    R"(QComboBox
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
    })"};

    // Filter.
    cFilter = new QComboBox;
    cFilter->setAttribute(Qt::WA_StyledBackground, true);
    cFilter->setMinimumHeight(itemHeight);
    cFilter->setStyleSheet(comboBoxStyle);
    cFilter->addItem(QIcon(":/icons/icon-status-all.png"), "Все");
    cFilter->addItem(listItem->getIcon(Status::ACTUAL),     QString("Сегодня"));
    cFilter->addItem(listItem->getIcon(Status::OVERDUE),    QString("Просрочено"));
    cFilter->addItem(listItem->getIcon(Status::QUEUE),      QString("Запланировано"));
    cFilter->addItem(listItem->getIcon(Status::COMPLETE),   QString("Выполнено"));
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
    cSort->addItem(listItem->getIcon(Status::COMPLETE),"Статус");
    cSort->addItem(QIcon(":/icons/icon-sort-alphabet.png"),"Алфавит");

    // Button add (+).
    bAdd = new QPushButton(QIcon(":/icons/icon-button-add.png"), "");
    bAdd->setStyleSheet(R"(
    QPushButton
    {
        background: #555555; border-radius: 5px;
    }
    QPushButton:hover
    {
        background: #666666;
    })");
    bAdd->setMinimumHeight(itemHeight);





    rootVLayout->setContentsMargins(0,0,0,0);
    rootVLayout->addLayout(topHLayout);
    rootVLayout->addLayout(mainVLayout);

    mainVLayout->setContentsMargins(10,0,10,10);
    mainVLayout->addLayout(toolHLayout);
    mainVLayout->addWidget(listItem);
    mainVLayout->addWidget(bAdd);

    topHLayout->addWidget(topWidget);

    toolHLayout->addLayout(filterHLayout);
    toolHLayout->addLayout(SortHLayout);
    toolHLayout->setStretch(0,1);
    toolHLayout->setStretch(1,1);

    filterHLayout->addWidget(lSearch);

    SortHLayout->addWidget(cFilter);
    SortHLayout->addWidget(cSort);
}





void MainWidget::setupConnections()
{
    // Top - minimize.
    connect(topWidget, &TopWidget::pushMinimize, this, [this]()
    {
        parentWidget()->showMinimized();
    });

    // Top - maximize.
    connect(topWidget, &TopWidget::pushMaximize, this, [this]()
    {
        QWidget* widget {parentWidget()};
        QLayout* layout {widget->layout()};

        if (widget->isMaximized())
        {
            QTimer::singleShot(0, widget, [widget](){ widget->showNormal(); });

            layout->setContentsMargins(20,20,20,20);

            // Update borders.
            topWidget->setStyleSheet(R"(
            TopWidget
            {
                background: #444;
                border-top-left-radius: 10px;
                border-top-right-radius: 10px;
                border-bottom-left-radius: 0px;
                border-bottom-right-radius: 0px;
            }
            )");
            topWidget->buttonClose->setStyleSheet(R"(
            QPushButton
            {
                background: transparent;
                border: none;
            }
            QPushButton:hover
            {
                background: #444;
                border-top-right-radius: 10px;
            })");

            setStyleSheet("MainWidget {background: #2a2a2a; border-radius: 10px;}");
        }
        else
        {
            QTimer::singleShot(0, widget, [widget](){ widget->showMaximized(); });

            layout->setContentsMargins(0,0,0,0);

            // Update borders.
            topWidget->setStyleSheet("TopWidget {background: #444; border-radius: 0px;}");
            topWidget->buttonClose->setStyleSheet(R"(
            QPushButton
            {
                background: transparent;
                border: none;
            }
            QPushButton:hover
            {
                background: #444;
                border-top-right-radius: 0px;
            })");

            setStyleSheet("MainWidget {background: #2a2a2a; border-radius: 0px;}");
        }
    });

    // Top - close.
    connect(topWidget, &TopWidget::pushClose, this, [this]()
    {
        listItem->save();
        qApp->quit();
    });

    // List item.
    connect(listItem, &ListItem::currentItemChanged, this, [this](QListWidgetItem* current, QListWidgetItem* previous)
    {
        if (previous) listItem->setSelectedStyle(previous, false);
        if (current) listItem->setSelectedStyle(current, true);
    });
    connect(listItem, &ListItem::doubleClicked, this, [this](const QModelIndex& index)
    {
        QListWidgetItem* item {listItem->item(index.row())};

        if (!item) return;

        EditingWidget* editWidget {new EditingWidget(listItem, item)};

        listItem->setItemWidget(item, editWidget);
    });

    // Sort.
    connect(cSort, &QComboBox::currentIndexChanged, listItem, &ListItem::sort);

    // Filter.
    connect(cFilter, &QComboBox::currentTextChanged, this, [this]()
    {
        listItem->filter(lSearch->text().trimmed(), static_cast<Status>(cFilter->currentData(Qt::UserRole).toInt()));
    });

    // Search.
    connect(lSearch, &QLineEdit::textChanged, this, [this]()
    {
        listItem->filter(lSearch->text().trimmed(), static_cast<Status>(cFilter->currentData(Qt::UserRole).toInt()));
    });

    // Add.
    connect(bAdd, &QPushButton::clicked, listItem, &ListItem::newItem);
}





void MainWidget::closeEvent(QCloseEvent* event)
{
    listItem->save();
    event->accept();
}





void MainWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) bAdd->click();
}
