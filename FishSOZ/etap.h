#ifndef ETAP_H
#define ETAP_H

#include <QWidget>
#include <QPainter>

class Etap : public QWidget
{
    Q_OBJECT

private:

    QString EtapName;
    QString EtapLabel;

    QBrush Brs;

    int EtapNum;

    bool isActive;


public:
    explicit Etap(QString _Name, QString _Label, int _Num, QWidget *parent = 0);
    ~Etap();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);

signals:
    void IClicked(int _Num);

public slots:

};

#endif // ETAP_H
