#ifndef FORM_H
#define FORM_H

#include "subwaycontainer.h"
#include <QWidget>
#include <QMessageBox>
#include <QPushButton>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    SubwayContainer data;
    QStringList sss;
    int lab1;
    int lab2;
    int lab3;
private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_4_currentTextChanged(const QString &arg1);

    void on_comboBox_5_currentTextChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
