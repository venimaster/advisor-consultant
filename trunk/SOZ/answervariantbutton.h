#ifndef ANSWERVARIANTBUTTON_H
#define ANSWERVARIANTBUTTON_H

//#include <QWidget>
//#include <QPainter>
//#include <QDebug>
//#include <QRgb>
#include "stable.h"
#include "testerdaleebutton.h"

class AnswerVariantButton : public QWidget
{
    Q_OBJECT

    double weight;
    QString label;

    TesterDaleeButton* OK;

    int ID;

    bool Choosen;
    bool MouseOn;

public:
    explicit AnswerVariantButton(int &ID, QString &lbl, double &weight, TesterDaleeButton* _OK, QWidget *parent = 0);
    ~AnswerVariantButton();

    void setLabel (QString &lbl);
    void setWeight (double &_weight);
    int GetID();
    void SetUnChoosen();

    bool isChoosen();

protected:

    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);


signals:

    void iPressed(int);

public slots:

};

#endif // ANSWERVARIANTBUTTON_H
