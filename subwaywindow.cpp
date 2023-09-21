
#include "subwaywindow.h"
#include "ui_subwaywindow.h"
#include "line.h"



SubwayWindow::SubwayWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SubwayWindow)
{
    ui->setupUi(this);

    QStringList strList1;
    QStringList strList2;
    tu();
    strList1<<"无"<<"1号线"<<"2号线"<<"3号线"<<"4号线";
    strList2<<"无"<<"1号线"<<"2号线"<<"3号线"<<"4号线";
    ss<<"王家港站"<<"石油大学站"<<"太行山路站"<<"井冈山路站"<<"丁家河站"<<"薛家岛站"<<"天目山站"
      <<"安子站"<<"新港山路站"<<"南北屯站"<<"山里站"<<"凤凰岛站"<<"团岛站"<<"西镇站（暂不开通）"
      <<"青岛站"<<"中山路站"<<"观象山（市立医院）站"<<"广饶路站"<<"台东站"<<"海泊桥（海慈医疗）站"
      <<"小村庄站"<<"北岭站"<<"水清沟站"<<"中心医院站"<<"胜利桥（纺织谷）站"<<"安顺路站"<<"青岛北站"
      <<"沧安路站"<<"永年路站"<<"兴国路站"<<"南岭路站"<<"遵义路站"<<"瑞金路站"<<"仙家寨（汽车北站）"
      <<"流亭站"<<"凤岗路站"<<"小寨子站"<<"正阳中路站"<<"农业大学站"<<"沟岔站"<<"东郭庄站"
      <<"李村公园站"<<"李村站"<<"枣山路站"<<"华楼山路站"<<"东韩站"<<"辽阳东路站"<<"同安路站"<<"苗岭路站"
      <<"石老人浴场站"<<"海安路站"<<"海川路站"<<"海游路站"<<"麦岛站"<<"高雄路站"<<"燕儿岛路站"<<"浮山所站"
      <<"五四广场站"<<"芝泉路站"<<"海信桥站"<<"台东站"<<"利津路站"<<"泰山路站"<<"青岛站"<<"人民会堂站"
      <<"汇泉广场站"<<"中山公园站"<<"太平角公园站"<<"延安三路站"<<"五四广场站"<<"江西路站"
      <<"宁夏路站"<<"敦化路站"<<"错埠岭站"<<"清江路站"<<"双山站"<<"长沙路站"<<"地铁大厦站"<<"海尔路站"<<"万年泉路站"
      <<"李村站"<<"君峰路站"<<"振华路站"<<"永平路站"<<"青岛北站"<<"人民会堂"<<"信号山"<<"观象山"
      <<"泰山路"<<"昌乐路"<<"海泊河公园"<<"海泊桥"<<"西吴家村"<<"错埠岭"
      <<"福辽立交桥"<<"洪山坡"<<"劲松三路"<<"埠西"<<"大埠东"<<"辽阳东路"<<"董家下庄"<<"科苑经七路"<<"张村"<<"彭家庄"
      <<"南宅科"<<"小唠山"<<"沙子口"<<"段家埠"<<"登瀛"<<"大河东";
    ui->xianlu1->addItems(strList1);
    ui->xianlu2->addItems(strList2);
}

SubwayWindow::~SubwayWindow()
{
    delete ui;
}



