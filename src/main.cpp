#include "mainWidget.h"
#include "backgroundWidget.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QSettings>
#include <QTimer>
#include <QFontDatabase>





int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWidget* mainWidget {new MainWidget};
    QVBoxLayout* backgroundVLayout {new QVBoxLayout(mainWidget)};
    BackgroundWidget* backgroundWidget {new BackgroundWidget(mainWidget)};

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
        mainWidget->resize(size.toSize());
        mainWidget->updateNormalSize();
    }
    else
    {
        mainWidget->resize(600,600);
        mainWidget->updateNormalSize();
    }

    backgroundVLayout->setContentsMargins(20,20,20,20);
    backgroundVLayout->addWidget(backgroundWidget);

    mainWidget->show();

    // Save settings.
    QObject::connect(&app, &QApplication::aboutToQuit, mainWidget, [&settings, mainWidget]()
    {
        settings.setValue("window/window_size", mainWidget->getNormalSize());
    });

    return app.exec();
}
