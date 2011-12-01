#ifndef SIMPLEBUTTON_H
#define SIMPLEBUTTON_H

#include "etapbutton.h"

class SimpleButton : public EtapButton
{
    Q_OBJECT
public:
    explicit SimpleButton(int _num = -1, QString Name = "", QWidget *parent = 0);

signals:

public slots:

};

#endif // SIMPLEBUTTON_H
