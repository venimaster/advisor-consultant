#ifndef TESTPANEL_H
#define TESTPANEL_H

//#include <QWidget>
//#include <QPainter>
//#include <QPushButton>
//#include <QDebug>
#include "stable.h"
#include "answervariantbutton.h"
#include "testerdaleebutton.h"


class TestPanel : public QWidget
{
    Q_OBJECT

    QString Question;
    QVector<QString> varAnswers;
    QVector<double> weightAnswers;
    QVector<AnswerVariantButton *> AnswersBtns;

    QRect QuestionRect;
    QRect AnswersRect;
    QRect ButtonsRect;


    TesterDaleeButton* OK;


    void drawButtons();
    void updateWidgets();
    void resizeAnswerButtons();


public:
    explicit TestPanel(QWidget *parent = 0);


    void drawAnswers();


    void SetQuestion(const QString &_quest);
    void SetAnswers(const QVector<QString> &Ans);
    void SetWeightAnswers(const QVector<QString> &WeightAns);


protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);


signals:
    void sig_enterPressed();
    void sig_nextPressed();

public slots:
    void UnClick(int N);
    void slot_enterPressed();
    void slot_nextPressed();

};

#endif // TESTPANEL_H
