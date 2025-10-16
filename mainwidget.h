#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "topwidget.h"
#include "listitem.h"

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCloseEvent>
#include <QMouseEvent>





class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget* parent = nullptr);

private:
    void setupUI();
    void setupConnections();

    TopWidget* topWidget;
    QLineEdit* lSearch;
    QComboBox* cSort;
    QComboBox* cFilter;
    ListItem* listItem;
    QLabel* placeholder;
    QPushButton* bAdd;

    void closeEvent(QCloseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
};

#endif // MAINWIDGET_H
