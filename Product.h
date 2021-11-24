#ifndef _Product_
#define _Product_

#include <QString>

class Product {

private:

    QString name; //
    QString dateOfRegister;//
    QString creator;//
    QString description;//
    QString dateOfCreation;//
    QString color;//
    QString state;
    QString name_category;//
    double sellPrice; //
    double pureSellPrice;
    float rating; //
    float offPercent;
    unsigned int viewNumber;
    unsigned int voteNumber;
    unsigned int availableNumber;//
    unsigned int activeCondition;
    unsigned int complainNumber;//
    unsigned int soldNumber;//
    unsigned long long key;//
    unsigned long long key_seller;//

public :

    Product();
    Product(const Product& p);

    Product(Product&& p);
    ~Product();

    void setName(QString s);
    void setDateOfRegister(QString s);
    void setCreator(QString s);
    void setDescription(QString s);
    void setDateOfCreation(QString s);
    void setColor(QString s);
    void setState(QString s);
    void setNameCategory(QString s);

    void setSellPrice(double s);
    void setPureSellPrice(double s);
    void setRating(float s);
    void setOffPercent(float s);
    void setViewNumber(unsigned int s);
    void setAvailableNumber(unsigned int s);
    void setActiveCondition(int a);
    void setSoldNumber(unsigned int s);
    void setComplainNumber(unsigned int s);
    void setVoteNumber(unsigned int s);
    void setKeySeller(unsigned long long s);
    void setKey(unsigned long long i);




    QString getName();
    QString getDateOfRegister();
    QString getCreator();
    QString getDescription();
    QString getDateOfCreation();
    QString getColor();
    QString getState();
    QString getNameCategory();
    double getSellPrice();
    double getPureSellPrice();
    float getRating();
    float getOffPercent();
    unsigned int getViewNumber();
    unsigned int getSoldNumber();
    unsigned int getVoteNumber();
    int getActiveCondition();
    unsigned int getComplainNumber();
    unsigned int getAvailableNumber();
    unsigned long long getKeySeller();
    unsigned long long getKey();
    bool operator==(Product x);
    void operator=(Product x);

};



#endif
