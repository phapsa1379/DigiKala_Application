#include "RatingDialog.h"
#include "ui_RatingDialog.h"
#include "Global.h"
#include "DetailOfBoughtProducts.h"
#include <QMessageBox>
using namespace GlobalNameSpace;


RatingDialog::RatingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RatingDialog)
{
    ui->setupUi(this);

    NodeProduct *temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    p = temp->getData();

    ui->totalRatingL->setText(QString::number(p.getRating()));
    ui->yourRateSpin->setRange(1, 5);

    if (DetailOfBoughtProducts::givenRating > 0){
        ui->yourRateSpin->setValue(DetailOfBoughtProducts::givenRating);
    }



}



RatingDialog::~RatingDialog()
{
    delete ui;
}


void RatingDialog::on_confirmB_clicked()
{

    NodeProduct *temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    p = temp->getData();

    float totalRating = (float)(p.getRating() * p.getVoteNumber() - DetailOfBoughtProducts::givenRating);

    if (DetailOfBoughtProducts::givenRating == 0){
        p.setVoteNumber(p.getVoteNumber() + 1);
    }

    DetailOfBoughtProducts::givenRating = ui->yourRateSpin->value();
    totalRating += (float) DetailOfBoughtProducts::givenRating;
    float aveRating = (float) (totalRating / p.getVoteNumber());
    p.setRating(aveRating);

    if (Globals::TYPE_USER == DEALER){

        TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
        Dealer d_data = d_node->getData();

        d_data.deleteProductFromListOfBuyBefore(p);
        d_data.addKeyToListOfBuyBefore(p);

        ////////////////////////////////////////////// Added By Arash
        if (d_data.getListOfInterestKeyLinkedList().containsKey(p.getKey())){
            d_data.deleteProductToListOfInterest(p);
            d_data.addKeyToListOfInterest(p);
        }
        //////////////////////////////////////////////

        d_node->setData(d_data);

        Globals::DEALER_LIST.writeToFileUser();
    }

    else{

        TNodeUser<Users>* d_node = &Globals::USER_LIST.getByKey(Globals::KEY_USER);
        Users d_data = d_node->getData();

        d_data.deleteProductFromListOfBuyBefore(p);
        d_data.addKeyToListOfBuyBefore(p);

        ////////////////////////////////////////////// Added By Arash
        if (d_data.getListOfInterestKeyLinkedList().containsKey(p.getKey())){
            d_data.deleteProductToListOfInterest(p);
            d_data.addKeyToListOfInterest(p);
        }
        //////////////////////////////////////////////

        d_node->setData(d_data);

        Globals::USER_LIST.writeToFileUser();
    }

    temp->setData(p);
    Globals::PRODUCT_LIST.writeFile();
    QMessageBox::information(this, "Done", "Thank you for your review");
    close();
}


void RatingDialog::on_cancelB_clicked()
{
    close();
}


