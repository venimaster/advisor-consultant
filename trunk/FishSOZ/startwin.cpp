#include "startwin.h"

StartWin::StartWin(QWidget *parent) :
    QWidget(parent)
{
}

void StartWin::mousePressEvent(QMouseEvent *)
{
    emit MousePressed();

}

void StartWin::paintEvent(QPaintEvent *)
{

    QPen Pen(Qt::white,50);
    QFont Font("Times", 20, QFont::Bold);

    QString TitleText("ÄÎÁÐÎ ÏÎÆÀËÎÂÀÒÜ Â \n ÑÈÑÒÅÌÓ - ÊÎÍÑÓËÜÒÀÍÒ :)");
    QImage Image("C:/Projects/FishSOZ/Images/Humpback Whale.jpg");




    QPainter painter(this);

    painter.drawImage(this->rect(),Image);

    painter.setPen(Pen);
    painter.setFont(Font);
    painter.drawText(QRect(this->rect()),Qt::AlignCenter,TitleText);

    painter.end();

}

StartWin::~StartWin()
{
    update();

}
