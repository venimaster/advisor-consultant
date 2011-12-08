#ifndef TESTERDALEEBUTTON_H
#define TESTERDALEEBUTTON_H

#include <QWidget>
#include <QPainter>

class TesterDaleeButton : public QWidget
{
    Q_OBJECT

    bool Avilable;
    QString label;

    QColor BgColor;

    int Alpha;

public:
    explicit TesterDaleeButton(QWidget *parent = 0);

    bool isAvilable();

    void setAvilable();
    void setDisAvilable();

protected:
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void resizeEvent(QResizeEvent *);
    void leaveEvent(QEvent *);


signals:

    void iPressed();


public slots:

};

#endif // TESTERDALEEBUTTON_H
