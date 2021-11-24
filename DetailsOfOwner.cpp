#include "DetailsOfOwner.h"
#include "ui_DetailsOfOwner.h"

#include "Global.h"
#include "NewMessageDialogForOwner.h"
using namespace GlobalNameSpace;

DetailsOfOwner::DetailsOfOwner(const unsigned long long keyOfOwner, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailsOfOwner)
{
    ui->setupUi(this);

    this->keyOfOwner = keyOfOwner;
    TNodeUser<Dealer> * temp = &Globals::DEALER_LIST.getByKey(this->keyOfOwner);
    Dealer adm = temp->getData();

    ui->led_name->setText(adm.getName());
    ui->led_lastname->setText(adm.getLastName());
    ///ui->led_email->setText(adm.getEmail());
    ui->led_postcode->setText(adm.getPostCode());
    ui->led_companyname->setText(adm.getComponyName());
    ui->userNameL->setText(adm.getUserName());
    ui->led_mobilenumber->setText(adm.getMobileNumber());
    ui->led_last_enter->setText(adm.getDateOfLastEnter());
    ui->led_city->setText(adm.getCity());
    ui->cmb_state->setText(adm.getState());
}

DetailsOfOwner::~DetailsOfOwner()
{
    delete ui;
}

void DetailsOfOwner::setBack(DetailOfAllProducts *back)
{
    this->back_details = back;
    return;
}

void DetailsOfOwner::setBackFavorite(DetailOfFavoriteProducts *back)
{
    this->back_favorite = back;
    return;
}

void DetailsOfOwner::setInt(int a)
{
    this->back = a;
    return;
}

void DetailsOfOwner::on_btn_ok_clicked()
{
    if(back == 2)
    {
        this->back_favorite->show();
        this->hide();
    }
    else
    {
        this->back_details->show();
        this->hide();
    }

}

void DetailsOfOwner::on_chatB_clicked()
{

    NewMessageDialogForOwner* d = new NewMessageDialogForOwner(keyOfOwner , this);

    d->show(); // Restore from systray


}
