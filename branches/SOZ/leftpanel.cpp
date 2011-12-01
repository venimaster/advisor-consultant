#include "leftpanel.h"

LeftPanel::LeftPanel(int _status, QWidget *parent) :
    QWidget(parent)
{

    Status=_status;

    buttonsNum=5;


    ButtonsRect = QRectF(0,0,width(),height()/2);
    LabelRect = QRectF(0,height()/2,width(),height()/2);

    setButtonSize(width()/buttonsNum,height());

    switch(Status)
    {
        case 1:
            addLoginPanel();
        break;
        case 2:
            addRegistrationPanel();
        break;
        case 3:
            addButtons();
        break;

    }


}

void LeftPanel::addButtons()
{
    {
        for(int i=1;i<=buttonsNum;i++)
        {
            addButton(i,"ÝÒÀÏ "+ QString::number(i));
        }
    }
}

void LeftPanel::addLoginPanel()
{


}

void LeftPanel::addRegistrationPanel()
{


}



void LeftPanel::addButton(int _num, QString Name)
{
    int size = Buttons.size();
    if (Name!="")
        Buttons<<new EtapButton(_num, Name,this);


    Buttons[size]->setGeometry(BtnWidth*size,5,BtnWidth,BtnHeight);


    connect(Buttons[size],SIGNAL(iPressed(int)),this,SLOT(unPress(int)));


}

void LeftPanel::setButtonSize(double Wid, double Hei)
{
    BtnWidth=Wid;
    BtnHeight=Hei;
}

void LeftPanel::unPress(int _num)
{
    for (int i=0;i<Buttons.size();i++)
    {
        if (Buttons[i]->status==2)
        {
            Buttons[i]->status=0;
            Buttons[i]->isPressed=false;

            Buttons[i]->update();
        }

    }
    Buttons[_num-1]->status = 2;
    Buttons[_num-1]->isPressed = true;
    Buttons[_num-1]->update();

    emit ButtonPressed(_num+2);

}

void LeftPanel::setLabel(QString lbl)
{
    LabelText=lbl;
    update();

}

void LeftPanel::setStatus(int _stat)
{
    Status=_stat;

}


void LeftPanel::paintEvent(QPaintEvent *)
{
    QPen pen(Qt::black);
    QBrush Brs(Qt::gray);
    QFont Font("Times",13);


    QPainter painter(this);



    //painter.setRenderHint(QPainter::Antialiasing,true);

    painter.setBrush(Brs);
    painter.drawRect(rect());

    painter.setPen(pen);


    painter.setRenderHint(QPainter::Antialiasing,true);

 //   painter.drawEllipse(0,height()/2-1,width(),1);

    painter.setRenderHint(QPainter::Antialiasing,false);


  //  painter.drawLine(width()-1,0,width()-1,height());
  //  painter.drawLine(width()-3,0,width()-3,height());

  //  painter.setFont(Font);
  //  painter.drawText(LabelRect, Qt::AlignHCenter | Qt::TextWordWrap, LabelText);

  //  painter.end();
}

void LeftPanel::resizeEvent(QResizeEvent *)
{
    setButtonSize(width()/buttonsNum,height());

    for (int i=0;i<Buttons.size();i++)
    {
        Buttons[i]->setGeometry(BtnWidth*i,0,BtnWidth,BtnHeight);
        qDebug()<<BtnWidth<<BtnHeight;

    }

   // ButtonsRect.adjust(0,0,width(),height()/2);
    LabelRect = QRectF(0,height()/2,width(),height());

    update();

}







