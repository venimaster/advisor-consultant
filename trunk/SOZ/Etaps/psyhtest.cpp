#include "psyhtest.h"

PsyhTest::PsyhTest(dbWork *_db, int _TestNum, QString _login, QWidget *parent) :
    QWidget(parent)
{
    SetDB(_db);

    TestNum=_TestNum;


    login = _login;
    UserType=1;

    TestName="";
    DopMSG="";



    Dalee=new TesterDaleeButton(this);
    Dalee->setAvilable();
    connect(Dalee,SIGNAL(iPressed()),this,SLOT(obrabotka()));

    Lay = new QGridLayout(this);

    setLayout(Lay);


    setQuestion(TestNum);



}

void PsyhTest::SetDB(dbWork *db)
{
    DB=db;
}

void PsyhTest::countParams()
{
    qTests=5;
}

void PsyhTest::setQuestion(int _quest)
{
    switch (_quest)
    {

        case 1: test1(); break;
        case 2: test2(); break;
        case 3: test3(); break;
        case 4: test4(); break;
        case 5: test5(); break;
        case 6: test6(); break;

        case 7: globalTest1(); break;
        case 8: globalTest2(); break;
        case 9: globalTest3(); break;
        case 10: globalTest4(); break;
        case 11: globalTest5(); break;

    }

    renameNames();

}

void PsyhTest::test1()
{
    TestName = "“≈—“»–Œ¬¿Õ»≈ “¬Œ–≈÷/Ã€—À»“≈À‹";
    DopMSG = "Œ÷≈Õ»“≈ œŒ ƒ≈—ﬂ“»¡¿À‹ÕŒ… ÿ ¿À≈";

    int QuestSize;

    Questions = DB->GetColumnFromTable("question","creator_speculator");
    QuestSize=Questions.size();
    qQuestions=QuestSize;
    qVariants=11;



    QPalette pal;
    pal.setBrush(QPalette::Base,Qt::transparent);
    pal.setBrush(QPalette::WindowText,Qt::white);



    QVector <QGridLayout*> AnsLay;

    for (int i=0;i<QuestSize;i++)
    {
        ChoosenVars<<0;
        QLabel* Quest = new QLabel(Questions[i]);
        Quest->setPalette(pal);
        Lay->addWidget(Quest,i*2,0,1,1);
        AnsLay<<new QGridLayout();
        for (int k=0; k<11; k++)
        {
            QString num = QString::number(k);
            PsyhTestVariantButton* btn = new PsyhTestVariantButton(k,i,QString::number(k),k,this);
            btn->SetUnChoosen();
            AllBtns<<btn;
            connect (btn,SIGNAL(iPressed(int,int)),this,SLOT(changeVariant(int,int)));



            AnsLay[i]->addWidget(btn,0,k,1,1);
            Lay->addLayout(AnsLay[i],i*2+1,0,1,1);
        }


    }

    Lay->addWidget(Dalee,QuestSize*2+1,0,3,1);


    update();
}

void PsyhTest::changeVariant(int Var, int Quest)
{
    int i = Quest;


    qDebug()<<Var<<Quest;

    for (int j=qVariants*i;j<qVariants*(i+1);j++)
    {
        AllBtns[j]->SetUnChoosen();
    }
    AllBtns[qVariants*i+Var]->SetChoosen();
    ChoosenVars[Quest]=Var;
    qDebug()<<ChoosenVars;

    if (!(Dalee->isAvilable()))
    {
        int DaleeFlag=0;
        for (int i=0;i<ChoosenVars.size();i++)
        {
            if (ChoosenVars[i]==-1) DaleeFlag=1;
        }
        if (DaleeFlag==0) Dalee->setAvilable();

    }

}

void PsyhTest::test2()
{
    TestName = "“≈—“ –»√»ƒÕŒ—“‹/√»¡ Œ—“‹";
    DopMSG = "¬€¡≈–»“≈ ƒ¿ »À» Õ≈“";

    int QuestSize;

    Questions = DB->GetColumnFromTable("statement","rigidity_versatility");
    qDebug()<<Questions;
    QuestSize=Questions.size();
    qQuestions=QuestSize;
    qVariants=2;



    QPalette pal;
    pal.setBrush(QPalette::Base,Qt::transparent);
    pal.setBrush(QPalette::WindowText,Qt::white);


    QVector <QGridLayout*> AnsLay;

    for (int i=0;i<QuestSize;i++)
    {
        ChoosenVars<<-1;
        QLabel* Quest = new QLabel(Questions[i]);
        Quest->setPalette(pal);
        Lay->addWidget(Quest,i*2,0,1,1);
        AnsLay<<new QGridLayout();
        for (int k=0; k<2; k++)
        {
            QString num = QString::number(k);
            PsyhTestVariantButton* btn = new PsyhTestVariantButton(k,i,k==0?"ÌÂÚ":"‰‡",k,this);
            btn->SetUnChoosen();
            AllBtns<<btn;
            connect (btn,SIGNAL(iPressed(int,int)),this,SLOT(changeVariant(int,int)));



            AnsLay[i]->addWidget(btn,0,k,1,1);
            Lay->addLayout(AnsLay[i],i*2+1,0,1,1);
        }


    }

    Lay->addWidget(Dalee,QuestSize*2+1,0,3,1);

    update();
}

