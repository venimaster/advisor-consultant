#include "obrabotchik.h"

Obrabotchik::Obrabotchik(QObject *parent) :
    QObject(parent)
{

}

void Obrabotchik::addAnswer(double &_weight)
{
    Answers<<_weight;

    qDebug()<<Answers;



}
