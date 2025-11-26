#include "backgroundWidget.h"

#include <QVBoxLayout>
#include <QTimer>
#include <QGraphicsDropShadowEffect>

#include "titleWidget.h"
#include "contentWidget.h"





BackgroundWidget::BackgroundWidget(QWidget *parent)
    :   QWidget{parent},
        view{new BackgroundWidgetView(this)},
        controller{new BackgroundWidgetController(view, this)}
{
    setMouseTracking(true);
    setFocusPolicy(Qt::NoFocus);
    setLayout(new QVBoxLayout(this));

    layout()->setContentsMargins(0,0,0,0);
    layout()->addWidget(view);

    // QGraphicsDropShadowEffect* shadowEffect {new QGraphicsDropShadowEffect(this)};

    // shadowEffect->setBlurRadius(20);
    // shadowEffect->setColor(QColor(255,255,255,255));
    // shadowEffect->setOffset(0);

    // setGraphicsEffect(shadowEffect);
}
