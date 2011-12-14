#ifndef BOTTOMPANEL_H
#define BOTTOMPANEL_H

//#include <QWidget>
//#include <QPainter>
#include "stable.h"

class BottomPanel : public QWidget
{
    Q_OBJECT
    QString Text;
    int FontSize;
    int type;


public:
    explicit BottomPanel(int _type, QWidget *parent = 0);
    void SetText(QString text);
    void SetFontSize(int _size);

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:

};

#endif // BOTTOMPANEL_H
