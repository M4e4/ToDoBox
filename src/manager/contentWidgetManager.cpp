#include "contentWidgetManager.h"

#include <QApplication>
#include <QLayout>
#include <QTimer>

#include "../editingwidget.h"




ContentWidgetManager::ContentWidgetManager(ContentWidgetUI* ui, QObject* parent)
    : ui{ui}, QObject{parent}
{
    setupConnections();
}





void ContentWidgetManager::setupConnections()
{


    // List item.
    connect(ui->listTask, &ListTask::currentItemChanged, this, [this](QListWidgetItem* current, QListWidgetItem* previous)
            {
                if (previous) ui->listTask->setSelectedStyle(previous, false);
                if (current)  ui->listTask->setSelectedStyle(current,   true);
            });
    connect(ui->listTask, &ListTask::doubleClicked, this, [this](const QModelIndex& index)
            {
                QListWidgetItem* item {ui->listTask->item(index.row())};

                if (!item) return;

                EditingWidget* editWidget {new EditingWidget(ui->listTask, item)};

                ui->listTask->setItemWidget(item, editWidget);
            });

    // Sort.
    connect(ui->cSort, &QComboBox::currentIndexChanged, ui->listTask, &ListTask::sort);

    // Filter.
    connect(ui->cFilter, &QComboBox::currentTextChanged, this, [this]()
            {
                ui->listTask->filter(ui->lSearch->text().trimmed(), static_cast<Status>(ui->cFilter->currentData(Qt::UserRole).toInt()));
            });

    // Search.
    connect(ui->lSearch, &QLineEdit::textChanged, this, [this]()
            {
                ui->listTask->filter(ui->lSearch->text().trimmed(), static_cast<Status>(ui->cFilter->currentData(Qt::UserRole).toInt()));
            });

    // Add.
    connect(ui, &ContentWidgetUI::clickedAdd, ui->listTask, &ListTask::newTask);

    // Key press event.
    connect(ui, &ContentWidgetUI::clickedkeyPressEvent, this, &ContentWidgetManager::handleKeyPressEvent);

    // Close event.
    connect(ui, &ContentWidgetUI::clickedCloseEvent, this, &ContentWidgetManager::handleCloseEvent);
}





void ContentWidgetManager::handleKeyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        ui->listTask->newTask();
    }
}





void ContentWidgetManager::handleCloseEvent(QCloseEvent* event)
{
    // ui->listTask->save();
    event->accept();
}
