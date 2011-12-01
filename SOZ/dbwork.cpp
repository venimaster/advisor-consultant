#include "dbwork.h"

dbWork::dbWork()
{
    connectDB();
    int id=1;
//-----------------------------------------------------------------------------------
// ������ ����
//-----------------------------------------------------------------------------------

 //*****************�����**************
    // ������� ��� �������� �� relevance_research
    qDebug()<<GetColumnFromTable("measure","relevance_research");

    // ������� ��� �������� �� propriety_research
    qDebug()<<GetColumnFromTable("measure","propriety_research");

    // ������� ��� �������� �� opportunity_research
    qDebug()<<GetColumnFromTable("measure","opportunity_research");

    //������� ���� ��������� �� relevance_research
    qDebug()<<GetColumnFromTable("weight","relevance_research");

    //������� ���� ��������� �� propriety_research
    qDebug()<<GetColumnFromTable("weight","propriety_research");

    //������� ���� ��������� �� opportunity_research
    qDebug()<<GetColumnFromTable("weight","opportunity_research");


    //������� �������� ������ �� �������� �� relevance_research � ������� id
    qDebug()<<GetAnswerVariants("relevance_research",id);

    //������� �������� ������ �� �������� �� propriety_research � ������� id
    qDebug()<<GetAnswerVariants("propriety_research",id);

    //������� �������� ������ �� �������� �� opportunity_research � ������� id
    qDebug()<< GetAnswerVariants("opportunity_research",id);

//*****************����**************





//----------------------------------------------------------------------------------------------------------------
// ������ ����
//----------------------------------------------------------------------------------------------------------------
    //������� ��� ������� �� ideal_knowledge_ingeneer
    qDebug()<<GetColumnFromTable("question","ideal_knowledge_ingeneer");

    //������� ��� ������� �� ideal_expert
    qDebug()<<GetColumnFromTable("question","ideal_expert");

    //������� ���� ��������� �� ideal_knowledge_ingeneer
    qDebug()<<GetColumnFromTable("weight","ideal_knowledge_ingeneer");

    //������� ���� ��������� �� ideal_expert
    qDebug()<<GetColumnFromTable("weight","ideal_expert");

    //������� �������� ������ �� ������ �� ideal_knowledge_ingeneer � ������� id
    qDebug()<<GetAnswerVariants("ideal_knowledge_ingeneer",id);

    //������� �������� ������ �� ������ �� ideal_expert � ������� id
    qDebug()<<GetAnswerVariants("ideal_expert",id);


    qDebug()<<GetAttribute("user","u_id","login",1);
    qDebug()<<GetAttribute("answer_variant_list","a_v_id","answer_variant_1",1);
    qDebug()<<GetAttribute("system","id","system_name",2);

    qDebug()<<GetProjectGroup("�� ���");
//����
    // ������ � ���� o_r_result �������� 1, 0 - ���������� ��������� ���������� ��� 1 - ��������
    SetResult("venima", "o_r_result",1);
    // ������ � ���� f_f_result �������� ���������������
    SetResult("venima", "f_f_result","���������������");
    // ������ � ������� s_result ������� ����� �������� 1 - �.�. ��� ���� ������ ������������ ������� � id 1
    SetResult("venima", "s_result",1);

    SetRegistrationInfo("prep", "123","������ ������ ������������", "�� ���");
    SetRegistrationInfo("stud", "123","������ ���� ����������", "�� ���","�������","���",21);
    // ������� ���� �� 2 � 3.
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

     //������� ��������������� ������ � user (���������� ������������)
     query.exec("INSERT INTO `user` (`u_id` ,`password` ,`name` ,`gender` ,`age` ,`u_g_id` ,`login` ,`competience_result` ,`r_r_result` ,`p_r_result` ,`o_r_result` ,`research_result` ,`f_f_result` ,`c_s_result` ,`r_v_result` ,`t_t_result` ,`prototyping_strategy_result`)"
                "VALUES('','"+password+"','"+name+"','','','1','"+login+"','','','','','','','','','','')");

     //������� ��������������� ������ � project (���������� �������)
     query.exec("INSERT INTO `project` (`id` ,`project_name`)"
                "VALUES ('','"+projectName+"')");
     //�������� u_id
     query.exec("SELECT `u_id` FROM `user` WHERE `user`.`login`='"+login+"'");
     query.next();
     u_id=query.value(0).toInt();
     //�������� pr_id
     query.exec("SELECT `id` FROM `project` WHERE `project`.`project_name`='"+projectName+"'");
     query.next();
     pr_id=query.value(0).toInt();
     //������ ���������� � �������������� ������������ �������
     query.exec("INSERT INTO `project_group` (`u_id` ,`pr_id`)"
                "VALUES ('"+QString::number(u_id)+"','"+QString::number(pr_id)+"')");
}


void dbWork::SetRegistrationInfo(QString login, QString password,QString name, QString projectName, QString groupName, QString gender, int age)
{
    QSqlQuery query;
    int u_g_id,pr_id,u_id;

    //�������� u_g_id �� �������� ������
    query.exec("SELECT `id` FROM `user_group` WHERE `user_group`.`group_name`='"+groupName+"'");
    query.next();
    u_g_id=query.value(0).toInt();
    //������� ��������������� ������ � user (���������� ������������)
    query.exec("INSERT INTO `user` (`u_id` ,`password` ,`name` ,`gender` ,`age` ,`u_g_id` ,`login` ,`competience_result` ,`r_r_result` ,`p_r_result` ,`o_r_result` ,`research_result` ,`f_f_result` ,`c_s_result` ,`r_v_result` ,`t_t_result` ,`prototyping_strategy_result`)"
               "VALUES('','"+password+"','"+name+"','"+gender+"','"+QString::number(age)+"','"+QString::number(u_g_id)+"','"+login+"','','','','','','','','','','')");

    //�������� u_id
    query.exec("SELECT `u_id` FROM `user` WHERE `user`.`login`='"+login+"'");
    query.next();
    u_id=query.value(0).toInt();
    //�������� pr_id
    query.exec("SELECT `id` FROM `project` WHERE `project`.`project_name`='"+projectName+"'");
    query.next();
    pr_id=query.value(0).toInt();
    //������ ���������� � �������������� ������������ �������
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
    // �������� ������������� ������
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
