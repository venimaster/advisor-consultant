#include "answervariantbutton.h"

AnswerVariantButton::AnswerVariantButton(int &_ID, QString &lbl, double &weight, const TesterDaleeButton *_OK, QWidget *parent) :
    QWidget(parent)
{
    ID = _ID;
    setLabel(lbl);
    setWeight(weight);
    Choosen=false;

    OK=_OK;

    update();




}

void AnswerVariantButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QColor MyColor(Qt::lightGray);
    MyColor.setAlpha(100);

    painter.setRenderHint(QPainter::Antialiasing,true);
    if (Choosen)
    {

        QColor color(Qt::white);
        color.setAlpha(100);

        painter.setBrush(QBrush(MyColor));
        painter.setPen(QPen(Qt::gray));
        painter.setFont(QFont("Times",13,QFont::Bold));

        painter.setPen(QPen(Qt::white));
//        painter.drawEllipse(0,1,width(),2);
//        painter.drawEllipse(0,height()-1,width(),2);
    }
    else
    {

        QColor color(Qt::gray);
        color.setAlpha(50);

        painter.setBrush(QBrush(color));
        painter.setPen(QPen(Qt::white));
        painter.setFont(QFont("Times",13,QFont::Bold));

    }

    painter.drawRect(rect());

    painter.drawText(rect(),Qt::AlignCenter | Qt::TextWordWrap,label);

    painter.end();




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

void AnswerVariantButton::enterEvent(QEvent *)
{

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
    qDebug()<<"iDestruct";
}
