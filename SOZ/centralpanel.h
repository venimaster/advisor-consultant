#ifndef CENTRALPANEL_H
#define CENTRALPANEL_H

//#include <QWidget>
//#include <QPainter>
//#include <QPushButton>
//#include <QDebug>
#include "stable.h"
#include "answervariantbutton.h"
#include "testerdaleebutton.h"


class CentralPanel : public QWidget
{
    Q_OBJECT

    QString Question;
    QVector<QString> varAnswers;
    QVector<double> weightAnswers;
    QVector<AnswerVariantButton *> AnswersBtns;

    QRect QuestionRect;
    QRect AnswersRect;
    QRect ButtonsRect;

    QImage BrainImg;
    QImage BrainSourceImg;
    QPixmap BrainPixmap;


    void drawButtons();
    void updateWidgets();
    void updateBrain();
    void resizeAnswerButtons();


public:
    explicit CentralPanel(QWidget *parent = 0);

    TesterDaleeButton* OK;

    void drawAnswers();


    void SetQuestion(const QString &_quest);
    void SetAnswers(const QVector<QString> &Ans);
    void SetWeightAnswers(const QVector<QString> &WeightAns);


protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);


signals:

public slots:
    void UnClick(int N);

};

#endif // CENTRALPANEL_H
