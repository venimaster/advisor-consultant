#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setMinimumSize(1024,768);

    LeftPanel=new QWidget();
    LeftPanel->resize(width(),height());


    StartWindow = new StartWin(this);
    setCentralWidget(StartWindow);

    setMouseTracking(true);


    EtapsWGT=new QDockWidget("ÝÒÀÏÛ ÊÎÍÑÓËÜÒÀÖÈÈ");

    addDockWidget(Qt::LeftDockWidgetArea,EtapsWGT);

    EtapsWGT->setFeatures(QDockWidget::NoDockWidgetFeatures);
    this->setDockOptions();


    QVBoxLayout* Lay1 = new QVBoxLayout();
    LeftPanel->setLayout(Lay1);


    for (int i=0;i<5;i++)
    {
        EtapBtns<<new Etap("ÝÒÀÏ "+QString::number(i),"ÌÅÒÊÀ ÝÒÀÏÀ",i);
        Lay1->addWidget(EtapBtns[i]);



    }

    EtapsWGT->setWidget(LeftPanel);



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
    statusBar()->showMessage(QString::number(event->x())+" ; "+QString::number(event->y()));
    statusBar()->show();


}

MainWindow::~MainWindow()
{

}
