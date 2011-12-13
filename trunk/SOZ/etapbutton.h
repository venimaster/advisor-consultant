#ifndef ETAPBUTTON_H
#define ETAPBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

class EtapButton : public QWidget
{
    Q_OBJECT
public:
    explicit EtapButton(int _num, QString Name = "", QWidget *parent = 0);

    QString Name;
    QString Lbl;

    int number;

    int status; //0,если ничего, 1, если наведена мышь, 2-если нажата

    bool avilable;
    bool isPressed;

    void SetLabel(QString label);
    void SetName(QString name);

protected:
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);


signals:
    void iPressed(int num);

public slots:

};

#endif // ETAPBUTTON_H
