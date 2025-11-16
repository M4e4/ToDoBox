#include "mainWidgetManager.h"

#include <QLayout>
#include <QTimer>
#include <QDebug>

MainWidgetManager::MainWidgetManager(MainWidgetUI *ui, QObject *parent)
    : ui{ui}, QObject{parent}
{
    setupConnection();
}





void MainWidgetManager::setupConnection()
{
    connect(ui->title, &TitleWidget::clickedMaximize, this, [this]()
    {
        if (ui->window()->isMaximized())
        {
            ui->setStyleSheet("MainWidgetUI {background: #2a2a2a; border-radius: 10px;}");
        }
        else
        {
            ui->setStyleSheet("MainWidgetUI {background: #2a2a2a; border-radius: 0px;}");
        }
    });
}