void SubwayWindow::on_xianlu1_currentTextChanged(const QString &arg1)
{
    QStringList strList;
    qDebug()<<"起点："<<arg1;
    int x;
    if(arg1=="1号线") x=0;
    else if(arg1=="2号线") x=1;
    else if(arg1=="3号线") x=2;
        else if(arg1=="4号线") x=3;
        else x=4;
    switch (x) {
    case 0:
        ui->qidian->clear();
        strList<<"王家港站"<<"石油大学站"<<"太行山路站"<<"井冈山路站"<<"丁家河站"<<"薛家岛站"<<"天目山站"
                <<"安子站"<<"新港山路站"<<"南北屯站"<<"山里站"<<"凤凰岛站"<<"团岛站"<<"西镇站（暂不开通）"
                <<"青岛站"<<"中山路站"<<"观象山（市立医院）站"<<"广饶路站"<<"台东站"<<"海泊桥（海慈医疗）站"
                <<"小村庄站"<<"北岭站"<<"水清沟站"<<"中心医院站"<<"胜利桥（纺织谷）站"<<"安顺路站"<<"青岛北站"
                <<"沧安路站"<<"永年路站"<<"兴国路站"<<"南岭路站"<<"遵义路站"<<"瑞金路站"<<"仙家寨（汽车北站）"
                <<"流亭站"<<"凤岗路站"<<"小寨子站"<<"正阳中路站"<<"农业大学站"<<"沟岔站"<<"东郭庄站";
        ui->qidian->addItems(strList);
        lien=1;
        strList.clear();
        break;
    case 1:
        ui->qidian->clear();
        strList<<"李村公园站"<<"李村站"<<"枣山路站"<<"华楼山路站"<<"东韩站"<<"辽阳东路站"<<"同安路站"<<"苗岭路站"
                <<"石老人浴场站"<<"海安路站"<<"海川路站"<<"海游路站"<<"麦岛站"<<"高雄路站"<<"燕儿岛路站"<<"浮山所站"
                <<"五四广场站"<<"芝泉路站"<<"海信桥站"<<"台东站"<<"利津路站"<<"泰山路站";
        ui->qidian->addItems(strList);
        lien=2;
        strList.clear();
        break;
    case 2:
        ui->qidian->clear();
        strList<<"青岛站"<<"人民会堂站"<<"汇泉广场站"<<"中山公园站"<<"太平角公园站"<<"延安三路站"<<"五四广场站"<<"江西路站"
                <<"宁夏路站"<<"敦化路站"<<"错埠岭站"<<"清江路站"<<"双山站"<<"长沙路站"<<"地铁大厦站"<<"海尔路站"<<"万年泉路站"
                <<"李村站"<<"君峰路站"<<"振华路站"<<"永平路站"<<"青岛北站";
        ui->qidian->addItems(strList);
        lien=3;
        strList.clear();
        break;
    case 3:
        ui->qidian->clear();
        strList<<"人民会堂站"<<"信号山"<<"观象山"<<"泰山路"<<"昌乐路"<<"海泊河公园"<<"海泊桥站"<<"西吴家村站"<<"错埠岭站"
                <<"福辽立交桥站"<<"洪山坡站"<<"劲松三路站"<<"埠西站"<<"大埠东站"<<"辽阳东路站"<<"董家下庄站"<<"科苑经七路站"<<"张村站"<<"彭家庄站"
                <<"南宅科站"<<"小唠山站"<<"沙子口站"<<"段家埠站"<<"登瀛站"<<"大河东站";
        ui->qidian->addItems(strList);
        lien=4;
        strList.clear();
        break;
    default:
        ui->qidian->clear();
        strList<<ss;
        ui->qidian->addItems(strList);
        strList.clear();
        break;
    }
}

void SubwayWindow::on_xianlu2_currentTextChanged(const QString &arg1)
{
    QStringList strList;
    qDebug()<<"终点："<<arg1;
    int x;
    if(arg1=="1号线") x=0;
        else if(arg1=="2号线") x=1;
            else if(arg1=="3号线") x=2;
            else if(arg1=="4号线") x=3;
            else x=4;
    switch (x) {
    case 0:
        ui->zhongdian->clear();
        strList<<"王家港站"<<"石油大学站"<<"太行山路站"<<"井冈山路站"<<"丁家河站"<<"薛家岛站"<<"天目山站"
                <<"安子站"<<"新港山路站"<<"南北屯站"<<"山里站"<<"凤凰岛站"<<"团岛站"<<"西镇站"
                <<"青岛站"<<"中山路站"<<"观象山站"<<"广饶路站"<<"台东站"<<"海泊桥站"
                <<"小村庄站"<<"北岭站"<<"水清沟站"<<"中心医院站"<<"胜利桥站"<<"安顺路站"<<"青岛北站"
                <<"沧安路站"<<"永年路站"<<"兴国路站"<<"南岭路站"<<"遵义路站"<<"瑞金路站"<<"仙家寨站"
                <<"流亭站"<<"凤岗路站"<<"小寨子站"<<"正阳中路站"<<"农业大学站"<<"沟岔站"<<"东郭庄站";
        ui->zhongdian->addItems(strList);

        strList.clear();
        break;
    case 1:
        ui->zhongdian->clear();
        strList<<"李村公园站"<<"李村站"<<"枣山路站"<<"华楼山路站"<<"东韩站"<<"辽阳东路站"<<"同安路站"<<"苗岭路站"
                <<"石老人浴场站"<<"海安路站"<<"海川路站"<<"海游路站"<<"麦岛站"<<"高雄路站"<<"燕儿岛路站"<<"浮山所站"
                <<"五四广场站"<<"芝泉路站"<<"海信桥站"<<"台东站"<<"利津路站"<<"泰山路站";
        ui->zhongdian->addItems(strList);

        strList.clear();
        break;
    case 2:
        ui->zhongdian->clear();
        strList<<"青岛站"<<"人民会堂站"<<"汇泉广场站"<<"中山公园站"<<"太平角公园站"<<"延安三路站"<<"五四广场站"<<"江西路站"
                <<"宁夏路站"<<"敦化路站"<<"错埠岭站"<<"清江路站"<<"双山站"<<"长沙路站"<<"地铁大厦站"<<"海尔路站"<<"万年泉路站"
                <<"李村站"<<"君峰路站"<<"振华路站"<<"永平路站"<<"青岛北站";
        ui->zhongdian->addItems(strList);

        strList.clear();
        break;
    case 3:
        ui->zhongdian->clear();
        strList<<"人民会堂站"<<"信号山站"<<"观象山站"<<"泰山路站"<<"昌乐路站"<<"海泊河公园站"<<"海泊桥站"<<"西吴家村站"<<"错埠岭站"
                <<"福辽立交桥站"<<"洪山坡站"<<"劲松三路站"<<"埠西站"<<"大埠东站"<<"辽阳东路站"<<"董家下庄站"<<"科苑经七路站"<<"张村站"<<"彭家庄站"
                <<"南宅科站"<<"小唠山站"<<"沙子口站"<<"段家埠站"<<"登瀛站"<<"大河东站";
        ui->zhongdian->addItems(strList);

        strList.clear();
        break;
    default:
        ui->zhongdian->clear();
        strList<<ss;
        ui->zhongdian->addItems(strList);
        strList.clear();
        break;
    }
}

