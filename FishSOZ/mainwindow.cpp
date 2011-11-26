#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setMinimumSize(1024,768);

    StartWindow = new StartWin(this);
    StartWindow->resize(width(),height());


    connect(StartWindow,SIGNAL(MousePressed()),this,SLOT(GoToSecond()));

 //   statusBar()->showMessage("ASS");
//    statusBar()->show();





}

void MainWindow::GoToSecond()
{


    delete StartWindow;


   // SecondWindow->addPage(SecondWindow->createPage(new QLabel("AAA"),"AAA"));
   // SecondWindow->addPage(SecondWindow->createPage(new QLabel("BBB"),"BBB"));



    //SecondWindow->show();

    //resize(1024,768);


}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    statusBar()->showMessage("ASS");
    statusBar()->show();


}

MainWindow::~MainWindow()
{

}
