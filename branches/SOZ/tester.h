#ifndef TESTER_H
#define TESTER_H

#include <QObject>

#include "dbwork.h"
#include "centralpanel.h"

class Tester : public QObject
{
    Q_OBJECT

    QVector<QString> Questions;
    QVector<QString> VarAnswers;

    dbWork* DB;
    CentralPanel* CP;

    int QuestionNum;
    int QuestionAll;

    void AskQuestion(int QuestNumber);


public:
    explicit Tester(CentralPanel *CP, dbWork *_DB, QObject *parent = 0);

    void SetQuestions();
    void SetAnswers();

    void Test_I();

signals:

public slots:

    void NextQuestion();

};

#endif // TESTER_H
