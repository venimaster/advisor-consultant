#include "psyhtestvariantbutton.h"

PsyhTestVariantButton::PsyhTestVariantButton(int ID, int GroupID, QString lbl,int weight, QWidget *parent) :
    QWidget(parent)
{
    this->ID=ID;
    this->GroupID=GroupID;
    this->label=lbl;
    this->weight=weight;

    update();
}

void PsyhTestVariantButton::paintEvent(QPaintEvent *)
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

void PsyhTestVariantButton::mousePressEvent(QMouseEvent *)
{
    emit (iPressed(ID,GroupID));



    update();


}

void PsyhTestVariantButton::resizeEvent(QResizeEvent *)
{
    update();
}

void PsyhTestVariantButton::enterEvent(QEvent *)
{
    MouseOn=true;
    update();
}

void PsyhTestVariantButton::leaveEvent(QEvent *)
{
    MouseOn=false;
    update();
}

void PsyhTestVariantButton::setLabel(QString &lbl)
{
    label = lbl;
}

void PsyhTestVariantButton::setWeight(double &_weight)
{
    weight=_weight;

}

int PsyhTestVariantButton::GetID()
{
    return ID;
}

int PsyhTestVariantButton::GetGroupID()
{
    return GroupID;
}

void PsyhTestVariantButton::SetUnChoosen()
{
    Choosen=false;
    update();

}
void PsyhTestVariantButton::SetChoosen()
{
    Choosen=true;
    update();
}

bool PsyhTestVariantButton::isChoosen()
{
    return Choosen;
}
