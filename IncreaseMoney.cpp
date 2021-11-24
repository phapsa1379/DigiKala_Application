#include "IncreaseMoney.h"
#include "ui_IncreaseMoney.h"
#include "Global.h"
#include "EditProfileUser.h"
//#include <iostream>

void IncreaseMoney::fillBlanks(double last_m)
{

     this->ui->spb_money->setValue(last_m);
     this->ui->spb_sum->setValue(last_m);
     return;

}

double IncreaseMoney::getMoney()
{
    double money = this->ui->spb_sum->value();
    return money;
}

IncreaseMoney::IncreaseMoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncreaseMoney)
{
    ui->setupUi(this);
    //fillBlanks();
}

IncreaseMoney::~IncreaseMoney()
{
    delete ui;
}

void IncreaseMoney::on_spb_add_valueChanged(double arg1)
{
    double first = this->ui->spb_money->value();
    double sum = arg1 + first;
    this->ui->spb_sum->setValue(sum);

}


void IncreaseMoney::on_btn_box_accepted()
{
    double sum_money = this->ui->spb_sum->value();

}
