#include "mylineedit.h"

MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    QPalette palette;

    QColor MyColor(QColor::fromRgb(45,75,129));
    MyColor.setAlpha(200);

    palette.setBrush(QPalette::Highlight,QBrush(Qt::gray));
    palette.setColor(QPalette::HighlightedText,Qt::white);
    palette.setBrush(QPalette::Background,QBrush(Qt::black));
    palette.setBrush(QPalette::Base,QBrush(MyColor));

    palette.setColor(QPalette::Text,Qt::white);


    setPalette(palette);

    setFont(QFont("Times",13));






}

void MyLineEdit::resizeEvent(QResizeEvent *)
{
    update();

}


