#include "namepanel.h"

NamePanel::NamePanel(QWidget *parent) :
    QWidget(parent)
{
    Name = "";
}

void NamePanel::SetName(QString Name)
{
    this->Name=Name;
    update();

}

void NamePanel::paintEvent(QPaintEvent *)
{


        QFont myFont;
        QPen pen(Qt::white);

        QColor MyColor(Qt::black);
        QColor MyColor1(Qt::white);

        MyColor1.setAlpha(0);

        QBrush Brs(MyColor);


        myFont=QFont("Times",13,QFont::Bold);


        QPainter painter(this);

        painter.setBrush(Brs);
        painter.setFont(myFont);
        painter.drawRect(rect());

        painter.setBrush(QBrush(MyColor1));
        painter.drawRect(rect());
        painter.setPen(QPen(Qt::white));

        if (Name != "")
        {

            painter.setPen(pen);
            painter.drawText(rect(),Qt::AlignCenter | Qt::TextWordWrap,Name);

            painter.setRenderHint(QPainter::Antialiasing,true);
            painter.setBrush(QBrush(Qt::white));
            painter.drawEllipse(0,height()-3,width(),3);
            painter.setRenderHint(QPainter::Antialiasing,false);

        }
        painter.end();



}

void NamePanel::resizeEvent(QResizeEvent *)
{
    update();

}
