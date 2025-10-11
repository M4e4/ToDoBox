#include "topwidget.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>





TopWidget::TopWidget()
{
    // Layoutns.
    QHBoxLayout* hTopLayout {new QHBoxLayout(this)};

    // Icon.
    QLabel* icon {new QLabel};
    icon->setPixmap(QIcon(":/icons/icon-top.png").pixmap(20));

    // Title.
    QLabel* title {new QLabel("ToDoBox")};
    title->setStyleSheet("color: #aaaaaa;");

    // Button style.
    QString buttonStyle {"background-color: transparent; border: none;"};

    // Button minimize.
    QPushButton* bMinimize {new QPushButton(QIcon(":/icons/icon-button-minimize.png"), "")};
    bMinimize->setIconSize(QSize(12,12));
    bMinimize->setFixedSize(45,30);
    bMinimize->setStyleSheet(buttonStyle);
    connect(bMinimize, &QPushButton::clicked, this, &TopWidget::buttonMinimize);

    // Button maximize.
    QPushButton* bMaximize {new QPushButton(QIcon(":/icons/icon-button-maximize.png"), "")};
    bMaximize->setIconSize(QSize(12,12));
    bMaximize->setFixedSize(45,30);
    bMaximize->setStyleSheet(buttonStyle);
    connect(bMaximize, &QPushButton::clicked, this, &TopWidget::buttonMaximize);

    // Button close.
    QPushButton* bClose {new QPushButton(QIcon(":/icons/icon-button-close.png"), "")};
    bClose->setIconSize(QSize(12,12));
    bClose->setFixedSize(45,30);
    bClose->setStyleSheet(buttonStyle);
    connect(bClose, &QPushButton::clicked, this, &TopWidget::buttonClose);





    hTopLayout->setContentsMargins(0,0,0,0);
    hTopLayout->setSpacing(0);
    hTopLayout->addSpacing(5);
    hTopLayout->addWidget(icon);
    hTopLayout->addSpacing(5);
    hTopLayout->addWidget(title);
    hTopLayout->addStretch();
    hTopLayout->addWidget(bMinimize);
    hTopLayout->addWidget(bMaximize);
    hTopLayout->addWidget(bClose);
}
