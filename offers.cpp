#include "offers.h"
#include "ui_offers.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
//#include "personal_page1.h"
//include "personal_page2.h"
#include <QtGui>
#include <QScrollBar>
#include <QScrollArea>
#include "Global.h"
#include "ExternalFunctions.h"

using namespace GlobalNameSpace;

offers::offers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::offers)
{
    ui->setupUi(this);


    ui->lbl_gif1->setWindowFlag(Qt::FramelessWindowHint);
     ui->lbl_gif1->setMask((new QPixmap(":/gifs/gifs/1.gif") )->mask());
     QMovie* movie=new QMovie(":/gifs/gifs/1.gif");
     ui->lbl_gif1->setMovie(movie);
     movie->start();



















}

offers::~offers()
{
    delete ui;
}

void offers::setBackUser(personal_page1 *back)
{
    this->back_user = back;
    return;
}

void offers::setBackDealer(personal_page2 *back)
{
    this->back_dealer = back;
    return;
}

void offers::on_btn_back_clicked()
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
void offers::closeEvent(QCloseEvent *event)
{
    switch (QMessageBox(tr("Warning!"), tr("Are you sure you want to exit?"), QMessageBox::Warning, QMessageBox::Yes | QMessageBox::Default, QMessageBox::No, QMessageBox::Escape).exec()) {
        case 3: {
            updateFiles();
            event->accept();
            //rewrite files egain...


            break;
        }
        default: {
            event->ignore();
            break;
        }
    }
}
