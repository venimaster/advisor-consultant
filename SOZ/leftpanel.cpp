#include "leftpanel.h"

LeftPanel::LeftPanel(int _status, QWidget *parent) :
    QWidget(parent)
{

    Status=_status;


    ButtonsRect = QRectF(0,0,width(),height()/2);
    LabelRect = QRectF(0,height()/2,width(),height()/2);

    ErrorMsg = "";

    addLoginPanel();
    addEtapPanel();
    addAutorisationPanel();
    addRegistrationPanel();




    switch (Status)
    {

    case 1: etapPnl->show();
        regPnl->hide();
        autPanel->hide();
        regPanel->hide();
        break;

    case 2: etapPnl->hide();
        regPnl->show();
        autPanel->hide();
        regPanel->hide();
        break;

    case 3: etapPnl->hide();
        regPnl->hide();
        autPanel->hide();
        regPanel->show();
        break;

    case 4: etapPnl->hide();
        regPnl->hide();
        regPanel->hide();
        autPanel->show();
        break;

    }






}

void LeftPanel::addEtapPanel()
{

    etapPnl = new EtapPanel(this);
    etapPnl->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    connect(etapPnl,SIGNAL(ButtonPressed(int)),this,SLOT(EtapButtonCalls(int)));
}

void LeftPanel::addLoginPanel()
{
    regPnl = new RegPanel(this);
    regPnl->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());

    qDebug()<<"123";
}

void LeftPanel::addAutorisationPanel()
{
    autPanel = new AutorisationPanel(this);
    autPanel->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    connect (autPanel,SIGNAL(sendError(QString)),this,SLOT(catchError(QString)));
}

void LeftPanel::addRegistrationPanel()
{
    regPanel = new RegistrationPanel(this);
    regPanel->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    connect (regPanel,SIGNAL(sendError(QString)),this,SLOT(catchError(QString)));

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
    QPen pen(Qt::white);
    QBrush Brs(Qt::black);
    QFont Font("Times",13);


    QPainter painter(this);



    //painter.setRenderHint(QPainter::Antialiasing,true);

    painter.setBrush(Brs);
    painter.drawRect(rect());

    painter.setPen(pen);


    painter.setRenderHint(QPainter::Antialiasing,true);

    painter.drawEllipse(0,height()/2-1,width(),1);

    painter.setRenderHint(QPainter::Antialiasing,false);


    painter.drawLine(width()-1,0,width()-1,height());
    painter.drawLine(width()-3,0,width()-3,height());

    painter.setFont(Font);
    painter.drawText(LabelRect, Qt::AlignHCenter | Qt::TextWordWrap, LabelText);

    if (ErrorMsg != "")
    {
        painter.setPen(QPen(QColor::fromRgb(255,128,0)));
        painter.setFont(QFont("Times",10));
        painter.drawText(LabelRect, Qt::AlignLeft | Qt::TextWordWrap, ErrorMsg);
    }
    painter.end();
}

void LeftPanel::resizeEvent(QResizeEvent *)
{

    ButtonsRect.setRect(0,0,width(),height()/2);
    LabelRect.setRect(0,height()/2,width(),height());



    if (regPnl)
        regPnl->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    if (etapPnl)
        etapPnl->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    if (autPanel)
        autPanel->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    if (regPanel)
        regPanel->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());


    update();

}

void LeftPanel::EtapButtonCalls(int _a)
{
    emit EtapButtonPressed(_a);
    qDebug()<<_a;
}

void LeftPanel::RegDataCatch(const QString &_log, const QString &_pass)
{



}

void LeftPanel::catchError(const QString &_errMsg)
{
    ErrorMsg = _errMsg;
    update();
}







