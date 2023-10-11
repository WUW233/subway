
#ifndef LIAN_H
#define LIAN_H
#include <string>
#include <QVector>
#include <QList>
#include <QWidget>
//using namespace std;
#define X1 l++
#define X2 l--
class lian
{
private:

    typedef struct xianlu{
        QString id;//站点名称
        int code;//站点当前位置
        QString other;//站点若是换乘点，则是另一条线路名称
        QString ben;//站点若是换乘点，则是当前线路名称
        int other_data;//站点是否是换乘点的标识符
    }Tx;

    QVector<QString>A={"王家港站", "石油大学站", "太行山路站", "井冈山路站", "丁家河站", "薛家岛站", "天目山站", "安子站", "新港山路站", "南北屯站", "山里站", "凤凰岛站", "团岛站", "西镇站", "青岛站", "中山路站", "观象山站", "广饶路站", "台东站", "海泊桥站", "小村庄站", "北岭站", "水清沟站", "中心医院站", "胜利桥站", "安顺路站", "青岛北站", "沧安路站", "永年路站", "兴国路站", "南岭路站", "遵义路站", "瑞金路站", "仙家寨站", "流亭站", "凤岗路站", "小寨子站", "正阳中路站", "农业大学站", "沟岔站", "东郭庄站"};
    QVector<QString>B={"泰山路站", "利津路站", "台东站", "海信桥站", "芝泉路站", "五四广场站", "浮山所站", "燕儿岛路站", "高雄路站", "麦岛站", "海游路站", "海川路站", "海安路站", "石老人浴场站", "苗岭路站", "同安路站", "辽阳东路站", "东韩站", "华楼山路站", "枣山路站", "李村站", "李村公园站"};
    QVector<QString>C={"青岛站", "人民会堂站", "汇泉广场站", "中山公园站", "太平角公园站", "延安三路站", "五四广场站", "江西路站", "宁夏路站", "敦化路站", "错埠岭站", "清江路站", "双山站", "长沙路站", "地铁大厦站", "海尔路站", "万年泉路站", "李村站", "君峰路站", "振华路站", "永平路站", "青岛北站"};
    QVector<QString>D={"人民会堂站", "信号山站", "观象山站", "泰山路站", "昌乐路站", "海泊河公园站", "海泊桥站", "西吴家村站", "错埠岭站", "福辽立交桥站", "洪山坡", "劲松三路站", "埠西站", "大埠东站", "辽阳东路站", "董家下庄站", "科苑经七路站", "张村站", "彭家庄站", "南宅科站", "小唠山站", "沙子口站", "段家埠站", "登瀛站", "大河东站"};

    //QVector<QString> *x_a=&A,*x_b=&B,*x_c=&C,*x_d=&D;
    //四条线路链表
    QList<Tx>a;
    QList<Tx>b;
    QList<Tx>c;
    QList<Tx>d;

    QList<Tx>::iterator find(QList<Tx>*x,QString s);//链表查找
    void put(QList<Tx>::iterator x);//输出单个节点
    void jie(QList<Tx>*x,QList<Tx>*y,QString s);//添加换乘站

    QVector<Tx>X;//存储dfs函数的返回值
    QVector<QString>Y;//存储已遍历线路
    QVector<Tx>X_2;//存储dfs函数的返回值
    QVector<QString>Y_2;//存储已遍历线路
    //int san=0;
    QList<Tx>* qd(QString s);//确定是哪一条线路
    bool pd(QString s);//判断是否已经遍历
    bool pd2(QString s);
    QString fd(QString s);
public:
    lian();
    bool dfs(QString s, QString z, QString zz);//DFS函数
    bool dfs2(QString s, QString z, QString zz);
    QString printf(QString s, QString z, QString zz);//输出函数
    QString printf2(QString s, QString z, QString zz);
    QString prun(QString a, QString b, QString c, int *jie);
    int jie_data=0,jie_data2=0;
    void cs();
};

#endif // LIAN_H
