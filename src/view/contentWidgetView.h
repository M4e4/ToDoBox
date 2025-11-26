#ifndef CONTENTWIDGETVIEW_H
#define CONTENTWIDGETVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QKeyEvent>

#include "../taskList.h"





class ContentWidgetView : public QWidget
{
    Q_OBJECT
public:
    ContentWidgetView(QWidget* parent = nullptr);

public:
    TaskList* taskList;
    QLineEdit* lSearch;
    QComboBox* cSort;
    QComboBox* cFilter;

private:
    void setupView();
    void keyPressEvent(QKeyEvent* event) override;

signals:
    void clickedAdd();
    void clickedkeyPressEvent(QKeyEvent* event);
};





#endif // CONTENTWIDGETVIEW_H
