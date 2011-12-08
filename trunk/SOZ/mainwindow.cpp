#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    setMinimumSize(800,600);


    connect(this,SIGNAL(NeedRefresh()),SLOT(Refresh()));

    AddPanels();

}


void MainWindow::AddPanels()
{
    HeaderPnl = new BottomPanel(1,this);
    HeaderPnl->SetText("ÑÒÀÐÒÎÂÎÅ ÎÊÍÎ");
    HeaderPnl->SetFontSize(15);

    NamePnl = new NamePanel(this);
    HelpBtn = new HelpButton(this);

    LeftPnl = new LeftPanel(3,this);
    RegPnl = new LeftPanel(2,this);

    CentralPnl = new CentralPanel(this);

    BottomPnl = new BottomPanel(2,this);
    BottomPnl->SetText("Èñïîëíèòåëè: Êóñêîâ È.Ì., Àìèíåâ Á.Ä.          Ðóêîâîäèòåëü: Ðûáèíà Ã.Â. \nÌîñêâà  2011");
    BottomPnl->SetFontSize(10);


    DB = new dbWork();

    tester = new Tester(CentralPnl,DB);
    connect (tester,SIGNAL(RenameSubEtap(QString)),this,SLOT(RenameSubEtap(QString)));

    connect(LeftPnl,SIGNAL(ButtonPressed(int)),this,SLOT(SetEtap(int)));

    emit NeedRefresh();

}

void MainWindow::Refresh()
{
    double W=width();
    double H=height();

    HeaderPnl->setGeometry(0,0,width(),30);
    NamePnl->setGeometry(W/3,30,W-W/3,50);

    LeftPnl->setGeometry(0,30,W/3,H-30);
    RegPnl->setGeometry(0,30,W/3,H-30);
    RegPnl->setVisible(false);

    CentralPnl->setGeometry(W/3,48+30,W-W/3,H-48-30);
    HelpBtn->setGeometry(W-48,H-48-30,48,48);
    BottomPnl->setGeometry(0,H-30,width(),30);

}


void MainWindow::SetEtap(int _num)
{
    EtapNum=_num;
    QString EtapName;
    QString Label;

    switch (EtapNum)
    {
        case 0:
            EtapName="ÊÐÀÒÊÀß ÈÍÔÎÐÌÀÖÈß Î ÑÈÑÒÅÌÅ";
            Label="";
        break;
        case 1:
            EtapName="ÐÅÃÈÑÒÐÀÖÈß È ÂÕÎÄ Â ÑÈÑÒÅÌÓ";
            Label="";
        break;
        case 2:
            EtapName="ÏÑÈÕÎËÎÃÈ×ÅÑÊÎÅ ÒÅÑÒÈÐÎÂÀÍÈÅ";
            Label="";
        break;
        case 3:
            EtapName="ÀÍÀËÈÇ ÍÀ ÏÐÈÌÅÍÈÌÎÑÒÜ/ÍÅÏÐÈÌÅÍÈÌÎÑÒÜ ÒÅÕÍÎËÎÃÈÈ ÑÎÇ";
            Label="Ïðîâåäåíèå ñèñòåìíîãî àíàëèçà ïðîáëåìíîé îáëàñòè íà ïðåäìåò ïðèìåíèìîñòè/íåïðèìåíèìîñòè òåõíîëîãèè ÑÎÇ äëÿ çàäà÷è çàêàç÷èêà (ýòàï èäåíòèôèêàöèè)";
            tester->Test_I_I();


        break;
        case 4:
            EtapName="ÂÛÁÎÐ ÓÑÏÅØÍÎÉ ÊÎÍÒÀÊÒÍÎÉ ÏÀÐÛ";
            Label="Âûáîð èäåàëüíîé ïàðû \"ýêñïåðò-èíæåíåð ïî çíàíèÿì\" èç íåñêîëüêèõ êàíäèäàòîâ ñ öåëüþ ýôôåêòèâíîé ðåàëèçàöèè ïðîöåññà ïîëó÷åíèÿ çíàíèé î ïðîáëåìíîé îáëàñòè";

        break;
        case 5:
            EtapName="ÂÛÁÎÐ ÌÎÄÅËÅÉ ÏÐÅÄÑÒÀÂËÅÍÈß ÇÍÀÍÈÉ";
            Label="Âûáîð ñïîñîáîâ(ìîäåëåé) ïðåäñòàâëåíèÿ çíàíèé";

        break;
        case 6:
            EtapName="ÂÛÁÎÐ ÈÍÑÒÐÓÌÅÍÒÀËÜÍÛÕ ÑÐÅÄÑÒÂ";
            Label="Âûáîð èíñòðóìåíòàëüíûõ ñðåäñòâ äëÿ áóäóùåé ÑÎÇ(ÝÑ) (ýòàï ôîðìàëèçàöèè)";
        break;
        case 7:
            EtapName="ÂÛÁÎÐ ÑÒÐÀÒÅÃÈÈ ÏÐÎÒÎÒÈÏÈÐÎÂÀÍÈß";
            Label="Âûáîð ñòðàòåãèé ïðîòîòèïèðîâàíèÿ (ýòàïû ïðîåêòèðîâàíèÿ è ðåàëèçàöèè)";
        break;

    }

    HeaderPnl->SetText(EtapName);
    LeftPnl->setLabel(Label);



}

void MainWindow::RenameSubEtap(QString str)
{
    NamePnl->SetName(str);

}

void MainWindow::resizeEvent(QResizeEvent *)
{

    emit NeedRefresh();

}

void MainWindow::mousePressEvent(QMouseEvent *)
{


}


MainWindow::~MainWindow()
{

}
