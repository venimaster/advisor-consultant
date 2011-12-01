#include "glossary.h"


Glossary::Glossary(QWidget *parent) :
    QLabel(parent)
{
    this->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    this->setText("<H1>Глоссарий</H1>");
    this->setWindowTitle("Глоссарий");
    this->setFixedSize(600,800);
    dbWork* dbw = new dbWork();

    QString glossaryElement,id, termin, abbreviation, definition;
    QVector<QString> glossaryContent,idColumn, terminColumn, abbreviationColumn, definitionColumn;

    idColumn << dbw->GetColumnFromTable("id","glossary");
    terminColumn << dbw->GetColumnFromTable("termin","glossary");
    abbreviationColumn << dbw->GetColumnFromTable("abbreviation","glossary");
    definitionColumn << dbw->GetColumnFromTable("definition","glossary");


    id = idColumn.front();
    termin = terminColumn .front();
    abbreviation = abbreviationColumn.front();
    definition = definitionColumn.front();
    glossaryElement = "<p>"+termin+" - "+definition+"</p>";

    this->setText(glossaryElement);





}
