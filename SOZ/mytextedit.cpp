#include "mytextedit.h"

MyTextEdit::MyTextEdit(QWidget *parent) :
    QTextEdit(parent)
{

    changePalette();

    setText("AAAAAAAAAAAAAAAAAA");
}

void MyTextEdit::resizeEvent(QResizeEvent *e)
{

    update();
}




void MyTextEdit::changePalette()
{
    QPalette palette;

   // palette.setBrush(QPalette::Base,QBrush(BrainPixmap));

    palette.setBrush(QPalette::Base,Qt::transparent);
    palette.setBrush(QPalette::Background, Qt::transparent);
    palette.setBrush(QPalette::Window,Qt::transparent);
    palette.setBrush(QPalette::WindowText,Qt::white);
    palette.setBrush(QPalette::Text,Qt::white);



    setPalette(palette);


    update();
}
