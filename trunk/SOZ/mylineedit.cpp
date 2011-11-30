#include "mylineedit.h"

MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    QPalette palette;

    palette.setBrush(QPalette::Highlight,QBrush(Qt::gray));
    palette.setColor(QPalette::HighlightedText,Qt::black);
    palette.setBrush(QPalette::Background,QBrush(Qt::black));
    palette.setBrush(QPalette::Base,QBrush(Qt::black));

    palette.setColor(QPalette::Text,Qt::white);


    setPalette(palette);

    setFont(QFont("Times",13));




}


