#include "common_questions.h"
#include <QCloseEvent>
#include "ui_common_questions.h"
#include "personal_page1.h"
#include "Global.h"
#include "ExternalFunctions.h"
#include <QMessageBox>

using namespace GlobalNameSpace;


common_questions::common_questions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::common_questions)
{
    ui->setupUi(this);
}

common_questions::~common_questions()
{
    delete ui;
}

void common_questions::setBackUser(personal_page1 * back)
{
    this->back_user = back;
    return;
}

void common_questions::setBackDealer(personal_page2 *back)
{
    this->back_dealer = back;
    return;
}

void common_questions::on_qpb1_clicked()
{

    ui->tb->setText("1- Customer peace and satisfaction has always been one of the priorities of Digikala and Digikala strives to ensure that every order reaches the customer in the desired and expected conditions. However, esteemed customers may encounter issues after the purchase, in which case the service is provided in the context of after-sales service.");
}

void common_questions::on_qpb_back_clicked()
{
    if(Globals::TYPE_USER == USER)
    {
        back_user->show();
         this->hide();
    }

    else if(Globals::TYPE_USER == DEALER)
    {
         back_dealer->show();
         this->hide();
    }

}

void common_questions::on_qpb_2_clicked()
{
    ui->tb->setText("2- Because the warranty of different companies varies according to the type of product and therefore it is not possible to give an exact answer here, it is best to contact the warranty companies themselves.");
}

void common_questions::on_qpb_3_clicked()
{
    ui->tb->setText("3- Yes . Up to 7 days, you must notify the after-sales service unit of your cancellation.");
}

void common_questions::on_qpb_4_clicked()
{
    ui->tb->setText("4- Cancellation of purchase and return request is for a product that has not been opened and has not been used.");
}

void common_questions::on_qpb_5_clicked()
{
    ui->tb->setText("5- You can notify us of your return request for up to 7 days for goods with technical defects and up to 24 hours for goods with apparent defects and discrepancies.");
}

void common_questions::closeEvent(QCloseEvent *event) {
    switch (QMessageBox(tr("Warning!"), tr("Are you sure you want to exit?"), QMessageBox::Warning, QMessageBox::Yes | QMessageBox::Default, QMessageBox::No, QMessageBox::Escape).exec()) {
        case 3: {
            event->accept();
            //rewrite files egain...

            updateFiles();
            break;
        }
        default: {
            event->ignore();
            break;
        }
    }
}
