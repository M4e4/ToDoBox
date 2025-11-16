#ifndef TITLEWIDGETUI_H
#define TITLEWIDGETUI_H

#include <QWidget>
#include <QPushButton>





class TitleWidgetUI : public QWidget
{
    Q_OBJECT
public:
    TitleWidgetUI(QWidget* parent = nullptr);

public:
    QPushButton* bClose;

private:
    void setupUI();
    void mouseDoubleClickEvent(QMouseEvent* event) override;

signals:
    void clickedMouseDoubleClickEvent(QMouseEvent* event);
    void clickedMinimize();
    void clickedMaximize();
    void clickedClose();
};





#endif // TITLEWIDGETUI_H
