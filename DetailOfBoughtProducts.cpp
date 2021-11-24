#include "DetailOfBoughtProducts.h"
#include "ui_DetailOfBoughtProducts.h"

#include "Global.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "DialogBuy.h"
#include <QMessageBox>
#include "EditProduct.h"
#include "RatingDialog.h"
using namespace GlobalNameSpace;

int DetailOfBoughtProducts::givenRating = 0;


DetailOfBoughtProducts::DetailOfBoughtProducts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailOfBoughtProducts)
{
    ui->setupUi(this);

    setWindowTitle("Details Of Product");
    resize(500, 800);

    NodeProduct *temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    p = temp->getData();

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


    QPushButton *rateB = new QPushButton("");
    mainLayout->addWidget(rateB, i++, 1);

    if (givenRating == 0){
        rateB->setText("Rate");
    }
    else{
        rateB->setText("Edit Rating");
    }

    QPushButton *removeB = new QPushButton("Remove from bought products");
    mainLayout->addWidget(removeB, i, 0);



    if (Globals::TYPE_USER == USER){

        TNodeUser<Users>* d_node = &Globals::USER_LIST.getByKey(Globals::KEY_USER);
        Users d_data = d_node->getData();

        if (d_data.getListOfInterestKeyLinkedList().containsKey(p.getKey())){

            likedB->setText("Remove From Favorite List");

        }else{
            likedB->setText("Add To Favorite List");
        }
    }

    else{

        TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
        Dealer d_data = d_node->getData();

        if (d_data.getListOfInterestKeyLinkedList().containsKey(p.getKey())){

            likedB->setText("Remove From Favorite List");

        }else{
            likedB->setText("Add To Favorite List");
        }
    }



    setLayout(mainLayout);

    mainLayout->setSizeConstraint(QLayout::SetMinimumSize);

    connect(likedB, SIGNAL(clicked(bool)), this, SLOT(on_btn_likedB_Clicked(bool)));
    connect(rateB, SIGNAL(clicked(bool)), this, SLOT(on_btn_rateB_Clicked(bool)));
    connect(removeB, SIGNAL(clicked(bool)), this, SLOT(on_btn_removeB_Clicked(bool)));

}

void DetailOfBoughtProducts::on_btn_rateB_Clicked(bool){

    RatingDialog* r = new RatingDialog(this);
    r->show();
}


void DetailOfBoughtProducts::on_btn_removeB_Clicked(bool){


    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "", "Are you sure?",
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {

        if (Globals::TYPE_USER == DEALER){

            TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
            Dealer d_data = d_node->getData();

            d_data.deleteProductFromListOfBuyBefore(p);
            d_node->setData(d_data);

            Globals::DEALER_LIST.writeToFileUser();

        }else{

            TNodeUser<Users>* d_node = &Globals::USER_LIST.getByKey(Globals::KEY_USER);
            Users d_data = d_node->getData();

            d_data.deleteProductFromListOfBuyBefore(p);
            d_node->setData(d_data);
            Globals::USER_LIST.writeToFileUser();

        }
        close();

    }
}

void DetailOfBoughtProducts::on_btn_likedB_Clicked(bool){

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


DetailOfBoughtProducts::~DetailOfBoughtProducts()
{
    delete ui;
}
