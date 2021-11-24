#include "DetailOfFavoriteProducts.h"
#include "ui_DetailOfFavoriteProducts.h"

#include "Global.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "DialogBuy.h"
#include <QMessageBox>
#include "DetailsOfOwner.h"

using namespace GlobalNameSpace;

DetailOfFavoriteProducts::DetailOfFavoriteProducts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailOfFavoriteProducts)
{
    ui->setupUi(this);

    setWindowTitle("Details Of Product");
    resize(500, 800);

    NodeProduct *temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    p = temp->getData();

    p.setViewNumber(p.getViewNumber() + 1);
    temp->setData(p);
    Globals::PRODUCT_LIST.writeFile();
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








    QPushButton* likedB = new QPushButton("Remove From Favorite List");
    mainLayout->addWidget(likedB, i, 0);

    QPushButton* ownerB = new QPushButton("Details Of Owner");
    mainLayout->addWidget(ownerB, i, 1);

    setLayout(mainLayout);

    mainLayout->setSizeConstraint(QLayout::SetMinimumSize);

    connect(likedB, SIGNAL(clicked(bool)), this, SLOT(on_btn_likedB_Clicked(bool)));
    connect(ownerB, SIGNAL(clicked(bool)), this, SLOT(on_btn_ownerB_Clicked(bool)));

}



void DetailOfFavoriteProducts::on_btn_ownerB_Clicked(bool)
{

    DetailsOfOwner *d = new DetailsOfOwner(p.getKeySeller());
    d->setInt(2);
    d->setBackFavorite(this);
    d->setModal(true);
    d->show();
    this->hide();
}
void DetailOfFavoriteProducts::on_btn_likedB_Clicked(bool){

    NodeProduct *temp = &Globals::PRODUCT_LIST.getByKey(Globals::KEY_PRODUCT);
    const Product p = temp->getData();

    if (Globals::TYPE_USER == DEALER){

        TNodeUser<Dealer>* d_node = &Globals::DEALER_LIST.getByKey(Globals::KEY_USER);
        Dealer d_data = d_node->getData();

        d_data.deleteProductToListOfInterest(p);
        d_node->setData(d_data);

        Globals::DEALER_LIST.writeToFileUser();
    }
    else{

        TNodeUser<Users>* d_node = &Globals::USER_LIST.getByKey(Globals::KEY_USER);
        Users d_data = d_node->getData();

        d_data.deleteProductToListOfInterest(p);
        d_node->setData(d_data);

        Globals::USER_LIST.writeToFileUser();
    }

    QMessageBox::information(this, "Done", "Product removed from favorite List.");

    close();
}

DetailOfFavoriteProducts::~DetailOfFavoriteProducts()
{
    delete ui;
}
