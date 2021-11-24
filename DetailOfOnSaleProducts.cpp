#include "DetailOfOnSaleProducts.h"
#include "ui_DetailOfOnSaleProducts.h"
#include "Global.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "DialogBuy.h"
#include <QMessageBox>
#include "EditProduct.h"

using namespace GlobalNameSpace;


DetailOfOnSaleProducts::DetailOfOnSaleProducts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailOfOnSaleProducts)
{
    ui->setupUi(this);

    setWindowTitle("Details Of Product");
    resize(500, 800);

    NodeProduct *temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    Product p = temp->getData();


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

    QLabel *ratingL = new QLabel("Rating: " + p.getDateOfRegister());
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

    activeB = new QPushButton("");
    mainLayout->addWidget(activeB, i, 1);

    QPushButton *editB = new QPushButton("Edit");
    mainLayout->addWidget(editB, i, 2);


    if (p.getActiveCondition() == PUBLIC){
        activeB->setText("Private");
    }else{
        activeB->setText("Public");
    }




    TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
    Dealer d_data = d_node->getData();

    if (d_data.getListOfInterestKeyLinkedList().containsKey(p.getKey())){
        likedB->setText("Remove From Favorite List");
    }else{
        likedB->setText("Add To Favorite List");
    }





    setLayout(mainLayout);

    mainLayout->setSizeConstraint(QLayout::SetMinimumSize);



    connect(activeB, SIGNAL(clicked(bool)), this, SLOT(on_btn_activeB_Clicked(bool)));
    connect(likedB, SIGNAL(clicked(bool)), this, SLOT(on_btn_likedB_Clicked(bool)));
    connect(editB, SIGNAL(clicked(bool)), this, SLOT(on_btn_editB_Clicked(bool)));
}



void DetailOfOnSaleProducts::on_btn_activeB_Clicked(bool){

    NodeProduct *temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    Product p = temp->getData();

    TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
    Dealer d_data = d_node->getData();

    if (activeB->text() == "Private"){
        p.setActiveCondition(PRIVATE);
        temp->setData(p);
        activeB->setText("Public");
        QMessageBox::information(this, "Done", "Now, this product is hidden in the main list");
    }
    else{
        p.setActiveCondition(PUBLIC);
        temp->setData(p);
        activeB->setText("Private");
        QMessageBox::information(this, "Done", "Now, this product is visible in the main list.");
    }

    Globals::DEALER_LIST.writeToFileUser();
    Globals::PRODUCT_LIST.writeFile();

}



void DetailOfOnSaleProducts::on_btn_likedB_Clicked(bool){

    TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
    Dealer d_data = d_node->getData();

    NodeProduct *temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    Product p = temp->getData();

    if (likedB->text() == "Remove From Favorite List"){

        d_data.deleteProductToListOfInterest(p);
        d_node->setData(d_data);
        likedB->setText("Add To Favorite List");
        QMessageBox::information(this, "Done", "Product removed from favorite list.");

    }else{
        d_data.addKeyToListOfInterest(p);
        d_node->setData(d_data);
        likedB->setText("Remove From Favorite List");
        QMessageBox::information(this, "Done", "Product added to favorite list.");
    }
}

void DetailOfOnSaleProducts::on_btn_editB_Clicked(bool){

    EditProduct *d = new EditProduct(this);
    d->setModal(true);
    d->show();
    close();
}


DetailOfOnSaleProducts::~DetailOfOnSaleProducts()
{
    delete ui;
}



