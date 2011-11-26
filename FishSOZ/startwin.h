#ifndef STARTWIN_H
#define STARTWIN_H

#include <QWidget>
#include <QPainter>

class StartWin : public QWidget
{
    Q_OBJECT
public:
    explicit StartWin(QWidget *parent = 0);
    ~StartWin();

private:
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);


signals:
    void MousePressed();

public slots:

};

#endif // STARTWIN_H
