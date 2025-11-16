#ifndef CONTENTWIDGETUI_H
#define CONTENTWIDGETUI_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

#include "../titleWidget.h"
#include "../listTask.h"





class ContentWidgetUI : public QWidget
{
    Q_OBJECT
public:
    ContentWidgetUI(QWidget* parent = nullptr);

public:
    QLineEdit* lSearch;
    QComboBox* cSort;
    QComboBox* cFilter;
    ListTask* listTask;
    QLabel* placeholder;

private:
    void setupUI();
    void keyPressEvent(QKeyEvent* event) override;
    void closeEvent(QCloseEvent* event) override;

signals:
    void clickedAdd();
    void clickedkeyPressEvent(QKeyEvent* event);
    void clickedCloseEvent(QCloseEvent* event);
};





#endif // CONTENTWIDGETUI_H
