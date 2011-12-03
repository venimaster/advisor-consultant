#include "bottompanel.h"

BottomPanel::BottomPanel(int _type, QWidget *parent) :
    QWidget(parent)
{
    type=_type;
}

void BottomPanel::SetText(QString _text)
{
    Text=_text;
    update();

}

void BottomPanel::SetFontSize(int _size)
{
    FontSize=_size;
}

void BottomPanel::paintEvent(QPaintEvent *)
{
    QPen pen(Qt::white);
    QBrush Brs(Qt::black);
    QFont Font("Times",FontSize);

    QPainter painter(this);
    painter.setBrush(Brs);
    painter.setPen(QPen(Qt::black));
    painter.setFont(Font);
    painter.drawRect(rect());

    painter.setPen(pen);
    painter.drawText(rect(),Qt::AlignCenter,Text);

    painter.setRenderHint(QPainter::Antialiasing,true);

    if (type==1)
    painter.drawEllipse(0,height()-1,width(),1);

    if (type==2)
    painter.drawEllipse(0,0,width(),1);

    painter.setRenderHint(QPainter::Antialiasing,false);


    painter.end();


}
