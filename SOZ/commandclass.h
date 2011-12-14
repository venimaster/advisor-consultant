#ifndef COMMANDCLASS_H
#define COMMANDCLASS_H

//#include <QObject>
#include "stable.h"
#include "simplebutton.h"

class CommandClass : public QObject
{
    Q_OBJECT

    void DrawButton(QRectF Rect, SimpleButton* Btn);


public:
    explicit CommandClass(QObject *parent = 0);

signals:

public slots:

};

#endif // COMMANDCLASS_H
