#include <QMessageBox>
#include "login.h"
#include "ui_login.h"
//#include "TNodeUser.h"
#include "TLinkedListUser.h"
#include "ExternalFunctions.h"
#include "Global.h"
#include "signup.h"
#include "forgot_password.h"
#include "EditProfileUser.h"
#include "personal_page2.h"
#include <time.h>
#include <stdlib.h>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QtCore/qmath.h>
#include <QFile>
#include <QDir>
#include <QTimer>
#include <QLabel>
#include <QtGui>
using namespace GlobalNameSpace;

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);


    //***************************************************************captcha

    ui->qle_username->setFocus();


    QPixmap butPixmap(":/icon/images/button.png");
    QIcon butIcon(butPixmap);

    qApp->setStyleSheet("#pushButton_2{border:5px;}");

    //this->setWindowFlags(Qt::FramelessWindowHint);
    if(!QDir("pics").exists())
        QDir().mkdir("pics");



    srand(time(NULL));
    long int a1,a2,a3,a4,a5;
    a1=(1+rand()%9)*10000;
    a2=(1+rand()%9)*1000;
    a3=(rand()%10)*100;
    a4=(1+rand()%9)*10;
    a5=(rand()%10);
    a=a1+a2+a3+a4+a5;
    QString inText=QString::number(a);

    QFile newpic("pics/"+inText+".png");
    newpic.open(QIODevice::WriteOnly);
    qDebug() << "pics/"+inText+".png";
    distortImg(makeImg(inText)).save(&newpic,"PNG");

    //**************************************************captcha




}











//*****************************************************************captcha




QPixmap login::makeImg(QString inText){
    QPixmap pixmap(300,150);
    pixmap.fill(Qt::blue);

    QPainter painter(&pixmap);
    painter.setPen(Qt::green);
    painter.setFont(QFont("Arial",45));
    painter.drawText(15,90,inText);


    return pixmap;
}

QPixmap login::distortImg(QPixmap pixmap)
{
    QImage pixmapImg = pixmap.toImage();
    QPixmap pixmap2(pixmap.width(),pixmap.height());
    QPainter painter2(&pixmap2);

    // Distort text
    for(int x = 0; x < pixmap.width(); x++){
        for(int y = 0; y < pixmap.height(); y++){
            qsrand(x);
            float rand1 = qrand()%5;
            qsrand(y);
            float rand2 = qrand()%5;
            float sinx = sin(x/10+1)*5;
            float siny = qSin(y/10)*5;
            int newx = x+rand1+sinx;
            int newy = y+rand2+siny;
            if(newx < pixmap.width() && newy < pixmap.height()){
                if(rand1+rand2 > 1) {
                    painter2.setPen(pixmapImg.pixel(newx,newy));
                } else {
                    painter2.setPen(Qt::green);
                    painter2.drawRect(x,y,10,10);
                }
                painter2.drawRect(x,y,1,1);

            }
        }
    }

    ui->label->setPixmap(pixmap2);

    return pixmap2;

}



//********************************************************************captcha


void login::setLogin(login *log)
{
    this->l = log;
    return;
}

login *login::getLogin()
{
    return this->l;
}

login::~login()
{
    delete ui;
}


void login::on_qpb_signup_clicked()
{


    signup sign;
    sign.setModal(true);
    sign.setWindowTitle("Which one do you choose?");
    sign.setLastPage(this);
    sign.exec();

}

void login::on_pushButton_clicked()
{

    forgot_password fp;
    fp.setModal(true);
    fp.setWindowTitle("Are you forgon your password ?");
    fp.setLastPage(this);

    this->hide();
    fp.exec();

}

void login::on_actionExit_3_triggered()
{
    Globals::USER_LIST.writeToFileUser();
    Globals::DEALER_LIST.writeToFileUser();

    this->close();
}

void login::on_actionReset_2_triggered()
{
    this->hide();
    l=new login();
    l->show();
}

void login::on_actionHelp_triggered()
{

    h=new help();
    h->setWindowTitle("Help");
    h->setModal(true);
    h->show();

}

void login::on_actionAbout_triggered()
{
    ab=new about();
    ab->setWindowTitle("About");
    ab->show();
}

