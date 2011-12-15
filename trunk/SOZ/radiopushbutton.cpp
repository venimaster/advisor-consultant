#include "radiopushbutton.h"
#include <QDebug>

RadioPushButton::RadioPushButton(int _ID, const QString &_label, QWidget *parent) :
    QWidget(parent)
{
    label = _label;
    ID = _ID;
    mouseOn = false;
    checked = false;
}

void RadioPushButton::enterEvent(QEvent *)
{
    mouseOn=true;
    update();
}

void RadioPushButton::leaveEvent(QEvent *)
{
    mouseOn=false;
    update();
}

void RadioPushButton::mousePressEvent(QMouseEvent *)
{
    checked = true;
    update();
}

void RadioPushButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    int Alph;

    QColor color(Qt::white);
    if (checked)
        Alph=150;
    else
        if (mouseOn)
            Alph = 100;
        else
            Alph = 150;

    color.setAlpha(Alph);

    QPen pen(Qt::white);
    QFont font("Times",13,QFont::Bold);
    QBrush Brs(color);

    painter.setBrush(Brs);
    painter.setPen(pen);
    painter.setFont(font);

    painter.drawRect(rect());
    painter.drawText(rect(),Qt::AlignCenter,label);

    painter.end();


}

void RadioPushButton::resizeEvent(QResizeEvent *)
{
    update();

}
