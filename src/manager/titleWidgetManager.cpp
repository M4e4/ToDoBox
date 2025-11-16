#include "titleWidgetManager.h"

#include <QTimer>
#include <QLayout>





TitleWidgetManager::TitleWidgetManager(TitleWidgetUI *ui, QObject *parent)
    : ui{ui}, QObject{parent}
{
    setupConnection();
}





void TitleWidgetManager::setupConnection()
{
    // Mouse double click event.
    connect(ui, &TitleWidgetUI::clickedMouseDoubleClickEvent, this, &TitleWidgetManager::handleMouseDoubleClickEvent);

    // Top - minimize.
    connect(ui, &TitleWidgetUI::clickedMinimize, this, [this]()
    {
        ui->window()->showMinimized();
    });

    // Top - maximize.
    connect(ui, &TitleWidgetUI::clickedMaximize, this, [this]()
    {
        QWidget* window {ui->window()};
        QLayout* layout {window->layout()};

        if (window->isMaximized())
        {
            QTimer::singleShot(0, window, [window](){ window->showNormal(); });

            layout->setContentsMargins(20,20,20,20);

            ui->bClose->setStyleSheet(R"(
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
        }
        else
        {
            QTimer::singleShot(0, window, [window](){ window->showMaximized(); });

            layout->setContentsMargins(0,0,0,0);

            ui->bClose->setStyleSheet(
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
    });

    // Top - close.
    connect(ui, &TitleWidgetUI::clickedClose, this, [this]()
    {
        // ui->listTask->save();
        qApp->quit();
    });
}





void TitleWidgetManager::handleMouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit ui->clickedMaximize();
    }
}
