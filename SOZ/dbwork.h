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

    //���������� ����������� html-����� - � ��������� ������� � ��������� ������ ��� �������� ������� � ������ �����������.
    //�����: b -  ������, i - ������, u - �������������, dfn - �����������...
    QString getGlossary(QString terminFontStyle, int terminFontSize, QString definitionFontStyle, int definitionFontSize);
//�����
    //������� ��� �������� ������� ColumnName �� ������� TableName
    QVector<QString> GetColumnFromTable(QString columnName, QString tableName);
    QVector<QString> GetColumnFromTable(QString columnName, QString tableName, QString login);
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

    // ������� ��������(�), ��������������� id, ������������ � ���� idColumnName (����� ������� �������� �� id ��� ��� ��-�� ������� ��� ������� id)
    QVector<QString> GetAttribute(QString tableName,QString idColumnName, QString attributeColumnName,int id);
    QVector<QString> GetAttribute(QString tableName,QString idColumnName, QString attributeColumnName,QString id);
    // ������� ������������������ � ������ ������� ���������� � �������� � �������� �� �������
    QVector<int> GetProjectGroup(QString projectName);
    // ������������� ������ ����� � ���� �������
    void SetPair (int u_id, int pair_id);
    ~dbWork();
};

#endif // DBWORK_H
