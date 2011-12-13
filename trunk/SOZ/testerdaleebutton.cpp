#include "testerdaleebutton.h"

TesterDaleeButton::TesterDaleeButton(QWidget *parent) :
    QWidget(parent)
{
    BgColor = QColor(Qt::white);
    Alpha = 100;
    Avilable = false;

    label = "Далее";

    Grad = new Gradients();

    Obrab = new Obrabotchik();

    FontSize = 15;

    update();
}

bool TesterDaleeButton::isAvilable()
{
    return Avilable;
}

void TesterDaleeButton::setAvilable()
{
    Avilable = true;
    update();
}

void TesterDaleeButton::setDisAvilable()
{

    Avilable = false;
    update();
}

void TesterDaleeButton::mousePressEvent(QMouseEvent *)
{
    if (isAvilable())
    {
        emit iPressed();
        Obrab->addAnswer(weight);
    }
        update();
}


void TesterDaleeButton::enterPressed()
{
    if (isAvilable())
    {
        emit iPressed();
        Obrab->addAnswer(weight);
    }
    update();

}

void TesterDaleeButton::enterEvent(QEvent *)
{
    Alpha = 150;
        MouseOn = true;
    update();
}

void TesterDaleeButton::leaveEvent(QEvent *)
{
    Alpha = 100;
    MouseOn = false;
    update();
}

void TesterDaleeButton::paintEvent(QPaintEvent *)
{



    BgColor.setAlpha(100);

    QBrush Brs(BgColor);
    QPen Pen(Qt::white);
    QFont MyFont ("TIMES",FontSize,QFont::Bold);


    QPainter painter(this);

    if (!MouseOn and isAvilable())
        Brs = QBrush(Grad->getDaleeGrad(width()/2,0,width()/2,height()));
    if (MouseOn and isAvilable())
        Brs = QBrush(Grad->getDaleeGrad(width()/2,0,width()/2,height(),1));

    if (!isAvilable())
    {

        Brs = QBrush(Grad->getDaleeGrad(width()/2,0,width()/2,height(),2));
    }


    painter.setPen(Pen);
    painter.setFont(MyFont);
    painter.setBrush(Brs);

    painter.drawRect(rect());

    painter.drawText(rect(),Qt::AlignCenter | Qt::TextWordWrap,label);

    painter.end();
}

void TesterDaleeButton::resizeEvent(QResizeEvent *)
{
    update();

}

void TesterDaleeButton::changeWeight(double &_weight)
{
    weight = _weight;
}

void TesterDaleeButton::setName(const QString &_label)
{
    label=_label;
    update();
}

void TesterDaleeButton::setFontSize(int _fontsize)
{
    FontSize = _fontsize;
}