void login::on_qpb_signin_clicked()//******************************************************sign in
{
    QString captcha=QString::number(a);//captcha
    personal_page1* p1 = new personal_page1();
    personal_page2* p2 = new personal_page2();

    p1->setWindowTitle("Personal Page");
    p2->setWindowTitle("Personal Page");

    QString username = this->ui->qle_username->text();
    QString pass= this->ui->qle_password->text();
    long long k_user = Globals::USER_LIST.isInclude(username , pass);
    long long k_dealer = Globals::DEALER_LIST.isInclude(username,pass);


    if(k_user != -1)
    {
        if(captcha==ui->led_captcha->text())
        {
            //*******************welcome

            QLabel* qlb_use=new QLabel();
            this->hide();
            qlb_use->setGeometry(300,150,1270,700);
            qlb_use->setWindowFlag(Qt::FramelessWindowHint);
            qlb_use->setMask((new QPixmap(":/gifs/gifs/main.gif") )->mask());
            QMovie* movie=new QMovie(":/gifs/gifs/main.gif");
            qlb_use->setMovie(movie);
            movie->start();
            qlb_use->show();
            QTimer *timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), qlb_use, SLOT(close()));
            timer->start(13000);


            //**************************welcome

            Globals::KEY_USER= k_user;
            TNodeUser<Users> *node = &Globals::USER_LIST.getByKey(Globals::KEY_USER);

            Users usr = node->getData();
            //if(usr.getUserName() == username && usr.getPassword() == pass)
            //{
            Globals::TYPE_USER = USER;
            usr.setDateOfLastEnter(NowTime());
            //KEY_USER = usr.getKey();

            // THIS_USER =usr;
            node->setData(usr);


            QTimer::singleShot(13000, p1, SLOT(show())); //***************************************QTimer


            return;


        }
        else
        {
            QMessageBox::information(this,"captcha","Captcha is wrong");
        }




    }

    else if(k_dealer!= -1)
    {
        if(captcha==this->ui->led_captcha->text())
        {

            //*******************welcome

            QLabel* qlb_dea=new QLabel();
            this->hide();
            qlb_dea->setGeometry(300,150,1270,700);
            qlb_dea->setWindowFlag(Qt::FramelessWindowHint);
            qlb_dea->setMask((new QPixmap(":/gifs/gifs/main.gif") )->mask());
            QMovie* movie=new QMovie(":/gifs/gifs/main.gif");
            qlb_dea->setMovie(movie);
            movie->start();
            qlb_dea->show();
            QTimer *timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), qlb_dea, SLOT(close()));
            timer->start(13000);


            //**************************welcome

            Globals::KEY_USER = k_dealer;
            TNodeUser<Dealer> *node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
            Dealer usr = node->getData();
            Globals::TYPE_USER = DEALER;
            usr.setDateOfLastEnter(NowTime());


            node->setData(usr);

            QTimer::singleShot(13000, p2, SLOT(show())); //***************************************QTimer

            return;


        }
        else
        {
            QMessageBox::information(this,"captcha","Captcha is wrong");
        }


    }
    else
    {
        QMessageBox::warning(this,"failed !","Your password or usersname not correct !");
    }





}

void login::on_qpb_replace_clicked()
{
    srand(time(NULL));
    long int a1,a2,a3,a4,a5;
    a1=(1+rand()%9)*10000;
    a2=(1+rand()%9)*1000;
    a3=(rand()%10)*100;
    a4=(1+rand()%9)*10;
    a5=(rand()%10);
    a=a1+a2+a3+a4+a5;

    QString inText=QString::number(a);

    //QString inText = ui->lineEdit->text();
    QFile newpic("pics/"+inText+".png");
    newpic.open(QIODevice::WriteOnly);
    qDebug() << "pics/"+inText+".png";
    distortImg(makeImg(inText)).save(&newpic,"PNG");

}

void login::on_qpb_show_password_toggled(bool checked)
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

void login::closeEvent(QCloseEvent *event) {
    switch (QMessageBox(tr("Warning!"), tr("Are you sure you want to exit?"), QMessageBox::Warning, QMessageBox::Yes | QMessageBox::Default, QMessageBox::No, QMessageBox::Escape).exec()) {
    case 3: {
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
void login::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        on_qpb_signin_clicked();
    }

}
