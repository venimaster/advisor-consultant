#include "answervariantbutton.h"

AnswerVariantButton::AnswerVariantButton(int &_ID, QString &lbl, double &weight, QWidget *parent) :
    QWidget(parent)
{
    ID = _ID;
    setLabel(lbl);
    setWeight(weight);
    Choosen=false;

    update();




}

void AnswerVariantButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (Choosen)
    {
        painter.setBrush(QBrush(Qt::white));
        painter.setPen(QPen(Qt::gray));
        painter.setFont(QFont("Times",10,QFont::Bold));
    }
    else
    {
        painter.setBrush(QBrush(Qt::black));
        painter.setPen(QPen(Qt::white));
        painter.setFont(QFont("Times",10,QFont::Bold));

    }

    painter.drawRect(rect());

    painter.end();

    qDebug()<<size();



}

void AnswerVariantButton::mousePressEvent(QMouseEvent *)
{
    emit (iPressed(ID));

    Choosen = !Choosen;

    update();


}

void AnswerVariantButton::resizeEvent(QResizeEvent *)
{
    update();

}

void AnswerVariantButton::setLabel(QString &lbl)
{
    label = lbl;
}

void AnswerVariantButton::setWeight(double &_weight)
{
    weight=_weight;

}

int AnswerVariantButton::GetID()
{
    return ID;
}

void AnswerVariantButton::SetUnChoosen()
{
    Choosen=!Choosen;

}

bool AnswerVariantButton::isChoosen()
{
    return Choosen;
}
