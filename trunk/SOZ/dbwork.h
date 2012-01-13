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

    //возвращает размеченный html-текст - с казанными стилями и размерами шрифта для названия термина и самого определения.
    //Стили: b -  жирный, i - курсив, u - подчеркивание, dfn - определение...
    QString getGlossary(QString terminFontStyle, int terminFontSize, QString definitionFontStyle, int definitionFontSize);
//ВЫВОД
    //выводит все элементы колонки ColumnName из таблицы TableName
    QVector<QString> GetColumnFromTable(QString columnName, QString tableName);
    QVector<QString> GetColumnFromTable(QString columnName, QString tableName, QString login);
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

    // выводит аттрибут(ы), соответствующие id, находящемуся в поле idColumnName (может вывести название по id или все эл-ты колонки для данного id)
    QVector<QString> GetAttribute(QString tableName,QString idColumnName, QString attributeColumnName,int id);
    QVector<QString> GetAttribute(QString tableName,QString idColumnName, QString attributeColumnName,QString id);
    // выводит зарегистрированных в данном проекте кандидатов в эксперты и инженеры по знаниям
    QVector<int> GetProjectGroup(QString projectName);
    // устанавливает одному юзеру в пару другого
    void SetPair (int u_id, int pair_id);
    ~dbWork();
};

#endif // DBWORK_H
