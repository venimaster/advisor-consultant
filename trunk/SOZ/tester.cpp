#include "tester.h"

Tester::Tester(CentralPanel *_CP, dbWork *_DB, QObject *parent) :
    QObject(parent)
{
    DB = _DB;
    CP = _CP;
    TP = CP->getTestPanel();

    ChoozenVariantNumber=-1;

    connect(CP,SIGNAL(sig_askNextQuestion()),this,SLOT (NextQuestion()));

}

void Tester::Test(int _et, int _set)
{
    EtapNum = _et;
    SubEtapNum = _set;
    switch (EtapNum)
    {
        case 1:
            switch (SubEtapNum)
            {
                case 1:
                    emit RenameSubEtap("ÈÑÑËÅÄÎÂÀÍÈÅ ÍÀ ÓÌÅÑÒÍÎÑÒÜ");
                    table = "relevance_research";
                    Questions = DB->GetColumnFromTable("measure",table);
                    QuestionAll = Questions.size();
                    QuestionNum=0;
                    AskQuestion(0);
                break;

                case 2:
                    emit RenameSubEtap("ÈÑÑËÅÄÎÂÀÍÈÅ ÍÀ ÎÏÐÀÂÄÀÍÍÎÑÒÜ");
                    table = "propriety_research";
                    Questions = DB->GetColumnFromTable("measure",table);
                    QuestionAll = Questions.size();
                    QuestionNum=0;
                    AskQuestion(0);
                break;

                case 3:

                emit RenameSubEtap("ÈÑÑËÅÄÎÂÀÍÈÅ ÍÀ ÂÎÇÌÎÆÍÎÑÒÜ");
                    table = "opportunity_research";
                    Questions = DB->GetColumnFromTable("measure",table);
                    QuestionAll = Questions.size();
                    QuestionNum=0;
                    AskQuestion(0);
                break;
            }
        break;

        case 2:
        {
            switch (SubEtapNum)
            {
                case 1:
                    emit RenameSubEtap("ÈÑÑËÅÄÎÂÀÍÈÅ ÍÀ ÓÌÅÑÒÍÎÑÒÜ");
                    table = "relevance_research";
                    Questions = DB->GetColumnFromTable("measure",table);
                    QuestionAll = Questions.size();
                    QuestionNum=0;
                    AskQuestion(0);
                break;

                case 2:
                    emit RenameSubEtap("ÈÑÑËÅÄÎÂÀÍÈÅ ÍÀ ÎÏÐÀÂÄÀÍÍÎÑÒÜ");
                    table = "propriety_research";
                    Questions = DB->GetColumnFromTable("measure",table);
                    QuestionAll = Questions.size();
                    QuestionNum=0;
                    AskQuestion(0);
                break;

                case 3:

                emit RenameSubEtap("ÈÑÑËÅÄÎÂÀÍÈÅ ÍÀ ÂÎÇÌÎÆÍÎÑÒÜ");
                    table = "opportunity_research";
                    Questions = DB->GetColumnFromTable("measure",table);
                    QuestionAll = Questions.size();
                    QuestionNum=0;
                    AskQuestion(0);
                break;
            }
            break;
        }
        case 3:
        break;

    }
}



void Tester::AskQuestion( int QuestNumber)
{
    TP->SetQuestion(Questions[QuestNumber]);

   // qDebug()<<DB->GetAnswerVariants(table,QuestNumber+1)<<Questions[QuestNumber];

    TP->SetAnswers(DB->GetAnswerVariants(table,QuestNumber+1));

    TP->SetWeightAnswers(DB->GetColumnFromTable("weight",table));

    TP->update();

    TP->drawAnswers();

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
        Test(EtapNum,SubEtapNum);

    }

  //  else
    //    AskLastQuestion(QuestionNum);


}




