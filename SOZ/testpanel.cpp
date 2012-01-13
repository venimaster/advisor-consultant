#include "testpanel.h"

TestPanel::TestPanel(QWidget *parent) :
    QWidget(parent)
{

    Question="";
    OK = new TesterDaleeButton(this);
    connect(this,SIGNAL(sig_enterPressed()),OK,SLOT(enterPressed()));
    connect(OK,SIGNAL(iPressed()),this,SLOT(slot_nextPressed()));


    double W = width();
    double H = height();

    QuestionRect = QRect(0,0,W,H/6);
    AnswersRect = QRect(0,H/6,W,H-2*H/6);
    ButtonsRect = QRect(0,H-H/6,W,H/6);




    varAnswers<<"";

    updateWidgets();



}

void TestPanel::updateWidgets()
{

    double W = width();
    double H = height();

    QuestionRect.setRect(0,0,W,H/6);
    AnswersRect.setRect(0,H/6,W,H-2*H/6);
    ButtonsRect.setRect(0,H-H/6,W,H/6);


    drawButtons();







    update();

}





void TestPanel::paintEvent(QPaintEvent *)
{
    QColor MyColor(QColor::fromRgb(45,75,129));
    MyColor.setAlpha(180);

    QPen pen(Qt::black);
    QBrush Brs(Qt::black);

    QPainter painter(this);

    painter.setBrush(Brs);
    painter.setPen(pen);






    painter.setBrush(QBrush(MyColor));


    painter.setPen(QPen(Qt::white));
    painter.setFont(QFont("Sherif",11,QFont::Bold));
    painter.drawRect(QuestionRect);
    painter.drawText(QuestionRect,Qt::AlignCenter | Qt::TextWordWrap, Question);


    painter.end();




}

void TestPanel::SetQuestion(const QString &_quest)
{
    Question=_quest;
    update();

}

void TestPanel::SetAnswers(const QVector<QString> &Ans)
{
    if (!varAnswers.isEmpty())
    {
        varAnswers.clear();

    }


    varAnswers=Ans;


    update();
}

void TestPanel::SetWeightAnswers(const QVector<QString> &WeightAns)
{
    weightAnswers.clear();
    foreach (QString str, WeightAns)
        weightAnswers<<str.toDouble();


}

void TestPanel::drawButtons()
{

    OK->setGeometry(ButtonsRect);

}

void TestPanel::drawAnswers()
{
    if (!AnswersBtns.isEmpty())
    {
        foreach(AnswerVariantButton* A, AnswersBtns)
        {

            A->deleteLater();
        }
        AnswersBtns.clear();

    }

    int i = 0;
    int size = varAnswers.size();

    double H = AnswersRect.height()/size;

    foreach(QString str, varAnswers)
    {
        AnswersBtns<<new AnswerVariantButton(i,str,weightAnswers[i],OK,this);

        AnswersBtns[i]->setGeometry(0,QuestionRect.height()+ H*i,width(),H);

        connect(AnswersBtns[i],SIGNAL(iPressed(int)),this,SLOT(UnClick(int)));

        AnswersBtns[i]->setHidden(false);


        i++;


    }



}

void TestPanel::resizeAnswerButtons()
{
    int i=0;

    if (!(varAnswers[0]==""))
    {

        int size = varAnswers.size();

        double H = AnswersRect.height()/size;

        foreach(QString str, varAnswers)
        {
            AnswersBtns[i]->setGeometry(0,QuestionRect.height()+ H*i,width(),H);
            i++;
        }
    }

}

void TestPanel::UnClick(int N)
{
    foreach(AnswerVariantButton* Ans, AnswersBtns)
        if ((Ans->isChoosen()) && (Ans->GetID()!=N))
            Ans->SetUnChoosen();


}

void TestPanel::resizeEvent(QResizeEvent *)
{

        updateWidgets();
        resizeAnswerButtons();

}

void TestPanel::slot_enterPressed()
{
    emit sig_enterPressed();

}

void TestPanel::slot_nextPressed()
{
    emit sig_nextPressed();
}




