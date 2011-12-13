#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include <QWidget>
#include <QPainter>
#include <QApplication>

#include "etapbutton.h"
#include "leftPanels/regpanel.h"
#include "leftPanels/etappanel.h"
#include "leftPanels/autorisationpanel.h"

class LeftPanel : public QWidget
{
    Q_OBJECT

    int Status; //1-окошко входа в систему, 2-окошко

    QRectF ButtonsRect;
    QRectF LabelRect;

    QString LabelText;
    QString ErrorMsg;


    RegPanel *regPnl;
    EtapPanel *etapPnl;
    AutorisationPanel *autPanel;



    void addEtapPanel();
    void addLoginPanel();
    void addRegistrationPanel();
    void addAutorisationPanel();


public:
    explicit LeftPanel(int _status, QWidget *parent = 0);
    void setLabel(QString lbl);
    void setStatus(int _stat);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:
    void EtapButtonPressed(int);

public slots:
    void EtapButtonCalls(int);
    void RegDataCatch(const QString &_log, const QString &_pass);
    void catchError(const QString &_errMsg);

};

#endif // LEFTPANEL_H
