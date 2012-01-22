#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
//#include <QSplashScreen>
//#include <QResizeEvent>
//#include <QDebug>
//#include <QLineEdit>


#include "stable.h"
#include "helpbutton.h"
#include "namepanel.h"
#include "centralpanel.h"
#include "leftpanel.h"
#include "bottompanel.h"
#include "dbwork.h"
#include "mylineedit.h"
#include "tester.h"
#include "psyhtest.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT



    NamePanel* NamePnl;
    HelpButton* HelpBtn;

    LeftPanel* LeftPnl;

    CentralPanel* CentralPnl;
    BottomPanel* BottomPnl;
    BottomPanel* HeaderPnl;

    dbWork* DB;


    QMenu* Menu;

    Tester* tester;

    int EtapNum;


    void AddPanels();


    void GetInfoFromDB();


//    void AddNamePanel(NamePanel* _WGT);
//    void AddLeftPanel(QWidget* _WGT);
//    void AddHelpButton(QWidget* _WGT);
//    void AddMenu();



public:
    MainWindow(QWidget *parent = 0);
    QSplashScreen* Zastavka;
    ~MainWindow();



private:
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);

signals:

    void NeedRefresh();
    void EnterPressed();

public slots:


    void Refresh();
    void SetEtap(int _num);
    void RenameSubEtap(QString);
    void RenameMainName(QString);


};

#endif // MAINWINDOW_H
