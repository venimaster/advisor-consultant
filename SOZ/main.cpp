#include <QtGui/QApplication>
#include <QTextCodec>

#include <QSplashScreen>
#include <QSplashScreen>
#include <QPixmap>
#include <QDebug>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));

    QPixmap pixmap(":/backgrounds/brain");

    QSplashScreen* splash = new QSplashScreen(pixmap);

    splash->show();

    a.processEvents();

    MainWindow w;
    w.window()->setWindowTitle("Советчик-консультант по проблемной области \"Проектирование систем, основанных на знаниях\"");


    splash->showMessage("Opening Main Window");


    w.show();




    splash->hide();


    return a.exec();
}
