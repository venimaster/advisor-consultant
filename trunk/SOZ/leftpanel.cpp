#include "leftpanel.h"

LeftPanel::LeftPanel(int _status, QWidget *parent) :
    QWidget(parent)
{

    Status=_status;


    ButtonsRect = QRectF(0,0,width(),height()/2+50);
    LabelRect = QRectF(0,height()/2+50,width(),height()/2-50);

    ErrorMsg = "";

    addLoginPanel();
    addEtapPanel();
    addAutorisationPanel();
    addRegistrationPanel();
    addHelpButton();




    changeWGT(Status);






}

void LeftPanel::addEtapPanel()
{

    etapPnl = new EtapPanel(this);
    etapPnl->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    connect(etapPnl,SIGNAL(ButtonPressed(int)),this,SLOT(EtapButtonCalls(int)));
}

void LeftPanel::addLoginPanel()
{
    choosePanel = new RegPanel(this);
    choosePanel->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());

}

void LeftPanel::addAutorisationPanel()
{
    autPanel = new AutorisationPanel(this);
    autPanel->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    connect (autPanel,SIGNAL(sendError(QString)),this,SLOT(catchError(QString)));
    connect (autPanel,SIGNAL(doRegistration(int)),this,SLOT(changeWGT(int)));
    connect (autPanel,SIGNAL(getEtaps(int)),this,SLOT(changeWGT(int)));
}

void LeftPanel::addRegistrationPanel()
{
    regPanel = new RegistrationPanel(1,this);
    regPanel->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    connect (regPanel,SIGNAL(sendError(QString)),this,SLOT(catchError(QString)));
    connect (regPanel,SIGNAL(doAutorisation(int)),this,SLOT(changeWGT(int)));
    connect (regPanel,SIGNAL(getEtaps(int)),this,SLOT(changeWGT(int)));



}
void LeftPanel::addHelpButton()
{
    HB = new HelpButton(this);
    HB->setGeometry(rect().left()+2,rect().bottom()-66,32,32);
    connect (HB,SIGNAL(iPressed()),this,SIGNAL(showHelp()));
    connect (HB,SIGNAL(iPressed(int)),this,SLOT(changeWGT(int)));

    LB = new Literature(this);
    LB->setGeometry(rect().left()+2+32,rect().bottom()-66,32,32);
    connect (LB,SIGNAL(iPressed()),this,SIGNAL(showHelp()));
    connect (LB,SIGNAL(iPressed(int)),this,SLOT(changeWGT(int)));
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
    QString LblTxt;
    QString ErrMsg;

    if (ErrorMsg!="") LblTxt=""; else LblTxt=LabelText;


    QPainter painter(this);



    //painter.setRenderHint(QPainter::Antialiasing,true);

    painter.setBrush(Brs);
    painter.drawRect(rect());

    painter.setPen(pen);


    painter.setRenderHint(QPainter::Antialiasing,true);

    painter.drawEllipse(0,height()/2+50,width(),1);

    painter.setRenderHint(QPainter::Antialiasing,false);


    painter.drawLine(width()-1,0,width()-1,height());
    painter.drawLine(width()-3,0,width()-3,height());

    painter.setFont(Font);
    painter.drawText(LabelRect, Qt::AlignHCenter | Qt::TextWordWrap, LblTxt);

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



    if (choosePanel)
        choosePanel->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    if (etapPnl)
        etapPnl->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    if (autPanel)
        autPanel->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    if (regPanel)
        regPanel->setGeometry(ButtonsRect.left(),ButtonsRect.top(),ButtonsRect.width(),ButtonsRect.height());
    if (HB)
        HB->setGeometry(rect().left()+2,rect().bottom()-66,32,32);
    if (LB)
        LB->setGeometry(rect().left()+2+50,rect().bottom()-66,32,32);

    update();

}

void LeftPanel::EtapButtonCalls(int _a)
{
    emit EtapButtonPressed(_a);
}

void LeftPanel::RegDataCatch(const QString &_log, const QString &_pass)
{



}

void LeftPanel::catchError(const QString &_errMsg)
{
    ErrorMsg = _errMsg;
    update();
}


void LeftPanel::changeWGT(int st)
{
    switch (st)
    {

    case 1:
        choosePanel->show();
        autPanel->hide();
        regPanel->hide();
        etapPnl->hide();
        break;

    case 2:
        choosePanel->hide();
        autPanel->show();
        regPanel->hide();
        etapPnl->hide();
        break;

    case 3:
        choosePanel->hide();
        autPanel->hide();
        regPanel->show();
        etapPnl->hide();
        break;

    case 4:
        choosePanel->hide();
        regPanel->hide();
        autPanel->hide();
        etapPnl->show();
        break;

//    case 5:
//        choosePanel->hide();
//        regPanel->hide();
//        autPanel->hide();
//        etapPnl->hide();
//        LabelText="Справочная информация";
//        ErrorMsg="";
//        update();
//        break;

    }

}

void LeftPanel::setDB(dbWork *_db)
{

    DB = _db;

    autPanel->setDB(_db);
    regPanel->setDB(_db);

}