void PsyhTest::test3()
{
    TestName = "“≈—“ Õ¿ “≈Ãœ≈–¿Ã≈Õ“";
    DopMSG = "¬€¡≈–»“≈ ƒ¿ »À» Õ≈“";

    int QuestSize;

    Questions = DB->GetColumnFromTable("question","temperament_type");
    qDebug()<<Questions;
    QuestSize=Questions.size();
    qQuestions=QuestSize;
    qVariants=2;



    QPalette pal;
    pal.setBrush(QPalette::Base,Qt::transparent);
    pal.setBrush(QPalette::WindowText,Qt::white);


    QVector <QGridLayout*> AnsLay;

    for (int i=0;i<QuestSize;i++)
    {
        ChoosenVars<<-1;
        QLabel* Quest = new QLabel(Questions[i]);
        Quest->setPalette(pal);
        Lay->addWidget(Quest,i*2,0,1,1);
        AnsLay<<new QGridLayout();
        for (int k=0; k<2; k++)
        {
            QString num = QString::number(k);
            PsyhTestVariantButton* btn = new PsyhTestVariantButton(k,i,k==0?"ÌÂÚ":"‰‡",k,this);
            btn->SetUnChoosen();
            AllBtns<<btn;
            connect (btn,SIGNAL(iPressed(int,int)),this,SLOT(changeVariant(int,int)));



            AnsLay[i]->addWidget(btn,0,k,1,1);
            Lay->addLayout(AnsLay[i],i*2+1,0,1,1);
        }


    }

    Lay->addWidget(Dalee,QuestSize*2+1,0,3,1);

    update();

}

void PsyhTest::test4()
{
    TestName = "“≈—“ Õ¿ œŒÀ≈«¿¬»—»ÃŒ—“‹/œŒÀ≈Õ≈«¿¬»—»ÃŒ—“‹";

    int span = 0;

    qDebug()<<Questions;
    qVariants=5;
    qQuestions = 5;

    QTime Timer;


    Timer=Timer.currentTime();
    timeStart=Timer.second();


    QImage PolEx1 = QImage(":/backgrounds/PolEx1");
    QImage PolEx2 = QImage(":/backgrounds/PolEx2");
    QImage Pol1 = QImage(":/backgrounds/Pol1");
    QImage Pol2 = QImage(":/backgrounds/Pol2");
    QImage Pol3 = QImage(":/backgrounds/Pol3");
    QImage Pol4 = QImage(":/backgrounds/Pol4");
    QImage Pol5 = QImage(":/backgrounds/Pol5");





    QPalette pal;
    pal.setBrush(QPalette::Base,Qt::transparent);
    pal.setBrush(QPalette::WindowText,Qt::white);

    //ƒÓ·‡‚ÎˇÂÏ ËÌÒÚÛÍˆË˛

    QLabel* lbl1 = new QLabel("»Õ—“–” ÷»ﬂ:"); lbl1->setPalette(pal);
    QLabel* lbl2 = new QLabel("¬ Í‡Ê‰ÓÏ ÒÎÓÊÌÓÏ ËÒÛÌÍÂ ËÏÂÂÚÒˇ Ó‰ËÌ ËÁ ÒÎÂ‰Û˛˘Ëı ˝ÎÂÏÂÌÚÓ‚:");lbl2->setPalette(pal);
    QLabel* lbl3 = new QLabel(); lbl3->setPixmap(QPixmap::fromImage(PolEx1));lbl3->setPalette(pal);
    QLabel* lbl4 = new QLabel("Õ‡ÁÓ‚ËÚÂ ‚ Í‡Ê‰ÓÏ ÒÎÛ˜‡Â, Í‡ÍÓÈ ËÁ ˝ÚËı ˝ÎÂÏÂÌÚÓ‚ ÒÓ‰ÂÊËÚÒˇ ‚ ËÒÛÌÍÂ. Õ‡ÔËÏÂ:");lbl4->setPalette(pal);
    QLabel* lbl5 = new QLabel(); lbl5->setPixmap(QPixmap::fromImage(PolEx2));lbl5->setPalette(pal);
    QLabel* lbl51 = new QLabel("œŒÃÕ»“≈:");lbl51->setPalette(pal);
    QLabel* lbl52 = new QLabel("ï	¬ Í‡Ê‰ÓÏ ËÒÛÌÍÂ ËÏÂÂÚÒˇ Ó‰ËÌ ËÁ ˝ÎÂÏÂÌÚÓ‚ ÚÓÈ ÊÂ ‚ÂÎË˜ËÌ˚ Ë Ú‡ÍÊÂ ‡ÒÔÓÎÓÊÂÌÌ˚È Í‡Í Ì‡ Ó·‡ÁˆÂ;");lbl52->setPalette(pal);
    QLabel* lbl53 = new QLabel("ï	¬ Í‡Ê‰ÓÏ ËÒÛÌÍÂ ËÏÂÂÚÒˇ ÚÓÎ¸ÍÓ Ó‰ËÌ ËÁ ˝ÎÂÏÂÌÚÓ‚."); lbl53->setPalette(pal);
    QLabel* lbl6 = new QLabel("___________________________________________________________________________________________________________________________________");lbl6->setPalette(pal);
    QLabel* lbl61 = new QLabel("___________________________________________________________________________________________________________________________________");lbl61->setPalette(pal);
    QLabel* lbl7 = new QLabel("«¿ƒ¿Õ»≈:");lbl7->setPalette(pal);

    Lay->addWidget(lbl1,span,0,1,6);span++;
    Lay->addWidget(lbl2,span,0,1,6);span++;
    Lay->addWidget(lbl3,span,0,4,6,Qt::AlignCenter);span+=4;
    Lay->addWidget(lbl4,span,0,1,6);span++;
    Lay->addWidget(lbl5,span,0,4,6,Qt::AlignCenter);span+=4;
    Lay->addWidget(lbl51,span,0,1,6);span++;
    Lay->addWidget(lbl52,span,0,1,6);span++;
    Lay->addWidget(lbl53,span,0,1,6);span++;
    Lay->addWidget(lbl6,span,0,1,6);span++;
    Lay->addWidget(lbl61,span,0,1,6);span++;
    Lay->addWidget(lbl7,span,0,1,6);span++;

    // œŒÿÀ» «¿ƒ¿Õ»ﬂ

    QVector <QLabel*> IMGs;
    QLabel* Z1 = new QLabel(); Z1->setPixmap(QPixmap::fromImage(Pol1));Z1->setPalette(pal);
    QLabel* Z2 = new QLabel(); Z2->setPixmap(QPixmap::fromImage(Pol2));Z2->setPalette(pal);
    QLabel* Z3 = new QLabel(); Z3->setPixmap(QPixmap::fromImage(Pol3));Z3->setPalette(pal);
    QLabel* Z4 = new QLabel(); Z4->setPixmap(QPixmap::fromImage(Pol4));Z4->setPalette(pal);
    QLabel* Z5 = new QLabel(); Z5->setPixmap(QPixmap::fromImage(Pol5));Z5->setPalette(pal);
    IMGs<<Z1<<Z2<<Z3<<Z4<<Z5;

    QVector<QGridLayout *> Grids;
    QGridLayout* ZL1 = new QGridLayout(this);
    QGridLayout* ZL2 = new QGridLayout(this);
    QGridLayout* ZL3 = new QGridLayout(this);
    QGridLayout* ZL4 = new QGridLayout(this);
    QGridLayout* ZL5 = new QGridLayout(this);
    Grids<<ZL1<<ZL2<<ZL3<<ZL4<<ZL5;

    QVector<QLabel *> ZLLab;

    int counter = 1;
    int group = 1;
    for (int i=1;i<=30;i++)
    {
        if (counter > 6) {counter=1; group++;}
        ZLLab<<new QLabel(QString::number(i)+":");ZLLab[i-1]->setPalette(pal);

        Grids[group-1]->addWidget(ZLLab[i-1],counter-1,0,1,1,Qt::AlignCenter);
        qDebug()<<group<<counter;
        counter++;
    }

    QVector<PsyhTestVariantButton *> Answers;

    counter=1;
    group=1;
    int grid;
    ChoosenVars<<-1;

    for (int i=1;i<=30*5;i++)
    {
        grid = (i-1)/30;
        QString lb;
        if (counter>5) {counter = 1; group++;ChoosenVars<<-1;}

        switch (i%5)
        {
            case 1: lb = "A"; break;
            case 2: lb = "¡"; break;
            case 3: lb = "¬"; break;
            case 4: lb = "√"; break;
            case 0: lb = "ƒ"; break;
        }

        Answers<<new PsyhTestVariantButton(counter-1,group-1,lb,counter,this);
        Answers[i-1]->SetUnChoosen();

        connect (Answers[i-1],SIGNAL(iPressed(int,int)),this,SLOT(changeVariant(int,int)));

        qDebug()<<counter<<group;

        counter++;
    }

    counter = 0;
    for (int i=1;i<=5;i++)
    {

        for (int j=1;j<=6;j++)
            for (int k=1;k<=5;k++)
            {
                Grids[i-1]->addWidget(Answers[counter],j-1,k,1,1);
                counter++;
            }
    }

    QVector<QLabel *> poloski;
    for (int i=1;i<=5;i++)
    {
        Lay->addWidget(IMGs[i-1],span,0,15,6,Qt::AlignCenter);span+=15;
        Lay->addLayout(Grids[i-1],span,0,5,5);span+=5;
        QLabel *_lbl = new QLabel("___________________________________________________________________________________________________________________________________");_lbl->setPalette(pal);
        poloski<<_lbl;

        Lay->addWidget(poloski[i-1],span,0,1,6,Qt::AlignCenter);span++;
    }

    AllBtns=Answers;


    Lay->addWidget(Dalee,span,0,3,6);

    qQuestions = span/2+2;

    update();

}

