#include "signup.h"
#include "ui_signup.h"
#include "login.h"
#include "Global.h"
#include "signup_user.h"
#include "signup_dealer.h"

using namespace GlobalNameSpace;


signup::signup(QWidget *parent):
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);

}

signup::~signup()
{
    delete ui;
}

void signup::on_qpb_next_clicked()
{
    if(ui->qrb_username->isChecked())
    {
        Globals::TYPE_USER = 3;

        signup_user sign_user;
        sign_user.setModal(true);
        sign_user.setWindowTitle("Users Form");

        sign_user.setLogin(this->last_page);
        sign_user.setLastPageSign(this);

        this->hide();
        sign_user.exec();


    }

    else if(ui->qrb_dealer->isChecked())
    {
        Globals::TYPE_USER = 2;

        signup_dealer sign_dealer;
        sign_dealer.setModal(true);
        sign_dealer.setWindowTitle("Dealers Form");

        sign_dealer.setLogin(this->last_page);
        sign_dealer.setLastPageSign(this);
        this->hide();
        sign_dealer.exec();




    }

    else
    {
       QMessageBox::information(this,"","Select an item");
    }
}

void signup::on_qpb_back_clicked()
{
    this->hide();


}

void signup::setLastPage(login *log)
{
    this->last_page = log;
    return;
}
