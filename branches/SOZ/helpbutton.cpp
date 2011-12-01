#include "helpbutton.h"

HelpButton::HelpButton(QWidget *parent) :
    QWidget(parent)
{
    isHelpShown=false;
    helpBrw = new HelpBrowser("C:/SOZ/SOZ/doc", "index.htm");
    helpBrw->hide();
    helpBrw->resize(800, 600);

}

void HelpButton::paintEvent(QPaintEvent *)
{
    QPen pen(Qt::transparent);
    QBrush Brs(Qt::transparent);

    QPixmap pixmap(":/images/help");
    pixmap=pixmap.scaled(width(),height());

    QPainter painter(this);
    painter.setBrush(Brs);
    painter.setPen(pen);
    painter.drawRect(rect());
    painter.drawPixmap(rect(),pixmap);
    painter.end();

}

void HelpButton::mousePressEvent(QMouseEvent *)
{
    helpBrw->setHidden(!helpBrw->isHidden());
}


