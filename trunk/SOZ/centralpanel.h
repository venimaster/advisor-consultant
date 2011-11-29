#ifndef CENTRALPANEL_H
#define CENTRALPANEL_H

#include <QWidget>
#include <QPainter>


class CentralPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CentralPanel(QWidget *parent = 0);


protected:
    void paintEvent(QPaintEvent *);



signals:

public slots:

};

#endif // CENTRALPANEL_H
