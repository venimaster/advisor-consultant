#ifndef TESTER_H
#define TESTER_H

//#include <QObject>

#include "stable.h"
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

    int ChoozenVariantNumber;

    QString table;


    int EtapNum;
    int SubEtapNum;

    void AskQuestion(int QuestNumber);


public:
    explicit Tester(CentralPanel *CP, dbWork *_DB, QObject *parent = 0);

    void SetQuestions();
    void SetAnswers();

    void ChangeChoozenVariantNumber(int num);

    void Test_I_I();
    void Test_I_II();
    void Test_I_III();

    void Test_II_I();
    void Test_III_I();
    void Test_IV_I();
    void Test_V_I();


signals:

    void RenameSubEtap(QString str);

public slots:

    void NextQuestion();

};

#endif // TESTER_H