void PsyhTest::test5()
{
    TestName = "“≈—“ \"»ƒ≈¿À‹Õ€… › —œ≈–“\"";
    DopMSG = "¬€¡≈–»“≈ Œƒ»Õ »« ¬¿–»¿Õ“Œ¬ Œ“¬≈“¿";

    int QuestSize;

    Questions = DB->GetColumnFromTable("question","ideal_expert");
    qDebug()<<Questions;

    QuestSize=Questions.size();
    qQuestions=QuestSize;
    qVariants=5;



    QPalette pal;
    pal.setBrush(QPalette::Base,Qt::transparent);
    pal.setBrush(QPalette::WindowText,Qt::white);


    QVector <QGridLayout*> AnsLay;
    QVector <QLabel*> lines;

    for (int i=0;i<QuestSize;i++)
    {
        ChoosenVars<<-1;
        QLabel* Quest = new QLabel(Questions[i]);
        Quest->setPalette(pal);

        lines<< new QLabel("___________________________________________________________________________________________________________________________________");
        lines[i]->setPalette(pal);

        Lay->addWidget(lines[i],i*4+1,0,1,1,Qt::AlignCenter);
        Lay->addWidget(Quest,i*4+2,0,1,1);





        AnsLay<<new QGridLayout();

        QVector<QString> AnsVariant;
        AnsVariant = DB->GetAnswerVariants("ideal_expert",i+1);
        qDebug()<<AnsVariant;


        for (int k=0; k<5; k++)
        {
            QString num = QString::number(k);
            PsyhTestVariantButton* btn = new PsyhTestVariantButton(k,i,AnsVariant[k],k,this);
            btn->SetUnChoosen();
            AllBtns<<btn;
            connect (btn,SIGNAL(iPressed(int,int)),this,SLOT(changeVariant(int,int)));



            AnsLay[i]->addWidget(btn,0,k,1,1);
            Lay->addLayout(AnsLay[i],i*4+3,0,2,1);
        }
        qDebug()<<i;


    }

    Lay->addWidget(Dalee,QuestSize*4+5,0,3,1);

    qQuestions = 50;

    update();

}

