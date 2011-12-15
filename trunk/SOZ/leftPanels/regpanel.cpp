#include "regpanel.h"
#include <QDebug>

RegPanel::RegPanel(QWidget *parent) :
    QWidget(parent)
{
    Zak = new RadioPushButton(1,"ÇÀÊÀÇ×ÈÊ",this);
    Eksp = new RadioPushButton(2,"ÝÊÑÏÅÐÒ",this);
    Inz = new RadioPushButton(3,"ÈÍÆÅÍÅÐ ÏÎ ÇÍÀÍÈßÌ",this);

//    Zak->show();
//    Eksp->show();
//    Inz->show();

    resizeWidgets();

}

void RegPanel::resizeWidgets()
{
    NameRect = QRect(0,0,width(),height()/6);
    ButtonsRect = QRect(0,height()/6,width(),height()-height()/6);

    Zak->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height()/3);
    Eksp->setGeometry(ButtonsRect.left(),ButtonsRect.height()/3+ButtonsRect.top(),ButtonsRect.width(), ButtonsRect.height()/3);
    Inz->setGeometry(ButtonsRect.left(),ButtonsRect.top()+2*ButtonsRect.height()/3,ButtonsRect.width(),ButtonsRect.height()/3);

    update();
}


void RegPanel::paintEvent(QPaintEvent *)
{



}

void RegPanel::resizeEvent(QResizeEvent *)
{

    resizeWidgets();
    update();

}

void RegPanel::UnClick(int ID)
{


}
