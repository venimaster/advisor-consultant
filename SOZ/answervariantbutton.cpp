#include "answervariantbutton.h"

AnswerVariantButton::AnswerVariantButton(int &_ID, QString &lbl, double &weight, TesterDaleeButton *_OK, QWidget *parent) :
    QWidget(parent)
{
    ID = _ID;
    setLabel(lbl);
    setWeight(weight);

    Choosen=false;
    MouseOn = false;

    OK=_OK;


    update();




}

void AnswerVariantButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing,true);
    if (Choosen)
    {

        QColor color(Qt::white);
        color.setAlpha(100);

        painter.setBrush(QBrush(color));
        painter.setPen(QPen(Qt::white));
        painter.setFont(QFont("Times",13,QFont::Bold));

    }
    else
    {
        if (!MouseOn)
        {

            QColor color(Qt::gray);
            color.setAlpha(50);

            painter.setBrush(QBrush(color));
            painter.setPen(QPen(Qt::white));
            painter.setFont(QFont("Times",13,QFont::Bold));

        }
        else
        {
            QColor color(Qt::white);
            color.setAlpha(70);

            painter.setBrush(QBrush(color));
            painter.setPen(QPen(Qt::white));
            painter.setFont(QFont("Times",13,QFont::Bold));


        }
    }
    painter.drawRect(rect());

    painter.drawText(rect(),Qt::AlignCenter | Qt::TextWordWrap,label);

    painter.end();




}

void AnswerVariantButton::mousePressEvent(QMouseEvent *)
{
    emit (iPressed(ID));

    if (Choosen)
        OK->setDisAvilable();
    else
    {
        OK->setAvilable();
        OK->changeWeight(weight);
    }
    OK->update();


    Choosen = !Choosen;



    update();


}

void AnswerVariantButton::resizeEvent(QResizeEvent *)
{
    update();

}

void AnswerVariantButton::enterEvent(QEvent *)
{
    MouseOn=true;
    update();
}

void AnswerVariantButton::leaveEvent(QEvent *)
{
    MouseOn=false;
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
    update();

}

bool AnswerVariantButton::isChoosen()
{
    return Choosen;
}

AnswerVariantButton::~AnswerVariantButton()
{
    OK->setDisAvilable();
    OK->update();
}
