#include "registrationpanel.h"

RegistrationPanel::RegistrationPanel(const int _type, QWidget *parent) :
    QWidget(parent)
{

    type = _type;

    Name = "�����������";

    LineEditHeight = 20;
    ButtonHeight = 40;
    LblHeight = 20;

    ErrorMsgs<<"������: \n"<<""<<""<<""<<""<<""<<""<<"";

    NameRect = QRect(0,0,width(),height()/8);



    NickName = new MyLineEdit(this);
    NickName->setPlaceholderText("�����");
    connect (NickName, SIGNAL(textChanged(QString)), this, SLOT (getNickName(QString)));
    connect (NickName, SIGNAL(editingFinished()),this, SLOT(getNickName()));



    Passwd = new MyLineEdit(this);
    Passwd->setEchoMode(QLineEdit::Password);
    Passwd->setPlaceholderText("������ (������� 4 �������)");
    connect (Passwd, SIGNAL(textChanged(QString)),this,SLOT (getPass(QString)));
    connect (Passwd,SIGNAL(editingFinished()),this,SLOT(getPass()));

    ConfPasswd = new MyLineEdit(this);
    ConfPasswd->setEchoMode(QLineEdit::Password);
    ConfPasswd->setPlaceholderText("������������� (������� 4 �������)");
    connect (ConfPasswd, SIGNAL(textChanged(QString)),this,SLOT(getConfirmPass(QString)));
    connect (ConfPasswd, SIGNAL(editingFinished()),this,SLOT(getConfirmPass()));

    FIO = new MyLineEdit(this);
    FIO->setPlaceholderText("������� ��� ��������");
    connect(FIO,SIGNAL(textChanged(QString)),this,SLOT(getFIO(QString)));

    Sex = new MyLineEdit(this);
    Sex->setPlaceholderText("� ��� �");
    Sex->setAlignment(Qt::AlignCenter);
    connect(Sex,SIGNAL(textChanged(QString)),this,SLOT(getSex(QString)));

    Age = new MyLineEdit(this);
    Age->setPlaceholderText("�������");
    Age->setAlignment(Qt::AlignHCenter);
    connect(Age,SIGNAL(textChanged(QString)),this,SLOT(getAge(QString)));

    if (type == 1)
    {
        GroupName = "��������";
        Project = new MyLineEdit(this);
        Project->setPlaceholderText("�������� �������");
    }

    if (type == 2)
    {
        GroupName = "������� �� �������";

    }

    if (type == 3)
    {
        GroupName = "�������";
    }




    OK = new TesterDaleeButton(this);
    OK->setName("�����������");
    OK->setFontSize(12);
    OK->setDisAvilable();
    connect (OK,SIGNAL(iPressed()),this,SLOT(writeUser()));

    Reg = new TesterDaleeButton(this);
    Reg->setName("��������������");
    Reg->setFontSize(12);
    Reg->setAvilable();
    connect(Reg,SIGNAL(iPressed()),this,SLOT(doAut()));




    resizeWidgets();

    Nick = "";
    Pass = "";
    ConfPassStr = "";
    FIOStr = "";
    SexStr = "";
    AgeStr = "";
    ProjectStr = "";

    ErrorMsg = "";

    connect(this,SIGNAL(checkInput()),SLOT(unlockOK()));

}

void RegistrationPanel::resizeWidgets()
{

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

    if (type == 1)
    {
        ProjRect.setRect(0,NameRect.bottom()+LineEditHeight*10,width()-3,LblHeight);
        Project->setGeometry(0,NameRect.bottom()+LineEditHeight*11,width()-3,LineEditHeight);
    }

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
    painter.drawText(NickNameLblRect,Qt::AlignCenter,"������� �����");
    painter.drawText(PasswdLblRect,Qt::AlignCenter,"������� ������");
    painter.drawText(ConfPasswdLblRect,Qt::AlignCenter,"����������� ������");
    painter.drawText(FIORect,Qt::AlignCenter,"������� ���");
    painter.drawText(SexRect,Qt::AlignCenter,"������� ���");
    painter.drawText(AgeRect,Qt::AlignCenter,"������� �������");

    if (type == 1)
        painter.drawText(ProjRect, Qt::AlignCenter, "������� �������� �������");



    painter.end();

}

void RegistrationPanel::resizeEvent(QResizeEvent *)
{
    resizeWidgets();


}

void RegistrationPanel::getNickName(QString str)
{
    ErrorMsgs[1]="";

    Nick = NickName->text();

    if ((str == ""))
    if (NickName->text().length()<=4) ErrorMsgs[1] = "� ���� ����� ������ ���� �� ����� 4 ��������";
    if (str!="")
    {

        QString Err="";

        QRegExp rx("[0-9A-Za-z-_]{4,100}");
        QRegExpValidator v(rx,0);
        int pos = 0;

        if (v.validate(Nick,pos)==0)
        {
           Err = "\t     � ���� '�����' ������� ������������ �������. ���������� �������-����� ���������� ��������, ����� � ����� '-' � '_' \n";
           ErrorMsgs[1]=Err;
        }
        else ErrorMsgs[1]="";
    }
    else
         if (NickName->text().length()<=4) ErrorMsgs[1] = "\t    � ���� ����� ������ ���� �� ����� 4 ��������  \n";





    emit checkInput();
}

