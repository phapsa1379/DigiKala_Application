#include "EditProfileUser.h"
#include "ui_EditProfileUser.h"
#include "Global.h"
#include <QMessageBox>
#include "TNodeUser.h"
#include "IncreaseMoney.h"
#include "IncreaseMoney.h"
#include "ChangePassword.h"

using namespace GlobalNameSpace;

EditProfile::EditProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProfile)
{
    //friend void IncreaseMoney::fillBlanks();
    ui->setupUi(this);
    fillBlanks();

}



void EditProfile::fillBlanks()
{
    if (Globals::TYPE_USER == DEALER)
    {
        TNodeUser<Dealer> * temp = Globals::DEALER_LIST.getHead();
        while(temp)
        {
            Dealer adm = temp->getData();
            if(adm.getKey() == Globals::KEY_USER)
            {
                this->ui->led_name->setText(adm.getName());
                this->ui->led_lastname->setText(adm.getLastName());
                this->ui->led_email->setText(adm.getEmail());
                this->ui->led_address->setText(adm.getAddress());
                this->ui->led_postcode->setText(adm.getPostCode());
                this->ui->led_companyname->setText(adm.getComponyName());
                this->ui->led_username->setText(adm.getUserName());
                this->ui->led_mobilenumber->setText(adm.getMobileNumber());
                this->ui->spb_money->setValue(adm.getMoney());
                money_ = adm.getMoney();

                this->ui->led_city->setText(adm.getCity());
                this->ui->cmb_state->setCurrentText(adm.getState());
                break;
            }
            temp = temp->getNext();
        }

    }
    else if(Globals::TYPE_USER == USER)
    {
        this->ui->lbl_company->setVisible(false);
        this->ui->led_companyname->setVisible(false);
        TNodeUser<Users> * temp = Globals::USER_LIST.getHead();
        while(temp)
        {
            Users adm = temp->getData();
            if(adm.getKey() == Globals::KEY_USER)
            {
                this->ui->led_name->setText(adm.getName());
                this->ui->led_lastname->setText(adm.getLastName());
                this->ui->led_email->setText(adm.getEmail());
                this->ui->led_address->setText(adm.getAddress());
                this->ui->led_postcode->setText(adm.getPostCode());
                this->ui->led_username->setText(adm.getUserName());
                this->ui->led_mobilenumber->setText(adm.getMobileNumber());
                this->ui->spb_money->setValue(adm.getMoney());
                money_ = adm.getMoney();
                this->ui->led_city->setText(adm.getCity());
                this->ui->cmb_state->setCurrentText(adm.getState());
                break;
            }
            temp = temp->getNext();
        }

}
}
EditProfile::~EditProfile()
{
    delete ui;
}

QString EditProfile::getPass()
{
    return this->new_pass;
}

double EditProfile::getMoney()
{
    return this->money_;
}

void EditProfile::on_btn_box_rejected()
{
    reject();
}

void EditProfile::on_btn_box_accepted()
{
    QString name = this->ui->led_name->text();
    QString lastname = this->ui->led_lastname->text();
    QString email = this->ui->led_email->text();
    QString username = this->ui->led_username->text();
    QString address = this->ui->led_address->text();
    QString m_number = this->ui->led_mobilenumber->text();
    QString post_code = this->ui->led_postcode->text();
    QString city = this->ui->led_city->text();
    QString state = this->ui->cmb_state->currentText();
    double money = this->ui->spb_money->value();
    QString newpa = getPass();


    if(Globals::TYPE_USER == USER)
    {
    TNodeUser<Users> * temp = Globals::USER_LIST.getHead();
    while(temp)
    {
        Users adm = temp->getData();
        if(adm.getKey() == Globals::KEY_USER)
        {
            if(ui->led_name->text().isEmpty() || ui->led_lastname->text().isEmpty() || ui->led_mobilenumber->text().isEmpty() || ui->led_email->text().isEmpty())
            {
                QMessageBox::information(this , "Warning" , "Please fill All Blanks",QMessageBox::Ok);
                break;
            }


            else
            {

            adm.setName(name);
            adm.setLastName(lastname);
            adm.setEmail(email);
            adm.setUserName(username);
            adm.setAddress(address);
            adm.setPostCode(post_code);
            adm.setMoney(money);
            adm.setMobileNumber(m_number);
            adm.setCity(city);
            adm.setState(state);
            if(newpa != "")
                adm.setPassword(newpa);
            temp->setData(adm);

             Globals::USER_LIST.writeToFileUser();
            this->close();
            QMessageBox::information(this , "Edited" , "Your profile Edited",QMessageBox::Ok);

            break;

            }
        }
        temp = temp->getNext();
    }


}
    else if(Globals::TYPE_USER == DEALER)
    {
    QString company = this->ui->led_companyname->text();
    TNodeUser<Dealer> * temp = Globals::DEALER_LIST.getHead();
    while(temp)
    {
        Dealer adm = temp->getData();
        if(adm.getKey() == Globals::KEY_USER)
        {
            if(ui->led_name->text().isEmpty() || ui->led_lastname->text().isEmpty() || ui->led_mobilenumber->text().isEmpty() || ui->led_email->text().isEmpty() || ui->led_companyname->text().isEmpty())
            {
                QMessageBox::information(this , "Warning" , "Please fill All Blanks",QMessageBox::Ok);
                break;
            }
            else
            {
                adm.setName(name);
                adm.setLastName(lastname);
                adm.setEmail(email);
                adm.setUserName(username);
                adm.setAddress(address);
                adm.setPostCode(post_code);
                adm.setMoney(money);
                adm.setMobileNumber(m_number);
                adm.setComponyName(company);
                if(newpa != "")
                    adm.setPassword(newpa);
                adm.setCity(city);
                adm.setState(state);
                temp->setData(adm);
                 Globals::DEALER_LIST.writeToFileUser();
                 this->close();
                QMessageBox::information(this , "Edited" , "Your profile Edited",QMessageBox::Ok);


                break;
            }


        }
        temp = temp->getNext();
    }

}




}



void EditProfile::on_btn_increasemoney_clicked()
{
    int res;
    IncreaseMoney *poor = new IncreaseMoney();
    poor->setModal(true);
    poor->setWindowTitle("Increase your accunt money ");

    poor->fillBlanks(this->getMoney());
    res = poor->exec();

    if (res == QDialog::Rejected)
    {
        return;
    }

    this->ui->spb_money->setValue(poor->getMoney());


}


void EditProfile::on_btn_changepass_clicked()
{
    ChangePassword * ch_pass = new ChangePassword();
    ch_pass->setModal(true);
    ch_pass->setWindowTitle("Change Password");
    int res;
    res = ch_pass->exec();
    if(res == QDialog::Rejected)
    {
        return;
    }

    QString newpass = ch_pass->getPass();
    this->new_pass = newpass;

}
