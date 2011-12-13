#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QPainter>
#include <QCursor>




class MyLineEdit : public QLineEdit
{
    Q_OBJECT



public:
    explicit MyLineEdit(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);

signals:

public slots:

};

#endif // MYLINEEDIT_H