void PsyhTest::test6()
{
    TestName = "“≈—“ \"»ƒ≈¿À‹Õ€… »Õ∆≈Õ≈– œŒ «Õ¿Õ»ﬂÃ\"";
    DopMSG = "¬€¡≈–»“≈ Œƒ»Õ »« ¬¿–»¿Õ“Œ¬ Œ“¬≈“¿";

    int QuestSize;

    Questions = DB->GetColumnFromTable("question","ideal_knowledge_ingeneer");
    qDebug()<<Questions;

    QuestSize=Questions.size();
    qQuestions=QuestSize;
    qVariants=5;



    QPalette pal;
    pal.setBrush(QPalette::Base,Qt::transparent);
    pal.setBrush(QPalette::WindowText,Qt::white);


    QVector <QGridLayout*> AnsLay;
    QVector <QLabel*> lines;

    for (int i=0;i<QuestSize;i++)
    {
        ChoosenVars<<-1;
        QLabel* Quest = new QLabel(Questions[i]);
        Quest->setPalette(pal);

        lines<< new QLabel("___________________________________________________________________________________________________________________________________");
        lines[i]->setPalette(pal);

        Lay->addWidget(lines[i],i*4+1,0,1,1,Qt::AlignCenter);
        Lay->addWidget(Quest,i*4+2,0,1,1);





        AnsLay<<new QGridLayout();

        QVector<QString> AnsVariant;
        AnsVariant = DB->GetAnswerVariants("ideal_knowledge_ingeneer",i+1);
        qDebug()<<AnsVariant;


        for (int k=0; k<5; k++)
        {
            QString num = QString::number(k);
            PsyhTestVariantButton* btn = new PsyhTestVariantButton(k,i,AnsVariant[k],k,this);
            btn->SetUnChoosen();
            AllBtns<<btn;
            connect (btn,SIGNAL(iPressed(int,int)),this,SLOT(changeVariant(int,int)));



            AnsLay[i]->addWidget(btn,0,k,1,1);
            Lay->addLayout(AnsLay[i],i*4+3,0,2,1);
        }
        qDebug()<<i;


    }

    Lay->addWidget(Dalee,QuestSize*4+5,0,3,1);

    qQuestions = 50;

    update();


}

void PsyhTest::globalTest1()
{
    TestName = "¿Õ¿À»« Õ¿ ”Ã≈—“ÕŒ—“‹, Œœ–¿¬ƒ¿ÕÕŒ—“‹, ¬Œ«ÃŒ∆ÕŒ—“‹";
    DopMSG = "¬€¡≈–»“≈ Œƒ»Õ »« ¬¿–»¿Õ“Œ¬ Œ“¬≈“¿";

    int QuestSize;

    Questions = DB->GetColumnFromTable("measure","relevance_research");
    QVector<QString> str;
    str = DB->GetColumnFromTable("measure","propriety_research");
    for (int i=0; i<str.size(); i++)
    {
        Questions<<str[i];
    }
    str = DB->GetColumnFromTable("measure","opportunity_research");
    for (int i=0; i<str.size(); i++)
    {
        Questions<<str[i];
    }

    qDebug()<<Questions;

    QuestSize=Questions.size();
    qQuestions=QuestSize;
    qVariants=5;



    QPalette pal;
    pal.setBrush(QPalette::Base,Qt::transparent);
    pal.setBrush(QPalette::WindowText,Qt::white);


    QVector <QGridLayout*> AnsLay;
    QVector <QLabel*> lines;

    for (int i=0;i<QuestSize;i++)
    {
        ChoosenVars<<-1;
        QLabel* Quest = new QLabel(Questions[i]);
        Quest->setPalette(pal);

        lines<< new QLabel("___________________________________________________________________________________________________________________________________");
        lines[i]->setPalette(pal);

        Lay->addWidget(lines[i],i*4+1,0,1,1,Qt::AlignCenter);
        Lay->addWidget(Quest,i*4+2,0,1,1);





        AnsLay<<new QGridLayout();

        QVector<QString> AnsVariant;
        AnsVariant = DB->GetAnswerVariants("opportunity_research",1);
        qDebug()<<AnsVariant;


        for (int k=0; k<5; k++)
        {
            QString num = QString::number(k);
            PsyhTestVariantButton* btn = new PsyhTestVariantButton(k,i,AnsVariant[k],k,this);
            btn->SetUnChoosen();
            AllBtns<<btn;
            connect (btn,SIGNAL(iPressed(int,int)),this,SLOT(changeVariant(int,int)));



            AnsLay[i]->addWidget(btn,0,k,1,1);
            Lay->addLayout(AnsLay[i],i*4+3,0,2,1);
        }
        qDebug()<<i;


    }

    Lay->addWidget(Dalee,QuestSize*4+5,0,3,1);

    qQuestions = 50;

    update();
}

void PsyhTest::globalTest2()
{

}

