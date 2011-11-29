#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QSplashScreen>
#include <QResizeEvent>
#include <QDebug>

#include "helpbutton.h"
#include "namepanel.h"
#include "centralpanel.h"
#include "leftpanel.h"
#include "bottompanel.h"
#include "dbwork.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT



    NamePanel* NamePnl;
    HelpButton* HelpBtn;

    LeftPanel* LeftPnl;
    LeftPanel* RegPnl;

    CentralPanel* CentralPnl;
    BottomPanel* BottomPnl;
    BottomPanel* HeaderPnl;

    dbWork* DB;


    QMenu* Menu;

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

signals:

    void NeedRefresh();

public slots:


    void Refresh();
    void SetEtap(int _num);

};

#endif // MAINWINDOW_H
