#include "Product.h"
#include "EnumsProduct.h"

Product::Product()
{
    name = "";
    dateOfRegister = "";
    creator = "";
    description = "";
    dateOfCreation = "";
    color = "";
    state = "";
    sellPrice = 0;
    pureSellPrice = 0;
    rating = 5;
    offPercent = 0;
    viewNumber = 1;
    activeCondition = PUBLIC;
    availableNumber = 0;
    voteNumber = 0;
    complainNumber = 0;
    soldNumber = 0;
    key = 0;
    key_seller = 0;
    name_category = "";
    return;
}

Product::Product(const Product& p) {

    name = p.name;
    dateOfRegister = p.dateOfRegister;
    creator = p.creator;
    description = p.description;
    state = p.state;
    dateOfCreation = p.dateOfCreation;
    color = p.color;
    sellPrice = p.sellPrice;
    pureSellPrice = p.pureSellPrice;
    rating = p.rating;
    offPercent = p.offPercent;
    viewNumber = p.viewNumber;
    availableNumber = p.availableNumber;
    voteNumber = p.voteNumber;
    activeCondition = p.activeCondition;
    complainNumber = p.complainNumber;
    soldNumber = p.soldNumber;
    key = p.key;
    key_seller = p.key_seller;
    name_category = p.name_category;
    return;
}

Product::Product(Product&& p) {

    name = p.name;
    dateOfRegister = p.dateOfRegister;
    creator = p.creator;
    description = p.description;
    state = p.state;
    dateOfCreation = p.dateOfCreation;
    color = p.color;
    sellPrice = p.sellPrice;
    pureSellPrice = p.pureSellPrice;
    rating = p.rating;
    offPercent = p.offPercent;
    viewNumber = p.viewNumber;
    availableNumber = p.availableNumber;
    voteNumber = p.voteNumber;
    activeCondition = p.activeCondition;
    complainNumber = p.complainNumber;
    soldNumber = p.soldNumber;
    key = p.key;
    key_seller = p.key_seller;
    name_category = p.name_category;
    return;

}


Product::~Product(){}

void Product::setName(QString s)
{
    name = s;
    return;
}

void Product::setDateOfRegister(QString s)
{
    dateOfRegister = s;
    return;
}

void Product::setCreator(QString s)
{
    creator = s;
    return;
}

void Product::setDescription(QString s)
{
    description = s;
    return;
}

void Product::setDateOfCreation(QString s)
{
    dateOfCreation = s;
    return;
}

void Product::setColor(QString s)
{
    color = s;
    return;
}

void Product::setSellPrice(double s)
{
    sellPrice = s;
    return;
}

void Product::setRating(float s)
{
    rating = s;
    return;
}

void Product::setState(QString s){

    state = s;
    return;
}

void Product::setOffPercent(float s)
{
    offPercent = s;
    return;
}

void Product::setViewNumber(unsigned int s)
{
    viewNumber = s;
    return;
}

void Product::setAvailableNumber(unsigned int s)
{
    availableNumber = s;
    return;
}

void Product::setVoteNumber(unsigned int s)
{
    voteNumber = s;
    return;
}

void Product::setSoldNumber(unsigned int s)
{
    soldNumber = s;
    return;
}

void Product::setActiveCondition(int a){

    activeCondition = a;
}

void Product::setComplainNumber(unsigned int s)
{
    complainNumber = s;
}

void Product::setKeySeller(unsigned long long s)
{
    key_seller = s;
    return;
}

void Product::setNameCategory(QString s)
{
    name_category = s;
    return;
}

void Product::setKey(unsigned long long i)
{
    key = i;
    return;
}

void Product::setPureSellPrice(double s){

    pureSellPrice = s;
}






QString Product::getName()
{
    return name;
}

QString Product::getDateOfRegister()
{
    return dateOfRegister;
}

QString Product::getCreator()
{
    return creator;
}

QString Product::getDescription()
{
    return description;
}

QString Product::getDateOfCreation()
{
    return dateOfCreation;
}

QString Product::getColor()
{
    return color;
}
QString Product::getState(){

    return state;
}

double Product::getSellPrice()
{
    return sellPrice;
}

double Product::getPureSellPrice(){

    return pureSellPrice;
}

float Product::getRating()
{
    return rating;
}

float Product::getOffPercent()
{
    return offPercent;
}

unsigned int Product::getViewNumber()
{
    return viewNumber;
}

unsigned int Product::getSoldNumber()
{
    return soldNumber;
}

int Product::getActiveCondition(){

    return activeCondition;
}

unsigned int Product::getComplainNumber()
{
    return complainNumber;
}

unsigned int Product::getAvailableNumber()
{
    return availableNumber;
}

unsigned int Product::getVoteNumber()
{
    return voteNumber;
}

unsigned long long Product::getKeySeller()
{
    return key_seller;
}

QString Product::getNameCategory()
{
    return name_category;
}

unsigned long long Product::getKey()
{
    return key;
}




bool Product::operator==(Product x)
{
    if (this->availableNumber == x.availableNumber &&
            this->color == x.color &&
            this->dateOfRegister == x.dateOfRegister &&
            this->complainNumber == x.complainNumber &&
            this->creator == x.creator &&
            this->dateOfCreation == x.dateOfCreation &&
            this->description == x.description &&
            this->key == x.key &&
            this->name_category == x.name_category &&
            this->key_seller == x.key_seller &&
            this->name == x.name &&
            this->offPercent == x.offPercent &&
            this->sellPrice == x.sellPrice &&
            this->rating == x.rating &&
            this->sellPrice == x.sellPrice &&
            this->soldNumber == x.soldNumber &&
            this->viewNumber == x.viewNumber &&
            this->activeCondition == x.activeCondition &&
            this->voteNumber == x.voteNumber &&
            this->state == x.state)
    {
        return true;
    }

    return false;
}

void Product::operator=(Product p)
{
    name = p.name;
    dateOfRegister = p.dateOfRegister;
    creator = p.creator;
    description = p.description;
    dateOfCreation = p.dateOfCreation;
    color = p.color;
    sellPrice = p.sellPrice;
    pureSellPrice = p.pureSellPrice;
    rating = p.rating;
    offPercent = p.offPercent;
    viewNumber = p.viewNumber;
    availableNumber = p.availableNumber;
    voteNumber = p.voteNumber;
    activeCondition = p.activeCondition;
    complainNumber = p.complainNumber;
    soldNumber = p.soldNumber;
    key = p.key;
    key_seller = p.key_seller;
    name_category = p.name_category;
    state = p.state;

    return;
}

