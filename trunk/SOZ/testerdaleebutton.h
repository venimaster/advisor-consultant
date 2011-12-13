#ifndef TESTERDALEEBUTTON_H
#define TESTERDALEEBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QLinearGradient>
#include <QKeyEvent>
#include <QDebug>

#include "gradients.h"
#include "obrabotchik.h"


class TesterDaleeButton : public QWidget
{
    Q_OBJECT

    bool Avilable;
    bool MouseOn;

    QString label;

    QColor BgColor;

    int FontSize;

    int Alpha;

    double weight;

    Gradients* Grad;
    Obrabotchik* Obrab;


public:
    explicit TesterDaleeButton(QWidget *parent = 0);


    bool isAvilable();

    void setAvilable();
    void setDisAvilable();
    void setName(const QString &label);
    void setFontSize(int _fontsize);


    void changeWeight(double &_weight);

protected:
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void resizeEvent(QResizeEvent *);
    void leaveEvent(QEvent *);


signals:

    void iPressed();


public slots:
    void enterPressed();

};

#endif // TESTERDALEEBUTTON_H
