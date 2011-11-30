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
//�����
    //������� ��� �������� ������� ColumnName �� ������� TableName
    QVector<QString> GetColumnFromTable(QString columnName, QString tableName);
    //������� ��� �������� ������ �� ������ �� ��������� ������� � ��������� ���������������
    QVector<QString> GetAnswerVariants(QString questionTableName, int id);
//����
    //��� ���������
    void SetRegistrationInfo(QString login, QString password,QString name, QString projectName);
    //��� ���������� � �������� � �������� �� �������
    void SetRegistrationInfo(QString login, QString password,QString name, QString projectName, QString groupName, QString gender, int age);

    //������ ��������� � ������� columnName ��� � ������� s_result, k_r_result
    void SetResult(QString login, QString columnName,int result);
    void SetResult(QString login, QString columnName,QString result);
    ~dbWork();
};

#endif // DBWORK_H
