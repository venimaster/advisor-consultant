#include "dbwork.h"

dbWork::dbWork()
{
    connectDB();
    int id=1;
//-----------------------------------------------------------------------------------
// ПЕРВЫЙ ЭТАП
//-----------------------------------------------------------------------------------

 //*****************ВЫВОД**************
    // выводит все критерии из relevance_research
    qDebug()<<GetColumnFromTable("measure","relevance_research");

    // выводит все критерии из propriety_research
    qDebug()<<GetColumnFromTable("measure","propriety_research");

    // выводит все критерии из opportunity_research
    qDebug()<<GetColumnFromTable("measure","opportunity_research");

    //выводит веса критериев из relevance_research
    qDebug()<<GetColumnFromTable("weight","relevance_research");

    //выводит веса критериев из propriety_research
    qDebug()<<GetColumnFromTable("weight","propriety_research");

    //выводит веса критериев из opportunity_research
    qDebug()<<GetColumnFromTable("weight","opportunity_research");


    //выводит варианты ответа на критерий из relevance_research с номером id
    qDebug()<<GetAnswerVariants("relevance_research",id);

    //выводит варианты ответа на критерий из propriety_research с номером id
    qDebug()<<GetAnswerVariants("propriety_research",id);

    //выводит варианты ответа на критерий из opportunity_research с номером id
    qDebug()<< GetAnswerVariants("opportunity_research",id);

//*****************ВВОД**************





//----------------------------------------------------------------------------------------------------------------
// ВТОРОЙ ЭТАП
//----------------------------------------------------------------------------------------------------------------
    //выводит все вопросы из ideal_knowledge_ingeneer
    qDebug()<<GetColumnFromTable("question","ideal_knowledge_ingeneer");

    //выводит все вопросы из ideal_expert
    qDebug()<<GetColumnFromTable("question","ideal_expert");

    //выводит веса критериев из ideal_knowledge_ingeneer
    qDebug()<<GetColumnFromTable("weight","ideal_knowledge_ingeneer");

    //выводит веса критериев из ideal_expert
    qDebug()<<GetColumnFromTable("weight","ideal_expert");

    //выводит варианты ответа на вопрос из ideal_knowledge_ingeneer с номером id
    qDebug()<<GetAnswerVariants("ideal_knowledge_ingeneer",id);

    //выводит варианты ответа на вопрос из ideal_expert с номером id
    qDebug()<<GetAnswerVariants("ideal_expert",id);


    qDebug()<<GetAttribute("user","u_id","login",1);
    qDebug()<<GetAttribute("answer_variant_list","a_v_id","answer_variant_1",1);
    qDebug()<<GetAttribute("system","id","system_name",2);

    qDebug()<<GetProjectGroup("ПК СОЗ");
//ВВОД
    // вводит в поле o_r_result значение 1, 0 - невозможно применять технологию СОЗ 1 - возможно
    SetResult("venima", "o_r_result",1);
    // вводит в поле f_f_result значение полезависимость
    SetResult("venima", "f_f_result","полезависимость");
    // вводит в таблицу s_result данному юзеру значение 1 - т.е. ему было решено посоветовать систему с id 1
    SetResult("venima", "s_result",1);

    SetRegistrationInfo("prep", "123","Рыбина Галина Валентиновна", "ПК СОЗ");
    SetRegistrationInfo("stud", "123","Кусков Иван Михайлович", "ПК СОЗ","эксперт","муж",21);
    // создает пару из 2 и 3.
    SetPair (2,3);
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


QVector<QString> dbWork::GetColumnFromTable(QString columnName, QString tableName)
{
    QVector<QString> columnContent;
    QSqlQuery query;
    query.exec("SELECT `"+columnName+"` FROM `"+tableName+"`;");

    while(query.next())
    {
        columnContent<<query.value(0).toString();
    }
    return columnContent;
}


QVector<QString> dbWork::GetAnswerVariants(QString questionTableName, int id)
{
    QVector<QString> answerVariants;
    QSqlQuery query;
    query.exec("SELECT `answer_variant_1`, `answer_variant_2`, `answer_variant_3`, `answer_variant_4`, `answer_variant_5`, `answer_variant_6`, `answer_variant_7`, `answer_variant_8`, `answer_variant_9`, `answer_variant_10`, `answer_variant_11`"
               "FROM `answer_variant_list` , `"+questionTableName+"`"
               "WHERE `"+questionTableName+"`.`id` = '"+QString::number(id)+"'"
               "AND `"+questionTableName+"`.`a_v_id` = `answer_variant_list`.`a_v_id`");
    query.next();
    for(int i=0;i<11;++i)
    {
        if (query.value(i).toString()!="")
        answerVariants<<query.value(i).toString();
    }
    return answerVariants;
}

void dbWork::SetResult(QString login, QString columnName,int result)

{
    QSqlQuery query;
    int u_id,c;
    if (columnName=="s_result")
    {
        c=0;
    }
    else
    {
        if (columnName=="k_r_result") {
            c=1;
        }
        else
        {
            c=2;
        }
    }
    switch(c)
    {
    case 0:
        query.exec("SELECT `u_id` FROM`db`.`user` WHERE `user`.`login`='"+login+"'");
        query.next();
        u_id = query.value(0).toInt();
        query.exec("INSERT INTO `db`.`s_result`(`id`, `u_id`) VALUES ('"+QString::number(result)+"','"+QString::number(u_id)+"')");
    break;
    case 1:
        query.exec("SELECT `u_id` FROM`db`.`user` WHERE `user`.`login`='"+login+"'");
        query.next();
        u_id = query.value(0).toInt();
        query.exec("INSERT INTO `db`.`k_r_result`(`id`, `u_id`) VALUES ('"+QString::number(result)+"','"+QString::number(u_id)+"')");
    break;
    case 2:
            query.exec("UPDATE `db`.`user` SET `"+columnName+"` = '"+QString::number(result)+"' WHERE `user`.`login` ='"+login+"';");
    break;
    }
}
void dbWork::SetResult(QString login, QString columnName,QString result){
    QSqlQuery query;
    query.exec("UPDATE `db`.`user` SET `"+columnName+"` = '"+result+"' WHERE `user`.`login` ='"+login+"';");
}


void dbWork::SetRegistrationInfo(QString login, QString password,QString name, QString projectName)
{
     QSqlQuery query;
     int pr_id,u_id;

     //заносим регистрационные данные в user (добавление пользователя)
     query.exec("INSERT INTO `user` (`u_id` ,`password` ,`name` ,`gender` ,`age` ,`u_g_id` ,`login` ,`competience_result` ,`r_r_result` ,`p_r_result` ,`o_r_result` ,`research_result` ,`f_f_result` ,`c_s_result` ,`r_v_result` ,`t_t_result` ,`prototyping_strategy_result`)"
                "VALUES('','"+password+"','"+name+"','','','1','"+login+"','','','','','','','','','','')");

     //заносим регистрационные данные в project (добавление проекта)
     query.exec("INSERT INTO `project` (`id` ,`project_name`)"
                "VALUES ('','"+projectName+"')");
     //получаем u_id
     query.exec("SELECT `u_id` FROM `user` WHERE `user`.`login`='"+login+"'");
     query.next();
     u_id=query.value(0).toInt();
     //получаем pr_id
     query.exec("SELECT `id` FROM `project` WHERE `project`.`project_name`='"+projectName+"'");
     query.next();
     pr_id=query.value(0).toInt();
     //вносим информацию о принадлежности пользователя проекту
     query.exec("INSERT INTO `project_group` (`u_id` ,`pr_id`)"
                "VALUES ('"+QString::number(u_id)+"','"+QString::number(pr_id)+"')");
}


void dbWork::SetRegistrationInfo(QString login, QString password,QString name, QString projectName, QString groupName, QString gender, int age)
{
    QSqlQuery query;
    int u_g_id,pr_id,u_id;

    //получаем u_g_id по названию группы
    query.exec("SELECT `id` FROM `user_group` WHERE `user_group`.`group_name`='"+groupName+"'");
    query.next();
    u_g_id=query.value(0).toInt();
    //заносим регистрационные данные в user (добавление пользователя)
    query.exec("INSERT INTO `user` (`u_id` ,`password` ,`name` ,`gender` ,`age` ,`u_g_id` ,`login` ,`competience_result` ,`r_r_result` ,`p_r_result` ,`o_r_result` ,`research_result` ,`f_f_result` ,`c_s_result` ,`r_v_result` ,`t_t_result` ,`prototyping_strategy_result`)"
               "VALUES('','"+password+"','"+name+"','"+gender+"','"+QString::number(age)+"','"+QString::number(u_g_id)+"','"+login+"','','','','','','','','','','')");

    //получаем u_id
    query.exec("SELECT `u_id` FROM `user` WHERE `user`.`login`='"+login+"'");
    query.next();
    u_id=query.value(0).toInt();
    //получаем pr_id
    query.exec("SELECT `id` FROM `project` WHERE `project`.`project_name`='"+projectName+"'");
    query.next();
    pr_id=query.value(0).toInt();
    //вносим информацию о принадлежности пользователя проекту
    query.exec("INSERT INTO `project_group` (`u_id` ,`pr_id`)"
               "VALUES ('"+QString::number(u_id)+"','"+QString::number(pr_id)+"')");

}


QVector<QString> dbWork::GetAttribute(QString tableName, QString idColumnName, QString attributeColumnName, int id)
{
    QVector<QString> attributeList;
    QSqlQuery query;
    query.exec("SELECT `"+attributeColumnName+"` FROM `"+tableName+"`WHERE `"+idColumnName+"`='"+QString::number(id)+"';");
    while(query.next())
    {
        attributeList<<query.value(0).toString();
    }
    return attributeList;
}

QVector<QString> dbWork::GetAttribute(QString tableName, QString idColumnName, QString attributeColumnName, QString id)
{
    QVector<QString> attributeList;
    QSqlQuery query;
    query.exec("SELECT `"+attributeColumnName+"` FROM `"+tableName+"`WHERE `"+idColumnName+"`='"+id+"';");
    while(query.next())
    {
        attributeList<<query.value(0).toString();
    }
    return attributeList;
}

QVector<int> dbWork::GetProjectGroup(QString projectName)
{
    QVector<int> groupList;
    QVector<QString> pr_idVector;
    QSqlQuery query;
    QString pr_id;
    // получаем идентификатор группы
    pr_idVector =  GetAttribute("project","project_name","id",projectName);

    pr_id=pr_idVector[0];
    query.exec("SELECT  `project_group`.`u_id`"
    "FROM `project_group`, `user`"
    "WHERE"
    "`project_group`.`pr_id`='"+pr_id+"' AND"
    "`user`.`u_id`=`project_group`.`u_id` AND"
    "`user`.`u_g_id`!='1';");
    while(query.next())
    {
        groupList<<query.value(0).toInt();
    }
    return groupList;
}

void dbWork::SetPair (int u_id, int pair_id)
{
    QSqlQuery query;
    query.exec("INSERT INTO `ideal_pair` (`u_id` ,`pair_id`)"
               "VALUES ('"+QString::number(u_id)+"','"+QString::number(pair_id)+"')");
}

dbWork::~dbWork()
{
    db.close();
    db.removeDatabase(db.connectionName());

}
