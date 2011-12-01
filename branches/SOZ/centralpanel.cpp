#include "centralpanel.h"

CentralPanel::CentralPanel(QWidget *parent) :
    QWidget(parent)
{
    update();
    Question="";

    OK = new QPushButton("Далее",this);

    updateWidgets();




}

void CentralPanel::updateWidgets()
{

    double W = width();
    double H = height();

    QuestionRect = QRect(0,0,W,H/6);
    AnswersRect = QRect(0,H/6,W,H-H/6);
    ButtonsRect = QRect(0,H-H/6,W,H/6);

    drawButtons();

    update();

}


void CentralPanel::paintEvent(QPaintEvent *)
{
    QPen pen(Qt::black);
    QBrush Brs(Qt::gray);
    //QImage img(":/images/brain");
    //img = img.scaled(width(),height());//Далее идет преобразование под прозрачность

    //QPixmap pixmap(img.size());

    // Do transparency
    //pixmap.fill(Qt::transparent);


//    QPainter p;
//    //p.begin(&pixmap);
//    p.setCompositionMode(QPainter::CompositionMode_Source);
//    //p.drawPixmap(0, 0, QPixmap::fromImage(img));
//    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);

//    // Set transparency level to 150 (possible values are 0-255)
//    // The alpha channel of a color specifies the transparency effect,
//    // 0 represents a fully transparent color, while 255 represents
//    // a fully opaque color.
//   // p.fillRect(pixmap.rect(), QColor(0, 0, 0, 100));
//    p.end();

    QPainter painter(this);
    painter.setBrush(Brs);
    painter.setPen(pen);
    painter.drawRect(rect());
    //painter.drawPixmap(rect(),pixmap);


//Рисуем вопрос

    painter.setFont(QFont("Times",13));

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
        varAnswers.clear();
    varAnswers=Ans;

    qDebug()<<"BBBB"<<Ans;

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
        AnswersBtns.clear();
    }

    int i = 0;
    int size = varAnswers.size();

    double H = AnswersRect.height()/size;

    foreach(QString str, varAnswers)
    {
        AnswersBtns<<new AnswerVariantButton(i,str,weightAnswers[i]);

        AnswersBtns[i]->setGeometry(0,H*i,width(),H);

        connect(AnswersBtns[i],SIGNAL(iPressed(int)),this,SLOT(UnClick(int)));

        i++;

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

}


