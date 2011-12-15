#include "registrationpanel.h"

RegistrationPanel::RegistrationPanel(QWidget *parent) :
    QWidget(parent)
{
    Name = "РЕГИСТРАЦИЯ";

    LineEditHeight = 25;
    ButtonHeight = 40;
    LblHeight = 25;

    ErrorMsgs<<"ОШИБКА: \n"<<""<<""<<""<<""<<""<<""<<"";

    NameRect = QRect(0,0,width(),height()/8);



    NickName = new MyLineEdit(this);
    NickName->setPlaceholderText("Логин");
    connect (NickName, SIGNAL(textChanged(QString)), this, SLOT (getNickName(QString)));



    Passwd = new MyLineEdit(this);
    Passwd->setEchoMode(QLineEdit::Password);
    Passwd->setPlaceholderText("Пароль (минимум 4 символа)");
    connect (Passwd, SIGNAL(textChanged(QString)),this,SLOT (getPass(QString)));

    ConfPasswd = new MyLineEdit(this);
    ConfPasswd->setEchoMode(QLineEdit::Password);
    ConfPasswd->setPlaceholderText("Подтверждение (минимум 4 символа)");
    connect (ConfPasswd, SIGNAL(textChanged(QString)),this,SLOT(getConfirmPass(QString)));

    FIO = new MyLineEdit(this);
    FIO->setPlaceholderText("Фамилия Имя Отчество");
    connect(FIO,SIGNAL(textChanged(QString)),this,SLOT(getFIO(QString)));

    Sex = new MyLineEdit(this);
    Sex->setPlaceholderText("М или Ж");
    Sex->setAlignment(Qt::AlignCenter);
    connect(Sex,SIGNAL(textChanged(QString)),this,SLOT(getSex(QString)));

    Age = new MyLineEdit(this);
    Age->setPlaceholderText("Возраст");
    Age->setAlignment(Qt::AlignHCenter);
    connect(Age,SIGNAL(textChanged(QString)),this,SLOT(getAge(QString)));


    OK = new TesterDaleeButton(this);
    OK->setName("ВХОД");
    OK->setFontSize(12);
    OK->setDisAvilable();

    Reg = new TesterDaleeButton(this);
    Reg->setName("АВТОРИЗАЦИЯ");
    Reg->setFontSize(12);
    Reg->setAvilable();

    resizeWidgets();

    Nick = "";
    Pass = "";
    ConfPassStr = "";
    FIOStr = "";
    SexStr = "";
    AgeStr = "";

    ErrorMsg = "";

    connect(this,SIGNAL(checkInput()),SLOT(unlockOK()));

}

void RegistrationPanel::resizeWidgets()
{

    qDebug()<<"AAAAAA";
    NameRect.setRect(0,0,width(),height()/9);


    NickNameLblRect.setRect(0,NameRect.bottom()+5,width()-3,LblHeight);

    NickName->setGeometry(0,NameRect.bottom()+LineEditHeight,width()-3, LineEditHeight);

    PasswdLblRect.setRect(0,NameRect.bottom()+LineEditHeight*2,width()-3,LblHeight);

    Passwd->setGeometry(0,NameRect.bottom()+LineEditHeight*3,width()-3, LineEditHeight);

    ConfPasswdLblRect.setRect(0,NameRect.bottom()+LineEditHeight*4,width()-3,LblHeight);

    ConfPasswd->setGeometry(0,NameRect.bottom()+LineEditHeight*5,width()-3, LineEditHeight);

    FIORect.setRect(0,NameRect.bottom()+LineEditHeight*6,width()-3,LblHeight);

    FIO->setGeometry(0,NameRect.bottom()+LineEditHeight*7,width()-3, LineEditHeight);

    SexRect.setRect(0,NameRect.bottom()+LineEditHeight*8,(width()-3)/2,LblHeight);

    Sex->setGeometry(0,NameRect.bottom()+LineEditHeight*9,(width()-3)/2,LineEditHeight);

    AgeRect.setRect((width()-3)/2,NameRect.bottom()+LineEditHeight*8,width()-(width()-3)/2,LblHeight);

    Age->setGeometry((width()-3)/2,NameRect.bottom()+LineEditHeight*9,width()-(width()-3)/2,LineEditHeight);

    OK->setGeometry(0,height()-ButtonHeight-5,width()/2-2,ButtonHeight);
    Reg->setGeometry(width()/2,height()-ButtonHeight-5,width()/2-2,ButtonHeight);



    update();

}

void RegistrationPanel::paintEvent(QPaintEvent *)
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
    painter.drawText(ConfPasswdLblRect,Qt::AlignCenter,"ПОДТВЕРДИТЕ ПАРОЛЬ");
    painter.drawText(FIORect,Qt::AlignCenter,"ВВЕДИТЕ ФИО");
    painter.drawText(SexRect,Qt::AlignCenter,"ВВЕДИТЕ ПОЛ");
    painter.drawText(AgeRect,Qt::AlignCenter,"ВВЕДИТЕ ВОЗРАСТ");


    painter.end();

}

void RegistrationPanel::resizeEvent(QResizeEvent *)
{
    resizeWidgets();


}

