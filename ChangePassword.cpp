#include "ChangePassword.h"
#include "ui_ChangePassword.h"
#include "ExternalFunctions.h"
#include "Global.h"
#include "QMessageBox"
using namespace GlobalNameSpace;

ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

QString ChangePassword::getPass()
{
    return this->pass;
}

void ChangePassword::on_led_newpass_textChanged(const QString &arg1)
{
    if(ComputePassPow(arg1)==0)
    {
        ui->qlb_password_power->setStyleSheet("QLabel { background-color: rgb(243, 243, 243);}");
        ui->qlb_password_power->setText("");
    }




    else if(ComputePassPow(arg1)<30 && ComputePassPow(arg1)>0)
    {
        ui->qlb_password_power->setText("Weak");
        ui->qlb_password_power->setStyleSheet("QLabel { background-color : red;}");

    }
    else if(ComputePassPow(arg1)>=30 && ComputePassPow(arg1)<70 )
    {
       ui->qlb_password_power->setText("Normal");
       ui->qlb_password_power->setStyleSheet("QLabel { background-color : yellow;}");
    }
    else if(70 <= ComputePassPow(arg1) && ComputePassPow(arg1) <=100)
    {
        ui->qlb_password_power->setText("Strong");
        ui->qlb_password_power->setStyleSheet("QLabel { background-color : green;}");

    }
}

void ChangePassword::on_btn_box_accepted()
{
    QString pass1 =this->ui->led_newpass->text();
    QString pass2 = this->ui->led_cunfirmpass->text();
    QString current_pass;

    if(Globals::TYPE_USER == DEALER)
    {
        TNodeUser<Dealer> *temp = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
        current_pass = temp->getData().getPassword();
    }
    else if(Globals::TYPE_USER == USER)
    {
        TNodeUser<Users> *temp = &Globals::USER_LIST.getByKey(Globals::KEY_USER);
        current_pass = temp->getData().getPassword();
    }

    if(ui->led_currentpass->text() ==current_pass)
    {

        if(ComputePassPow(pass1) < 30)
        {
            QMessageBox::warning(this,"Warning","Your new password is weak !");
        }
        else
        {
            if(pass1 == pass2)
            {
                this->pass = pass1;
                QMessageBox::information(this,"Successfully","Your password changed.");

            }
            else
            {
                QMessageBox::information(this,"Not match","Passwords are not same !");

            }
        }
    }
    else
    {
        QMessageBox::information(this,"Warning","Your current password is not currect !");

    }




}


