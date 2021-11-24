#include "rating_product.h"
#include "ui_rating_product.h"

rating_product::rating_product(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rating_product)
{
    ui->setupUi(this);
}

rating_product::~rating_product()
{
    delete ui;
}

void rating_product::on_qpb_1_toggled(bool checked)
{
    if(checked)
    {
        QPixmap pixmap2(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon2(pixmap2);
        ui->qpb_1->setIcon(ButtonIcon2);
        QSize qs(50,50);
        ui->qpb_1->setIconSize(qs);
        ui->qlb_rate->setText("1");
    }
    else
    {
        QPixmap pixmap1(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon1(pixmap1);
        ui->qpb_1->setIcon(ButtonIcon1);
        QSize qs1(50,50);
        ui->qpb_1->setIconSize(qs1);
        ui->qlb_rate->setText("1");


        QPixmap pixmap2(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon2(pixmap2);
        ui->qpb_2->setIcon(ButtonIcon2);
        QSize qs2(50,50);
        ui->qpb_2->setIconSize(qs2);

        QPixmap pixmap3(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon3(pixmap3);
        ui->qpb_3->setIcon(ButtonIcon3);
        QSize qs3(50,50);
        ui->qpb_3->setIconSize(qs3);
        ui->qlb_rate->setText("3");

        QPixmap pixmap4(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon4(pixmap4);
        ui->qpb_4->setIcon(ButtonIcon4);
        QSize qs4(50,50);
        ui->qpb_4->setIconSize(qs4);

        QPixmap pixmap5(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon5(pixmap5);
        ui->qpb_5->setIcon(ButtonIcon5);
        QSize qs5(50,50);
        ui->qpb_5->setIconSize(qs5);



        ui->qlb_rate->setText("0");

    }
}

void rating_product::on_qpb_2_toggled(bool checked)
{
    if(checked)
    {
        QPixmap pixmap1(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon1(pixmap1);
        ui->qpb_1->setIcon(ButtonIcon1);
        QSize qs1(50,50);
        ui->qpb_1->setIconSize(qs1);
        ui->qlb_rate->setText("1");

        QPixmap pixmap2(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon2(pixmap2);
        ui->qpb_2->setIcon(ButtonIcon2);
        QSize qs2(50,50);
        ui->qpb_2->setIconSize(qs2);
        ui->qlb_rate->setText("2");
    }
    else
    {QPixmap pixmap1(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon1(pixmap1);
        ui->qpb_1->setIcon(ButtonIcon1);
        QSize qs1(50,50);
        ui->qpb_1->setIconSize(qs1);
        ui->qlb_rate->setText("1");


        QPixmap pixmap2(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon2(pixmap2);
        ui->qpb_2->setIcon(ButtonIcon2);
        QSize qs2(50,50);
        ui->qpb_2->setIconSize(qs2);

        QPixmap pixmap3(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon3(pixmap3);
        ui->qpb_3->setIcon(ButtonIcon3);
        QSize qs3(50,50);
        ui->qpb_3->setIconSize(qs3);
        ui->qlb_rate->setText("3");

        QPixmap pixmap4(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon4(pixmap4);
        ui->qpb_4->setIcon(ButtonIcon4);
        QSize qs4(50,50);
        ui->qpb_4->setIconSize(qs4);

        QPixmap pixmap5(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon5(pixmap5);
        ui->qpb_5->setIcon(ButtonIcon5);
        QSize qs5(50,50);
        ui->qpb_5->setIconSize(qs5);



        ui->qlb_rate->setText("0");

    }
}

void rating_product::on_qpb_3_toggled(bool checked)
{
    if(checked)
    {
        QPixmap pixmap1(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon1(pixmap1);
        ui->qpb_1->setIcon(ButtonIcon1);
        QSize qs1(50,50);
        ui->qpb_1->setIconSize(qs1);
        ui->qlb_rate->setText("1");

        QPixmap pixmap2(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon2(pixmap2);
        ui->qpb_2->setIcon(ButtonIcon2);
        QSize qs2(50,50);
        ui->qpb_2->setIconSize(qs2);

        QPixmap pixmap3(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon3(pixmap3);
        ui->qpb_3->setIcon(ButtonIcon3);
        QSize qs3(50,50);
        ui->qpb_3->setIconSize(qs3);
        ui->qlb_rate->setText("3");
    }
    else
    {
        QPixmap pixmap1(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon1(pixmap1);
        ui->qpb_1->setIcon(ButtonIcon1);
        QSize qs1(50,50);
        ui->qpb_1->setIconSize(qs1);
        ui->qlb_rate->setText("1");


        QPixmap pixmap2(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon2(pixmap2);
        ui->qpb_2->setIcon(ButtonIcon2);
        QSize qs2(50,50);
        ui->qpb_2->setIconSize(qs2);

        QPixmap pixmap3(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon3(pixmap3);
        ui->qpb_3->setIcon(ButtonIcon3);
        QSize qs3(50,50);
        ui->qpb_3->setIconSize(qs3);
        ui->qlb_rate->setText("3");

        QPixmap pixmap4(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon4(pixmap4);
        ui->qpb_4->setIcon(ButtonIcon4);
        QSize qs4(50,50);
        ui->qpb_4->setIconSize(qs4);

        QPixmap pixmap5(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon5(pixmap5);
        ui->qpb_5->setIcon(ButtonIcon5);
        QSize qs5(50,50);
        ui->qpb_5->setIconSize(qs5);



        ui->qlb_rate->setText("0");

    }
}

void rating_product::on_qpb_4_toggled(bool checked)
{
    if(checked)
    {
        QPixmap pixmap1(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon1(pixmap1);
        ui->qpb_1->setIcon(ButtonIcon1);
        QSize qs1(50,50);
        ui->qpb_1->setIconSize(qs1);
        ui->qlb_rate->setText("1");

        QPixmap pixmap2(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon2(pixmap2);
        ui->qpb_2->setIcon(ButtonIcon2);
        QSize qs2(50,50);
        ui->qpb_2->setIconSize(qs2);

        QPixmap pixmap3(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon3(pixmap3);
        ui->qpb_3->setIcon(ButtonIcon3);
        QSize qs3(50,50);
        ui->qpb_3->setIconSize(qs3);

        QPixmap pixmap4(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon4(pixmap4);
        ui->qpb_4->setIcon(ButtonIcon4);
        QSize qs4(50,50);
        ui->qpb_4->setIconSize(qs4);

        ui->qlb_rate->setText("4");
    }
    else
    {
        QPixmap pixmap1(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon1(pixmap1);
        ui->qpb_1->setIcon(ButtonIcon1);
        QSize qs1(50,50);
        ui->qpb_1->setIconSize(qs1);
        ui->qlb_rate->setText("1");


        QPixmap pixmap2(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon2(pixmap2);
        ui->qpb_2->setIcon(ButtonIcon2);
        QSize qs2(50,50);
        ui->qpb_2->setIconSize(qs2);

        QPixmap pixmap3(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon3(pixmap3);
        ui->qpb_3->setIcon(ButtonIcon3);
        QSize qs3(50,50);
        ui->qpb_3->setIconSize(qs3);
        ui->qlb_rate->setText("3");

        QPixmap pixmap4(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon4(pixmap4);
        ui->qpb_4->setIcon(ButtonIcon4);
        QSize qs4(50,50);
        ui->qpb_4->setIconSize(qs4);

        QPixmap pixmap5(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon5(pixmap5);
        ui->qpb_5->setIcon(ButtonIcon5);
        QSize qs5(50,50);
        ui->qpb_5->setIconSize(qs5);



        ui->qlb_rate->setText("0");
         }

}

void rating_product::on_qpb_5_toggled(bool checked)
{
    if(checked)
    {
        QPixmap pixmap1(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon1(pixmap1);
        ui->qpb_1->setIcon(ButtonIcon1);
        QSize qs1(50,50);
        ui->qpb_1->setIconSize(qs1);
        ui->qlb_rate->setText("1");

        QPixmap pixmap2(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon2(pixmap2);
        ui->qpb_2->setIcon(ButtonIcon2);
        QSize qs2(50,50);
        ui->qpb_2->setIconSize(qs2);

        QPixmap pixmap3(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon3(pixmap3);
        ui->qpb_3->setIcon(ButtonIcon3);
        QSize qs3(50,50);
        ui->qpb_3->setIconSize(qs3);

        QPixmap pixmap4(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon4(pixmap4);
        ui->qpb_4->setIcon(ButtonIcon4);
        QSize qs4(50,50);
        ui->qpb_4->setIconSize(qs4);




        QPixmap pixmap5(":/icon/images/icons8-star-96.png");
        QIcon ButtonIcon5(pixmap5);
        ui->qpb_5->setIcon(ButtonIcon5);
        QSize qs5(50,50);
        ui->qpb_5->setIconSize(qs5);

        ui->qlb_rate->setText("5");
    }
    else
    {
        QPixmap pixmap1(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon1(pixmap1);
        ui->qpb_1->setIcon(ButtonIcon1);
        QSize qs1(50,50);
        ui->qpb_1->setIconSize(qs1);
        ui->qlb_rate->setText("1");


        QPixmap pixmap2(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon2(pixmap2);
        ui->qpb_2->setIcon(ButtonIcon2);
        QSize qs2(50,50);
        ui->qpb_2->setIconSize(qs2);

        QPixmap pixmap3(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon3(pixmap3);
        ui->qpb_3->setIcon(ButtonIcon3);
        QSize qs3(50,50);
        ui->qpb_3->setIconSize(qs3);
        ui->qlb_rate->setText("3");

        QPixmap pixmap4(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon4(pixmap4);
        ui->qpb_4->setIcon(ButtonIcon4);
        QSize qs4(50,50);
        ui->qpb_4->setIconSize(qs4);

        QPixmap pixmap5(":/icon/images/icons8-star-100.png");
        QIcon ButtonIcon5(pixmap5);
        ui->qpb_5->setIcon(ButtonIcon5);
        QSize qs5(50,50);
        ui->qpb_5->setIconSize(qs5);



        ui->qlb_rate->setText("0");
    }

}
