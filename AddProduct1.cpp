#include "AddProduct1.h"
#include "ui_AddProduct1.h"
#include "Global.h"
#include <QString>
#include "FastArrays.h"
#include <QMessageBox>
#include "Dealer.h"
#include "TNodeUser.h"
#include "ExternalFunctions.h"
#include "CategoryDatas.h"
using namespace GlobalNameSpace;

AddProduct1::AddProduct1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProduct1)
{
    ui->setupUi(this);
    setWindowTitle("Add Product");

    for (int i = 0; i < 32; i++){
        ui->stateCombo->addItem(statesList[i]);
    }
    for (int i = 0; i < 11; i++){
        ui->colorCombo->addItem(colorList[i]);
    }
    for (int i = 0; i < 16; i++){
        ui->categoryCombo->addItem(LIST_CATEGORY[i]);
    }

    ui->titleL->setText("<font color='red'>Title: </font>");
    ui->priceL->setText("<font color='red'>Sell Price: </font>");
    ui->stateL->setText("<font color='red'>State: </font>");
    ui->colorL->setText("<font color='red'>Color: </font>");
    ui->numberL->setText("<font color='red'>Available Number: </font>");
    ui->categoryL->setText("<font color='red'>Category: </font>");

    ui->sellPriceE->setValidator(new QDoubleValidator(0, 100000000000 , 10, this));
    ui->numberE->setValidator( new QIntValidator(0, 1000000000, this) );

}

AddProduct1::~AddProduct1()
{
    delete ui;
}


void AddProduct1::on_confirmB_clicked()
{

    if (ui->titleE->text().isEmpty() || ui->sellPriceE->text().isEmpty()
            || ui->numberE->text().isEmpty()){

        QMessageBox::critical(this, "Failed", "Some necessary fields aren't mentioned!");

    }else{
        // Register and save this product:

        Product p;
        p.setName(ui->titleE->text());
        p.setDateOfCreation(ui->dateE->text());
        p.setNameCategory(ui->categoryCombo->currentText());
        p.setColor(ui->colorCombo->currentText());
        p.setState(ui->stateCombo->currentText());
        p.setCreator(ui->creatorE->text());
        p.setSellPrice(ui->sellPriceE->text().toDouble());
        p.setPureSellPrice(ui->sellPriceE->text().toDouble());
        p.setAvailableNumber(ui->numberE->text().toUInt());
        p.setDateOfRegister(NowTime());
        p.setDescription(ui->descriptionE->text());


        p.setKeySeller(Globals::KEY_USER);
        p.setKey(createKeyProduct());
        Globals::PRODUCT_LIST.pushBack(p);
        Globals::PRODUCT_LIST.writeFile();

        TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
        Dealer d_data = d_node->getData();

        d_data.addKeyToListOfSell(p);
        d_node->setData(d_data);
        /////////////////////////////////////////////////////////////
        d_data.getListOfSellLinkList().print();
        /////////////////////////////////////////////////////////////

        TNodeUser<Dealer>* d_node1 = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
        Dealer d_data1 = d_node1->getData();
        d_data1.getListOfSellLinkList().print();

        // d_data.getListOfSellLinkList().print();
     //   d_data.printDealer();
        Globals::DEALER_LIST.writeToFileUser();

        QMessageBox::information(this, "Done", "New product registered.");
        //add by navid
        close();
    }
}

void AddProduct1::on_cancelB_clicked()
{
    this->close();
}
