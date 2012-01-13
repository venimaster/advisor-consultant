#ifndef AUTORISATIONPANEL_H
#define AUTORISATIONPANEL_H

#include "../stable.h"
#include "../mylineedit.h"
#include "../testerdaleebutton.h"
#include "../dbwork.h"



class AutorisationPanel : public QWidget
{

    QRect NameRect;
    QRect NickNameLblRect;
    QRect PasswdLblRect;


    double LineEditHeight;
    double ButtonHeight;
    double LblHeight;

    QString Name;

    MyLineEdit* NickName;
    MyLineEdit* Passwd;
    TesterDaleeButton* OK;
    TesterDaleeButton* Reg;

    QString Nick;
    QString Pass;

    dbWork *DB;


    QString ErrorMsg;


    void resizeWidgets();







    Q_OBJECT
public:
    explicit AutorisationPanel(QWidget *parent = 0);
    void setDB(dbWork *_db);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:
    void sendData(const QString &_log, const QString &_pass);
    void checkInput(bool);
    void sendError(const QString &_ErrMsg);
    void doRegistration(int);
    void getEtaps(int);

public slots:
    void getNickName(QString="");
    void getPass(QString="");
    void unlockOK(bool b);
    void doReg();
    void enter();




};

#endif // AUTORISATIONPANEL_H
