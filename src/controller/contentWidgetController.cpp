#include "contentWidgetController.h"





ContentWidgetController::ContentWidgetController(ContentWidgetModel* model, ContentWidgetView* view, QObject* parent)
    :   QObject{parent},
        model{model},
        view{view}
{
    setupConnections();
}





void ContentWidgetController::setupConnections()
{
    // // List item.
    // connect(view->listTask, &ListTask::currentItemChanged, this, [this](QListWidgetItem* current, QListWidgetItem* previous)
    // {
    //     if (previous) view->listTask->setSelectedStyle(previous, false);
    //     if (current)  view->listTask->setSelectedStyle(current,   true);
    // });

    // connect(view->listTask, &ListTask::doubleClicked, this, [this](const QModelIndex& index)
    // {
    //     QListWidgetItem* item {view->listTask->item(index.row())};

    //     if (!item) return;

    //     EditingWidget* editWidget {new EditingWidget(view->listTask, item)};

    //     view->listTask->setItemWidget(item, editWidget);
    // });

    // // Sort.
    // connect(view->cSort, &QComboBox::currentIndexChanged, view->listTask, &ListTask::sort);

    // // Filter.
    // connect(view->cFilter, &QComboBox::currentTextChanged, this, [this]()
    // {
    //     view->listTask->filter(view->lSearch->text().trimmed(), static_cast<Status>(view->cFilter->currentData(Qt::UserRole).toInt()));
    // });

    // // Search.
    // connect(view->lSearch, &QLineEdit::textChanged, this, [this]()
    // {
    //     view->listTask->filter(view->lSearch->text().trimmed(), static_cast<Status>(view->cFilter->currentData(Qt::UserRole).toInt()));
    // });

    // // Add.
    // connect(view, &ContentWidgetView::clickedAdd, view->listTask, &ListTask::newTask);

    // // Key press event.
    // connect(view, &ContentWidgetView::clickedkeyPressEvent, this, &ContentWidgetController::handleKeyPressEvent);

    // // Close event.
    // connect(qobject_cast<MainWidget*>(view->window()), &MainWidget::aboutToClose, this, [this]()
    // {
    //     view->listTask->save();
    // });
}
