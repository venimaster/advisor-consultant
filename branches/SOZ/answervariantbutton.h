#ifndef ANSWERVARIANTBUTTON_H
#define ANSWERVARIANTBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

class AnswerVariantButton : public QWidget
{
    Q_OBJECT

    double weight;
    QString label;

    int ID;

    bool Choosen;

public:
    explicit AnswerVariantButton(int &ID, QString &lbl, double &weight, QWidget *parent = 0);

    void setLabel (QString &lbl);
    void setWeight (double &_weight);
    int GetID();
    void SetUnChoosen();

    bool isChoosen();

protected:

    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);



signals:

    void iPressed(int);

public slots:

};

#endif // ANSWERVARIANTBUTTON_H