void PsyhTest::globalTest3()
{

    Dalee->setDisAvilable();
    TestName = "¬€¡Œ– ÃŒƒ≈À» œ–≈ƒ—“¿¬À≈Õ»ﬂ «Õ¿Õ»…";
    DopMSG = "¬€¡≈–»“≈ Œƒ»Õ »« ¬¿–»¿Õ“Œ¬ Œ“¬≈“¿";

    int QuestSize;

    Questions<<"Œ„‡ÌËÁ‡ˆËˇ ÒÛ˘ÌÓÒÚÂÈ ‚ ÔÓÌˇÚËˇı"<<"ŒÚÌÓ¯ÂÌËˇ ÏÂÊ‰Û ÔÓÌˇÚËˇÏË"<<"—ÔÓÒÓ· ‡ÒÒÛÊ‰ÂÌËÈ";

    qDebug()<<Questions;

    QuestSize=Questions.size();

    qQuestions=QuestSize;
    qVariants=3;



    QPalette pal;
    pal.setBrush(QPalette::Base,Qt::transparent);
    pal.setBrush(QPalette::WindowText,Qt::white);


    QVector <QGridLayout*> AnsLay;
    QVector <QLabel*> lines;

    for (int i=0;i<QuestSize;i++)
    {
        ChoosenVars<<-1;
        QLabel* Quest = new QLabel(Questions[i]);
        Quest->setPalette(pal);

        lines<< new QLabel("___________________________________________________________________________________________________________________________________");
        lines[i]->setPalette(pal);

        Lay->addWidget(lines[i],i*4+1,0,1,1,Qt::AlignCenter);
        Lay->addWidget(Quest,i*4+2,0,1,1);





        AnsLay<<new QGridLayout();

        QVector<QString> AnsVariant;

        switch(i)
        {
            case 0: AnsVariant<<"œ–Œ—“€≈"<<"¬ Œ—ÕŒ¬ÕŒÃ, œ–Œ—“€≈"<<"—ÀŒ∆Õ€≈";break;
            case 1: AnsVariant<<"¬€–¿∆¿ﬁ“—ﬂ Õ¿ ﬂ«€ ≈ »—◊»—À≈Õ»ﬂ œ–≈ƒ» ¿“Œ¬"<<"Õ≈¡ŒÀ‹ÿŒ≈ ◊»—ÀŒ"<<"¡ŒÀ‹ÿŒ≈ ◊»—ÀŒ";break;
            case 2: AnsVariant<<"ƒ≈ƒ” “»¬Õ€…"<<"»Õƒ” “»¬Õ€…"<<"¬€ƒ¬»∆≈Õ»ﬂ √»œŒ“≈«";break;
        }


        for (int k=0; k<3; k++)
        {
            QString num = QString::number(k);
            PsyhTestVariantButton* btn = new PsyhTestVariantButton(k,i,AnsVariant[k],k,this);
            btn->SetUnChoosen();
            AllBtns<<btn;
            connect (btn,SIGNAL(iPressed(int,int)),this,SLOT(changeVariant(int,int)));



            AnsLay[i]->addWidget(btn,0,k,1,1);
            Lay->addLayout(AnsLay[i],i*4+3,0,2,1);
        }
        qDebug()<<i;


    }

    Lay->addWidget(Dalee,QuestSize*4+5,0,3,1);

    qQuestions = 10;

    update();

}

void PsyhTest::globalTest4()
{

    int step=0;
    TestName = "¬€¡Œ– »Õ—“–”Ã≈Õ“¿À‹Õ€’ —–≈ƒ—“¬";
    DopMSG = "¬€¡≈–»“≈ œŒƒ’ŒƒﬂŸ»≈ ƒÀﬂ ¬¿— ¬¿–»¿Õ“€";

    int QuestSize;

    Questions<<"œÓËÁ‚Ó‰ËÚÂÎ¸"<<"œÎ‡ÚÙÓÏ‡ Â‡ÎËÁ‡ˆËË"<<"ﬂÁ˚Í Â‡ÎËÁ‡ˆËË"<<"œÂ‰ÒÚ‡‚ÎÂÌËÂ ÁÌ‡ÌËÈ"<<"Ã‡¯ËÌ‡ ‚˚‚Ó‰‡"<<"»ÌÚÂÙÂÈÒÌ˚Â ÒÂ‰ÒÚ‚‡"<<"—Â‰ÒÚ‚‡ ËÌÚÂ„‡ˆËË";


    qDebug()<<Questions;

    QuestSize=Questions.size();

    qQuestions=QuestSize;



    QPalette pal;
    pal.setBrush(QPalette::Base,Qt::transparent);
    pal.setBrush(QPalette::WindowText,Qt::white);


    QVector <QGridLayout*> AnsLay;
    AnsLay<<new QGridLayout(this);

    QVector <QLabel*> lines;
    QVector <int> borders;

        QVector<QString> AnsVariant;

        AnsVariant=DB->GetColumnFromTable("company","manufacturing_company");

        borders<<AnsVariant.size();

        AnsVariant+=DB->GetColumnFromTable("platform_name","platform");

        borders<<AnsVariant.size();

        AnsVariant+=DB->GetColumnFromTable("language","programming_language");

        borders<<AnsVariant.size();

        AnsVariant+=DB->GetColumnFromTable("knowledge_representation","knowledge_representation");

        borders<<AnsVariant.size();

        AnsVariant+=DB->GetColumnFromTable("solver","solver");

        borders<<AnsVariant.size();

        AnsVariant+=DB->GetColumnFromTable("interface_mean","interface_means");

        borders<<AnsVariant.size();

        AnsVariant+=DB->GetColumnFromTable("integration_mean","integration_means");

        borders<<AnsVariant.size();

        qDebug()<<borders;


        int bord=0;
        int iter1=0;
        int iter2=0;
        int iter3=0;
        int iter4=0;

        for (int i=0;i<AnsVariant.size();i++)
        {
            if (iter3>4) {iter3=0; iter4++;}
            if ((iter1<borders.size()) && (bord==borders[iter1]))
            {
                iter1++;
                iter2=0;
                iter3=0;
                iter4+=2;
                qDebug()<<"AAAA";
                AnsLay  << new QGridLayout(this);

            }
            qDebug()<<iter1<<iter2<<iter3<<iter4;

            PsyhTestVariantButton* btn = new PsyhTestVariantButton(iter2,iter1,AnsVariant[i],iter2,this);
            btn->SetUnChoosen();
            AllBtns<<btn;

            AnsLay[AnsLay.size()-1]->addWidget(btn,iter4,iter3,1,1);

            iter2++;
            iter3++;
            bord++;

        }

        int cntr=0;

        for (int i=0;i<AnsLay.size();i++)
        {


            qDebug()<<"cntr"<<cntr;
            cntr=borders[i]/5;
            qDebug()<<borders[i];
            Lay->addLayout(AnsLay[i],cntr,0,(i>0)?(borders[i]-borders[i-1])/5:borders[i]/5,5);
            qDebug()<<i;


        }


    Lay->addWidget(Dalee,QuestSize*4+5,0,3,1);

    qQuestions = 30;

    update();


}
void PsyhTest::globalTest5()
{

}

void PsyhTest::startTest()
{
    TestNum=1;
    setQuestion(TestNum);
}

