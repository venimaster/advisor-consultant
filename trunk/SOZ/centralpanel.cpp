#include "centralpanel.h"

CentralPanel::CentralPanel(dbWork* _db, QWidget *parent) :
    QWidget(parent)
{

    DB = _db;

    WgtNum=0;
    PrevWgtNum=0;

    TP = new TestPanel(this);
    connect(this,SIGNAL(sig_enterPressed()),TP,SLOT(slot_enterPressed()));
    connect(TP,SIGNAL(sig_nextPressed()),this,SLOT(slot_askNextQuestion()));


    HP = new HelpPanel(0);
    LP = new HelpPanel(1);
    LP->hide();

    HiP = new HiPanel(this);

    PsTest = new PsyhTest(DB,3,"venima",this);
    connect(PsTest,SIGNAL(changeCentralName(QString)),this,SIGNAL(changeCentralName(QString)));
    connect(PsTest,SIGNAL(changeLeftPanLabel(QString)),this,SIGNAL(changeLeftPanLabel(QString)));
    connect(PsTest,SIGNAL(changeMainName(QString)),this,SIGNAL(changeMainName(QString)));
    connect(PsTest,SIGNAL(heightChanged(int)),this,SLOT(changeScroll(int)));
    PsTest->hide();
    HiP->show();

    PsScr = new QScrollBar(Qt::Vertical,this);
    connect(PsScr,SIGNAL(valueChanged(int)),this,SLOT(scrollMove(int)));



    changeWgt(3);


    BrainSourceImg = QImage(":/backgrounds/brain");
    BrainImg = BrainSourceImg.scaled(width(),height());


    updateWidgets();
}

void CentralPanel::updateWidgets()
{
    TP->resize(width(),height());
    HP->resize(width(),height());
    HiP->resize(width(),height());
    PsTest->resize(width()-18,height());
    PsScr->setGeometry(QRect(width()-18,0,18,height()));

    PsScr->setSingleStep(50);
    PsScr->setMinimum(height());
    PsScr->setValue(PsScr->minimum());


    BrainImg = BrainSourceImg.scaled(width(),height());
    updateBrain();

}

void CentralPanel::changeWgt(const int _num)
{
    switch (_num)
    {
        case 0: TP->hide(); HP->hide(); HiP->show(); PsTest->hide(); PrevWgtNum=WgtNum; WgtNum=0; PsScr->hide(); break;
        case 1: TP->show(); HP->hide(); HiP->hide(); PsTest->hide(); PrevWgtNum=WgtNum; WgtNum=1; PsScr->hide(); break;
        case 2: HP->show();  break;
        case 3: TP->hide(); HP->hide(); HiP->hide(); PsTest->show(); PrevWgtNum=WgtNum; WgtNum=3; PsTest->renameNames(); PsScr->show(); break;
    }
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

    QPainter painter(this);
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(rect());
    painter.drawPixmap(rect(),BrainPixmap);

    painter.end();

}




void CentralPanel::resizeEvent(QResizeEvent *)
{

        updateWidgets();
        update();
}

void CentralPanel::slot_enterPressed()
{
    emit sig_enterPressed();

}

void CentralPanel::slot_askNextQuestion()
{
    emit sig_askNextQuestion();
}

TestPanel* CentralPanel::getTestPanel()
{
    return TP;
}

void CentralPanel::needHelp()
{
    HP->show();
    LP->show();
}

void CentralPanel::dontNeedHelp()
{
    changeWgt(1);
}

void CentralPanel::scrollMove(int pos)
{


    PsTest->moveUp(-pos+PsScr->minimum());


}

void CentralPanel::changeScroll(int _h)
{
    PsScr->setMaximum(_h);
    PsScr->setValue(PsScr->minimum());
    PsScr->update();

    qDebug()<<PsScr->minimum()<<PsScr->maximum();


}





