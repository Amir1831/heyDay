#ifndef WHEATLAND_H
#define WHEATLAND_H

#include <QWidget>

namespace Ui {
class wheatland;
}

class wheatland : public QWidget
{
    Q_OBJECT

public:
     wheatland(QWidget *parent = nullptr);
    ~wheatland();

private slots:
    void on_kesht_clicked();

    void on_bardasht_clicked();

    void on_upGrade_clicked();

private:
    Ui::wheatland *ui;
    int area;
    bool isKeshting;
    int keshtAmount;
    int startDay;
    int startMonth;
    int startYear;
    int id;
};

#endif // WHEATLAND_H