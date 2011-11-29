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

    // œ≈–¬€… ›“¿œ

    QVector<QString> GetQuestion_I();
    QVector<QString> GetAnswerVariants(QString questionTableName, int r_r_id);






    ~dbWork();
};

#endif // DBWORK_H
