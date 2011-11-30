#include "centralpanel.h"

CentralPanel::CentralPanel(QWidget *parent) :
    QWidget(parent)
{
    update();

}

void CentralPanel::paintEvent(QPaintEvent *)
{
    QPen pen(Qt::black);
    QBrush Brs(Qt::black);
    QImage img(":/backgrounds/brain");
    img = img.scaled(width(),height());//ƒалее идет преобразование под прозрачность

    QPixmap pixmap(img.size());

    // Do transparency
    pixmap.fill(Qt::transparent);


    QPainter p;
    p.begin(&pixmap);
    p.setCompositionMode(QPainter::CompositionMode_Source);
    p.drawPixmap(0, 0, QPixmap::fromImage(img));
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);

    // Set transparency level to 150 (possible values are 0-255)
    // The alpha channel of a color specifies the transparency effect,
    // 0 represents a fully transparent color, while 255 represents
    // a fully opaque color.
    p.fillRect(pixmap.rect(), QColor(0, 0, 0, 100));
    p.end();

    QPainter painter(this);
    painter.setBrush(Brs);
    painter.setPen(pen);
    painter.drawRect(rect());
    painter.drawPixmap(rect(),pixmap);

    painter.end();




}
