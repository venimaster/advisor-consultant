//#include <QApplication>
//#include <QTextCodec>
//#include <QSplashScreen>
//#include <QSplashScreen>
//#include <QPixmap>
//#include <QDebug>

#include "stable.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));

    QPixmap pixmap(":/backgrounds/brain");
    pixmap = pixmap.scaled(1200,800);

    QSplashScreen* splash = new QSplashScreen(pixmap);

    splash->showFullScreen();

    a.processEvents();

    MainWindow w;
    w.window()->setWindowTitle("Советчик-консультант по проблемной области \"Проектирование систем, основанных на знаниях\"");


    splash->showMessage("Opening Main Window");


    w.showMaximized();




    splash->hide();


    return a.exec();
}
