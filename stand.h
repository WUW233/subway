
#ifndef STAND_H
#define STAND_H
#include <QSet>
#include <QVector>
#include <QHash>


class Stand//站点类
{
private:
    int id;//站点线路
    double lon,lat;//站点经纬度
    QString stand;//站点名
    static double minLongitude, minLatitude, maxLongitude, maxLatitude;//所有站点的边界位置
public:
    Stand();
    Stand(int a,double lo,double la,QString s){
        id=a;
        lon=lo;
        lat=la;
        stand=s;
    }
    friend class QTextStream;
};

class Lin
{
public:
    Lin();
};

#endif // STAND_H
