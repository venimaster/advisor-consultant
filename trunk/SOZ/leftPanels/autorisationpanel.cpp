#include "autorisationpanel.h"
#include <QDebug>

AutorisationPanel::AutorisationPanel(QWidget *parent) :
    QWidget(parent)
{

    Name = "АВТОРИЗАЦИЯ";

    LineEditHeight = 25;
    ButtonHeight = 40;
    LblHeight = 25;

    NameRect = QRect(0,0,width(),height()/8);



    NickName = new MyLineEdit(this);
    NickName->setPlaceholderText("Логин");
    connect (NickName, SIGNAL(textChanged(QString)), this, SLOT (getNickName(QString)));
    connect (NickName, SIGNAL(editingFinished()),this,SLOT(getPass()));



    Passwd = new MyLineEdit(this);
    Passwd->setEchoMode(QLineEdit::Password);
    Passwd->setPlaceholderText("Пароль");
    connect (Passwd, SIGNAL(textChanged(QString)),this,SLOT (getPass(QString)));
    connect (Passwd, SIGNAL(editingFinished()),this, SLOT(getNickName()));


    OK = new TesterDaleeButton(this);
    OK->setName("ВХОД");
    OK->setFontSize(12);
    OK->setDisAvilable();
    connect (OK,SIGNAL(iPressed()),this,SLOT(enter()));

    Reg = new TesterDaleeButton(this);
    Reg->setName("ЗАРЕГИСТРИРОВАТЬСЯ");
    Reg->setFontSize(12);
    Reg->setAvilable();
    connect(Reg,SIGNAL(iPressed()),this,SLOT(doReg()));

    resizeWidgets();

    Nick = "";
    Pass = "";

    ErrorMsg = "";

    connect(this,SIGNAL(checkInput(bool)),SLOT(unlockOK(bool)));

}

void AutorisationPanel::resizeWidgets()
{

    //qDebug()<<"AAAAAA";
    NameRect.setRect(0,0,width(),height()/8);


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
    painter.drawText(NickNameLblRect,Qt::AlignCenter,"ВВЕДИТЕ ЛОГИН");
    painter.drawText(PasswdLblRect,Qt::AlignCenter,"ВВЕДИТЕ ПАРОЛЬ");


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
            ErrorMsg+="ОШИБКА: \n";
        }

        ErrorMsg+="\t     В поле 'Логин' введены недопустимые символы. Допустимые символы-буквы латинского алфавита, цифры и знаки '-' и '_' \n\n";
        if (Nick.length()<4)
        ErrorMsg+="\t  Длина логина не должна быть меньше четырех символов; \n\n";
        b=false;
    }

    if (valPass == 0)
    {
        if (ErrorMsg.length()==0)
        {
            ErrorMsg+="ОШИБКА: \n";
        }
        if (Pass.length() >= 4)
        ErrorMsg+="\t     В поле 'Пароль' введены недопустимые символы. Допустимые символы-буквы латинского алфавита и цифры\n\n";
        else ErrorMsg+="\t  Длина пароля не должна быть меньше четырех символов; \n\n";
        b=false;
    }

    emit sendError(ErrorMsg);

    if (b)
        OK->setAvilable();
    else
        OK->setDisAvilable();
}

void AutorisationPanel::doReg()
{
    Passwd->clear();
    emit sendError("");
    emit doRegistration(3);

}

void AutorisationPanel::setDB(dbWork *_db)
{
    DB = _db;
}

void AutorisationPanel::enter()
{
    QVector<QString> Logins;
    QVector<QString> Group;
    QVector<QString> Passwrd;
    int flag = 0;

    Logins = DB->GetColumnFromTable("login","user");
    for (int i = 0; i<Logins.size(); i++)
    {
        Group = DB->GetColumnFromTable("u_g_id","user",Logins[i]);
        Passwrd = DB->GetColumnFromTable("password","user",Logins[i]);
        qDebug()<<Logins[i]<<Group<<Passwrd;

        if (Logins[i]==NickName->text() && Group[0] == "1" && Passwrd[0]==Passwd->text())
        {
            flag = 1;
        }
    }

    if (flag == 0) emit sendError("Заказчика с таким именем нет в базе данных");
    else
    {
        emit getEtaps(4);
    }
}
