#include "etap.h"
#include <QDebug>

Etap::Etap(QString _Name, QString _Label, int _Num, QWidget *parent) :
    QWidget(parent)
{
    EtapName = _Name;
    EtapLabel = _Label;
    EtapNum = _Num;
    isActive=false;

    setMouseTracking(true);

    //resize(100,100);

    Brs=QBrush(Qt::white);

    update();
}

void Etap::paintEvent(QPaintEvent *)
{


    QPen Pen(Qt::white,50);
    QFont Font("Times", 20, QFont::Bold);

    QPainter painter(this);

    painter.setBrush(Brs);
    painter.drawRect(rect());




    painter.drawText(this->rect(),Qt::AlignCenter,EtapName);

    painter.end();


}

void Etap::mouseMoveEvent(QMouseEvent *)
{
    Brs.setColor(Qt::lightGray);

    update();

}

void Etap::mousePressEvent(QMouseEvent *)
{
    Brs.setColor(Qt::gray);

    emit IClicked(EtapNum);

    update();

}

void Etap::resizeEvent(QResizeEvent *)
{
    update();
}
Etap::~Etap()
{

}


