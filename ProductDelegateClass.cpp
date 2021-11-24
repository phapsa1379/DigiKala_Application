#include "ProductDelegateClass.h"

ProductDelegateClass::ProductDelegateClass()
{
    name = "";
    company = "";
    viewNumber = 0;
    purePrice = 0;
    availableNumber = 0;
    rating = 0;
    key = 0;
    return;
}

ProductDelegateClass::~ProductDelegateClass(){};


ProductDelegateClass::ProductDelegateClass(const ProductDelegateClass& p){

    name = p.name;
    company = p.company;
    viewNumber = p.viewNumber;
    purePrice = p.purePrice;
    availableNumber = p.availableNumber;
    rating = p.rating;
    key = p.key;
    return;
}


ProductDelegateClass::ProductDelegateClass(ProductDelegateClass &&p){

    name = p.name;
    company = p.company;
    viewNumber = p.viewNumber;
    purePrice = p.purePrice;
    availableNumber = p.availableNumber;
    rating = p.rating;
    key = p.key;
    return;
}

void ProductDelegateClass::operator=(Product a){

    name = a.getName();
    company = a.getCreator();
    viewNumber = a.getViewNumber();
    purePrice = a.getPureSellPrice();
    availableNumber = a.getAvailableNumber();
    rating = a.getRating();
    key = a.getKey();
    return;
}


void ProductDelegateClass::operator=(ProductDelegateClass a)
{
    name = a.getName();
    company = a.getCompany();
    viewNumber = a.getViewNumber();
    purePrice = a.getPurePrice();
    availableNumber = a.getAvailableNumber();
    rating = a.getRating();
    key = a.getKey();
    return;
}










void ProductDelegateClass::setKey(unsigned long long a){
    key = a;
    return;
}

void ProductDelegateClass::setName(QString a){
    name = a;
    return;
}

void ProductDelegateClass::setPurePrice(double a){
    purePrice = a;
    return;
}

void ProductDelegateClass::setAvailablePrice(unsigned int a){
    availableNumber = a;
    return;
}

void ProductDelegateClass::setRating(float a){
    rating = a;
    return;
}

void ProductDelegateClass::setViewNumber(unsigned int a){
    viewNumber = a;
    return;
}

void ProductDelegateClass::setCompany(QString a){
    company = a;
    return;
}






unsigned int ProductDelegateClass:: getViewNumber(){

    return viewNumber;
}

QString ProductDelegateClass::getCompany(){
    return company;
}


unsigned long long ProductDelegateClass::getKey(){
    return key;
}

QString ProductDelegateClass::getName(){
    return name;
}

double ProductDelegateClass::getPurePrice(){
    return purePrice;
}

unsigned int ProductDelegateClass::getAvailableNumber(){
    return availableNumber;
}

float ProductDelegateClass::getRating(){
    return rating;
}
