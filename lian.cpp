
#include "lian.h"

lian::lian()
{
    a.push_back({"1",0,"0","0",0});
    b.push_back({"2",0,"0","0",0});
    c.push_back({"3",0,"0","0",0});
    d.push_back({"4",0,"0","0",0});
    int x=1;
    for(auto i=A.begin();i<A.end();i++)
    {
        a.push_back({*i,x,"0","0",0});
        x++;
    }
    x=1;
    for(auto i=B.begin();i<B.end();i++)
    {
        b.push_back({*i,x,"0","0",0});
        x++;
    }
    x=1;
    for(auto i=C.begin();i<C.end();i++)
    {
        c.push_back({*i,x,"0","0",0});
        x++;
    }
    x=1;
    for(auto i=D.begin();i<D.end();i++)
    {
        d.push_back({*i,x,"0","0",0});
        x++;
    }

    jie(&a,&b,"台东站");
    jie(&a,&c,"青岛站");
    jie(&a,&c,"青岛北站");
    jie(&a,&d,"观象山站");
    jie(&a,&d,"海泊桥站");
    jie(&b,&c,"五四广场站");
    jie(&b,&c,"李村站");
    jie(&b,&d,"泰山路站");
    jie(&b,&d,"辽阳东路站");
    jie(&c,&d,"人民会堂站");
    jie(&c,&d,"错埠岭站");
    qDebug()<<"success luxian";
}

QList<lian::Tx>::iterator lian::find(QList<Tx>*x,QString s)
{
    for(auto i=x->begin()+1;i!=x->end();i++)
    {
        if(i->id==s)
        {
            //qDebug()<<"success find";
            return i;
        }
        //qDebug()<<i->id.data();
    }
    //qDebug()<<"error find"<<s;
    return x->begin();
}

void lian::put(QList<Tx>::iterator x)
{
    qDebug()<<x->id<<" "<<x->code;
    if(x->other!="0")
        qDebug()<<x->other<<x->other_data;

}

