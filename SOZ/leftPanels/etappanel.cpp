#include "etappanel.h"

EtapPanel::EtapPanel(QWidget *parent) :
    QWidget(parent)
{

    setButtonSize(width()-10,height()/15);
    for (int i=0; i<5; i++)
    {
        addButton(i+1,"ÝÒÀÏ "+QString::number(i+1));
    }

}

void EtapPanel::paintEvent(QPaintEvent *)
{

}

void EtapPanel::setButtonSize(double Wid, double Hei)
{
    BtnWidth=Wid;
    BtnHeight=Hei;
}

void EtapPanel::addButton(int _num, QString Name)
{
    int size = etaps.size();
    qDebug()<<"10";
    if (Name!="")
        etaps<<new EtapButton(_num, Name ,this);

    etaps[size]->setGeometry((width()-BtnWidth)/2,10+(BtnHeight+10)*size,BtnWidth,BtnHeight);

    connect(etaps[size],SIGNAL(iPressed(int)),this,SLOT(unPress(int)));
}

void EtapPanel::unPress(int _num)
{
    for (int i=0;i<etaps.size();i++)
    {
        if (etaps[i]->status==2)
        {
            etaps[i]->status=0;
            etaps[i]->isPressed=false;

            etaps[i]->update();
        }

    }
    etaps[_num-1]->status = 2;
    etaps[_num-1]->isPressed = true;
    etaps[_num-1]->update();

    emit ButtonPressed(_num+2);

}

void EtapPanel::resizeEvent(QResizeEvent *)
{
    setButtonSize(width()-10,height()/8);

    for (int i=0;i<etaps.size();i++)
    {
        etaps[i]->setGeometry((width()-BtnWidth)/2,5+(BtnHeight+5)*i,BtnWidth,BtnHeight);

    }

}

