#include "forgot_password.h"
#include "ui_forgot_password.h"
#include "Global.h"
#include "TLinkedListUser.h"
#include "QMessageBox"
using namespace GlobalNameSpace;

forgot_password::forgot_password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forgot_password)
{
    ui->setupUi(this);
}

forgot_password::~forgot_password()
{
    delete ui;
}

void forgot_password::on_qpb_back_clicked()
{
    this->last_page->show();
    this->close();
}
void forgot_password::setLastPage(login * log)
{
    this->last_page = log;
    return;
}

void forgot_password::on_qpb_confirm_clicked()
{
    QString username = this->ui->qle_username->text();
    QString email = this->ui->qle_email->text();
    QString pass;
    TNodeUser<Users>* temp = Globals::USER_LIST.getHead();
    while(temp)
    {
        Users usr = temp->getData();
        if(usr.getEmail() == email && usr.getUserName() == username)
        {
            pass = usr.getPassword();
            QMessageBox::StandardButton button = QMessageBox::question(this , "Are you sure ?" , "Are you sure your password display now ?" , QMessageBox::Yes | QMessageBox::No);
            if(button == QMessageBox::Yes)
            {
                this->ui->led_pass->setText(pass);
                return;
            }
            else
            {

            }

        }


        temp = temp->getNext();
    }


    TNodeUser<Dealer>* temp2 = Globals::DEALER_LIST.getHead();
    while(temp2)
    {
        Dealer usr = temp2->getData();
        if(usr.getEmail() == email && usr.getUserName() == username)
        {
            pass = usr.getPassword();
            QMessageBox::StandardButton button = QMessageBox::question(this , "Are you sure ?" , "Are you sure your password display now ?" , QMessageBox::Yes | QMessageBox::No);
            if(button == QMessageBox::Yes)
            {
                this->ui->led_pass->setText(pass);
                return;

            }
            else
            {

            }
        }


        temp2 = temp2->getNext();
    }
    /////////////////////



    QMessageBox::warning(this , "NOT FOUND !" , "Your username or email not found. \nAre your sure Signed up before ? ");




}
