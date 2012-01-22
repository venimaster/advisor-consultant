#ifndef HIPANEL_H
#define HIPANEL_H

#include <QWidget>
#include "stable.h"

class HiPanel : public QWidget
{
    Q_OBJECT


    QString HiStr;

public:
    explicit HiPanel(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    
signals:
    
public slots:
    
};

#endif // HIPANEL_H
