#include "helpbutton.h"

HelpButton::HelpButton(QWidget *parent) :
    QWidget(parent)
{

}

void HelpButton::paintEvent(QPaintEvent *)
{
    QPen pen(Qt::black);
    QBrush Brs(Qt::black);

    QPixmap pixmap("C:/Projects/SOZ/Images/Help.png");
    pixmap=pixmap.scaled(width(),height());

    QPainter painter(this);
    painter.setBrush(Brs);
    painter.setPen(pen);
    painter.drawRect(rect());
    painter.drawPixmap(rect(),pixmap);
    painter.end();

}

void HelpButton::mousePressEvent(QMouseEvent *)
{


}
