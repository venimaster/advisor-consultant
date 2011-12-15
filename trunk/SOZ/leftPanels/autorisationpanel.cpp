#include "autorisationpanel.h"
#include <QDebug>

AutorisationPanel::AutorisationPanel(QWidget *parent) :
    QWidget(parent)
{

    Name = "ÀÂÒÎÐÈÇÀÖÈß";

    LineEditHeight = 25;
    ButtonHeight = 40;
    LblHeight = 25;

    NameRect = QRect(0,0,width(),height()/6);



    NickName = new MyLineEdit(this);
    NickName->setPlaceholderText("Ëîãèí");
    connect (NickName, SIGNAL(textChanged(QString)), this, SLOT (getNickName(QString)));



    Passwd = new MyLineEdit(this);
    Passwd->setEchoMode(QLineEdit::Password);
    Passwd->setPlaceholderText("Ïàðîëü");
    connect (Passwd, SIGNAL(textChanged(QString)),this,SLOT (getPass(QString)));


    OK = new TesterDaleeButton(this);
    OK->setName("ÂÕÎÄ");
    OK->setFontSize(12);
    OK->setDisAvilable();

    Reg = new TesterDaleeButton(this);
    Reg->setName("ÐÅÃÈÑÒÐÀÖÈß");
    Reg->setFontSize(12);
    Reg->setAvilable();

    resizeWidgets();

    Nick = "";
    Pass = "";

    ErrorMsg = "";

    connect(this,SIGNAL(checkInput(bool)),SLOT(unlockOK(bool)));

}

void AutorisationPanel::resizeWidgets()
{

    qDebug()<<"AAAAAA";
    NameRect.setRect(0,0,width(),height()/6);


    NickNameLblRect.setRect(0,NameRect.bottom()+5,width()-3,LblHeight);

    NickName->setGeometry(0,NameRect.bottom()+LineEditHeight+5,width()-3, LineEditHeight);

    PasswdLblRect.setRect(0,NameRect.bottom()+LineEditHeight*2+15,width()-3,LblHeight);

    Passwd->setGeometry(0,NameRect.bottom()+LineEditHeight*3+15,width()-3, LineEditHeight);


    OK->setGeometry(0,height()-ButtonHeight-5,width()/2-2,ButtonHeight);
    Reg->setGeometry(width()/2,height()-ButtonHeight-5,width()/2-2,ButtonHeight);



    update();

}

void AutorisationPanel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::white));
    painter.setFont(QFont("TIMES",13,QFont::Bold));
    painter.drawText(NameRect,Qt::AlignCenter,Name);


    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawEllipse(0,NameRect.bottom()+1,width(),1);

    painter.setFont(QFont("TIMES",10));
    painter.drawText(NickNameLblRect,Qt::AlignCenter,"ÂÂÅÄÈÒÅ ËÎÃÈÍ");
    painter.drawText(PasswdLblRect,Qt::AlignCenter,"ÂÂÅÄÈÒÅ ÏÀÐÎËÜ");


    painter.end();

}


void AutorisationPanel::resizeEvent(QResizeEvent *)
{
    resizeWidgets();


}

void AutorisationPanel::getNickName(QString str)
{
   Nick = str;
   if ((Pass.length()!=0) && (Nick.length()!=0))
       emit (checkInput(true));
   else
       emit (checkInput(false));
}

void AutorisationPanel::getPass(QString str)
{
    Pass = str;
    if ((Pass.length()!=0) && (Nick.length()!=0))
        emit (checkInput(true));
    else
        emit (checkInput(false));
}

void AutorisationPanel::unlockOK(bool b)
{

    ErrorMsg = "";

    QRegExp rxNick("[0-9A-Za-z-_]{4,100}");
    QRegExp rxPass("[0-9A-Za-z]{4,100}");
    QRegExpValidator vNick(rxNick,0);
    QRegExpValidator vPass(rxPass,0);
    int pos = 0;

    int valNick;
    int valPass;

    valNick = vNick.validate(Nick,pos);
    valPass = vPass.validate(Pass,pos);

    if (valNick == 0)
    {
        if (ErrorMsg.length()==0)
        {
            ErrorMsg+="ÎØÈÁÊÀ: \n";
        }
        ErrorMsg+="\t     Â ïîëå 'Ëîãèí' ââåäåíû íåäîïóñòèìûå ñèìâîëû. Äîïóñòèìûå ñèìâîëû-áóêâû ëàòèíñêîãî àëôàâèòà, öèôðû è çíàêè '-' è '_' \n\n";
        b=false;
    }

    if (valPass == 0)
    {
        if (ErrorMsg.length()==0)
        {
            ErrorMsg+="ÎØÈÁÊÀ: \n";
        }
        ErrorMsg+="\t     Â ïîëå 'Ïàðîëü' ââåäåíû íåäîïóñòèìûå ñèìâîëû. Äîïóñòèìûå ñèìâîëû-áóêâû ëàòèíñêîãî àëôàâèòà è öèôðû\n\n";
        b=false;
    }

    emit sendError(ErrorMsg);

    if (b)
        OK->setAvilable();
    else
        OK->setDisAvilable();
}

