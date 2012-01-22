#ifndef CENTRALPANEL_H
#define CENTRALPANEL_H

//#include <QWidget>
//#include <QPainter>
//#include <QPushButton>
//#include <QDebug>
#include "stable.h"
#include "answervariantbutton.h"
#include "testerdaleebutton.h"
#include "testpanel.h"
#include "helppanel.h"
#include "hipanel.h"
#include "psyhtest.h"
#include "dbwork.h"


class CentralPanel : public QWidget
{
    Q_OBJECT

    TestPanel *TP;
    HelpPanel *HP;
    HelpPanel *LP;
    HiPanel* HiP;

    PsyhTest* PsTest;

    QVector <PsyhTest*> Psychs;
    QVector <PsyhTest*> Etaps;

    QScrollBar* PsScr;
    int ScrPrev;
    int ScrNext;

    int WgtNum;
    int PrevWgtNum;



    QImage BrainImg;
    QImage BrainSourceImg;
    QPixmap BrainPixmap;

    dbWork* DB;


    void updateBrain();

    void changeWgt(const int _num);


public:
    explicit CentralPanel(dbWork* _db,QWidget *parent = 0);

    void addTestPanel();

    void updateWidgets();

    TestPanel *getTestPanel();



protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);


signals:
    void sig_enterPressed();
    void sig_askNextQuestion();

    void changeMainName(QString);
    void changeLeftPanLabel(QString);
    void changeCentralName(QString);

public slots:
    void slot_enterPressed();
    void slot_askNextQuestion();
    void needHelp();
    void dontNeedHelp();
    void scrollMove(int pos);
    void changeScroll(int _h);

};

#endif // CENTRALPANEL_H
