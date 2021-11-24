#include "EditProduct.h"
#include "ui_EditProduct.h"

#include "Global.h"
#include <QString>
#include "FastArrays.h"
#include <QMessageBox>
#include "CategoryDatas.h"
using namespace GlobalNameSpace;



EditProduct::EditProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProduct)
{

    ui->setupUi(this);

   NodeProduct *p_node =  &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
   Product p_data = p_node->getData();


    for (int i = 0; i < 31; i++){
        ui->stateCombo->addItem(statesList[i]);
    }
    ui->stateCombo->setCurrentText(p_data.getState());

    for (int i = 0; i < 11; i++){
        ui->colorCombo->addItem(colorList[i]);
    }
    ui->colorCombo->setCurrentText(p_data.getColor());

    for (int i = 0; i < 16; i++){
        ui->categoryCombo_2->addItem(LIST_CATEGORY[i]);
    }

    ui->titleL->setText("<font color='red'>Title: </font>");
    ui->priceL->setText("<font color='red'>Sell Price: </font>");
    ui->stateL->setText("<font color='red'>State: </font>");
    ui->colorL->setText("<font color='red'>Color: </font>");
    ui->numberL->setText("<font color='red'>Available Number: </font>");
    ui->categoryL_2->setText("<font color='red'>Category: </font>");


    ui->sellPriceE->setValidator( new QIntValidator(0, 1000000000, this) );
    ui->numberE->setValidator( new QIntValidator(0, 1000000000, this) );
    ui->offPercentE->setValidator( new QIntValidator(0, 10, this) );


    ui->titleE->setPlaceholderText(p_data.getName());
    ui->creatorE->setPlaceholderText(p_data.getCreator());
    ui->sellPriceE->setPlaceholderText(QString::number(p_data.getSellPrice()));
    ui->numberE->setPlaceholderText(QString::number(p_data.getAvailableNumber()));
    ui->descriptionE->setPlaceholderText(p_data.getDescription());
    ui->offPercentE->setPlaceholderText(QString::number(p_data.getOffPercent()));
}

EditProduct::~EditProduct()
{
    delete ui;
}

void EditProduct::on_confirmB_clicked()
{

    NodeProduct* temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    Product p = temp->getData();

    if (ui->titleE->text() == "")
        p.setName(ui->titleE->placeholderText());
    else
        p.setName(ui->titleE->text());


    p.setColor(ui->colorCombo->currentText());
    p.setState(ui->stateCombo->currentText());

    if (ui->creatorE->text() == "")
        p.setCreator(ui->creatorE->placeholderText());
    else
        p.setCreator(ui->creatorE->text());

    if (ui->sellPriceE->text() == "")
        p.setSellPrice(ui->sellPriceE->placeholderText().toDouble());
    else
        p.setSellPrice(ui->sellPriceE->text().toDouble());

    if (ui->offPercentE->text() == "")
        p.setOffPercent(ui->offPercentE->placeholderText().toFloat());
    else
        p.setOffPercent(ui->offPercentE->text().toFloat());

    if (ui->numberE->text() == "")
        p.setAvailableNumber(ui->numberE->placeholderText().toUInt());
    else
        p.setAvailableNumber(ui->numberE->text().toUInt());

    if (ui->descriptionE->text() == "")
        p.setDescription(ui->descriptionE->placeholderText());
    else
        p.setDescription(ui->descriptionE->text());

    p.setNameCategory(ui->categoryCombo_2->currentText());

    double purePrice = (double)(p.getSellPrice() * (1 - p.getOffPercent() / 100));
    p.setPureSellPrice(purePrice);

    temp->setData(p); // Edit this product on LinkedListProduct

    Globals::PRODUCT_LIST.print();
    TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
    Dealer d_data = d_node->getData();

    d_data.deleteProductToListOfSell(p);
    d_data.addKeyToListOfSell(p);
    d_node->setData(d_data);  // Edit this product on DealerList

    Globals::DEALER_LIST.writeToFileUser();
    Globals::PRODUCT_LIST.writeFile();

    QMessageBox::information(this, "Done", "Product edited.");
    this->close();
}


void EditProduct::on_cancelB_clicked()
{
    this->close();
}
