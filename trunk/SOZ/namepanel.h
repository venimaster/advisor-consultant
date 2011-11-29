#ifndef NAMEPANEL_H
#define NAMEPANEL_H

#include <QWidget>
#include <QPainter>

class NamePanel : public QWidget
{
    Q_OBJECT

    QString Name;



public:
    explicit NamePanel(QWidget *parent = 0);
    void SetName(QString Name);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:

public slots:

};

#endif // NAMEPANEL_H
