#ifndef LITERATURE_H
#define LITERATURE_H

#include <QWidget>

class Literature : public QWidget
{
    Q_OBJECT
public:
    explicit Literature(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    
signals:
    void iPressed();

    
public slots:
    
};

#endif // LITERATURE_H
