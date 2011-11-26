#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QLabel>
#include <QStatusBar>
#include <QMouseEvent>
#include <QDockWidget>

#include "startwin.h"
#include "dialog.h"
#include "wizard.h"
#include "mywizard.h"
#include "etap.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    StartWin* StartWindow;

    MyWizard* SecondWindow;

    QVector<Etap*> EtapBtns;

    QDockWidget* EtapsWGT;
    QWidget* LeftPanel;



public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *);

public slots:
    void GoToSecond();

};

#endif // MAINWINDOW_H
