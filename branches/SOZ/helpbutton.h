#ifndef HELPBUTTON_H
#define HELPBUTTON_H

#include <QWidget>
#include <QPainter>

#include "HelpBrowser.h"

class HelpButton : public QWidget
{
    Q_OBJECT

    HelpBrowser*  helpBrw;
    bool isHelpShown;

public:
    explicit HelpButton(QWidget *parent = 0);


protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

signals:

public slots:

};

#endif // HELPBUTTON_H