void RegistrationPanel::getNickName(QString str)
{
    ErrorMsgs[1]="";

    Nick = str;
    QString Err="";

    QRegExp rx("[0-9A-Za-z-_]{4,100}");
    QRegExpValidator v(rx,0);
    int pos = 0;

    if (v.validate(Nick,pos)==0)
    {
       Err = "\t     В поле 'Логин' введены недопустимые символы. Допустимые символы-буквы латинского алфавита, цифры и знаки '-' и '_' \n";
       ErrorMsgs[1]=Err;
    }
    else ErrorMsgs[1]="";

    emit checkInput();
}

void RegistrationPanel::getPass(QString str)
{
    ErrorMsgs[2]="";
    ErrorMsgs[4]="";

    Pass = str;
    QString Err="";

    QRegExp rx("[0-9A-Za-z]{4,100}");
    QRegExpValidator v(rx,0);
    int pos = 0;

    if (v.validate(Pass,pos)==0)
    {
        Err="\t     В поле 'Пароль' введены недопустимые символы. Допустимые символы-буквы латинского алфавита и цифры \n";
        ErrorMsgs[2]=Err;
    }
    else ErrorMsgs[2]="";

    if (Err=="")
    {
        if ((Pass.length()==ConfPassStr.length()))
        {
            if (Pass!=ConfPassStr)
            {
                Err="\t    Введенные пароли не совпадают \n";
                ErrorMsgs[4]=Err;
            }
            else
                ErrorMsgs[4]="";
        }
        else
            ErrorMsgs[4]="";
    }


    emit checkInput();

}

void RegistrationPanel::getConfirmPass(QString str)
{
    ErrorMsgs[3]="";
    ErrorMsgs[4]="";

    ConfPassStr = str;
    QString Err="";

    QRegExp rx("[0-9A-Za-z]{4,100}");
    QRegExpValidator v(rx,0);
    int pos = 0;


    if (v.validate(ConfPassStr,pos)==0)
    {
        Err="\t     В поле 'Подтверждение пароля' введены недопустимые символы. Допустимые символы-буквы латинского алфавита и цифры \n";
        ErrorMsgs[3]=Err;
    }
    else ErrorMsgs[3]="";

    if (Err=="")
    {
        if ((Pass.length()==ConfPassStr.length()))
        {
            if (Pass!=ConfPassStr)
            {
                Err="\t    Введенные пароли не совпадают \n";
                ErrorMsgs[4]=Err;
            }
            else
                ErrorMsgs[4]="";
        }
        else
            ErrorMsgs[4]="";
    }

    emit checkInput();
}

void RegistrationPanel::getFIO(QString str)
{

    ErrorMsgs[5]="";


    FIOStr = str;
    QString Err="";

    QRegExp rx("[А-Яа-я]{1,100}[ ]{1,1}[А-Яа-я]{2,100}[ ]{1,1}[А-Яа-я]{2,100}");
    QRegExpValidator v (rx,0);

    int pos = 0;

    if (v.validate(FIOStr,pos)==0)
    {
        Err="\t     В поле 'ФИО' введены недопустимые символы. \n";
        ErrorMsgs[5]=Err;

    }
    else
        ErrorMsgs[5]="";

    emit checkInput();
}

void RegistrationPanel::getSex(QString str)
{

   ErrorMsgs[6]="";

   SexStr = str;

   QString Err = "";

   if (SexStr != "М" && SexStr != "Ж")
   {
       SexStr="";
       Sex->setText("");
       Err="\t     В поле 'Пол' введены недопустимые символы. Допустимые символы-буквы М или Ж \n";
       ErrorMsgs[6]=Err;
   }
   else
       ErrorMsgs[6]="";

       emit checkInput();
}

void RegistrationPanel::getAge(QString str)
{

    ErrorMsgs[7]="";

    QString Err="";

    AgeB = false;

    AgeStr = str;

    qDebug()<<AgeStr;

    if (AgeStr.size()==1)
    {


        QRegExp rx("[1-9]{1,1}");
        QRegExpValidator v (rx,0);

        int pos = 0;
        if (v.validate(AgeStr,pos)==0)
        {
            AgeStr = "";
            Age->setText("");
            Err="\t     Поле 'Возраст' введено неверно\n";
            ErrorMsgs[7]=Err;
        }

    }


    if (AgeStr.size()==2)
    {


        QRegExp rx("[0-9]{1,1}");
        QRegExpValidator v (rx,0);

        int pos = 0;

        QString S1 = AgeStr.left(1);
        QString S2 = AgeStr.right(1);

        if (v.validate(S2,pos)==0)
        {
            AgeStr = S1;
            Age->setText(S1);
            Err="\t     Поле 'Возраст' введено неверно\n";
            ErrorMsgs[7]=Err;
        }
        else
            AgeB = true;
    }

    if (AgeStr.size()>2)
    {
        AgeStr = AgeStr.left(2);
        Age->setText(AgeStr);
    }



    double A;

    A = AgeStr.toDouble();

        emit checkInput();
}

void RegistrationPanel::unlockOK()
{
    bool b=true;
    QString Err="";
    for (int i = 1; i<ErrorMsgs.size(); i++)
    {
        if (ErrorMsgs[i].size()!=0)
            b=false;

    }
    if ((!b) || (Nick.size()==0) || Pass.size()==0 || ConfPassStr.size()==0 || FIOStr.size()==0 || SexStr.size()==0 || AgeB==false )
    {
        OK->setDisAvilable();
        for (int i=0;i<ErrorMsgs.size(); i++)
        {
            Err+=ErrorMsgs[i];
        }
        if (b)
            Err="";
    }
    else
    {
        OK->setAvilable();
    }
    emit sendError(Err);



}
