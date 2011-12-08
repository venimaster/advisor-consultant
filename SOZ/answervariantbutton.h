#ifndef ANSWERVARIANTBUTTON_H
#define ANSWERVARIANTBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QRgb>
#include "testerdaleebutton.h"

class AnswerVariantButton : public QWidget
{
    Q_OBJECT

    double weight;
    QString label;

    const TesterDaleeButton* OK;

    int ID;

    bool Choosen;

public:
    explicit AnswerVariantButton(int &ID, QString &lbl, double &weight,const TesterDaleeButton* _OK, QWidget *parent = 0);
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



signals:

    void iPressed(int);

public slots:

};

#endif // ANSWERVARIANTBUTTON_H
