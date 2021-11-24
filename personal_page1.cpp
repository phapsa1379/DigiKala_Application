#include "personal_page1.h"
#include "ui_personal_page1.h"
#include "login.h"
#include <QLabel>
#include <QTextDocument>
#include <QtGui>
#include "DetailUser.h"
#include <QMessageBox>
#include "ExternalFunctions.h"
#include "Global.h"
#include "ListOfProducts.h"
#include "ListSettingsProduct.h"
#include "CategoryDatas.h"
#include "common_questions.h"
#include "ReportDialog.h"
#include "offers.h"
#include "ContactListDialog.h"

using namespace GlobalNameSpace;




personal_page1::personal_page1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::personal_page1)
{
    ui->setupUi(this);


  //connect(xButton,SIGNAL(clicked()),this,xButtonPressed()));





}

personal_page1::~personal_page1()
{
    delete ui;
}

void personal_page1::on_actionSign_Out_2_triggered()
{
    if(this->close())
    {
     login* lgi=new login();
     lgi->show();
    }

}

void personal_page1::on_actionCommon_Questions_triggered()
{
    common_questions* cq=new common_questions();
    cq->setBackUser(this);
    cq->setWindowTitle("Common Questions");
    cq->show();  
    this->hide();
}

/*void personal_page1::on_actionDiscounts_and_Offers_triggered()
{
    offers* off = new offers();
    off->setBackUser(this);
    off->setWindowTitle("Publicity");
    off->show();
    this->hide();

}*/

void personal_page1::on_actionEdit_Profile_triggered()
{

    EditProfile* ep=new EditProfile();
    ep->setModal(true);
    ep->setWindowTitle("Edit Profile ");
    ep->show();

}


void personal_page1::on_actionView_Account_triggered()
{
    DetailUser* du=new DetailUser();
    du->setModal(true);
    du->setWindowTitle("Profile Details ");
    du->show();
}

void personal_page1::closeEvent(QCloseEvent *event)
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

void personal_page1::on_actionTotal_list_of_goods_triggered()
{
    ListSettingsProduct::setCategory(ALL_CATEGORIES);
    Globals::TARGET_PRODUCT_LIST=ALL_SYSTEM_PRODUCTS;
    ListOfProducts* d = new ListOfProducts();
    d->setBackUser(this);
    this->hide();
    d->show();
}

void personal_page1::on_actionFavourites_triggered()
{
    Globals::TARGET_PRODUCT_LIST=MY_FAVORITE_PRODUCTS;
    ListOfProducts* d = new ListOfProducts();
    d->setBackUser(this);
    this->hide();
    d->show();



}

void personal_page1::on_actionBought_Basket_triggered()
{
    Globals::TARGET_PRODUCT_LIST=MY_BOUGHT_PRODUCTS;
    ListOfProducts* d = new ListOfProducts();
    d->setBackUser(this);
    this->hide();
    d->show();
}
///////left iconst :
///
///
///
void personal_page1::on_actionDigital_triggered()
{
    ListSettingsProduct::setCategory(DIGITAL);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}









/*
DIGITAL = "Digital";
const QString MAKE_UP = "Make up";
const QString HEALTH = "Health";
const QString CAR = "Car";
const QString OFFICE_EQUIPMENT = "Office Equipment";
const QString CLOTHES = "Clothes";
const QString HOUSE = "House";
const QString KITCHEN = "Kitchen";
const QString BOOK = "Book";
const QString STATIONERY = "Stationery";
const QString ART = "Art";
const QString TOYS = "Toys";
const QString CHILDREN = "Children";
const QString SPORT = "Sport";
const QString TRIP = "Trip";
const QString NUTRITION = "Nutrition";

*/
void personal_page1::on_actionHealth_triggered()
{
    ListSettingsProduct::setCategory(HEALTH);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionMake_up_triggered()
{

    ListSettingsProduct::setCategory(MAKE_UP);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionCar_triggered()
{

    ListSettingsProduct::setCategory(CAR);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionOffice_Equipment_triggered()
{
    ListSettingsProduct::setCategory(OFFICE_EQUIPMENT);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionHouse_triggered()
{
    ListSettingsProduct::setCategory(HOUSE);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionKitchen_triggered()
{
    ListSettingsProduct::setCategory(KITCHEN);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionBook_triggered()
{
    ListSettingsProduct::setCategory(BOOK);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionArt_triggered()
{
    ListSettingsProduct::setCategory(ART);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionStationary_triggered()
{
    ListSettingsProduct::setCategory(STATIONERY);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionToys_triggered()
{
    ListSettingsProduct::setCategory(TOYS);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionChildren_triggered()
{
    ListSettingsProduct::setCategory(CHILDREN);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionSport_triggered()
{
    ListSettingsProduct::setCategory(SPORT);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionTrip_triggered()
{

    ListSettingsProduct::setCategory(TRIP);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionClothes_triggered()
{
      ListSettingsProduct::setCategory(CLOTHES);
      Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
      ListOfProducts* list = new ListOfProducts();
      list->setBackUser(this);
      this->hide();
      list->show();
}

void personal_page1::on_actionNutrition_triggered()
{
    ListSettingsProduct::setCategory(NUTRITION);
    Globals::TARGET_PRODUCT_LIST = ALL_SYSTEM_PRODUCTS;
    ListOfProducts* list = new ListOfProducts();
    list->setBackUser(this);
    this->hide();
    list->show();
}

void personal_page1::on_actionChats_2_triggered()
{

    ContactListDialog* off = new ContactListDialog();
    //off->setBackUser(this);
    off->show();
    this->hide();
}

void personal_page1::on_actionView_Report_triggered()
{

    if (Globals::REPORT_LIST.size() > 0){
        ReportDialog* d = new ReportDialog(this);
        d->setModal(true);
        d->setWindowTitle("List Of Reports");
        d->scroll->setWindowTitle("List Of Reports");

        d->scroll->setMinimumSize(800,600);
        d->scroll->show();


    }
    else{
        QMessageBox::information(this, "Empty", "Ther are no reports here.");
    }
}

void personal_page1::on_actionDiscounts_and_Offers_triggered()
{
    offers* off = new offers();
    off->setBackUser(this);
    off->setWindowTitle("Publicity");
    off->show();
    this->hide();




}
