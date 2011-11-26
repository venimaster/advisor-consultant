#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>
#include <QLayout>

class Wizard : public QWizard
{
    Q_OBJECT

private:



public:
    explicit Wizard(QWidget *parent = 0);
    QWizardPage* createPage(QWidget* pwgt, QString strTitle);

signals:

public slots:

};

#endif // WIZARD_H
