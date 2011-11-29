#include "dbwork.h"

dbWork::dbWork()
{
    connectDB();
    qDebug()<<GetAnswerVariants("relevance_research",1);

}

bool dbWork::connectDB(QString _dbType, QString _dbName, QString _host, QString _dbUser, QString _dbPass)
{
    db = QSqlDatabase::addDatabase(_dbType);
    db.setDatabaseName(_dbName);
    db.setHostName(_host);

    db.setUserName(_dbUser);
    db.setPassword(_dbPass);

    if (!db.open())
    {
        return false;
    }
    else return true;

}

QString dbWork::getGlossary(int g_id)
{
    QSqlQuery query;

    query.exec("SELECT `g_id`, `termin`, `abbreviation`, `definition` FROM `glossary`;");
    query.seek(g_id);
        QString str = query.value(1).toString();
        qDebug()<<str;
    //}
    return str;
}

//----------------------------------------------------------------------------------------------------------------
// ÏÅÐÂÛÉ ÝÒÀÏ
//----------------------------------------------------------------------------------------------------------------

QVector<QString> dbWork::GetQuestion_I()
{
    QVector<QString> Questions;
    QSqlQuery query;
    query.exec("SELECT `question` FROM `relevance_research`;");

    while(query.next())
    {
        Questions<<query.value(0).toString();
    }

    return Questions;

}

QVector<QString> dbWork::GetAnswerVariants(QString questionTableName, int question_id)
{
    QVector<QString> answerVariants;
    QSqlQuery query;
    query.exec("SELECT `answer_variant_1`, `answer_variant_2`, `answer_variant_3`, `answer_variant_4`, `answer_variant_5`, `answer_variant_6`, `answer_variant_7`, `answer_variant_8`, `answer_variant_9`, `answer_variant_10`, `answer_variant_11`"
               "FROM `answer_variant_list` , `"+questionTableName+"`"
               "WHERE `"+questionTableName+"`.`r_r_id` = '"+QString::number(question_id)+"'"
               "AND `"+questionTableName+"`.`a_v_id` = `answer_variant_list`.`a_v_id`");

    int i=0;

    query.next();

    while(i<11)
    {
        //qDebug()<<query.value(i).toString();
        if (query.value(i).toString()!="")
        answerVariants<<query.value(i).toString();
        i++;
    }

    return answerVariants;

}

//----------------------------------------------------------------------------------------------------------------
// ÂÒÎÐÎÉ ÝÒÀÏ
//----------------------------------------------------------------------------------------------------------------


dbWork::~dbWork()
{
    db.close();
    db.removeDatabase(db.connectionName());

}
