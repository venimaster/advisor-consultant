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
    HeaderPnl->SetText("��������� ����");
    HeaderPnl->SetFontSize(15);

    NamePnl = new NamePanel(this);
    HelpBtn = new HelpButton(this);

    LeftPnl = new LeftPanel(3,this);
    RegPnl = new LeftPanel(2,this);

    CentralPnl = new CentralPanel(this);

    BottomPnl = new BottomPanel(2,this);
    BottomPnl->SetText("�����������: ������ �.�., ������ �.�.          ������������: ������ �.�. \n������  2011");
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
            EtapName="������� ���������� � �������";
            Label="";
        break;
        case 1:
            EtapName="����������� � ���� � �������";
            Label="";
        break;
        case 2:
            EtapName="��������������� ������������";
            Label="";
        break;
        case 3:
            EtapName="������ �� ������������/�������������� ���������� ���";
            Label="���������� ���������� ������� ���������� ������� �� ������� ������������/�������������� ���������� ��� ��� ������ ��������� (���� �������������)";
            tester->Test_I_I();


        break;
        case 4:
            EtapName="����� �������� ���������� ����";
            Label="����� ��������� ���� \"�������-������� �� �������\" �� ���������� ���������� � ����� ����������� ���������� �������� ��������� ������ � ���������� �������";

        break;
        case 5:
            EtapName="����� ������� ������������� ������";
            Label="����� ��������(�������) ������������� ������";

        break;
        case 6:
            EtapName="����� ���������������� �������";
            Label="����� ���������������� ������� ��� ������� ���(��) (���� ������������)";
        break;
        case 7:
            EtapName="����� ��������� ����������������";
            Label="����� ��������� ���������������� (����� �������������� � ����������)";
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
