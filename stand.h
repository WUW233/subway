
#ifndef STAND_H
#define STAND_H
#include <QSet>
#include <QVector>
#include <QHash>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMap>
#include <QStringList>


class Stand//站点类
{
private:
    QList<QString> t1;
    QList<QString> t2;
    QList<QString> t3;
    QList<QString> t4;
    QMap<QString,QList<QString>::iterator> jiao,jiao1,jiao2,jiao22,jiao3,jiao33,jiao4,jiao44;
    QVector<QString> dian={"青岛站","观象山站","台东站","海泊桥站","青岛北站"};
public:
    Stand();
    friend class QTextStream;
    void set_t();
    void lu(QString s,QString ss);
    bool fun(int a,QList<QString>::iterator i,QString s1);

};

#endif // STAND_H
