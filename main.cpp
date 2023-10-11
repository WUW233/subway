
#include "subwaywindow.h"
//#include "stand.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QSqlDatabase>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
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


    SubwayWindow w;
    w.show();
    return a.exec();
    //return 0;
}
