#include <QApplication>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>

#include "framewidget.h"
#include "mainwidget.h"





int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setStyle("Fusion");

    QLocale::setDefault(QLocale(QLocale::Russian, QLocale::Russia));

    FrameWidget* frameWidget {new FrameWidget};

    frameWidget->resize(600,600);
    frameWidget->setWindowFlags(Qt::FramelessWindowHint);
    frameWidget->setAttribute(Qt::WA_TranslucentBackground);

    QVBoxLayout* mainVLayout {new QVBoxLayout(frameWidget)};

    MainWidget* mainWidget {new MainWidget};

    mainVLayout->setContentsMargins(20,20,20,20);
    mainVLayout->addWidget(mainWidget);

    QGraphicsDropShadowEffect* shadowEffect {new QGraphicsDropShadowEffect(mainWidget)};

    shadowEffect->setBlurRadius(20);
    shadowEffect->setColor(QColor(255,255,255,255));
    shadowEffect->setOffset(0);

    mainWidget->setGraphicsEffect(shadowEffect);

    frameWidget->show();

    return app.exec();
}
