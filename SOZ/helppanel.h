#ifndef HELPPANEL_H
#define HELPPANEL_H

#include "stable.h"
#include "dbwork.h"
#include "mytextedit.h"

class HelpPanel : public QWidget
{
    Q_OBJECT

    dbWork* DB;

    int ID;

    QString HelpHTML;

    QWebView* TextEdit;


    void updateWidgets();

    QString Glossary();
    QString Literature();

public:
    explicit HelpPanel(int _ID, QWidget *parent=0);
    
protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:

    
public slots:
    
};

#endif // HELPPANEL_H