void lian::jie(QList<Tx>*x,QList<Tx>*y,QString s)
{
    auto i=find(x,s);
    auto j=find(y,s);
    i->other=y->begin()->id;
    i->ben=x->begin()->id;
    j->ben=y->begin()->id;
    i->other_data=j->code;
    j->other=x->begin()->id;
    j->other_data=i->code;
    //qDebug()<<i->id<<" "<<i->other;
    //qDebug()<<j->id<<" "<<j->other<<j->code;
}
bool lian::dfs(QString s,QString z,QString zz)
{
    if(s=="0")
        s=fd(z);
    Y.push_back(s);
    int y=0;//为0时是正向遍历，反之是反向遍历
    QList<lian::Tx>*h=qd(s);//确定是哪个线路
    //qDebug()<<h->begin()->id;
    QList<lian::Tx>::iterator l=find(h,z);//获得该线路的迭代器
    auto ls=l;//保存该线路的迭代器开始时的状态
    if(l->id=="1" || l->id=="2" || l->id=="3" || l->id=="4")//如果是线路头就报错
        return false;

    while(l<h->end() && l>h->begin())
    {
        if(l->other_data!=0 && pd(l->other))//该站点是换乘站，并且那条线路没有遍历过
        {
            Y.push_back(l->other);//将这条线路加入到已经遍历过的里面
            //qDebug()<<l->other;
            bool tf=dfs(l->other,l->id,zz);//递归调用函数，找那条线路里面有没有终点
            if(tf)
            {
                X.push_back(*l);//将路线的换乘点加入到容器中
                //qDebug()<<l->id;
                return true;
            }
        }
        if(l->id==zz)
            return true;
        if(l->id==h->rbegin()->id)//遍历到了线路末尾，改变y和迭代器，去遍历到起点（反向遍历）
        {
            y=1;
            l=ls;
        }
        if(y==0)
            l++;
        else
            l--;
    }
    return false;
    /*没有找到就返回false，代表这条线路没有终点，
    因为是递归调用，所以如果运行到这里，那么说明他和他所交叉的没有遍历过的线路都没有终点*/
}
bool lian::dfs2(QString s,QString z,QString zz)
{
    if(s=="0")
        s=fd(z);
    Y.push_back(s);
    int y=1;//为0时是正向遍历，反之是反向遍历
    QList<lian::Tx>*h=qd(s);//确定是哪个线路
    QList<lian::Tx>::iterator l=find(h,z);//获得该线路的迭代器
    auto ls=l;//保存该线路的迭代器开始时的状态
    if(l->id=="1" || l->id=="2" || l->id=="3" || l->id=="4")//如果是线路头就报错
        return false;

    while(l<h->end() &&l>h->begin())
    {
        if(l->other_data!=0 && pd2(l->other))//该站点是换乘站，并且那条线路没有遍历过
        {
            Y_2.push_back(l->other);//将这条线路加入到已经遍历过的里面
            bool tf=dfs(l->other,l->id,zz);//递归调用函数，找那条线路里面有没有终点
            if(tf)
            {
                X_2.push_back(*l);//将路线的换乘点加入到容器中
                //qDebug()<<l->id;
                return true;
            }
        }
        if(l->id==zz)
            return true;
        if(l->id==(h->begin()+1)->id)//
        {
            y=0;
            l=ls;
        }
        if(y==0)
            l++;
        else
            l--;
    }
    return false;
    /*没有找到就返回false，代表这条线路没有终点，
    因为是递归调用，所以如果运行到这里，那么说明他和他所交叉的没有遍历过的线路都没有终点*/
}
QList<lian::Tx>* lian::qd(QString s)
{

    if(s=="1")
        return &a;
    if(s=="2")
        return &b;
    if(s=="3")
        return &c;
    if(s=="4")
        return &d;
    return &a;
}
bool lian::pd(QString s)
{
    for(auto i=Y.begin();i<Y.end();i++)
    {
        if(s==*i)
            return false;
    }
    return true;
}
bool lian::pd2(QString s)
{
    for(auto i=Y_2.begin();i<Y_2.end();i++)
    {
        if(s==*i)
            return false;
    }
    return true;
}
QString lian::printf(QString s, QString z, QString zz)
{
    jie_data=0;
    QVector<lian::Tx>t;
    QString str;
    Y.clear();
    X.clear();
    bool w1=dfs(s,z,zz);
    if(w1)
    {
        qDebug()<<"success";
        for(auto i=X.begin();i<X.end();i++)
        {
            if(i->id==(i-1)->id || i->id==(i+1)->id)
                continue;
            t.push_back(*i);
        }
        QString str;
        if(t.size()==2)
        {
            str+=prun(s,z,t[1].id,&jie_data);
            str+="-换乘"+t[1].other+"线:";
            str+=prun(t[1].other,t[1].id,t[0].id,&jie_data);
            str+="-换乘"+t[0].other+"线:";
            str+=prun(t[0].other,t[0].id,zz,&jie_data);
            return str;
        }

        int u=t.size()-1;
        str+=prun(s,z,t[u].id,&jie_data);
        if(u==0)
        {
            str+="-换乘"+t[u].other+"线:"+prun(t[u].other,t[u].id,zz,&jie_data);
            return str;
        }
        u--;
        for(;u>0;u--)
        {
            str+="-换乘"+t[u+1].other+"线:"+prun(t[u+1].other,t[u].id,t[u-1].id,&jie_data);
        }
        str+="-换乘"+t[u].other+"线:"+prun(t[u].other,t[u].id,zz,&jie_data);
        return str;
    }
    else
        qDebug()<<"error";

    return str;

}
QString lian::printf2(QString s, QString z, QString zz)
{
    jie_data2=0;
    QVector<Tx>t;
    QString str;
    Y_2.clear();
    X_2.clear();
    bool w1=dfs2(s,z,zz);
    if(w1)
    {
        qDebug()<<"success";
        for(auto i=X_2.begin();i<X_2.end();i++)
        {
            if(i->id==(i-1)->id || i->id==(i+1)->id)
                continue;
            t.push_back(*i);
        }
        QString str;
        int u=t.size()-1;

        str+=prun(s,z,t[u].id,&jie_data2);
        if(u==0)
        {
            str+="-换乘"+t[u].other+"线:"+prun(t[u].other,t[u].id,zz,&jie_data2);
            return str;
        }
        u--;
        for(;u>0;u--)
        {
            str+="-换乘"+t[u+1].other+"线:"+prun(t[u+1].other,t[u].id,t[u-1].id,&jie_data2);
        }
        str+="-换乘"+t[u].other+"线:"+prun(t[u].other,t[u].id,zz,&jie_data2);
        return str;
    }
    else
        qDebug()<<"error";

    return str;

}
QString lian::prun(QString a, QString b, QString c, int *jie)
{
    QString str;
    QList<Tx> *h=qd(a);
    auto x=find(h,b);
    auto y=find(h,c);
    int o=0;
    if(x->code>y->code)
        o=-1;
    if(x->code<y->code)
        o=1;

    while(x->id!=y->id)
    {
        str+=x->id+"->";
        x+=o;
        *jie+=1;
    }
    str+=y->id;
    *jie+=1;
    return str;
}
QString lian::fd(QString s)
{
    for(auto i=A.begin()+1;i<A.end();i++)
    {
        if(s==*i)
            return "1";
    }
    for(auto i=B.begin()+1;i<B.end();i++)
    {
        if(s==*i)
            return "2";
    }
    for(auto i=C.begin()+1;i<C.end();i++)
    {
        if(s==*i)
            return "3";
    }
    for(auto i=D.begin()+1;i<D.end();i++)
    {
        if(s==*i)
            return "4";
    }
    return "error";
}
void lian::cs()
{
    for(auto i=X.begin();i<X.end();i++)
    {
        qDebug()<<i->id;
    }
}
