#include "signup_dealer.h"
#include "ui_signup_dealer.h"
#include "Global.h"
#include "ExternalFunctions.h"
#include "login.h"
using namespace GlobalNameSpace;

void signup_dealer::setLastPageSign(signup* lastpage)
{
    this->last_page_sign = lastpage;
    return;
}

void signup_dealer::setLogin(login *log)
{
    this->log_in = log;
    return;
}


signup_dealer::signup_dealer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup_dealer)
{
    ui->setupUi(this);
    ui->led_mobilenumber->setValidator(new QDoubleValidator(0, 100000000000 , 10, this));
}

signup_dealer::~signup_dealer()
{
    delete ui;
}

void signup_dealer::on_qle_password_textChanged(const QString &arg1)
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



void signup_dealer::on_qpb_back_clicked()
{

    this->hide();

    this->last_page_sign->show();

}

void signup_dealer::on_qpb_signup_clicked()
{




    Globals::TYPE_USER = 2;
    //int level_of_access=2;
    QString name =ui->qle_name->text();
    QString lastname = ui->qle_lastname->text();
    QString email=ui->qle_email->text();
    QString username=ui->qle_username->text();
    QString password1=ui->qle_password->text();
   QString password2=ui->qle_password2->text();
  // double  money=ui->qspb_money->value();
    QString mobilenum = ui->led_mobilenumber->text();
    QString address  = ui->led_address->text();
    QString state = ui->cmb_state->currentText();
    QString city = ui->qle_city->text();
    QString company = ui->qle_compony_name->text();
    QString post = ui->led_postcode->text();





    if(name==nullptr || lastname==nullptr || email==nullptr || username==nullptr || password1==nullptr || password2==nullptr ||
            mobilenum == nullptr )
    {


        QMessageBox::information(this,"Warning","You should complete all fields");
    }

    else if(password1!=password2)
    {
        QMessageBox::information(this,"Warning","Passwords are not same !");
    }
    else if(ComputePassPow(password1) < 30)
    {
        QMessageBox::information(this,"Warning","Your password is weak !");
    }
    else if(!uniqueUserName(username))
    {
        QMessageBox::information(this,"Warning","Your Username is not unique!");

    }
    else
    {


        Dealer new_user;
        new_user.setLevelOfAccess(3);
        new_user.setName(name);
        new_user.setLastName(lastname);
        new_user.setKey(CreateKey());
        new_user.setEmail(email);
        new_user.setUserName(username);
        new_user.setPassword(password1);
        new_user.setDateOfCreated(NowTime());
        new_user.setAddress(address);
        new_user.setCity(city);
        new_user.setState(state);
        new_user.setMobileNumber(mobilenum);
        new_user.setPostCode(post);
        new_user.setComponyName(company);
        Globals::LIST_USERNAMES.push_back(username);
        Globals::DEALER_LIST.pushBack(new_user);
        Globals::DEALER_LIST.writeToFileUser();


        QMessageBox::information(this,"Wellcome","Now you are a dealer in Digikala !");

        log_in->show();


        this->close();








    }


}

void signup_dealer::on_cob_country_currentIndexChanged(int index)
{
    if(index==1)
    {
        ui->grb_inside->setEnabled(true);
    }
    else
    {
        ui->grb_inside->setEnabled(false);
    }
}




void signup_dealer::on_grb_adress_clicked()
{

}

void signup_dealer::on_qpb_show_password1_toggled(bool checked)
{
    if(checked)
    {
      ui->qle_password->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->qle_password->setEchoMode(QLineEdit::Password);
    }
}

void signup_dealer::on_qpb_show_password2_toggled(bool checked)
{
    if(checked)
    {
      ui->qle_password2->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->qle_password2->setEchoMode(QLineEdit::Password);
    }
}