void RegistrationPanel::getPass(QString str)
{
    ErrorMsgs[2]="";
    ErrorMsgs[4]="";

    Pass = Passwd->text();

    if (str != "")
    {

        QString Err="";

        QRegExp rx("[0-9A-Za-z]{4,100}");
        QRegExpValidator v(rx,0);
        int pos = 0;

        if (v.validate(Pass,pos)==0)
        {
            Err="\t     � ���� '������' ������� ������������ �������. ���������� �������-����� ���������� �������� � ����� \n";
            ErrorMsgs[2]=Err;
        }
        else ErrorMsgs[2]="";

        if (Err=="")
        {
            if ((Pass.length()==ConfPassStr.length()))
            {
                if (Pass!=ConfPassStr)
                {
                    Err="\t    ��������� ������ �� ��������� \n";
                    ErrorMsgs[4]=Err;
                }
                else
                    ErrorMsgs[4]="";
            }
            else
                ErrorMsgs[4]="";
        }
    }
    else
        if (Passwd->text().length()<=4) ErrorMsgs[2] = "\t    � ���� ������ ������ ���� �� ����� 4 �������� \n";


    emit checkInput();

}

void RegistrationPanel::getConfirmPass(QString str)
{
    ErrorMsgs[3]="";
    ErrorMsgs[4]="";

    ConfPassStr = ConfPasswd->text();

    if (str != "")
    {
        QString Err="";

        QRegExp rx("[0-9A-Za-z]{4,100}");
        QRegExpValidator v(rx,0);
        int pos = 0;


        if (v.validate(ConfPassStr,pos)==0)
        {
            Err="\t     � ���� '������������� ������' ������� ������������ �������. ���������� �������-����� ���������� �������� � ����� \n";
            ErrorMsgs[3]=Err;
        }
        else ErrorMsgs[3]="";

        if (Err=="")
        {
            if ((Pass.length()==ConfPassStr.length()))
            {
                if (Pass!=ConfPassStr)
                {
                    Err="\t    ��������� ������ �� ��������� \n";
                    ErrorMsgs[4]=Err;
                }
                else
                    ErrorMsgs[4]="";
            }
            else
                ErrorMsgs[4]="";
        }
    }
    else
        if (ConfPasswd->text().length()<=4) ErrorMsgs[3] = "\t    � ���� ������������� ������ ������ ���� �� ����� 4 �������� \n";

    emit checkInput();
}

void RegistrationPanel::getFIO(QString str)
{

    ErrorMsgs[5]="";

    FIOStr = FIO->text();

    QString Err="";

    QRegExp rx("[�-��-�]{1,100}[ ]{1,1}[�-��-�]{2,100}[ ]{1,1}[�-��-�]{2,100}");
    QRegExpValidator v (rx,0);

    int pos = 0;

    if (v.validate(FIOStr,pos)==0)
    {
        Err="\t     � ���� '���' ������� ������������ �������. \n";
        ErrorMsgs[5]=Err;

    }
    else
        ErrorMsgs[5]="";

    emit checkInput();
}

void RegistrationPanel::getSex(QString str)
{

   ErrorMsgs[6]="";

   SexStr = Sex->text();

   QString Err = "";

   if (SexStr != "�" && SexStr != "�")
   {
       SexStr="";
       Sex->setText("");
       Err="\t     � ���� '���' ������� ������������ �������. ���������� �������-����� � ��� � \n";
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

    AgeStr = Age->text();


    if (AgeStr.size()==1)
    {


        QRegExp rx("[1-9]{1,1}");
        QRegExpValidator v (rx,0);

        int pos = 0;
        if (v.validate(AgeStr,pos)==0)
        {
            AgeStr = "";
            Age->setText("");
            Err="\t     ���� '�������' ������� �������\n";
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
            Err="\t     ���� '�������' ������� �������\n";
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

void RegistrationPanel::doAut()
{
    Passwd->clear();
    ConfPasswd->clear();
    NickName->clear();
    Project->clear();
    Sex->clear();
    Age->clear();
    FIO->clear();

    emit sendError("");

    emit doAutorisation(2);

}

void RegistrationPanel::writeUser()
{
    QVector<QString> Logins;
    int flag = 0;

    Logins = DB->GetColumnFromTable("login","user");
    for (int i = 0; i<Logins.size(); i++)
    {
        if (Logins[i]==NickName->text())
        {
            flag = 1;
        }
    }

    if (flag == 1) emit sendError("������������ � ����� ������ ��� ����������");
    else
    {
        DB->SetRegistrationInfo(NickName->text(),Passwd->text(),FIO->text(),Project->text(),GroupName,Sex->text(),Age->text().toDouble());
        emit getEtaps(4);
    }


}

void RegistrationPanel::setDB(dbWork *_db)
{
    DB = _db;

}
