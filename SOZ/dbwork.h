#ifndef DBWORK_H
#define DBWORK_H

#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QVariant>

class dbWork
{
    QSqlDatabase db;
    bool connectDB(QString _dbType = "QMYSQL", QString _dbName = "db", QString _host = "localhost", QString _dbUser = "root", QString _dbPass = "");
public:
    dbWork();


    QString getGlossary(int g_id);
//ВЫВОД
    //выводит все элементы колонки ColumnName из таблицы TableName
    QVector<QString> GetColumnFromTable(QString columnName, QString tableName);
    //выводит все варианты ответа на вопрос из указанной таблицы с указанным идентификатором
    QVector<QString> GetAnswerVariants(QString questionTableName, int id);
//ВВОД
    //для заказчика
    void SetRegistrationInfo(QString login, QString password,QString name, QString projectName);
    //для кандидатов в эксперты и инженеры по знаниям
    void SetRegistrationInfo(QString login, QString password,QString name, QString projectName, QString groupName, QString gender, int age);

    //вносит результат в колонку columnName или в таблицы s_result, k_r_result
    void SetResult(QString login, QString columnName,int result);
    void SetResult(QString login, QString columnName,QString result);
    ~dbWork();
};

#endif // DBWORK_H