void SubwayWindow::on_pushButton_clicked()
{
    QString xian,s1,s2;
    ui->textEdit->clear();
    switch (lien) {
    case 1:
        xian="1";
        break;
    case 2:
        xian="2";
        break;
    case 3:
        xian="3";
        break;
    case 4:
        xian="4";
        break;
    default:
        break;
    }
    s1=lx.printf(xian,ui->qidian->currentText(),ui->zhongdian->currentText());
    s2=lx.printf2(xian,ui->qidian->currentText(),ui->zhongdian->currentText());
    //lx.dfs(xian,ui->qidian->currentText(),ui->zhongdian->currentText());
    if(lx.jie_data>lx.jie_data2){
        ui->textEdit->setText(s2+'\n');
    }
    else{
        ui->textEdit->setText(s1+'\n');
    }

    ui->textEdit->setReadOnly(true);
    ui->textEdit->setTextInteractionFlags(Qt::NoTextInteraction);
}


void SubwayWindow::on_qiButton_clicked()
{
    QStringList s1;
    foreach (const QString &item, ss)//forchar循环，使用item遍历字符串列表ss
    {
        if (item.contains(ui->qidianEdit->text(), Qt::CaseInsensitive))//判断item中是否包含edit的内容，且区分大小写
        {
            s1<<item;
            ui->qidian->clear();
            ui->qidian->addItems(s1);
        }
    }
}


void SubwayWindow::on_zhongButton_clicked()
{
    QStringList s2;
    foreach (const QString &item, ss)
    {
        if (item.contains(ui->zhongdianEidt->text(), Qt::CaseInsensitive))
        {
            s2<<item;
            ui->zhongdian->clear();
            ui->zhongdian->addItems(s2);
        }
    }
}

