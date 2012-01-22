#ifndef PSYHTESTVARIANTBUTTON_H
#define PSYHTESTVARIANTBUTTON_H

#include <QWidget>

class PsyhTestVariantButton : public QWidget
{
    Q_OBJECT

    int weight;
    QString label;

    int ID;

    int GroupID;

    bool Choosen;
    bool MouseOn;

public:
    explicit PsyhTestVariantButton(int ID, int GroupID, QString lbl,int weight, QWidget *parent = 0);
    
    void setLabel (QString &lbl);
    void setWeight (double &_weight);
    int GetID();
    int GetGroupID();
    void SetUnChoosen();
    void SetChoosen();
    bool isChoosen();

protected:

    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

signals:

    void iPressed(int,int);
    
public slots:
    
};

#endif // PSYHTESTVARIANTBUTTON_H
