
#include "stand.h"

Stand::Stand()
{
    set_t();
    jiao["青岛站"]=t3.begin();
    jiao["观象山站"]=t4.begin()+2;
    jiao["台东站"]=t2.begin()+2;
    jiao["海泊桥站"]=t4.begin()+6;
    jiao["青岛北站"]=t1.begin()+26;
    jiao1["青岛站"]=t3.end();
    jiao1["观象山站"]=t4.end();
    jiao1["台东站"]=t2.end();
    jiao1["海泊桥站"]=t4.end();
    jiao1["青岛北站"]=t1.end();
    jiao2["泰山路"]=t4.begin()+3;
    jiao2["台东"]=t1.begin()+18;
    jiao2["五四广场站"]=t3.begin()+6;
    jiao2["辽阳东路站"]=t4.begin()+14;
    jiao2["李村站"]=t3.begin()+17;
    lu("王家港站","辽阳东路站");
}
void Stand::set_t(){
    QFile f1("D:/Qtwz/subway/subway.txt");
    QTextStream in(&f1);
    QString s;
    int id,i=1;
    double lon,lat;

    if(!f1.open(QIODevice::ReadOnly)){
        qDebug()<<"文件打开失败";
    }
    while(!(in.atEnd())){
        in>>id;
        in>>s;
        in>>lon>>lat;
        if(i<42){
            t1.push_back(s);
        }
        else if(i>41&&i<64){
            t2.push_back(s);
        }
        else if(i>63&&i<86){
            t3.push_back(s);
        }
        else{
            t4.push_back(s);
        }
        i++;
    }

}

void Stand::lu(QString s,QString ss){
    QList<QString>::iterator it;
    int n1=0,n2=0,n3=0,n4=0;
    for(it=t1.begin();it!=t1.end();it++){
        if(*it==s){
            n1++;
            fun(1,it,ss);
            qDebug()<<"1号线";
        }
    }
    if(0==n1){
        for(it=t2.begin();it!=t2.end();it++){
            if(*it==s){
                n2++;
                fun(2,it,ss);
            }
        }
    }
    if(0==n2&&0==n1){
        for(it=t3.begin();it!=t3.end();it++){
            if(*it==s){
                n3++;
                fun(3,it,ss);
            }
        }
    }
    if(0==n3&&0==n2&&0==n1){
        for(it=t4.begin();it!=t4.end();it++){
            if(*it==s){
                n4++;
                fun(4,it,ss);
            }
        }
    }
    if(0==n4&&0==n3&&0==n2&&0==n1){
            qDebug()<<"站点名称错误！";
    }
}

bool Stand::fun(int a,QList<QString>::iterator i,QString s){
    QVector<QString> xian;
    QList<QString>::iterator it;
    int k=0;
    switch (a) {
    case 1:
            for(;i!=t1.end();i++){
                xian.push_back(*i);
                qDebug()<<*i;
                if(*i==s){
                    k=1;
                }
            }
            if(0==k){
                for(int a=0;a<dian.size();a++){
                    it=jiao[dian[a]];
                    for(;it!=jiao1[dian[a]];it++){
                        qDebug()<<*it;
                        if(*it==s){
                            k=1;
                            break;
                        }
                    }
                    if(1==k) break;
                }
            }
            break;
    case 2:
            for(;i!=t2.end();i++){
                xian.push_back(*i);
                qDebug()<<*i;
                if(*i==s){
                    k=1;
                }
            }
            if(0==k){
                for(int a=0;a<dian.size();a++){
                    it=jiao[dian[a]];
                    for(;it!=jiao1[dian[a]];it++){
                        qDebug()<<*it;
                        if(*it==s){
                            k=1;
                            break;
                        }
                    }
                    if(1==k) break;
                }
            }
            break;
    case 3:
            for(;i!=t3.end();i++){
                xian.push_back(*i);
                qDebug()<<*i;
                if(*i==s){
                    k=1;
                }
            }
            if(0==k){
                for(int a=0;a<dian.size();a++){
                    it=jiao[dian[a]];
                    for(;it!=jiao1[dian[a]];it++){
                        qDebug()<<*it;
                        if(*it==s){
                            k=1;
                            break;
                        }
                    }
                    if(1==k) break;
                }
            }
            break;
    case 4:
            for(;i!=t4.end();i++){
                xian.push_back(*i);
                qDebug()<<*i;
                if(*i==s){
                    k=1;
                }
            }
            if(0==k){
                for(int a=0;a<dian.size();a++){
                    it=jiao[dian[a]];
                    for(;it!=jiao1[dian[a]];it++){
                        qDebug()<<*it;
                        if(*it==s){
                            k=1;
                            break;
                        }
                    }
                    if(1==k) break;
                }
            }
            break;
    default:
            break;
    }
    return true;
}
