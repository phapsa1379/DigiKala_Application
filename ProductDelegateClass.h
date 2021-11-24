#ifndef PRODUCTDELEGATECLASS_H
#define PRODUCTDELEGATECLASS_H

#include <QString>
#include "Product.h"

class ProductDelegateClass{

private:
    QString name;
    QString company;
    unsigned int viewNumber;
    unsigned int availableNumber;
    double purePrice;
    float rating;
    unsigned long long key;

public:
    ProductDelegateClass();
    ~ProductDelegateClass();
    ProductDelegateClass(const ProductDelegateClass& p);
    ProductDelegateClass(ProductDelegateClass &&p);

    void setName(QString a);
    void setCompany(QString a);
    void setPurePrice(double a);
    void setAvailablePrice(unsigned int a);
    void setViewNumber(unsigned int a);
    void setRating(float a);
    void setKey(unsigned long long);

    QString getName();
    QString getCompany();
    double getPurePrice();
    unsigned int getViewNumber();
    unsigned int getAvailableNumber();
    float getRating();
    unsigned long long getKey();

    void operator=(Product a);
    void operator=(ProductDelegateClass a);

};


#endif // PRODUCTDELEGATECLASS_H
