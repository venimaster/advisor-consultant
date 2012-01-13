#include "centralpanel.h"

CentralPanel::CentralPanel(QWidget *parent) :
    QWidget(parent)
{

    TP = new TestPanel(this);
    connect(this,SIGNAL(sig_enterPressed()),TP,SLOT(slot_enterPressed()));
    connect(TP,SIGNAL(sig_nextPressed()),this,SLOT(slot_askNextQuestion()));


    HP = new HelpPanel(this);

    changeWgt(1);


    BrainSourceImg = QImage(":/backgrounds/brain");
    BrainImg = BrainSourceImg.scaled(width(),height());


    updateWidgets();
}

void CentralPanel::updateWidgets()
{
    TP->resize(width(),height());
    HP->resize(width(),height());

    BrainImg = BrainSourceImg.scaled(width(),height());
    updateBrain();

}

void CentralPanel::changeWgt(const int _num)
{
    switch (_num)
    {
        case 1: TP->show(); HP->hide(); break;
        case 2: TP->hide(); HP->show(); break;
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
    changeWgt(2);
}

void CentralPanel::dontNeedHelp()
{
    changeWgt(1);
}





