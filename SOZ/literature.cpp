#include "literature.h"

Literature::Literature(QWidget *parent) :
    QWidget(parent)
{

}

void Literature::paintEvent(QPaintEvent *)
{
    QPen pen(Qt::black);
    QBrush Brs(Qt::black);

    QPixmap pixmap(":/icons/book");
    pixmap=pixmap.scaled(width(),height());

    QPainter painter(this);
    painter.setBrush(Brs);
    painter.setPen(pen);
    painter.drawRect(rect());
    painter.drawPixmap(rect(),pixmap);
    painter.end();

}

void Literature::mousePressEvent(QMouseEvent *)
{
    emit(iPressed());

}
