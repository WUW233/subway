#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    sss<<"1号线"<<"2号线"<<"3号线"<<"4号线";
    ui->comboBox_4->addItems(sss);
    ui->comboBox->addItems(sss);
    ui->comboBox_5->addItems(sss);
    //qDebug()<<data.ss;
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()//添加站点按钮
{
    QSqlQuery qre,q;
    QString zd,z,zz;
    double jd,wd;
    int t=1;
    zd=ui->lineEdit->text();
    jd=ui->lineEdit_2->text().toDouble();
    wd=ui->lineEdit_3->text().toDouble();
    if(zd.size()==0){
        QMessageBox box(this);
        box.setWindowTitle("错误");
        box.setText("请输入站点名称！");
        box.exec();
        t=0;
    }
    if(ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()){
        QMessageBox box1(this);
        box1.setWindowTitle("错误");
        box1.setText("请输入经纬度！");
        box1.exec();
        t=0;
    }
    if(t){
        qDebug()<<"开始添加";
        switch (lab1) {
        case 1:
            z="insert into line1(site,longitude,latitude) values('"+zd+QString("',%1,%2)").arg(jd).arg(wd);
            zz="update lab set id=0";
            if(qre.exec(z)){
                qDebug()<<"指令执行";
                QMessageBox box3(this);
                box3.setWindowTitle("成功");
                box3.setText("插入成功");
                box3.exec();
                if(q.exec(zz)){
                    qDebug()<<"修改成功";
                }
            }
            break;
        case 2:
            z="insert into line2(site,longitude,latitude) values('"+zd+QString("',%1,%2)").arg(jd).arg(wd);
            zz="update lab set id=0";
            if(qre.exec(z)){
                qDebug()<<"指令执行";
                QMessageBox box3(this);
                box3.setWindowTitle("成功");
                box3.setText("插入成功");
                box3.exec();
                if(q.exec(zz)){
                    qDebug()<<"修改成功";
                }
            }
            break;
        case 3:
            z="insert into line3(site,longitude,latitude) values('"+zd+QString("',%1,%2)").arg(jd).arg(wd);
            zz="update lab set id=0";
            if(qre.exec(z)){
                qDebug()<<"指令执行";
                QMessageBox box3(this);
                box3.setWindowTitle("成功");
                box3.setText("插入成功");
                box3.exec();
                if(q.exec(zz)){
                    qDebug()<<"修改成功";
                }
            }
            break;
        case 4:
            z="insert into line4(site,longitude,latitude) values('"+zd+QString("',%1,%2)").arg(jd).arg(wd);
            zz="update lab set id=0";
            if(qre.exec(z)){
                qDebug()<<"指令执行";
                QMessageBox box3(this);
                box3.setWindowTitle("成功");
                box3.setText("插入成功");
                box3.exec();
                if(q.exec(zz)){
                    qDebug()<<"修改成功";
                }
            }
            break;
        default:
            break;
        }
    }

}


void Form::on_comboBox_currentTextChanged(const QString &arg1)//连接站点线路选择
{
    if(arg1=="1号线") lab2=1;
    else if(arg1=="2号线") lab2=2;
    else if(arg1=="3号线") lab2=3;
    else if(arg1=="4号线") lab2=4;
    switch (lab2) {
        case 1:
            ui->comboBox_2->clear();
            ui->comboBox_3->clear();
            ui->comboBox_3->addItems(data.str1);
            ui->comboBox_2->addItems(data.str1);
            break;
        case 2:
            ui->comboBox_2->clear();
            ui->comboBox_3->clear();
            ui->comboBox_3->addItems(data.str2);
            ui->comboBox_2->addItems(data.str2);
            break;
        case 3:
            ui->comboBox_2->clear();
            ui->comboBox_3->clear();
            ui->comboBox_3->addItems(data.str3);
            ui->comboBox_2->addItems(data.str3);
            break;
        case 4:
            ui->comboBox_2->clear();
            ui->comboBox_3->clear();
            ui->comboBox_3->addItems(data.str4);
            ui->comboBox_2->addItems(data.str4);
            break;
        default:
            break;
    }
}


void Form::on_comboBox_4_currentTextChanged(const QString &arg1)//添加站点线路选择
{
    if(arg1=="1号线") lab1=1;
    else if(arg1=="2号线") lab1=2;
    else if(arg1=="3号线") lab1=3;
    else if(arg1=="4号线") lab1=4;
}


void Form::on_comboBox_5_currentTextChanged(const QString &arg1)//删除站点线路选择
{
    if(arg1=="1号线") lab3=1;
    else if(arg1=="2号线") lab3=2;
    else if(arg1=="3号线") lab3=3;
    else if(arg1=="4号线") lab3=4;

    switch (lab3) {
        case 1:
            ui->comboBox_6->clear();
            ui->comboBox_6->addItems(data.str1);
        break;
        case 2:
            ui->comboBox_6->clear();
            ui->comboBox_6->addItems(data.str2);
        break;
        case 3:
            ui->comboBox_6->clear();
            ui->comboBox_6->addItems(data.str3);
        break;
        case 4:
            ui->comboBox_6->clear();
            ui->comboBox_6->addItems(data.str4);
        break;
        default:
        break;
    }
}


void Form::on_pushButton_3_clicked()//删除站点
{
    QSqlQuery qry,q;
    QString tex,tse;

    QPushButton *okbtn = new QPushButton("确定");
    QPushButton *cancelbtn = new QPushButton("取消");
    QMessageBox *mymsgbox = new QMessageBox;

    mymsgbox->setIcon(QMessageBox::Warning);
    mymsgbox->setWindowTitle("提示");
    mymsgbox->setText("确定删除该站点？");
    mymsgbox->addButton(okbtn, QMessageBox::AcceptRole);
    mymsgbox->addButton(cancelbtn, QMessageBox::RejectRole);
    mymsgbox->show();

    mymsgbox->exec();//阻塞等待用户输入
    tse="update lab set id=0";
    if (mymsgbox->clickedButton()==okbtn)//点击了OK按钮
    {
        switch (lab3) {
        case 1:
            tex="delete from line1 where site='"+ui->comboBox_6->currentText()+"'";
            qDebug()<<tex;
            if(qry.exec(tex)){
                QMessageBox box(this);
                box.setWindowTitle("成功");
                box.setText("删除成功");
                box.exec();
                q.exec(tse);
            }
            break;
        case 2:
            tex="delete from line2 where site=\""+ui->comboBox_6->currentText()+"\"";
            if(qry.exec(tex)){
                QMessageBox box(this);
                box.setWindowTitle("成功");
                box.setText("删除成功");
                box.exec();
                q.exec(tse);
            }
            break;
        case 3:
            tex="delete from line3 where site=\""+ui->comboBox_6->currentText()+"\"";
            if(qry.exec(tex)){
                QMessageBox box(this);
                box.setWindowTitle("成功");
                box.setText("删除成功");
                box.exec();
                q.exec(tse);
            }
            break;
        case 4:
            tex="delete from line4 where site=\""+ui->comboBox_6->currentText()+"\"";
            if(qry.exec(tex)){
                QMessageBox box(this);
                box.setWindowTitle("成功");
                box.setText("删除成功");
                box.exec();
                q.exec(tse);
            }
            break;
        default:
            break;
        }

    }
    else{
        qDebug()<<"取消";
    }

}