void PsyhTest::obrabotka()
{
    switch (TestNum)
    {
        case 1:
        {

            QString str;
            int left;
            int right;

            for (int i=0; i<ChoosenVars.size();i++)
            {
                if (ChoosenVars[i]==-1) ChoosenVars[i]=0;
            }

            left = ChoosenVars[0]+ChoosenVars[1]+ChoosenVars[4]+ChoosenVars[7]+ChoosenVars[8];
            right = ChoosenVars[2]+ChoosenVars[3]+ChoosenVars[5]+ChoosenVars[6]+ChoosenVars[9];


            if (left>5+right)
            {
                str = "Ï˚ÒÎËÚÂÎ¸";
            }
            else if (right<left)
            {
                str = "ıÛ‰ÓÊÌËÍ";
            }
            else
            {
                str = "ÎÓ„Ë˜ÂÒÍÓÂ Ë ıÛ‰ÓÊÂÒÚ‚ÂÌÌÓÂ Ï˚¯ÎÂÌËÂ";
            }

            DB->SetResult(login,"c_s_result",str);

        }
        break;

        case 2:
        {
            int result=0;
            QString res;
            QVector<int> yes;
            QVector<int> no;

            yes<<1<<2<<4<<6<<9<<11<<14<<15<<16<<18<<20<<21<<23<<24<<27<<28<<31<<34<<35<<36<<40<<41<<44<<46<<48;
            no<<0<<3<<5<<7<<8<<10<<12<<13<<17<<19<<22<<25<<26<<29<<30<<32<<33<<37<<38<<39<<42<<43<<45<<47<<49;

            int yesi=0;
            int noi=0;

            qDebug()<<yes.size()<<no.size();

            for (int i=0;i<ChoosenVars.size();i++)
            {
                if (yesi<yes.size()&&i==yes[yesi])
                {
                    if (ChoosenVars[i]==1) result++;
                    yesi++;
                }
                else
                    if (i==no[noi]&&noi<no.size())
                    {
                        if (ChoosenVars[i]==0) result++;
                        noi++;
                    }

            }
            if (result<=13) res = "„Ë·ÍËÈ";
            if (result>13 && result<=27) res = "˜ÂÚ˚ Ë„Ë‰ÌÓÒÚË Ë „Ë·ÍÓÒÚË";
            if (result>27) res = "Ë„Ë‰Ì˚È";
            DB->SetResult(login,"r_v_result",res);

            qDebug()<<result;

        }
        break;

        case 3:
        {
            int iskrenScore=0;
            int unstableScore=0;
            int extraScore=0;

            QString str;

            ChoosenVars<<0;
            for (int i=ChoosenVars.size()-1;i>0;i--)
            {
                ChoosenVars[i]=ChoosenVars[i-1];
            }


            QVector<int> iskrenYes;
            iskrenYes<<6<<24<<36;

            QVector<int> iskrenNo;
            iskrenNo<<12<<18<<30<<42<<48<<54;

            QVector<int> unstableYes;
            unstableYes<<2<<4<<7<<9<<11<<14<<16<<19<<21<<23<<26<<28<<31<<33<<35<<38<<40<<43<<45<<47<<50<<52<<55<<57;

            QVector<int> extraYes;
            extraYes<<1<<3<<8<<10<<13<<17<<22<<25<<27<<39<<44<<46<<49<<53<<56;

            QVector<int> extraNo;
            extraNo<<5<<15<<20<<29<<32<<34<<37<<41<<51;

            //ÔÓ‚ÂÍ‡ Ì‡ ËÒÍÂÌÌÓÒÚ¸;
            int yesi=1;
            int noi=1;

            for(int i=1;i<ChoosenVars.size();i++)
            {
                if (yesi<iskrenYes.size() && i==iskrenYes[yesi])
                {
                    if (ChoosenVars[i]==1) iskrenScore++;
                    yesi++;
                }
                else
                    if(noi<iskrenNo.size() && i==iskrenNo[noi])
                    {
                        if (ChoosenVars[i]==1) iskrenScore++;
                        noi++;
                    }
            }
            noi=1;
            yesi=1;

            //ÔÓ‚ÂÍ‡ Ì‡ ÌÂÒÚ‡·ËÎ¸ÌÓÒÚ¸
            for(int i=1;i<ChoosenVars.size();i++)
            {
                if (yesi<unstableYes.size() && i==unstableYes[yesi])
                {
                    if (ChoosenVars[i]==1) unstableScore++;
                    yesi++;
                }
            }

            noi=1;
            yesi=1;

            //ÔÓ‚ÂÍ‡ Ì‡ ˝ÍÒÚ‡‚ÂÒË˛
            for(int i=1;i<ChoosenVars.size();i++)
            {
                if (yesi<extraYes.size() && i==extraYes[yesi])
                {
                    if (ChoosenVars[i]==1) extraScore++;
                    yesi++;
                }
                else
                    if(noi<extraNo.size() && i==extraNo[noi])
                    {
                        if (ChoosenVars[i]==1) extraScore++;
                        noi++;
                    }
            }

            //‡Ò˜ÂÚ Ë Á‡ÔËÒ¸ ‚ ¡ƒ

            qDebug()<<iskrenScore<<unstableScore<<extraScore;

            if (unstableScore<=12 && extraScore<=12) str = "ÙÎÂ„Ï‡ÚËÍ";
            if (unstableScore>12 && extraScore<=12) str = "ÏÂÎ‡ÌıÓÎËÍ";
            if (unstableScore<=12 && extraScore>12) str = "Ò‡Ì„‚ËÌËÍ";
            if (unstableScore>12 && extraScore>12) str = "ÏÂÎ‡ÌıÓÎËÍ";

            DB->SetResult(login,"t_t_result",str);


        }
        break;

        case 4:
        {

            QString str;
            QTime Timer;


            Timer=Timer.currentTime();
            timeFin=Timer.second();

            double Time = (timeFin-timeStart)/60;

            qDebug()<<Time;

            int scores;
            QVector<double> rightAnsws;
            rightAnsws<<0<<1<<2<<3<<2<<2<<0<<2<<4<<4<<1<<0<<0<<2<<1<<4<<0<<0<<1<<2<<3<<1<<3<<0<<4<<1<<0<<4<<2<<1;
            for (int i=0;i<ChoosenVars.size();i++)
            {
                if (ChoosenVars[i]==rightAnsws[i]) scores++;
            }
            if ((scores/Time)>=2.5) str = "ÔÓÎÂÌÂÁ‡‚ËÒËÏÓÒÚ¸";
            else str = "ÔÓÎÂÁ‡‚ËÒËÏÓÒÚ¸";

            DB->SetResult(login,"f_f_result",str);

        }
        break;

        case 5:
        {
            int maxWeight=0;
            QVector<int> weights;
            QVector<QString> sWeights;
            sWeights = DB->GetColumnFromTable("weight","ideal_expert");

            for (int i=0;i<sWeights.size();i++)
            {
                weights<<sWeights[i].toInt();
                maxWeight+=weights[i];
            }

            QVector<int> invQuestions;
            invQuestions<<2<<14;
            int invIterator=0;

            QVector<double> ChoosenVarsD;

            for (int i=0;i<ChoosenVars.size();i++)
            {
                if (!(ChoosenVars[i]==-1))
                {
                    if (invIterator<invQuestions.size() && invQuestions[invIterator]==i)
                    {
                        switch (ChoosenVars[i])
                        {
                            case 4 : ChoosenVarsD<<1; break;
                            case 3 : ChoosenVarsD<<0.8; break;
                            case 2 : ChoosenVarsD<<0.5; break;
                            case 1 : ChoosenVarsD<<0.3; break;
                            case 0 : ChoosenVarsD<<0.1; break;
                        }
                        invIterator++;
                    }
                    else
                        switch (ChoosenVars[i])
                        {
                            case 0 : ChoosenVarsD<<1; break;
                            case 1 : ChoosenVarsD<<0.8; break;
                            case 2 : ChoosenVarsD<<0.5; break;
                            case 3 : ChoosenVarsD<<0.3; break;
                            case 4 : ChoosenVarsD<<0.1; break;
                        }
                }
                else ChoosenVarsD<<0;
            }

            int summ=0;
            for (int i=0;i<ChoosenVarsD.size();i++)
            {
                summ+=ChoosenVarsD[i]*weights[i];
            }
            qDebug()<<summ;

            if (summ<maxWeight/2) DB->SetResult(login,"competience_result","0");
            else DB->SetResult(login,"competience_result","1");


        }
        break;

        case 6:
        {
            int maxWeight=0;
            QVector<int> weights;
            QVector<QString> sWeights;
            sWeights = DB->GetColumnFromTable("weight","ideal_knowledge_ingeneer");

            for (int i=0;i<sWeights.size();i++)
            {
                weights<<sWeights[i].toInt();
                maxWeight+=weights[i];
            }


            QVector<double> ChoosenVarsD;

            for (int i=0;i<ChoosenVars.size();i++)
            {
                if (!(ChoosenVars[i]==-1))
                {
                        switch (ChoosenVars[i])
                        {
                            case 0 : ChoosenVarsD<<1; break;
                            case 1 : ChoosenVarsD<<0.8; break;
                            case 2 : ChoosenVarsD<<0.5; break;
                            case 3 : ChoosenVarsD<<0.3; break;
                            case 4 : ChoosenVarsD<<0.1; break;
                        }
                }
                else ChoosenVarsD<<0;
            }

            int summ=0;
            for (int i=0;i<ChoosenVarsD.size();i++)
            {
                summ+=ChoosenVarsD[i]*weights[i];
            }
            qDebug()<<summ;

            if (summ<maxWeight/2) DB->SetResult(login,"competience_result","0");
            else DB->SetResult(login,"competience_result","1");


        }
        break;

        case 7:
        {

            double MaxUmest=32;
            double MaxOpravd=10;
            double MaxVozm=51;

            double Umest=0;
            double Opravd=0;
            double Vozm=0;

            QVector <int> weights;
            weights<<9<<9<<5<<6<<3<<9<<8<<7<<6<<8<<6<<5<<9<<9<<8<<7<<7;
            QVector <double> ChoosenVarsD;

            for (int i=0;i<ChoosenVars.size();i++)
            {
                switch (ChoosenVars[i])
                {
                    case 0:ChoosenVarsD<<1; break;
                    case 1:ChoosenVarsD<<0.8; break;
                    case 2:ChoosenVarsD<<0.5; break;
                    case 3:ChoosenVarsD<<0.2; break;
                    case 4:ChoosenVarsD<<0; break;
                }
            }

            for (int i=0;i<5;i++)
            {
                Umest+=ChoosenVarsD[i]*weights[i];
            }
            for (int i=5;i<10;i++)
            {
                if (Opravd<ChoosenVarsD[i]*weights[i]) Opravd = ChoosenVarsD[i]*weights[i];

            }
            for (int i=10; i<weights.size();i++)
            {
                Vozm+=ChoosenVarsD[i]*weights[i];
            }

            Umest=Umest/MaxUmest;
            Opravd=Opravd/MaxOpravd;
            Vozm=Vozm/MaxVozm;

            if (Umest>=0.5) Msgs<<"–¿«–¿¡Œ“ ¿ —»—“≈Ã€ ”Ã≈—“Õ¿ ("+QString::number(Umest*100)+" %)";
            else Msgs<<"–¿«–¿¡Œ“ ¿ —»—“≈Ã€ Õ≈”Ã≈—“Õ¿ ("+QString::number(Umest*100)+" %). œŒœ–Œ¡”…“≈ œŒÀ”◊ÿ≈ œ–Œƒ”Ã¿“‹ ”Ã≈—“ÕŒ—“‹ –¿«–¿¡Œ“ » ¬¿ÿ≈… —»—“≈Ã€.";

            if (Opravd>=0.5) Msgs<<"–¿«–¿¡Œ“ ¿ —»—“≈Ã€ Œœ–¿¬ƒ¿Õ¿ ("+QString::number(Opravd*100)+" %)";
            else Msgs<<"–¿«–¿¡Œ“ ¿ —»—“≈Ã€ Õ≈Œœ–¿¬ƒ¿Õ¿ ("+QString::number(Opravd*100)+" %). œŒœ–Œ¡”…“≈ œŒÀ”◊ÿ≈ œ–Œƒ”Ã¿“‹ Œœ–¿¬ƒ¿ÕÕŒ—“‹ –¿«–¿¡Œ“ » —»—“≈Ã€";

            if (Vozm>=0.5) Msgs<<"–¿«–¿¡Œ“ ¿ —»—“≈Ã€ ¬Œ«ÃŒ∆Õ¿ ("+QString::number(Vozm*100)+" %)";
            else Msgs<<"–¿«–¿¡Œ“ ¿ —»—“≈Ã€ Õ≈¬Œ«ÃŒ∆Õ¿ ("+QString::number(Vozm*100)+" %). œŒœ–Œ¡”…“≈ œŒÀ”◊ÿ≈ œ–Œƒ”Ã¿“‹ œ–»Õ÷»œ€ –¿«–¿¡Œ“ » —»—“≈Ã€.";

            qDebug()<<Msgs;

            sendItog(Msgs);

        }
        break;

        case 9:
        {
        QString msg="";
        if ((ChoosenVars[0]==0 || (ChoosenVars[0]==1)) && ChoosenVars[1]==0 && ChoosenVars[2]==0)
            msg = "¬ œ–Œ≈ “≈ ÷≈À≈—ŒŒ¡–¿«ÕŒ »—œŒÀ‹«Œ¬¿“‹ ÀŒ√»◊≈— »≈ ÃŒƒ≈À» œ–≈ƒ—“¿¬À≈Õ»ﬂ «Õ¿Õ»…";
        if ((ChoosenVars[0]==0 || (ChoosenVars[0]==1))  && ChoosenVars[1]==1 && ChoosenVars[2]==1)
            msg = "¬ œ–Œ≈ “≈ ÷≈À≈—ŒŒ¡–¿«ÕŒ »—œŒÀ‹«Œ¬¿“‹ »Õƒ” “»¬Õ€≈ ÃŒƒ≈À» œ–≈ƒ—“¿¬À≈Õ»ﬂ «Õ¿Õ»…";
        if (ChoosenVars[0]==2  && ChoosenVars[1]==2 && ChoosenVars[2]==1)
            msg = "¬ œ–Œ≈ “≈ ÷≈À≈—ŒŒ¡–¿«ÕŒ »—œŒÀ‹«Œ¬¿“‹ —≈“≈¬€≈ ÃŒƒ≈À» œ–≈ƒ—“¿¬À≈Õ»ﬂ «Õ¿Õ»…";
        if (ChoosenVars[0]==2  && ChoosenVars[1]==2 && ChoosenVars[2]==0)
            msg = "¬ œ–Œ≈ “≈ ÷≈À≈—ŒŒ¡–¿«ÕŒ »—œŒÀ‹«Œ¬¿“‹ Õ¿—À≈ƒ—“¬≈ÕÕŒ- ŒÕ≈◊Õ€≈ ÃŒƒ≈À» œ–≈ƒ—“¿¬À≈Õ»ﬂ «Õ¿Õ»…";
        if (ChoosenVars[0]==2  && ChoosenVars[1]==1 && ChoosenVars[2]==0)
            msg = "¬ œ–Œ≈ “≈ ÷≈À≈—ŒŒ¡–¿«ÕŒ »—œŒÀ‹«Œ¬¿“‹ ‘–≈…ÃŒ¬€≈ ÃŒƒ≈À» œ–≈ƒ—“¿¬À≈Õ»ﬂ «Õ¿Õ»…";
        if ((ChoosenVars[0]==0 || (ChoosenVars[0]==1))  && ChoosenVars[1]==2 && ChoosenVars[2]==0)
            msg = "¬ œ–Œ≈ “≈ ÷≈À≈—ŒŒ¡–¿«ÕŒ »—œŒÀ‹«Œ¬¿“‹ œ–Œƒ” ÷»ŒÕÕ€≈ ÃŒƒ≈À» œ–≈ƒ—“¿¬À≈Õ»ﬂ «Õ¿Õ»…";
        if (ChoosenVars[0]==2  && ChoosenVars[1]==0 && ChoosenVars[2]==2)
            msg = "¬ œ–Œ≈ “≈ ÷≈À≈—ŒŒ¡–¿«ÕŒ »—œŒÀ‹«Œ¬¿“‹ ÃŒƒ≈À‹ ¬€ƒ¬»∆≈Õ»ﬂ √»œŒ“≈«";
        if (ChoosenVars[0]==2  && ChoosenVars[1]==2 && ChoosenVars[2]==0)
            msg = "œŒƒ’ŒƒﬂŸ»… ‘Œ–Ã¿À»«Ã Œ“—”“—“¬”≈“";

        if (msg=="") msg = "œŒƒ’ŒƒﬂŸ»… ‘Œ–Ã¿À»«Ã Œ“—”“—“¬”≈“";
        QVector<QString> itog;
        itog<<msg;

        qDebug()<<itog;

        emit sendItog(itog);



        }
        break;



    }



}

void PsyhTest::renameNames()
{
    emit changeMainName("œ—»’ŒÀŒ√»◊≈— Œ≈ “≈—“»–Œ¬¿Õ»≈");
    emit changeCentralName(TestName);
    emit changeLeftPanLabel(DopMSG);
}

void PsyhTest::setLogin(QString _login)
{
    login = _login;
}

void PsyhTest::setUserType(int _type)
{
    UserType=_type;
}


void PsyhTest::resizeEvent(QResizeEvent *)
{
    Lay->setGeometry(QRect(0,0,width()-18,60*qQuestions));
    emit heightChanged(60*qQuestions);

}

void PsyhTest::moveUp(int _h)
{
    Lay->setGeometry(QRect(0,_h,width()-18,60*qQuestions));
    update();
}

