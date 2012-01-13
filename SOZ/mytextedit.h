#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include "stable.h"

class MyTextEdit : public QTextEdit
{
    Q_OBJECT


    void changePalette();



public:
    explicit MyTextEdit(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *e);
    
signals:
    
public slots:
    
};

#endif // MYTEXTEDIT_H
