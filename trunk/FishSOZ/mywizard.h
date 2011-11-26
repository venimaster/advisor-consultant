#ifndef MYWIZARD_H
#define MYWIZARD_H

#include <QWidget>

class MyWizard : public QWidget
{
    Q_OBJECT

    void ChangeWGT();

public:
    explicit MyWizard(QWidget *parent = 0);

signals:

public slots:

};

#endif // MYWIZARD_H
