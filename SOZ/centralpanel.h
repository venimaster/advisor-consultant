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


class CentralPanel : public QWidget
{
    Q_OBJECT

    TestPanel *TP;
    HelpPanel *HP;


    QImage BrainImg;
    QImage BrainSourceImg;
    QPixmap BrainPixmap;

    void updateBrain();

    void changeWgt(const int _num);


public:
    explicit CentralPanel(QWidget *parent = 0);

    void addTestPanel();

    void updateWidgets();

    TestPanel *getTestPanel();



protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);


signals:
    void sig_enterPressed();
    void sig_askNextQuestion();

public slots:
    void slot_enterPressed();
    void slot_askNextQuestion();
    void needHelp();
    void dontNeedHelp();

};

#endif // CENTRALPANEL_H
