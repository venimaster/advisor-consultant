#ifndef AUTORISATIONPANEL_H
#define AUTORISATIONPANEL_H

#include <QWidget>
#include "../mylineedit.h"
#include "../testerdaleebutton.h"
#include <QPainter>
#include <QRegExpValidator>
#include <QRegExp>


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


    QString ErrorMsg;


    void resizeWidgets();






    Q_OBJECT
public:
    explicit AutorisationPanel(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:
    void sendData(const QString &_log, const QString &_pass);
    void checkInput(bool);
    void sendError(const QString &_ErrMsg);

public slots:
    void getNickName(QString);
    void getPass(QString);
    void unlockOK(bool b);




};

#endif // AUTORISATIONPANEL_H
