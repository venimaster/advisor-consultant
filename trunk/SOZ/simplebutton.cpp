#include "simplebutton.h"

SimpleButton::SimpleButton(int _num, QString _Name, QWidget *parent) :
    EtapButton(_num, _Name, parent)
{
    Name=_Name;

}
