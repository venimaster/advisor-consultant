#include "tester.h"

Tester::Tester(CentralPanel *_CP, dbWork *_DB, QObject *parent) :
    QObject(parent)
{
    DB = _DB;
    CP = _CP;

    connect(CP->OK,SIGNAL(clicked()),this,SLOT (NextQuestion()));

}

void Tester::Test_I()
{
    Questions = DB->GetColumnFromTable("measure","relevance_research");

    QuestionAll = Questions.size();

    QuestionNum=0;

    AskQuestion(0);



}

void Tester::AskQuestion(int QuestNumber)
{
    CP->SetQuestion(Questions[QuestNumber]);

    CP->SetAnswers(DB->GetAnswerVariants("relevance_research",QuestNumber+1));

    CP->SetWeightAnswers(DB->GetColumnFromTable("weight","relevance_research"));

    CP->update();

    CP->drawAnswers();

}

void Tester::NextQuestion()
{
    QuestionNum++;
    if (QuestionNum<QuestionAll)

        AskQuestion(QuestionNum);



}




