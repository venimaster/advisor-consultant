#ifndef RADIOPUSHBUTTON_H
#define RADIOPUSHBUTTON_H

#include "stable.h"

class RadioPushButton : public QWidget
{
    Q_OBJECT

    bool checked;
    bool mouseOn;

    int ID;

    QString label;

public:
    explicit RadioPushButton(int _ID, const QString &_label, QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void resizeEvent(QResizeEvent *);


signals:
    void iClicked(int);

public slots:

};

#endif // RADIOPUSHBUTTON_H
