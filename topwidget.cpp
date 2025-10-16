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
    QString buttonStyle {R"(
    QPushButton
    {
        background: transparent;
        border: none;
    }
    QPushButton:hover
    {
        background: #444;
    }
    )"};

    // Button minimize.
    QPushButton* bMinimize {new QPushButton(QIcon(":/icons/icon-button-minimize.png"), "")};
    bMinimize->setIconSize(QSize(12,12));
    bMinimize->setFixedSize(45,30);
    bMinimize->setStyleSheet(buttonStyle);
    connect(bMinimize, &QPushButton::clicked, this, &TopWidget::pushMinimize);

    // Button maximize.
    QPushButton* bMaximize {new QPushButton(QIcon(":/icons/icon-button-maximize.png"), "")};
    bMaximize->setIconSize(QSize(12,12));
    bMaximize->setFixedSize(45,30);
    bMaximize->setStyleSheet(buttonStyle);
    connect(bMaximize, &QPushButton::clicked, this, &TopWidget::pushMaximize);

    // Button close.
    buttonClose = new QPushButton(QIcon(":/icons/icon-button-close.png"), "");
    buttonClose->setIconSize(QSize(12,12));
    buttonClose->setFixedSize(45,30);
    buttonClose->setStyleSheet(R"(
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
    connect(buttonClose, &QPushButton::clicked, this, &TopWidget::pushClose);





    hTopLayout->setContentsMargins(0,0,0,0);
    hTopLayout->setSpacing(0);
    hTopLayout->addSpacing(5);
    hTopLayout->addWidget(icon);
    hTopLayout->addSpacing(5);
    hTopLayout->addWidget(title);
    hTopLayout->addStretch();
    hTopLayout->addWidget(bMinimize);
    hTopLayout->addWidget(bMaximize);
    hTopLayout->addWidget(buttonClose);
}





void TopWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit pushMaximize();
    }
}
