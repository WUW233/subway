
#ifndef SUBWAYCONTAINER_H
#define SUBWAYCONTAINER_H

#include <QtSql>
#include <QSqlDatabase>
#include <QVector>
#include <QList>
#include <QFile>
#include <QTextStream>


class SubwayContainer
{
public:
    SubwayContainer();

    void sql_connect();
    void set_line1();
    void set_line2();
    void set_line3();
    void set_line4();
    void set1();
    void set2();
    void set3();
    void set4();
    void data_update();
    void data_clear();

    ~SubwayContainer(){

    }

    QVector<QString> str1;
    QVector<QString> str2;
    QVector<QString> str3;
    QVector<QString> str4;
    QVector<double> lon1;
    QVector<double> lat1;
    QVector<double> lon2;
    QVector<double> lat2;
    QVector<double> lon3;
    QVector<double> lat3;
    QVector<double> lon4;
    QVector<double> lat4;

    QStringList ss;
    QStringList ss1;
    QStringList ss2;
    QStringList ss3;
    QStringList ss4;

private:


};

#endif // SUBWAYCONTAINER_H
