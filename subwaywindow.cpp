#include "subwaywindow.h"
#include "ui_subwaywindow.h"
#include "line.h"

SubwayWindow::SubwayWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SubwayWindow)
{
    ui->setupUi(this);

    f=new Form;
    QStringList strList1;
    QStringList strList2;
    strList1<<"无"<<"1号线"<<"2号线"<<"3号线"<<"4号线";
    strList2<<"无"<<"1号线"<<"2号线"<<"3号线"<<"4号线";
    ui->xianlu1->addItems(strList1);
    ui->xianlu2->addItems(strList2);

    scene = new QGraphicsScene(ui->graphicsView);//创建一个场景
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);//设置左键可拖动
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    timeID=startTimer(10000);
}

SubwayWindow::~SubwayWindow()
{
    delete ui;
    delete f;
}

void SubwayWindow::on_xianlu1_currentTextChanged(const QString &arg1)
{
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
        ui->qidian->addItems(sub_data.ss1);
        lien=1;
        break;
    case 1:
        ui->qidian->clear();
        ui->qidian->addItems(sub_data.ss2);
        lien=2;
        break;
    case 2:
        ui->qidian->clear();
        ui->qidian->addItems(sub_data.ss3);
        lien=3;
        break;
    case 3:
        ui->qidian->clear();
        ui->qidian->addItems(sub_data.ss4);
        lien=4;
        break;
    default:
        ui->qidian->clear();
        ui->qidian->addItems(sub_data.ss);
        break;
    }
}

void SubwayWindow::on_xianlu2_currentTextChanged(const QString &arg1)
{
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
        ui->zhongdian->addItems(sub_data.ss1);
        break;
    case 1:
        ui->zhongdian->clear();
        ui->zhongdian->addItems(sub_data.ss2);
        break;
    case 2:
        ui->zhongdian->clear();
        ui->zhongdian->addItems(sub_data.ss3);
        break;
    case 3:
        ui->zhongdian->clear();
        ui->zhongdian->addItems(sub_data.ss4);
        break;
    default:
        ui->zhongdian->clear();
        ui->zhongdian->addItems(sub_data.ss);
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
        xian="0";
        break;
    }
    s1=lx.printf(xian,ui->qidian->currentText(),ui->zhongdian->currentText());
    s2=lx.printf2(xian,ui->qidian->currentText(),ui->zhongdian->currentText());
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
    foreach (const QString &item, sub_data.ss1)//forchar循环，使用item遍历字符串列表ss
    {
        if (item.contains(ui->qidianEdit->text(), Qt::CaseInsensitive))//判断item中是否包含edit的内容，且区分大小写
        {
            lien=1;
            s1<<item;
            ui->qidian->clear();
            ui->qidian->addItems(s1);
        }
    }
    foreach (const QString &item, sub_data.ss2)//forchar循环，使用item遍历字符串列表ss
    {
        if (item.contains(ui->qidianEdit->text(), Qt::CaseInsensitive))//判断item中是否包含edit的内容，且区分大小写
        {
            lien=2;
            s1<<item;
            ui->qidian->clear();
            ui->qidian->addItems(s1);
        }
    }
    foreach (const QString &item, sub_data.ss3)//forchar循环，使用item遍历字符串列表ss
    {
        if (item.contains(ui->qidianEdit->text(), Qt::CaseInsensitive))//判断item中是否包含edit的内容，且区分大小写
        {
            lien=3;
            s1<<item;
            ui->qidian->clear();
            ui->qidian->addItems(s1);
        }
    }
    foreach (const QString &item, sub_data.ss4)//forchar循环，使用item遍历字符串列表ss
    {
        if (item.contains(ui->qidianEdit->text(), Qt::CaseInsensitive))//判断item中是否包含edit的内容，且区分大小写
        {
            lien=4;
            s1<<item;
            ui->qidian->clear();
            ui->qidian->addItems(s1);
        }
    }
}

void SubwayWindow::on_zhongButton_clicked()
{
    QStringList s2;
    foreach (const QString &item, sub_data.ss)
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
    Line l1;

    QVector<double>::iterator i,j;
    QVector<QString>::iterator k;

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

    QGraphicsTextItem* textItem1=new QGraphicsTextItem;
    textItem1->setPlainText(*k);
    textItem1->setFont(QFont("consolas",8,3));
    textItem1->setPos(l1.set_x(*i),l1.set_y(*j)-10);
    scene->addItem(textItem1);

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

    QGraphicsTextItem* textItem2=new QGraphicsTextItem;
    textItem2->setPlainText(*k);
    textItem2->setFont(QFont("consolas",8,3));
    textItem2->setPos(l1.set_x(*i),l1.set_y(*j)-10);
    scene->addItem(textItem2);

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

    QGraphicsTextItem* textItem3=new QGraphicsTextItem;
    textItem3->setPlainText(*k);
    textItem3->setFont(QFont("consolas",8,3));
    textItem3->setPos(l1.set_x(*i),l1.set_y(*j)-10);
    scene->addItem(textItem3);

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

    QGraphicsTextItem* textItem=new QGraphicsTextItem;
    textItem->setPlainText(*k);
    textItem->setFont(QFont("consolas",8,3));
    textItem->setPos(l1.set_x(*i),l1.set_y(*j)-10);
    scene->addItem(textItem);
}

void SubwayWindow::on_action_3_triggered()
{
    f->show();

}

void SubwayWindow::on_action_4_triggered()
{
    ui->graphicsView->scale(1.1, 1.1);
}

void SubwayWindow::on_action_5_triggered()
{
    ui->graphicsView->scale(0.9, 0.9);
}


void SubwayWindow::on_action_2_triggered()
{
    scene->clear();
    tu();
}

void SubwayWindow::timerEvent(QTimerEvent *event){//重写定时器事件，实现数据更新
    int tmp=event->timerId();
    if(tmp==timeID){
        sub_data.data_clear();
        sub_data.data_update();
        qDebug()<<"定时器执行";
    }
}
