#include "wizard.h"

Wizard::Wizard(QWidget *parent) :
    QWizard(parent)
{

}

QWizardPage* Wizard::createPage(QWidget *pwgt, QString strTitle)
{
    QWizardPage* ppage = new QWizardPage;
    ppage->setTitle(strTitle);

    QVBoxLayout* VLayout = new QVBoxLayout();
    VLayout->addWidget(pwgt);
    ppage->setLayout(VLayout);

    return ppage;

}
