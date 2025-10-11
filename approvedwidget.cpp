#include "approvedwidget.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>

#include <QDate>





ApprovedWidget::ApprovedWidget (ListItem *list, QListWidgetItem *item, QWidget *parent) : QWidget{parent}
{
    setFixedHeight(itemHeight);
    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet("ApprovedWidget {background: #444; border-radius: 5px;}");

    // Layouts.
    QHBoxLayout* HLayout {new QHBoxLayout(this)};

    // Icon status.
    QPushButton* bIcon{new QPushButton};
    bIcon->setFixedSize(30,30);
    bIcon->setIconSize(QSize(20,20));
    bIcon->setIcon(list->getIcon(static_cast<Status>(item->data(toInt(Role::F_STATUS)).toInt())));
    bIcon->setFlat(true);
    bIcon->setStyleSheet("background: transparent; border: none;");
    connect(bIcon, &QPushButton::clicked, bIcon, [this, list, item, bIcon]()
    {
        Status currStatus {static_cast<Status>(item->data(toInt(Role::F_STATUS)).toInt())};
        Status nextStatus { (currStatus == Status::COMPLETE) ? static_cast<Status>(item->data(toInt(Role::B_STATUS)).toInt()) : Status::COMPLETE };

        item->setData(toInt(Role::F_STATUS), toInt(nextStatus));
        bIcon->setIcon(list->getIcon(nextStatus));
    });

    // Label title.
    QLabel* tTitle {new QLabel(item->data(toInt(Role::TITLE)).toString())};
    tTitle->setStyleSheet("color: white");
    // Label date.
    QLabel* tDate {new QLabel(item->data(toInt(Role::DATE)).toString())};
    tDate->setStyleSheet("color: white");
    tDate->setContentsMargins(0,0,10,0);





    HLayout->setContentsMargins(0,0,0,0);
    HLayout->setSpacing(0);
    HLayout->addWidget(bIcon);
    HLayout->addWidget(tTitle);
    HLayout->addSpacing(10);
    HLayout->addStretch();
    HLayout->addWidget(tDate);
}
