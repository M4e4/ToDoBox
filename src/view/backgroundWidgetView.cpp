#include "backgroundWidgetView.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QApplication>
#include <QLayout>
#include <QTimer>

#include "../titleWidget.h"
#include "../contentWidget.h"





BackgroundWidgetView::BackgroundWidgetView(QWidget *parent)
    :   QWidget{parent}
{
    setupView();
}





void BackgroundWidgetView::setupView()
{
    setMouseTracking(true);
    setFocusPolicy(Qt::NoFocus);
    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet("BackgroundWidgetView {background: #2a2a2a; border-radius: 10px;}");

    title = new TitleWidget(this);
    content = new ContentWidget(this);

    setLayout(new QVBoxLayout(this));

    layout()->setContentsMargins(0,0,0,0);

    layout()->addWidget(title);
    layout()->addWidget(content);
}





void BackgroundWidgetView::setMaximizeStyle()
{
    QWidget* focused {QApplication::focusWidget()};
    QWidget* window {this->window()};
    QLayout* layout {window->layout()};

    if (window->isMaximized())
    {
        QTimer::singleShot(0, window, [window](){ window->showNormal(); });

        setStyleSheet("BackgroundWidgetView {background: #2a2a2a; border-radius: 10px;}");

        layout->setContentsMargins(20,20,20,20);
    }
    else
    {
        QTimer::singleShot(0, window, [window](){ window->showMaximized(); });

        setStyleSheet("BackgroundWidgetView {background: #2a2a2a; border-radius: 0px;}");

        layout->setContentsMargins(0,0,0,0);
    }

    QTimer::singleShot(0, focused, [focused](){ focused->setFocus(); });
}
