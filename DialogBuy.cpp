#include "DialogBuy.h"
#include "ui_DialogBuy.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTextStream>
using namespace GlobalNameSpace;


DialogBuy::DialogBuy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBuy)
{
    ui->setupUi(this);

    resize(500, 600);

    ui->numberE->setValidator( new QIntValidator(0, 1000000000, this) );

    refresh();

}

DialogBuy::~DialogBuy()
{
    delete ui;
}

void DialogBuy::on_confirmB_clicked()
{


    if (!ui->numberE->text().isEmpty() && ui->numberE->text().toUInt() > 0){

        refresh();

        unsigned int number = ui->numberE->text().toUInt();
        double cost = (double) number * p.getPureSellPrice();

        if (number <= p.getAvailableNumber()){

            if ((Globals::TYPE_USER == DEALER && dealer_buyer.getMoney() >= cost) ||
                    (Globals::TYPE_USER == USER && user_buyer.getMoney() >= cost) ){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this,"", "Total Cost: " + QString::number(cost) + "\nAre you sure?",
                                              QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                    /////////////////////////////////////////////////////////////////////////// set data of product
                    p.setAvailableNumber(p.getAvailableNumber() - number);
                    p.setSoldNumber(p.getSoldNumber() + number);

                    NodeProduct* temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
                    temp->setData(p); // Edit this product on LinkedListProduct

                    Globals::PRODUCT_LIST.print();
                    /////////////////////////////////////////////////////////////////////////// set data of product
                    ///
                    ///
                    ///
                    /////////////////////////////////////////////////////////////////////////// set data of seller

                    const unsigned long long KEY_SELLER = p.getKeySeller();
                    TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(KEY_SELLER);
                    Dealer dealer_seller = d_node->getData();

                    dealer_seller.deleteProductToListOfSell(p);
                    dealer_seller.addKeyToListOfSell(p); // remove previous product on DealerList
                    dealer_seller.setMoney(dealer_seller.getMoney() + cost);
                    d_node->setData(dealer_seller);  // add new product on DealerList
                    /////////////////////////////////////////////////////////////////////////// set data of seller
                    ///
                    ///
                    ///
                    /////////////////////////////////////////////////////////////////////////// set data of buyer


                    if (Globals::TYPE_USER == DEALER){

                        TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
                        dealer_buyer.addKeyToListOfBuyBefore(p);
                        dealer_buyer.setMoney(dealer_buyer.getMoney() - cost);
                        d_node->setData(dealer_buyer);
                        ui->accountL->setText(QString::number(dealer_buyer.getMoney(), 'f', 1));
                    }
                    else{

                        TNodeUser<Users>* d_node = &Globals::USER_LIST.getByKey(Globals::KEY_USER);
                        user_buyer.addKeyToListOfBuyBefore(p);
                        user_buyer.setMoney(user_buyer.getMoney() - cost);
                        d_node->setData(user_buyer);
                        ui->accountL->setText(QString::number(user_buyer.getMoney(), 'f', 1));
                        Globals::USER_LIST.writeToFileUser();
                    }


                    Globals::DEALER_LIST.writeToFileUser();
                    Globals::PRODUCT_LIST.writeFile();

                    QMessageBox::information(this, "Done", "Product Bought.");
                    close();
                }
            }else{
                QMessageBox::critical(this, "Failed", "Your budget is not enough.");
            }
        }else{
            QMessageBox::critical(this, "Failed", "This product has only " + QString::number(p.getAvailableNumber()) + " items available.");
        }
    }else{
        QMessageBox::critical(this, "Failed", "Mention the number first!");
    }
}



void DialogBuy::on_cancelB_clicked()
{
    close();
}



void DialogBuy::refresh(){

    NodeProduct* temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    p = temp->getData();
    ui->availableNumberL->setText(QString::number(p.getAvailableNumber()));
    ui->priceL->setText(QString::number(p.getPureSellPrice()));

    if (Globals::TYPE_USER == DEALER){

        TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
        dealer_buyer = d_node->getData();
        ui->accountL->setText(QString::number(dealer_buyer.getMoney(), 'f', 1));
    }
    else{

        TNodeUser<Users>* d_node = &Globals::USER_LIST.getByKey(Globals::KEY_USER);
        user_buyer = d_node->getData();
        ui->accountL->setText(QString::number(user_buyer.getMoney(), 'f', 1));
    }
}
