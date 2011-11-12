#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDateTime>
#include <QFileDialog>
#include <QSpinBox>
#include <QTableWidget>
#include <QSqlDatabase>
#include <QLineEdit>
#include <QMainWindow>
#include <QTextCodec>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QCheckBox>
#include <QFileDialog>
#include <QWidget>
#include <QSqlError>
#include <QSqlQuery>

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
     MainWindow();
     ~MainWindow();

private:
     QAction *actionExit;
     QAction *actionAbout;
     QMenu *menuFile;
     QMenu *menuHelp;
     QLabel *labelMenu;
     QPushButton *butAdd;
     QPushButton *butDelete;
     QLineEdit *lineEdit;
     QSpinBox *spinBox;
     QVBoxLayout *vlayout;
     QHBoxLayout *hlayout;
     QWidget *mainWidget;
     QTableWidget *tableWidget;

     QSqlDatabase db;

     void RefreshTable();

private slots:
     void slotAdd();
     void slotDelete();
     void slotAbout();
};

#endif // MAINWINDOW_H
