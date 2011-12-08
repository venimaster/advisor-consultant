#include "testerdaleebutton.h"

TesterDaleeButton::TesterDaleeButton(QWidget *parent) :
    QWidget(parent)
{
    BgColor = QColor(Qt::white);
    Alpha = 100;
    Avilable = true;

    label = "Далее";

    update();
}

bool TesterDaleeButton::isAvilable()
{
    return Avilable;
}

void TesterDaleeButton::setAvilable()
{
    Avilable = true;
}

void TesterDaleeButton::setDisAvilable()
{

    Avilable = false;
}

void TesterDaleeButton::mousePressEvent(QMouseEvent *)
{
    if (isAvilable())
        emit iPressed();
    update();
}

void TesterDaleeButton::enterEvent(QEvent *)
{
    Alpha = 150;
    update();
}

void TesterDaleeButton::leaveEvent(QEvent *)
{
    Alpha = 100;
    update();
}

void TesterDaleeButton::paintEvent(QPaintEvent *)
{

    BgColor.setAlpha(Alpha);

    QBrush Brs(BgColor);
    QPen Pen(Qt::white);
    QFont MyFont ("TIMES",15,QFont::Bold);

    if (!isAvilable())
    {
        Brs.setStyle(Qt::DiagCrossPattern);
    }
    else Brs.setStyle(Qt::SolidPattern);

    QPainter painter(this);
    painter.setBrush(Brs);
    painter.setPen(Pen);
    painter.setFont(MyFont);

    painter.drawRect(rect());

    painter.drawText(rect(),Qt::AlignCenter | Qt::TextWordWrap,label);

    painter.end();
}

void TesterDaleeButton::resizeEvent(QResizeEvent *)
{
    update();

}

