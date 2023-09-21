
#include "subwaycontainer.h"

SubwayContainer::SubwayContainer()
{
    sql_connect();
    set_line1();
    set_line2_3();
    set_line4();
}

void SubwayContainer::set(){
    QFile f1("D:/Qtwz/subway/subway.txt");
    QTextStream in(&f1);
    QString s,s1;
    int id;
    double lon,lat;

    if(!f1.open(QIODevice::ReadOnly)){
        qDebug()<<"文件打开失败";
    }
    while(!(in.atEnd())){
        in>>id;
        in>>s;
        in>>lon>>lat;
        qDebug()<<s;
    }
}

void SubwayContainer::sql_connect(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("8.130.133.151");
    //db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("railway");
    db.setUserName("root");
    db.setPassword("123456");
    if(db.open()){
        qDebug()<<"连接成功！";
    }
    else {
        qDebug()<<"连接失败！";
    }
}

void SubwayContainer::set_line1(){
    QSqlQuery qry;//获取数据库套接字

    for(int i=1;i<=41;i++){
        QString s=QString("select * from line1 where id=%1").arg(i)+";";
        if(qry.exec(s)){
            qry.next();
            str1.push_back(qry.value(1).toString());
            lon1.push_back(qry.value(2).toDouble());
            lat1.push_back(qry.value(3).toDouble());
        }
    }


}

void SubwayContainer::set_line2_3(){
    QSqlQuery qry;//获取数据库套接字
    QFile f1("D:/Qtwz/subway/subway.txt");
    if(!(f1.open(QIODevice::WriteOnly | QIODevice::Append))){
        qDebug()<<"文件打开失败";
    }
    QTextStream txtoutput(&f1);
    for(int i=1;i<=22;i++){
        QString s=QString("select * from line2 where id=%1").arg(i)+";";
        if(qry.exec(s)){
            qry.next();
            str2.push_back(qry.value(1).toString());
            lon2.push_back(qry.value(2).toDouble());
            lat2.push_back(qry.value(3).toDouble());
        }
        QString ss=QString("select * from line3 where id=%1").arg(i)+";";
        if(qry.exec(ss)){
            qry.next();
            str3.push_back(qry.value(1).toString());
            lon3.push_back(qry.value(2).toDouble());
            lat3.push_back(qry.value(3).toDouble());
            txtoutput<<qry.value(0).toInt()<<"   "<<qry.value(1).toString()<<"  "<<qry.value(2).toDouble()<<","<<qry.value(3).toDouble()<<Qt::endl;
        }
    }


}

void SubwayContainer::set_line4(){
    QSqlQuery qry;//获取数据库套接字
    for(int i=1;i<=25;i++){
        QString s=QString("select * from line4 where id=%1").arg(i)+";";
        if(qry.exec(s)){
            qry.next();
            str4.push_back(qry.value(1).toString());
            lon4.push_back(qry.value(2).toDouble());
            lat4.push_back(qry.value(3).toDouble());
        }
    }
}
