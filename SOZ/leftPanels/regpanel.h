#ifndef REGPANEL_H
#define REGPANEL_H

#include "../stable.h"

#include "../mylineedit.h"
#include "../testerdaleebutton.h"
#include "../radiopushbutton.h"

class RegPanel : public QWidget
{
    Q_OBJECT

//    MyLineEdit* Login;
//    MyLineEdit* Passwd;
//    MyLineEdit* ConfPasswd;

//    TesterDaleeButton* Confirm;
//    TesterDaleeButton* Reg;

    RadioPushButton* Zak;
    RadioPushButton* Inz;
    RadioPushButton* Eksp;

    QRect NameRect;
    QRect ButtonsRect;


    void resizeWidgets();



public:
    explicit RegPanel(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);

signals:

public slots:
    void UnClick(int);

};

#endif // REGPANEL_H
