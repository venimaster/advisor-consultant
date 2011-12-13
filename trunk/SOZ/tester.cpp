#include "tester.h"

Tester::Tester(CentralPanel *_CP, dbWork *_DB, QObject *parent) :
    QObject(parent)
{
    DB = _DB;
    CP = _CP;

    ChoozenVariantNumber=-1;

    connect(CP->OK,SIGNAL(iPressed()),this,SLOT (NextQuestion()));

}

void Tester::Test_I_I()
{

    emit RenameSubEtap("ÈÑÑËÅÄÎÂÀÍÈÅ ÍÀ ÓÌÅÑÒÍÎÑÒÜ");

    EtapNum=1;

    SubEtapNum = 1;

    table = "relevance_research";

    Questions = DB->GetColumnFromTable("measure",table);

    QuestionAll = Questions.size();

    QuestionNum=0;

    AskQuestion(0);

}

void Tester::Test_I_II()
{

    emit RenameSubEtap("ÈÑÑËÅÄÎÂÀÍÈÅ ÍÀ ÎÏÐÀÂÄÀÍÍÎÑÒÜ");

    table = "propriety_research";

    Questions = DB->GetColumnFromTable("measure",table);

    QuestionAll = Questions.size();

    QuestionNum=0;

    AskQuestion(0);

}

void Tester::Test_I_III()
{

    emit RenameSubEtap("ÈÑÑËÅÄÎÂÀÍÈÅ ÍÀ ÂÎÇÌÎÆÍÎÑÒÜ");

    table = "opportunity_research";

    Questions = DB->GetColumnFromTable("measure",table);

    QuestionAll = Questions.size();

    QuestionNum=0;

    AskQuestion(0);



}

void Tester::Test_II_I()
{
    EtapNum = 2;

    SubEtapNum = 1;

    emit RenameSubEtap ("");
}

void Tester::AskQuestion( int QuestNumber)
{
    CP->SetQuestion(Questions[QuestNumber]);

   // qDebug()<<DB->GetAnswerVariants(table,QuestNumber+1)<<Questions[QuestNumber];

    CP->SetAnswers(DB->GetAnswerVariants(table,QuestNumber+1));

    CP->SetWeightAnswers(DB->GetColumnFromTable("weight",table));

    CP->update();

    CP->drawAnswers();

}

void Tester::NextQuestion()
{
    QuestionNum++;
    if (QuestionNum<QuestionAll)
    {

        AskQuestion(QuestionNum);

    }
    else
    {
        SubEtapNum++;



        if (EtapNum == 1)
        {
            if (SubEtapNum == 2)
                Test_I_II();

            if (SubEtapNum == 3)
                Test_I_III();
        }

    }

  //  else
    //    AskLastQuestion(QuestionNum);


}




