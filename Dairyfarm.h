#pragma once

#include <QtWidgets/QWidget>
//#include "ui_Dairyfarm.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <QMessageBox>
#include "farm.h"

class Dairyfarm : public QWidget
{
    Q_OBJECT

public:
    Dairyfarm(QWidget *parent = Q_NULLPTR, Farm* _Myfarm = Q_NULLPTR);

public slots:
    void status();
    void feeding();
    void removal();
    void starting_upgrade();
    void sakhtan();
private:

    Farm* myFarm;
    QVBoxLayout* Layout;
    QPushButton* btn1;
    QPushButton* btn2;
    QPushButton* btn3;
    QPushButton* btn4;
    QLabel* lbl;
    QPushButton* btn5;
    QPushButton* btn6;
   // Ui::DairyfarmClass ui;
};
