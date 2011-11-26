#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QLabel>
#include <QStatusBar>

#include "startwin.h"
#include "dialog.h"
#include "wizard.h"
#include "mywizard.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    StartWin* StartWindow;

    MyWizard* SecondWindow;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *);

public slots:
    void GoToSecond();

};

#endif // MAINWINDOW_H
