
#ifndef SUBWAYWINDOW_H
#define SUBWAYWINDOW_H

#include "subwaycontainer.h"
#include "lian.h"
#include "form.h"

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QGraphicsScene>//场景
#include <QGraphicsView>//视图
#include <QGraphicsItem>//图元
#include <QWheelEvent>
#include <QFile>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class SubwayWindow; }
QT_END_NAMESPACE

class SubwayWindow : public QMainWindow

{
    Q_OBJECT

public:
    SubwayWindow(QWidget *parent = nullptr);
    void tu();
    void timerEvent(QTimerEvent *event);
    ~SubwayWindow();

private slots:
    void on_xianlu1_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_xianlu2_currentTextChanged(const QString &arg1);

    void on_qiButton_clicked();

    void on_zhongButton_clicked();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_3_triggered();

    void on_action_2_triggered();

private:
    Ui::SubwayWindow *ui;
    int lien=0;
    int timeID;
    SubwayContainer sub_data;
    lian lx;
    QMap<QString,int> l;
    Form *f;
    QGraphicsScene *scene;
};

#endif // SUBWAYWINDOW_H
