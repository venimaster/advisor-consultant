#include "gradients.h"

Gradients::Gradients()
{

}

void Gradients::setAnsGrad(double x1, double y1, double x2, double y2)
{
    AnsButtonGrad = QLinearGradient(x1,y1,x2,y2);
}

void Gradients::setDaleeGrad(double x1, double y1, double x2, double y2)
{
    DaleeButtonGrad = QLinearGradient(x1,y1,x2,y2);

    QColor color1(QColor::fromRgb(45,75,129));
    color1.setAlpha(170);
    QColor color2(Qt::white);


    DaleeButtonGrad.setColorAt(0,color2);
    DaleeButtonGrad.setColorAt(0.1,color1);
    DaleeButtonGrad.setColorAt(0.9,color1);
    DaleeButtonGrad.setColorAt(1,color2);

}

void Gradients::setDaleeGradMouseOn(double x1, double y1, double x2, double y2)
{
    DaleeButtonGrad = QLinearGradient(x1,y1,x2,y2);

    QColor color1(QColor::fromRgb(45,75,129));
    color1.setAlpha(200);
    QColor color2(Qt::white);


    DaleeButtonGrad.setColorAt(0,color2);
    DaleeButtonGrad.setColorAt(0.3,color1);
    DaleeButtonGrad.setColorAt(0.7,color1);
    DaleeButtonGrad.setColorAt(1,color2);

    DaleeButtonGrad.setSpread(QGradient::RepeatSpread);
}

void Gradients::setDaleeGradDisabled(double x1, double y1, double x2, double y2)
{
    DaleeButtonGrad = QLinearGradient(x1,y1,x2,y2);

    QColor color1(Qt::white);
    color1.setAlpha(50);
    QColor color2(Qt::white);
    color2.setAlpha(80);


    DaleeButtonGrad.setColorAt(0,color2);
    DaleeButtonGrad.setColorAt(0.3,color1);
    DaleeButtonGrad.setColorAt(0.7,color1);
    DaleeButtonGrad.setColorAt(1,color2);

    DaleeButtonGrad.setSpread(QGradient::RepeatSpread);
}

void Gradients::setEtapGrad(double x1, double y1, double x2, double y2)
{
    EtapButtonGrad = QLinearGradient(x1,y1,x2,y2);
}

void Gradients::setNameGrad(double x1, double y1, double x2, double y2)
{
    NameGrad = QLinearGradient(x1,y1,x2,y2);

}

QLinearGradient Gradients::getAnsGrad(double x1, double y1, double x2, double y2)
{
    setAnsGrad(x1,y1,x2,y2);
    return AnsButtonGrad;
}

QLinearGradient Gradients::getDaleeGrad(double x1, double y1, double x2, double y2, int par)
{
    if (par==0)
        setDaleeGrad(x1,y1,x2,y2);
    if (par==1)
        setDaleeGradMouseOn(x1,y1,x2,y2);
    if (par==2)
        setDaleeGradDisabled(x1,y1,x2,y2);

    return DaleeButtonGrad;
}

QLinearGradient Gradients::getEtapGrad(double x1, double y1, double x2, double y2)
{
    setEtapGrad(x1,y1,x2,y2);
    return EtapButtonGrad;
}

QLinearGradient Gradients::getNameGrad(double x1, double y1, double x2, double y2)
{
    setNameGrad(x1,y1,x2,y2);
    return NameGrad;
}

