#ifndef RIGHTPANEL_H
#define RIGHTPANEL_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

class RightPanel : public QWidget
{
    Q_OBJECT
public:
    explicit RightPanel(QWidget *parent = 0);
    void setLabel(QString _lbl);

    QString Label;

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:

};

#endif // RIGHTPANEL_H
