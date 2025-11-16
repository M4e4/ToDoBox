#include "frameWidget.h"
#include "mainWIdget.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QSettings>
#include <QTimer>
#include <QFontDatabase>





int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FrameWidget* frameWidget {new FrameWidget};
    QVBoxLayout* mainVLayout {new QVBoxLayout(frameWidget)};
    MainWidget* mainWidget {new MainWidget};
    QGraphicsDropShadowEffect* shadowEffect {new QGraphicsDropShadowEffect(mainWidget)};

    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, "M4e4", "ToDoBox");
    QVariant size {settings.value("window/window_size")};

    // Set style.
    app.setStyle("Fusion");

    // Set locale.
    QLocale::setDefault(QLocale(QLocale::Russian, QLocale::Russia));

    // Set font.
    int idFont {QFontDatabase::addApplicationFont(":Fonts/Inter_28pt-Light.ttf")};

    if (idFont != -1)
    {
        QString family {QFontDatabase::applicationFontFamilies(idFont).at(0)};
        QFont font(family, 10);
        QApplication::setFont(font);
    }

    // Load settings.
    if (size.isValid())
    {
        frameWidget->resize(size.toSize());
        frameWidget->updateNormalSize();
    }
    else
    {
        frameWidget->resize(600,600);
        frameWidget->updateNormalSize();
    }

    // Setup window.
    frameWidget->setWindowFlags(Qt::FramelessWindowHint);
    frameWidget->setAttribute(Qt::WA_TranslucentBackground);

    mainVLayout->setContentsMargins(20,20,20,20);
    mainVLayout->addWidget(mainWidget);

    shadowEffect->setBlurRadius(20);
    shadowEffect->setColor(QColor(255,255,255,255));
    shadowEffect->setOffset(0);

    mainWidget->setGraphicsEffect(shadowEffect);

    frameWidget->show();

    // Save settings.
    QObject::connect(&app, &QApplication::aboutToQuit, frameWidget, [&settings, frameWidget]()
    {
        settings.setValue("window/window_size", frameWidget->getNormalSize());
    });

    return app.exec();
}
