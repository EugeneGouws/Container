#include "mainclient.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Load splash image from resources
    QPixmap splashPix(":/images/Splash.png");
    QSplashScreen splash(splashPix);
    splash.show();
    a.processEvents();
    MainClient mc;
    mc.show();
    splash.finish(&mc);

    return a.exec();
}
