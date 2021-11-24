#include "ListOfProducts.h"
#include "ui_ListOfProducts.h"
#include <QMessageBox>
#include "Global.h"
#include "StarDelegate.h"
#include <QTableWidget>
#include "ListSettingsProduct.h"
#include "ExternalFunctions.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <QCloseEvent>

using namespace GlobalNameSpace;

ListOfProducts::ListOfProducts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOfProducts)
{
    ui->setupUi(this);


    ui->qpb_search->setFocus();
    ui->qpb_search->focusProxy();
    ui->qpb_search->focusPolicy();
    ui->qle_search_in_digikala->setFocus();

    tableWidget = new QTableWidget(Globals::PRODUCT_LIST.size(), 6);

    refresh();
}

ListOfProducts::~ListOfProducts()
{
    delete ui;
}

void ListOfProducts::closeEvent(QCloseEvent *event) {
    switch (QMessageBox(tr("Warning!"), tr("Are you sure you want to exit?"), QMessageBox::Warning, QMessageBox::Yes | QMessageBox::Default, QMessageBox::No, QMessageBox::Escape).exec())
    {
       case 3:
    {
     updateFiles();
     event->accept();

  //rewrite files egain...


            break;
        }
        default:
    {

           event->ignore();
           break;
        }
    }
}

void ListOfProducts::setBackUser(personal_page1 *back)
{
    this->back_user = back;
    return;
}

void ListOfProducts::setBackDealer(personal_page2 *back)
{
    this->back_dealer = back;
    return;
}

void ListOfProducts::on_btn_back_clicked()
{
    if(Globals::TYPE_USER == USER)
        this->back_user->show();
    else if(Globals::TYPE_USER==DEALER)
        this->back_dealer->show();

    this->hide();
}








void ListOfProducts::refresh(){

    QString target = this->ui->qle_search_in_digikala->text();
    QHBoxLayout *search_layout = new QHBoxLayout;
    QHBoxLayout * btn_layout = new QHBoxLayout;
    QGridLayout * all_layout = new QGridLayout;

    tableWidget->setItemDelegate(new StarDelegate);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setHorizontalHeaderLabels({"           Name           "
                                            , "           Company/Creator           "
                                            , "          View Number          ",
                                            "               Price               ",
                                            "          Available Number           ",
                                            "             Rating                "});

    switch (Globals::TARGET_PRODUCT_LIST)
    {

    case ALL_SYSTEM_PRODUCTS:
        setWindowTitle("Main List Of Products");
        TableWidgetAll(tableWidget , target);
        break;

    case MY_SELL_PRODUCTS:
        setWindowTitle("My Products On Sale");
        TableWidgetSold(tableWidget , target);
        break;

    case MY_BOUGHT_PRODUCTS:
        setWindowTitle("My Bought Products");
        TableWidgetBought(tableWidget , target);
        break;

    case MY_FAVORITE_PRODUCTS:
        setWindowTitle("My Favorite Products");
        TableWidgetFavorites(tableWidget , target);
        break;
    }

    tableWidget->resizeColumnsToContents();
    //    tableWidget->resize(800, 600);


    search_layout->addWidget(ui->qpb_search);
    search_layout->addWidget(ui->qle_search_in_digikala);


    btn_layout->addWidget(ui->btn_back);
    btn_layout->addWidget(ui->btn_filter);
    btn_layout->addWidget(ui->refreshB);
    btn_layout->addItem(search_layout);


    all_layout->addItem(btn_layout , 0 ,0);
    all_layout->addWidget(tableWidget);
    //all_layout->addItem(btn_layout);

   // resize(850, 800);
    setLayout(all_layout);
}








void ListOfProducts::on_btn_filter_clicked()
{
    ListSettingsProduct * filter = new ListSettingsProduct();
    filter->setModal(true);
    filter->show();
}

void ListOfProducts::on_refreshB_clicked()
{
    refresh();
    refresh();
}
/*
void ListOfProducts::on_qle_search_in_digikala_textChanged(const QString &arg1)
{
    refresh();
}
*/
void ListOfProducts::on_qpb_search_clicked()
{
  refresh();
}
