
#include "subwaycontainer.h"

SubwayContainer::SubwayContainer()
{
    data_update();
}

void SubwayContainer::data_update(){
    QString str="select * from lab";
    QSqlQuery q;
    if(q.exec(str)){
        q.next();
        if(q.value(0).toInt()==1){
            set1();
            set2();
            set3();
            set4();
        }
        else{
            set_line1();
            set_line2();
            set_line3();
            set_line4();
            q.exec("update lab set id=1");
        }
    }
}

void SubwayContainer::set1(){
    QFile f1("D:/Qtwz/subway/line1.txt");
    QTextStream in(&f1);

    QString s;
    int id;
    double lon,lat;

    if(!f1.open(QIODevice::ReadOnly)){
        qDebug()<<"文件打开失败";
    }
    while(!(in.atEnd())){//如果没有数据可读结束循环
        in>>id;
        in>>s;
        in>>lon>>lat;
        if(s.size()!=0){
            ss<<s;
            ss1<<s;
            str1.push_back(s);
            lon1.push_back(lon);
            lat1.push_back(lat);
        }
    }
    f1.close();
}

void SubwayContainer::set2(){
    QFile f2("D:/Qtwz/subway/line2.txt");
    QTextStream in1(&f2);

    QString s;
    int id;
    double lon,lat;

    if(!f2.open(QIODevice::ReadOnly)){
        qDebug()<<"line2文件打开失败";
    }

    while(!(in1.atEnd())){
        in1>>id;
        in1>>s;
        in1>>lon>>lat;
        if(s.size()!=0){
            ss<<s;
            ss2<<s;
            str2.push_back(s);
            lon2.push_back(lon);
            lat2.push_back(lat);
        }
    }
    f2.close();
}

void SubwayContainer::set3(){
    QFile f3("D:/Qtwz/subway/line3.txt");
    QTextStream in2(&f3);

    QString s;
    int id;
    double lon,lat;

    if(!f3.open(QIODevice::ReadOnly)){
        qDebug()<<"line2文件打开失败";
    }

    while(!(in2.atEnd())){
        in2>>id;
        in2>>s;
        in2>>lon>>lat;
        if(s.size()!=0){
            ss<<s;
            ss3<<s;
            str3.push_back(s);
            lon3.push_back(lon);
            lat3.push_back(lat);
        }
    }
    f3.close();
}

void SubwayContainer::set4(){
    QFile f4("D:/Qtwz/subway/line4.txt");
    QTextStream in3(&f4);

    QString s;
    int id;
    double lon,lat;

    if(!f4.open(QIODevice::ReadOnly)){
        qDebug()<<"line2文件打开失败";
    }

    while(!(in3.atEnd())){
        in3>>id;
        in3>>s;
        in3>>lon>>lat;
        if(s.size()!=0){
            ss<<s;
            ss4<<s;
            str4.push_back(s);
            lon4.push_back(lon);
            lat4.push_back(lat);
        }
    }
    f4.close();
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
    QFile f1("D:/Qtwz/subway/line1.txt");
    if(!(f1.open(QIODevice::WriteOnly))){//只写打开，且写入文件尾部
        qDebug()<<"文件打开失败";
    }
    QTextStream txtoutput1(&f1);

    QString s1=QString("select * from line1 order by id asc");
    if(qry.exec(s1)){
        while(qry.next()){
            str1.push_back(qry.value(1).toString());
            lon1.push_back(qry.value(2).toDouble());
            lat1.push_back(qry.value(3).toDouble());
            txtoutput1<<qry.value(0).toInt()<<"   "<<qry.value(1).toString()<<"  "<<
                qry.value(2).toDouble()<<"   "<<qry.value(3).toDouble()<<Qt::endl;
        }
    }
    f1.close();
}

void SubwayContainer::set_line2(){
    QSqlQuery qry;//获取数据库套接字
    QFile f2("D:/Qtwz/subway/line2.txt");
    if(!(f2.open(QIODevice::WriteOnly))){
        qDebug()<<"文件打开失败";
    }
    QTextStream txtoutput2(&f2);

    QString s2=QString("select * from line2 order by id asc");
    if(qry.exec(s2)){
        while(qry.next()){
            str2.push_back(qry.value(1).toString());
            lon2.push_back(qry.value(2).toDouble());
            lat2.push_back(qry.value(3).toDouble());
            txtoutput2<<qry.value(0).toInt()<<"   "<<qry.value(1).toString()<<"  "<<
                qry.value(2).toDouble()<<"   "<<qry.value(3).toDouble()<<Qt::endl;
        }
    }
    f2.close();
}

void SubwayContainer::set_line3(){
    QSqlQuery qry;//获取数据库套接字
    QFile f3("D:/Qtwz/subway/line3.txt");
    if(!(f3.open(QIODevice::WriteOnly))){
        qDebug()<<"文件打开失败";
    }
    QTextStream txtoutput3(&f3);

    QString s3=QString("select * from line3 order by id asc");
    if(qry.exec(s3)){
        while(qry.next()){
            str3.push_back(qry.value(1).toString());
            lon3.push_back(qry.value(2).toDouble());
            lat3.push_back(qry.value(3).toDouble());
            txtoutput3<<qry.value(0).toInt()<<"   "<<qry.value(1).toString()<<"  "<<
                qry.value(2).toDouble()<<"   "<<qry.value(3).toDouble()<<Qt::endl;
        }
    }
    f3.close();
}

void SubwayContainer::set_line4(){
    QSqlQuery qry;//获取数据库套接字
    QFile f4("D:/Qtwz/subway/line4.txt");
    if(!(f4.open(QIODevice::WriteOnly))){
        qDebug()<<"文件打开失败";
    }
    QTextStream txtoutput4(&f4);

    QString s4=QString("select * from line4 order by id asc");
    if(qry.exec(s4)){
        while(qry.next()){
            str4.push_back(qry.value(1).toString());
            lon4.push_back(qry.value(2).toDouble());
            lat4.push_back(qry.value(3).toDouble());
            txtoutput4<<qry.value(0).toInt()<<"   "<<qry.value(1).toString()<<"  "<<
                qry.value(2).toDouble()<<"   "<<qry.value(3).toDouble()<<Qt::endl;
        }
    }
    f4.close();
}

void SubwayContainer::data_clear(){
    ss.clear();
    ss1.clear();
    ss2.clear();
    ss3.clear();
    ss4.clear();

    QVector<QString>().swap(str1);
    QVector<QString>().swap(str2);
    QVector<QString>().swap(str3);
    QVector<QString>().swap(str4);

    QVector<double>().swap(lon1);
    QVector<double>().swap(lon2);
    QVector<double>().swap(lon3);
    QVector<double>().swap(lon4);

    QVector<double>().swap(lat1);
    QVector<double>().swap(lat2);
    QVector<double>().swap(lat3);
    QVector<double>().swap(lat4);

}
