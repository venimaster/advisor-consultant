#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include <QWidget>
#include <QPainter>
#include <QApplication>

#include "etapbutton.h"

class LeftPanel : public QWidget
{
    Q_OBJECT

    QVector<EtapButton* > Buttons;
    double BtnWidth;
    double BtnHeight;
    int PressBtnNumber;

    int Status; //1-окошко входа в систему, 2-окошко

    QRectF ButtonsRect;
    QRectF LabelRect;

    QString LabelText;




    void addButton(int _num, QString Name = "");
    void setButtonSize(double Wid, double Hei);

    void addButtons();
    void addLoginPanel();
    void addRegistrationPanel();


public:
    explicit LeftPanel(int _status, QWidget *parent = 0);
    void setLabel(QString lbl);
    void setStatus(int _stat);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:
    void ButtonPressed(int num);

public slots:
    void unPress(int num);

};

#endif // LEFTPANEL_H
