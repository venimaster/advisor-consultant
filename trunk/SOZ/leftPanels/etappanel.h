#ifndef ETAPPANEL_H
#define ETAPPANEL_H

#include "../stable.h"
#include "../etapbutton.h"

class EtapPanel : public QWidget
{
    Q_OBJECT

    int amount;
    QVector <EtapButton* > etaps;

    double BtnWidth;
    double BtnHeight;

    void addButton(int _num, QString Name = "");
    void setButtonSize(double Wid, double Hei);

public:
    explicit EtapPanel(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:
    void ButtonPressed(int);

public slots:
    void unPress(int);

};

#endif // ETAPPANEL_H
