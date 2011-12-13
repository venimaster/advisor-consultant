#include "centralpanel.h"

CentralPanel::CentralPanel(QWidget *parent) :
    QWidget(parent)
{

    Question="";
    OK = new TesterDaleeButton(this);

    double W = width();
    double H = height();

    QuestionRect = QRect(0,0,W,H/6);
    AnswersRect = QRect(0,H/6,W,H-2*H/6);
    ButtonsRect = QRect(0,H-H/6,W,H/6);


    BrainSourceImg = QImage(":/backgrounds/brain");
    BrainImg = BrainSourceImg.scaled(width(),height());

    varAnswers<<"";

    updateWidgets();



}

void CentralPanel::updateWidgets()
{

    double W = width();
    double H = height();

    QuestionRect.setRect(0,0,W,H/6);
    AnswersRect.setRect(0,H/6,W,H-2*H/6);
    ButtonsRect.setRect(0,H-H/6,W,H/6);

    BrainImg = BrainSourceImg.scaled(width(),height());
    updateBrain();

    drawButtons();







    update();

}

void CentralPanel::updateBrain()
{
    BrainPixmap = QPixmap(BrainImg.size());
    BrainPixmap.fill(Qt::transparent);



    QPainter p;
    p.begin(&BrainPixmap);
    p.setCompositionMode(QPainter::CompositionMode_Source);
    p.drawPixmap(0, 0, QPixmap::fromImage(BrainImg));
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);

    // Set transparency level to 150 (possible values are 0-255)
    // The alpha channel of a color specifies the transparency effect,
    // 0 represents a fully transparent color, while 255 represents
    // a fully opaque color.
    p.fillRect(BrainPixmap.rect(), QColor(0, 0, 0, 30));
    p.end();

}



void CentralPanel::paintEvent(QPaintEvent *)
{
    QColor MyColor(QColor::fromRgb(45,75,129));
    MyColor.setAlpha(180);

    QPen pen(Qt::black);
    QBrush Brs(Qt::black);

    QPainter painter(this);

    painter.setBrush(Brs);
    painter.setPen(pen);
    painter.drawRect(rect());
    painter.drawPixmap(rect(),BrainPixmap);





    painter.setBrush(QBrush(MyColor));


    painter.setPen(QPen(Qt::white));
    painter.setFont(QFont("Sherif",11,QFont::Bold));
    painter.drawRect(QuestionRect);
    painter.drawText(QuestionRect,Qt::AlignCenter | Qt::TextWordWrap, Question);


    painter.end();




}

void CentralPanel::SetQuestion(const QString &_quest)
{
    Question=_quest;
    update();

}

void CentralPanel::SetAnswers(const QVector<QString> &Ans)
{
    if (!varAnswers.isEmpty())
    {
        varAnswers.clear();

    }


    varAnswers=Ans;


    update();
}

void CentralPanel::SetWeightAnswers(const QVector<QString> &WeightAns)
{
    weightAnswers.clear();
    foreach (QString str, WeightAns)
        weightAnswers<<str.toDouble();


}

void CentralPanel::drawButtons()
{

    OK->setGeometry(ButtonsRect);

}

void CentralPanel::drawAnswers()
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

void CentralPanel::resizeAnswerButtons()
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

void CentralPanel::UnClick(int N)
{
    foreach(AnswerVariantButton* Ans, AnswersBtns)
        if ((Ans->isChoosen()) && (Ans->GetID()!=N))
            Ans->SetUnChoosen();


}

void CentralPanel::resizeEvent(QResizeEvent *)
{

        updateWidgets();
        resizeAnswerButtons();

}



