#ifndef REGISTRATIONPANEL_H
#define REGISTRATIONPANEL_H

#include "../stable.h"
#include "../mylineedit.h"
#include "../testerdaleebutton.h"
#include "../dbwork.h"

class RegistrationPanel : public QWidget
{
    QRect NameRect;
    QRect NickNameLblRect;
    QRect PasswdLblRect;
    QRect ConfPasswdLblRect;
    QRect FIORect;
    QRect SexRect;
    QRect AgeRect;
    QRect ProjRect;

    int type;



    double LineEditHeight;
    double ButtonHeight;
    double LblHeight;

    QString Name;

    MyLineEdit* NickName;
    MyLineEdit* Passwd;
    MyLineEdit* ConfPasswd;
    MyLineEdit* FIO;
    MyLineEdit* Sex;
    MyLineEdit* Age;
    MyLineEdit* Project;

    TesterDaleeButton* OK;
    TesterDaleeButton* Reg;

    QString Nick;
    QString Pass;
    QString ConfPassStr;
    QString FIOStr;
    QString SexStr;
    QString AgeStr;
    QString ProjectStr;
    bool AgeB;

    dbWork* DB;


    QVector<QString> ErrorMsgs;

    QString ErrorMsg;
    QString GroupName;


    void resizeWidgets();


    Q_OBJECT
public:
    explicit RegistrationPanel(const int _type, QWidget *parent = 0);
    void setDB(dbWork *_db);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:
    void sendData(const QString &_log, const QString &_pass, const QString &_FIO, const QChar &_Sex, const int age);
    void checkInput();
    void sendError(const QString &_ErrMsg);
    void doAutorisation(int);
    void getEtaps(int);


public slots:
    void getNickName(QString = "");
    void getPass(QString = "");
    void getConfirmPass(QString = "");
    void getFIO(QString = "");
    void getSex(QString = "");
    void getAge(QString = "");
    void writeUser();
    void unlockOK();

    void doAut();

};

#endif // REGISTRATIONPANEL_H
