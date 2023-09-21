
#ifndef SUBWAYCONTAINER_H
#define SUBWAYCONTAINER_H

#include <QtSql>
#include <QSqlDatabase>
#include <QVector>
#include <QFile>


class SubwayContainer
{
public:
    SubwayContainer();

    void sql_connect();
    void set_line1();
    void set_line2_3();
    void set_line4();
    void set();

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

private:


};

#endif // SUBWAYCONTAINER_H
