#ifndef LEFTPANEL_H
#define LEFTPANEL_H

//#include <QWidget>
//#include <QPainter>
//#include <QApplication>

#include "stable.h"
#include "etapbutton.h"
#include "leftPanels/regpanel.h"
#include "leftPanels/etappanel.h"
#include "leftPanels/autorisationpanel.h"
#include "leftPanels/registrationpanel.h"
#include "dbwork.h"
#include "helpbutton.h"
#include "literature.h"

class LeftPanel : public QWidget
{
    Q_OBJECT

    int Status; //1-окошко входа в систему, 2-окошко

    QRectF ButtonsRect;
    QRectF LabelRect;

    QString LabelText;
    QString ErrorMsg;


    RegPanel *choosePanel;
    EtapPanel *etapPnl;
    AutorisationPanel *autPanel;
    RegistrationPanel *regPanel;

    HelpButton *HB;
    Literature *LB;

    dbWork* DB;



    void addHelpButton();

    void addEtapPanel();
    void addLoginPanel();
    void addRegistrationPanel();
    void addAutorisationPanel();


public:
    explicit LeftPanel(int _status, QWidget *parent = 0);
    void setStatus(int _stat);
    void setDB(dbWork *_db);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:
    void EtapButtonPressed(int);
    void showHelp();

public slots:
    void EtapButtonCalls(int);
    void RegDataCatch(const QString &_log, const QString &_pass);
    void catchError(const QString &_errMsg);
    void changeWGT(int st);
    void setLabel(QString lbl);

};

#endif // LEFTPANEL_H