void SubwayWindow::tu(){
//    QSqlQuery qry;//获取数据库套接字
//    QSqlQuery qry1;//获取数据库套接字
    Line l1;
//    double lon1,lat1,lon2,lat2;
//    int j=0;
    QVector<double>::iterator i,j;
    QVector<QString>::iterator k;

    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);//创建一个场景
    //scene->setBackgroundBrush(Qt::yellow);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);//设置左键可拖动
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    QPen pen;   // 定义一个画笔，设置画笔颜色和宽度
    pen.setColor(QColor(0, 160, 230));
    pen.setWidth(3);
    QPen pen1;
    pen1.setColor(QColor(255,255,0));
    pen1.setWidth(3);
    QPen pen2;
    pen2.setColor(QColor(20,255,0));
    pen2.setWidth(3);
    QPen pen3;
    pen3.setColor(QColor(10,200,158));
    pen3.setWidth(3);

    for(i=sub_data.lon2.begin(),j=sub_data.lat2.begin(),k=sub_data.str2.begin();i+1!=sub_data.lon2.end();i++,j++,k++){
        QVector<double>::iterator t1=i+1,t2=j+1;
        QLineF line1(l1.set_x(*i),l1.set_y(*j),l1.set_x(*t1),l1.set_y(*t2));
        QGraphicsLineItem *line = new QGraphicsLineItem;
        line->setPen(pen);
        line->setLine(line1);
        scene->addItem(line);

        QGraphicsEllipseItem *rect=new QGraphicsEllipseItem(l1.set_x(*i)-5,l1.set_y(*j)-5,10,10);
        rect->setBrush(Qt::red);
        scene->addItem(rect);

        QGraphicsTextItem* textItem=new QGraphicsTextItem;
        textItem->setPlainText(*k);
        textItem->setFont(QFont("consolas",8,3));
        textItem->setPos(l1.set_x(*i),l1.set_y(*j)-10);
        scene->addItem(textItem);
    }
    QGraphicsEllipseItem *rect1=new QGraphicsEllipseItem(l1.set_x(*i)-5,l1.set_y(*j)-5,10,10);
    rect1->setBrush(Qt::red);
    scene->addItem(rect1);

    for(i=sub_data.lon1.begin(),j=sub_data.lat1.begin(),k=sub_data.str1.begin();i+1!=sub_data.lon1.end();i++,j++,k++){
        QVector<double>::iterator t1=i+1,t2=j+1;
        QLineF line1(l1.set_x(*i),l1.set_y(*j),l1.set_x(*t1),l1.set_y(*t2));
        QGraphicsLineItem *line = new QGraphicsLineItem;
        line->setPen(pen1);
        line->setLine(line1);
        scene->addItem(line);

        QGraphicsEllipseItem *rect=new QGraphicsEllipseItem(l1.set_x(*i)-5,l1.set_y(*j)-5,10,10);
        rect->setBrush(Qt::red);
        scene->addItem(rect);

        QGraphicsTextItem* textItem=new QGraphicsTextItem;
        textItem->setPlainText(*k);
        textItem->setFont(QFont("consolas",8,3));
        textItem->setPos(l1.set_x(*i),l1.set_y(*j)-10);
        scene->addItem(textItem);
    }
    QGraphicsEllipseItem *rect2=new QGraphicsEllipseItem(l1.set_x(*i)-5,l1.set_y(*j)-5,10,10);
    rect2->setBrush(Qt::red);
    scene->addItem(rect2);

    for(i=sub_data.lon3.begin(),j=sub_data.lat3.begin(),k=sub_data.str3.begin();i+1!=sub_data.lon3.end();i++,j++,k++){
        QVector<double>::iterator t1=i+1,t2=j+1;
        QLineF line1(l1.set_x(*i),l1.set_y(*j),l1.set_x(*t1),l1.set_y(*t2));
        QGraphicsLineItem *line = new QGraphicsLineItem;
        line->setPen(pen2);
        line->setLine(line1);
        scene->addItem(line);

        QGraphicsEllipseItem *rect=new QGraphicsEllipseItem(l1.set_x(*i)-5,l1.set_y(*j)-5,10,10);
        rect->setBrush(Qt::red);
        scene->addItem(rect);

        QGraphicsTextItem* textItem=new QGraphicsTextItem;
        textItem->setPlainText(*k);
        textItem->setFont(QFont("consolas",8,3));
        textItem->setPos(l1.set_x(*i),l1.set_y(*j)-10);
        scene->addItem(textItem);
    }
    QGraphicsEllipseItem *rect3=new QGraphicsEllipseItem(l1.set_x(*i)-5,l1.set_y(*j)-5,10,10);
    rect3->setBrush(Qt::red);
    scene->addItem(rect3);

    for(i=sub_data.lon4.begin(),j=sub_data.lat4.begin(),k=sub_data.str4.begin();i+1!=sub_data.lon4.end();i++,j++,k++){
        QVector<double>::iterator t1=i+1,t2=j+1;
        QLineF line1(l1.set_x(*i),l1.set_y(*j),l1.set_x(*t1),l1.set_y(*t2));
        QGraphicsLineItem *line = new QGraphicsLineItem;
        line->setPen(pen3);
        line->setLine(line1);
        scene->addItem(line);

        QGraphicsEllipseItem *rect=new QGraphicsEllipseItem(l1.set_x(*i)-5,l1.set_y(*j)-5,10,10);
        rect->setBrush(Qt::red);
        scene->addItem(rect);

        QGraphicsTextItem* textItem=new QGraphicsTextItem;
        textItem->setPlainText(*k);
        textItem->setFont(QFont("consolas",8,3));
        textItem->setPos(l1.set_x(*i),l1.set_y(*j)-10);
        scene->addItem(textItem);
    }
    QGraphicsEllipseItem *rect4=new QGraphicsEllipseItem(l1.set_x(*i)-5,l1.set_y(*j)-5,10,10);
    rect4->setBrush(Qt::red);
    scene->addItem(rect4);


}


void SubwayWindow::wheelEvent(QWheelEvent *event)
{
    int wheelValue = event->angleDelta().y();
    double ratio = (double)wheelValue / (double)1200 + 1;
    ui->graphicsView->scale(ratio, ratio);
}

void SubwayWindow::on_action_4_triggered()
{
    ui->graphicsView->scale(1.1, 1.1);
}


void SubwayWindow::on_action_5_triggered()
{
    ui->graphicsView->scale(0.9, 0.9);
}

