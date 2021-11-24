#include "DetailUser.h"
#include "ui_DetailUser.h"
#include "Global.h"
#include <iostream>
using namespace GlobalNameSpace;

DetailUser::DetailUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailUser)
{
    ui->setupUi(this);
    fillBlonks();
}

DetailUser::~DetailUser()
{
    delete ui;
}

void DetailUser::fillBlonks()
{
    if (Globals::TYPE_USER == DEALER)
    {
        TNodeUser<Dealer> * temp = & Globals::DEALER_LIST.getByKey(Globals::KEY_USER);

        Dealer adm = temp->getData();

        this->ui->led_name->setText(adm.getName());
        this->ui->led_lastname->setText(adm.getLastName());
        this->ui->led_email->setText(adm.getEmail());
        this->ui->led_address->setText(adm.getAddress());
        this->ui->led_postcode->setText(adm.getPostCode());
        this->ui->led_companyname->setText(adm.getComponyName());
        this->ui->led_username->setText(adm.getUserName());
        this->ui->led_mobilenumber->setText(adm.getMobileNumber());
        this->ui->spb_money->setValue(adm.getMoney());
        this->ui->led_last_exit->setText(adm.getDateOfLastExit());
        this->ui->led_last_enter->setText(adm.getDateOfLastEnter());
        this->ui->led_create->setText(adm.getDateOfCreated());

        this->ui->led_city->setText(adm.getCity());
        this->ui->cmb_state->setCurrentText(adm.getState());

        return;

    }
    else
    {
        this->ui->lbl_company->setVisible(false);
        this->ui->led_companyname->setVisible(false);
        TNodeUser<Users> * temp = & Globals::USER_LIST.getByKey(Globals::KEY_USER);

        Users adm = temp->getData();

        this->ui->led_name->setText(adm.getName());
        this->ui->led_lastname->setText(adm.getLastName());
        this->ui->led_email->setText(adm.getEmail());
        this->ui->led_address->setText(adm.getAddress());
        this->ui->led_postcode->setText(adm.getPostCode());
        this->ui->led_username->setText(adm.getUserName());
        this->ui->led_mobilenumber->setText(adm.getMobileNumber());
        this->ui->spb_money->setValue(adm.getMoney());
        this->ui->led_last_exit->setText(adm.getDateOfLastExit());
        this->ui->led_last_enter->setText(adm.getDateOfLastEnter());
        this->ui->led_create->setText(adm.getDateOfCreated());
        this->ui->led_city->setText(adm.getCity());
        this->ui->cmb_state->setCurrentText(adm.getState());

        return;

    }

    return;
}

void DetailUser::on_btn_ok_clicked()
{
    this->close();
}
