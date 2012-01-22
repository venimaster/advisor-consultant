#ifndef PSYHTEST_H
#define PSYHTEST_H

#include <QWidget>
#include "../stable.h"
#include "../dbwork.h"
#include "../testerdaleebutton.h"
#include "psyhtestvariantbutton.h"

class PsyhTest : public QWidget
{
    Q_OBJECT


    QString TestName;
    QString DopMSG;

    QVector<QString> Variants;
    QVector<QString> Questions;
    QString QuestionName;
    double QuestionWeight;

    int timeStart;
    int timeFin;

    int MaxHeight;

    QString login;
    int UserType;

    int OldPos;



    int TestNum; // 1-творец/мыслитель, 2-ригидность/гибкость, 3-тип темперамента, 4 - полезависимость/поленезависимость, 5-тест на профпригодность эксперта 6-тест на профпригодность ИЗ

    int qTests;
    int qQuestions;
    int qVariants;

    dbWork* DB;

    void countParams();

    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
    void test6();

    void globalTest1();
    void globalTest2();
    void globalTest3();
    void globalTest4();
    void globalTest5();


    QVector<QString> Msgs;


    TesterDaleeButton* Dalee;

    QGridLayout* Lay;

    QVector <PsyhTestVariantButton*> AllBtns;
    QVector <int> ChoosenVars;





public:
    explicit PsyhTest(dbWork* _db, int _TestNum, QString login, QWidget *parent = 0);
    void SetDB(dbWork* db);
    void startTest();
    void renameNames();
    void setLogin(QString _login);
    void setUserType(int _type);
    void moveUp(int);


protected:
    void resizeEvent(QResizeEvent *);

    
signals:

    void changeMainName(QString);
    void changeLeftPanLabel(QString);
    void changeCentralName(QString);
    void heightChanged(int);

    void sendItog(QVector<QString>);
    
public slots:

    void changeVariant(int Var,int Quest);
    void obrabotka();
    void setQuestion(int _quest);
    
};

#endif // PSYHTEST_H
