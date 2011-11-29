#include "etapbutton.h"

EtapButton::EtapButton(int _num, QString _Name, QWidget *parent) :
    QWidget(parent)
{

    if (_Name!="")
            Name = _Name;

    status = 0;
    number=_num;

}

void EtapButton::paintEvent(QPaintEvent *)
{
    QFont Font;
    QPen Pen;
    QBrush Brush;


    QPainter painter(this);

    switch (status)
    {
        case 0:
            Font = QFont("Times",20);
            Pen = QPen(Qt::darkGray);
            Brush = QBrush(Qt::black);

        break;
        case 1:
            Font = QFont("Times",20);
            Pen = QPen(Qt::lightGray,3);
            Brush = QBrush(Qt::black);
            painter.drawRoundedRect(rect(),10,10);

        break;
        case 2:
            Font = QFont("Times",20);
            Pen = QPen(Qt::white,5);
        break;



    }

    painter.setFont(Font);
    painter.setBrush(Brush);
    painter.setPen(Pen);
    if (status!=0)
        painter.drawRoundedRect(rect(),10,10);

    painter.drawText(rect(),Qt::AlignCenter,Name);
    painter.end();


}

void EtapButton::SetLabel(QString label)
{
    Lbl = label;
    update();
}

void EtapButton::SetName(QString name)
{
    Name = name;
    update();
}

void EtapButton::enterEvent(QEvent *)
{
    if (!isPressed)
        status=1;
    update();

}
void EtapButton::leaveEvent(QEvent *)
{
    if(!isPressed)
        status=0;
    update();

}
void EtapButton::mousePressEvent(QMouseEvent *)
{
    isPressed = !isPressed;
    status=2;

    emit iPressed(number);
    update();

}


