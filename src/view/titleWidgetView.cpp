#include "titleWidgetView.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>





TitleWidgetView::TitleWidgetView(QWidget *parent)
    :   QWidget{parent}
{
    setupView();
}





void TitleWidgetView::setupView()
{
    setMouseTracking(true);
    setFocusPolicy(Qt::NoFocus);

    // Layoutns.
    QHBoxLayout* titleHLayout {new QHBoxLayout(this)};

    // Icon.
    QLabel* icon {new QLabel};
    icon->setPixmap(QIcon(":/icons/icon-top.png").pixmap(20));

    // Title.
    QLabel* title {new QLabel("ToDoBox")};
    title->setStyleSheet("color: #aaaaaa;");

    // Button style.
    QString buttonStyle {
    R"(
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
    bMinimize->setFocusPolicy(Qt::NoFocus);
    bMinimize->setIconSize(QSize(12,12));
    bMinimize->setFixedSize(45,30);
    bMinimize->setStyleSheet(buttonStyle);
    connect(bMinimize, &QPushButton::clicked, this, &TitleWidgetView::clickedMinimize);

    // Button maximize.
    QPushButton* bMaximize {new QPushButton(QIcon(":/icons/icon-button-maximize.png"), "")};
    bMaximize->setFocusPolicy(Qt::NoFocus);
    bMaximize->setIconSize(QSize(12,12));
    bMaximize->setFixedSize(45,30);
    bMaximize->setStyleSheet(buttonStyle);
    connect(bMaximize, &QPushButton::clicked, this, &TitleWidgetView::clickedMaximize);

    // Button close.
    bClose = new QPushButton(QIcon(":/icons/icon-button-close.png"), "");
    bClose->setFocusPolicy(Qt::NoFocus);
    bClose->setIconSize(QSize(12,12));
    bClose->setFixedSize(45,30);
    bClose->setStyleSheet(
    R"(
        QPushButton
        {
            background: transparent;
            border: none;
        }
        QPushButton:hover
        {
            background: #444;
            border-top-right-radius: 10px;
        }
    )");
    connect(bClose, &QPushButton::clicked, this, &TitleWidgetView::clickedClose);





    titleHLayout->setContentsMargins(0,0,0,0);
    titleHLayout->setSpacing(0);
    titleHLayout->addSpacing(5);
    titleHLayout->addWidget(icon);
    titleHLayout->addSpacing(5);
    titleHLayout->addWidget(title);
    titleHLayout->addStretch();
    titleHLayout->addWidget(bMinimize);
    titleHLayout->addWidget(bMaximize);
    titleHLayout->addWidget(bClose);
}





void TitleWidgetView::setMaximizeStyle(bool maximize)
{
    if (maximize)
    {
        bClose->setStyleSheet(
        R"(
            QPushButton
            {
                background: transparent;
                border: none;
            }
            QPushButton:hover
            {
                background: #444;
                border-top-right-radius: 8px;
            }
        )");
    }
    else
    {
        bClose->setStyleSheet(
        R"(
            QPushButton
            {
                background: transparent;
                border: none;
            }
            QPushButton:hover
            {
                background: #444;
                border-top-right-radius: 0px;
            }
        )");
    }
}





void TitleWidgetView::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit clickedMaximize();
    }
}
