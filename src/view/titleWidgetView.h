#ifndef TITLEWIDGETVIEW_H
#define TITLEWIDGETVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>





class TitleWidgetView : public QWidget
{
    Q_OBJECT
public:
    TitleWidgetView(QWidget* parent = nullptr);

public:
    QPushButton* bClose;

private:
    void setupView();
    void mouseDoubleClickEvent(QMouseEvent* event) override;

public slots:
    void setMaximizeStyle(bool maximize);

signals:
    void clickedMinimize();
    void clickedMaximize();
    void clickedClose();
};





#endif // TITLEWIDGETVIEW_H
