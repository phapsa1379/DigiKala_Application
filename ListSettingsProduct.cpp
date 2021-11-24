#include "ListSettingsProduct.h"
#include "ui_ListSettingsProduct.h"

#include "EnumsProduct.h"
#include "FastArrays.h"
#include <QMessageBox>
#include "Global.h"
#include "CategoryDatas.h"
using namespace GlobalNameSpace;


QString ListSettingsProduct::sortBasedOn = ASCENDING;
QString ListSettingsProduct::sortType = NAME_PRODUCT;
QString ListSettingsProduct::group = ALL_PRODUCTS;
QString ListSettingsProduct::state = "All States";
QString ListSettingsProduct::category = ALL_CATEGORIES;
double ListSettingsProduct::utmostPrice = 2000000000;


ListSettingsProduct::ListSettingsProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListSettingsProduct)
{
    // NAME_PRODUCT, RATING, SOLD_NUMBER, SELL_PRICE, REMOVE_DATE_PRODUCT, COMPLAIN_NUMBER;
    /*  enum sort_factor {NAME_PRODUCT, RATING, SOLD_NUMBER, SELL_PRICE, REMOVE_DATE_PRODUCT, COMPLAIN_NUMBER};
    enum sort_type{ASCENDING, DESCENDING};
    enum sort_advanced{ALL_PRODUCTS, WITH_OFF_PERCENT};*/

    ui->setupUi(this);

//////////////////////////////////////////////////////////////Start Of Preparations
    setWindowTitle("Filter Settings");

    ui->sortBasedCombo->addItem(NAME_PRODUCT);
    ui->sortBasedCombo->addItem(RATING);
    ui->sortBasedCombo->addItem(SOLD_NUMBER);
    ui->sortBasedCombo->addItem(SELL_PRICE);
    ui->sortBasedCombo->addItem(REGISTERATION_DATE);
    ui->sortBasedCombo->addItem(VIEW_NUMBER);

    ui->ascendingRadio->setCheckable(true);
    ui->descendingRadio->setCheckable(true);

    ui->allRadio->setCheckable(true);
    ui->withOffRadio->setCheckable(true);

    for (int i = 0 ; i < 32; i++)
        ui->stateCombo->addItem(statesList[i]);

    ui->priceE->setText(QString::number(utmostPrice, 'f', 1));
    ui->label->setStyleSheet("QLabel { background-color : #00bfff	; color : #4d3900	;font-weight: bold;font-size: 16px;font-family: Arial; }");
////////////////////////////////////////////////////////////////End Of Preparations





    if (sortType == ASCENDING)
        ui->ascendingRadio->setChecked(true);
    else
        ui->descendingRadio->setChecked(true);


    ui->sortBasedCombo->setCurrentText(sortBasedOn);


    if (group == WITH_OFF_PERCENT)
        ui->withOffRadio->setChecked(true);
    else
        ui->allRadio->setChecked(true);

    ui->stateCombo->setCurrentText(state);

}

ListSettingsProduct::~ListSettingsProduct()
{
    delete ui;
}


QString ListSettingsProduct::getSortBasedOn(){
    return sortBasedOn;
}

QString ListSettingsProduct::getSortType(){
    return sortType;
}

QString ListSettingsProduct::getGroup(){
    return group;
}

QString ListSettingsProduct::getState(){
    return state;
}

QString ListSettingsProduct::getCategory(){
    return category;
}

double ListSettingsProduct::getUtmostPrice(){
    return utmostPrice;
}





void ListSettingsProduct::setSortBasedOn(QString a){
    sortBasedOn = a;
    return;
}

void ListSettingsProduct::setSortType(QString a){
    sortType = a;
    return;
}

void ListSettingsProduct::setGroup(QString a){
    group = a;
    return;
}

void ListSettingsProduct::setCategory(QString a){
    category = a;
    return;
}

void ListSettingsProduct::setState(QString a){
    state = a;
    return;
}

void ListSettingsProduct::setUtmostPrice(double a){
    utmostPrice = a;
    return;
}


void ListSettingsProduct::on_confirmB_clicked()
{

    sortBasedOn = ui->sortBasedCombo->currentText();

    if(ui->ascendingRadio->isChecked())
        sortType = ASCENDING;
    else
        sortType = DESCENDING;

    if(ui->allRadio->isChecked())
        group = ALL_PRODUCTS;
    else
        group = WITH_OFF_PERCENT;

    utmostPrice = ui->priceE->text().toDouble();

    state = ui->stateCombo->currentText();

    QMessageBox::information(this, "Done", "Settings applied.");
    //added by navid:
    this->close();

}







void ListSettingsProduct::filterList(){ // This function is called only for the list list of all produccts
    // available in system.

    if (sortType == ASCENDING){
        Globals::PRODUCT_LIST.sortAscending(sortBasedOn);
    }else{
        Globals::PRODUCT_LIST.sortDescending(sortBasedOn);
    }

    const int SIZE = Globals::PRODUCT_LIST.size();

    ProductDelegateClass pdc;

    for (int i = 0; i < SIZE; i++){

        Product p = Globals::PRODUCT_LIST.get(i);

        if (p.getComplainNumber() > 2){
            continue;
        }
        if (p.getActiveCondition() != PUBLIC){
            continue;
        }
        if (category != ALL_CATEGORIES && p.getNameCategory() != category){
            continue;
        }
        if (state != "All States" && p.getState() != state && p.getState() != "All States"){
            continue;
        }
        if (p.getPureSellPrice() > utmostPrice){
            continue;
        }
        if (group == WITH_OFF_PERCENT && p.getOffPercent() == 0){
            continue;
        }

        pdc = p;
        Globals::DELEGATED_VECTOR_PRODUCT.push_back(pdc);
    }   
}




void ListSettingsProduct::on_cancelB_clicked()
{
    this->close();
}
