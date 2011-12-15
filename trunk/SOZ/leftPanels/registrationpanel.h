#ifndef REGISTRATIONPANEL_H
#define REGISTRATIONPANEL_H

//#include <QWidget>
//#include <QRegExpValidator>
#include "../stable.h"
#include "../mylineedit.h"
#include "../testerdaleebutton.h"

class RegistrationPanel : public QWidget
{
    QRect NameRect;
    QRect NickNameLblRect;
    QRect PasswdLblRect;
    QRect ConfPasswdLblRect;
    QRect FIORect;
    QRect SexRect;
    QRect AgeRect;


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

    TesterDaleeButton* OK;
    TesterDaleeButton* Reg;

    QString Nick;
    QString Pass;
    QString ConfPassStr;
    QString FIOStr;
    QString SexStr;
    QString AgeStr;
    bool AgeB;


    QVector<QString> ErrorMsgs;

    QString ErrorMsg;


    void resizeWidgets();


    Q_OBJECT
public:
    explicit RegistrationPanel(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:
    void sendData(const QString &_log, const QString &_pass, const QString &_FIO, const QChar &_Sex, const int age);
    void checkInput();
    void sendError(const QString &_ErrMsg);

public slots:
    void getNickName(QString);
    void getPass(QString);
    void getConfirmPass(QString);
    void getFIO(QString);
    void getSex(QString);
    void getAge(QString);
    void unlockOK();

};

#endif // REGISTRATIONPANEL_H
