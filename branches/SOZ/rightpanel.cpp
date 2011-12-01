#include "rightpanel.h"

RightPanel::RightPanel(QWidget *parent) :
    QWidget(parent)
{
    Label = "";
}

void RightPanel::setLabel(QString _lbl)
{


    Label = _lbl;
    update();

}

void RightPanel::paintEvent(QPaintEvent *)
{
    QPen pen(Qt::black);
    QBrush Brs(Qt::gray);

    QFont Font("Times",13,QFont::Bold);

    QPainter painter(this);
    painter.setFont(Font);
    painter.setBrush(Brs);
    painter.setPen(pen);
    painter.drawRect(rect());

    painter.drawText(rect(), Qt::AlignHCenter | Qt::TextWordWrap, Label);

    painter.end();

    qDebug()<<size();



}
