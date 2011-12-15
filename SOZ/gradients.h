#ifndef GRADIENTS_H
#define GRADIENTS_H

#include <QLinearGradient>

class Gradients
{
    QLinearGradient AnsButtonGrad;
    QLinearGradient NameGrad;
    QLinearGradient DaleeButtonGrad;
    QLinearGradient EtapButtonGrad;

public:
    Gradients();

    void setAnsGrad(double x1, double y1, double x2, double y2);

    void setNameGrad(double x1, double y1, double x2, double y2);

    void setDaleeGrad(double x1, double y1, double x2, double y2);
    void setDaleeGradMouseOn(double x1, double y1, double x2, double y2);
    void setDaleeGradDisabled(double x1, double y1, double x2, double y2);

    void setEtapGrad(double x1, double y1, double x2, double y2);


    QLinearGradient getAnsGrad(double x1, double y1, double x2, double y2);
    QLinearGradient getNameGrad(double x1, double y1, double x2, double y2);
    QLinearGradient getDaleeGrad(double x1, double y1, double x2, double y2, int par=0);
    QLinearGradient getEtapGrad(double x1, double y1, double x2, double y2);

};

#endif // GRADIENTS_H
