#ifndef OBRABOTCHIK_H
#define OBRABOTCHIK_H

#include <QObject>
#include <QVector>
#include <QDebug>

class Obrabotchik : public QObject
{
    Q_OBJECT

    QVector<double> Answers;

public:
    explicit Obrabotchik(QObject *parent = 0);

    void addAnswer(double &_weight);

signals:

public slots:

};

#endif // OBRABOTCHIK_H
