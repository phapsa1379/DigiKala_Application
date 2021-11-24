#include "DetailOfAllProducts.h"
#include "ui_DetailOfAllProducts.h"

#include "Global.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "DialogBuy.h"
#include <QMessageBox>
#include "ReportOptionsDialog.h"
#include "DetailsOfOwner.h"
using namespace GlobalNameSpace;

DetailOfAllProducts::DetailOfAllProducts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailOfAllProducts)
{
    ui->setupUi(this);

    setWindowTitle("Details Of Product");
    resize(500, 800);

    NodeProduct *temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    p =temp->getData();

    p.setViewNumber(p.getViewNumber() + 1);
    temp->setData(p);

    QGridLayout * mainLayout = new QGridLayout;

    QLabel *nameL = new QLabel("Name: " + p.getName());
    mainLayout->addWidget(nameL, 0, 0);

    QLabel *registerationDateL = new QLabel("Registeration Date: " + p.getDateOfRegister());
    mainLayout->addWidget(registerationDateL, 1, 0);

    QLabel *colorL = new QLabel("Color: " + p.getColor());
    mainLayout->addWidget(colorL, 2, 0);









    QLabel *stateL = new QLabel("State: " + p.getState());
    mainLayout->addWidget(stateL, 3, 0);

    QLabel *ratingL = new QLabel("Rating: " + QString::number(p.getRating()));
    mainLayout->addWidget(ratingL, 4, 0);

    QLabel *categoryL = new QLabel("Category: " + p.getNameCategory());
    mainLayout->addWidget(categoryL, 5, 0);

    int i = 6;

    float offPercent = p.getOffPercent();
    if (offPercent > 0){
        QLabel *offPercentL = new QLabel("Off Percent: " + QString::number(offPercent));
        mainLayout->addWidget(offPercentL, i++, 0);
    }

    QLabel *priceL = new QLabel("Price: " + QString::number(p.getPureSellPrice(), 'f', 1));
    mainLayout->addWidget(priceL, i++, 0);







    QLabel *availableNumberL = new QLabel("AvailableNumber: " + QString::number(p.getAvailableNumber()));
    mainLayout->addWidget(availableNumberL, i++, 0);

    QLabel *soldNumberL = new QLabel("Sold Number: " + QString::number(p.getSoldNumber()));
    mainLayout->addWidget(soldNumberL, i++, 0);

    QLabel *viewNumberL = new QLabel("ViewNumber: " +QString::number( p.getViewNumber()));
    mainLayout->addWidget(viewNumberL, i++, 0);


    if (!p.getCreator().isEmpty()){
        QLabel *creatorL = new QLabel("Creator: " + p.getCreator());
        mainLayout->addWidget(creatorL, i++, 0);
    }

    if (!p.getDateOfCreation().isEmpty()){
        QLabel *dateOfCreationL = new QLabel("Date Of Creation: " + p.getDateOfCreation());
        mainLayout->addWidget(dateOfCreationL, i++, 0);
    }

    if (!p.getDescription().isEmpty()){
        QLabel *descriptionL = new QLabel("Description: " + p.getDescription());
        mainLayout->addWidget(descriptionL, i++, 0);
    }

    likedB = new QPushButton("");
    mainLayout->addWidget(likedB, i, 0);

    QPushButton *chatB = new QPushButton("Details Of Owner");
    QPushButton *buyB = new QPushButton("Buy");
    QPushButton *reportB = new QPushButton("Report");

    mainLayout->addWidget(chatB, i++, 1);

    if (Globals::TYPE_USER == USER || p.getKeySeller() != Globals::KEY_USER){
        mainLayout->addWidget(buyB, i, 0);
        mainLayout->addWidget(reportB, i, 1);
    }

    if (Globals::TYPE_USER == USER){

        TNodeUser<Users>* d_node = &Globals::USER_LIST.getByKey(Globals::KEY_USER);
        Users d_data = d_node->getData();

        if (d_data.getListOfInterestKeyLinkedList().containsKey(p.getKey())){
            likedB->setText("Remove From Favorite List");
        }else{
            likedB->setText("Add To Favorite List");
        }



    }else{

        TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
        Dealer d_data = d_node->getData();

        if (d_data.getListOfInterestKeyLinkedList().containsKey(p.getKey())){
            likedB->setText("Remove From Favorite List");
        }else{
            likedB->setText("Add To Favorite List");
        }
    }




    mainLayout->setSizeConstraint(QLayout::SetMinimumSize);

    connect(buyB, SIGNAL(clicked(bool)), this, SLOT(on_btn_buyB_Clicked(bool)));
    connect(likedB, SIGNAL(clicked(bool)), this, SLOT(on_btn_likedB_Clicked(bool)));
    connect(chatB, SIGNAL(clicked(bool)), this, SLOT(on_btn_contactB_Clicked(bool)));
    connect(reportB, SIGNAL(clicked(bool)), this, SLOT(on_btn_reportB_Clicked(bool)));

    // Use the above line also for chatB button.
    setLayout(mainLayout);
}

void DetailOfAllProducts::on_btn_buyB_Clicked(bool){

    DialogBuy *d = new DialogBuy();
    d->show();
    close();
}

void DetailOfAllProducts::on_btn_contactB_Clicked(bool){

    DetailsOfOwner *d = new DetailsOfOwner(p.getKeySeller());
    d->setInt(1);
    d->setBack(this);
    d->setModal(true);
    d->show();
    this->hide();
}

void DetailOfAllProducts::on_btn_likedB_Clicked(bool){

    NodeProduct *temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    const Product p =temp->getData();

    if (Globals::TYPE_USER == DEALER){

        TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
        Dealer d_data = d_node->getData();

        if (likedB->text() == "Remove From Favorite List"){

            d_data.deleteProductToListOfInterest(p);
            d_node->setData(d_data);
            likedB->setText("Add To Favorite List");

            QMessageBox::information(this, "Done", "Product removed from favorite list.");

        }else{

            d_data.addKeyToListOfInterest(p);
            d_node->setData(d_data);
            likedB->setText("Remove From Favorite List");

            QMessageBox::information(this, "Done", "Product Added to favorite list.");
        }
        Globals::DEALER_LIST.writeToFileUser();

    }
    else{

        TNodeUser<Users>* d_node = &Globals::USER_LIST.getByKey(Globals::KEY_USER);
        Users d_data = d_node->getData();

        if (likedB->text() == "Remove From Favorite List"){

            d_data.deleteProductToListOfInterest(p);
            d_node->setData(d_data);
            likedB->setText("Add To Favorite List");
            QMessageBox::information(this, "Done", "Product removed from favorite list.");

        }else{
            d_data.addKeyToListOfInterest(p);
            d_node->setData(d_data);
            likedB->setText("Remove From Favorite List");
            QMessageBox::information(this, "Done", "Product Added to favorite list.");
        }

        Globals::USER_LIST.writeToFileUser();

    }
}


void DetailOfAllProducts::on_btn_reportB_Clicked(bool){

    ReportOptionsDialog* d = new ReportOptionsDialog(this);
    d->show();
}

DetailOfAllProducts::~DetailOfAllProducts()
{
    delete ui;
}
