#include <iostream>
#include <QString>
#include <QDebug>
#include "Dealer.h"
#include "ExternalFunctions.h"

using namespace std;
Dealer::Dealer()
{
    this->setLevelOfAccess(2);
}


Dealer::~Dealer()
{
}

Dealer::Dealer(Dealer& user) : Users(user)
{
    this->compony_name = user.compony_name;
    this->list_of_sell = user.list_of_sell;
    this->list_of_sell_linklist = user.list_of_sell_linklist;
    this->list_of_sell_key_linkedlist = user.list_of_sell_key_linkedlist;

    return;

}
Dealer::Dealer(Dealer&& user) : Users(std::move(user))
{

    this->compony_name = user.compony_name;
    this->list_of_sell = user.list_of_sell;

    this->list_of_sell_linklist = user.list_of_sell_linklist;
    this->list_of_sell_key_linkedlist = user.list_of_sell_key_linkedlist;

    return;
}



//////////////////////////
void Dealer::setComponyName(const QString& c_name)
{
    this->compony_name = c_name;
    return;
}

 QString Dealer::getComponyName() const
{
    return this->compony_name;
}


 void Dealer::setListOfSell(QString list)
 {
     this->list_of_sell = list;
     return;
 }

 void Dealer::setListOfSellKeyLinkedList(KeyLinkedList list)
 {
     this->list_of_sell_key_linkedlist = list;
     return;
 }

 void Dealer::setListOfSellLinkList(LinkedListProduct list)
 {
     this->list_of_sell_linklist = list;
     return;
 }

QString Dealer::getListOfSell()
{
    return this->list_of_sell;
}

KeyLinkedList Dealer::getListOfSellKeyLinkedList()
{
    return this->list_of_sell_key_linkedlist;
}

LinkedListProduct Dealer::getListOfSellLinkList()
{
    return this->list_of_sell_linklist;

}

void Dealer::printDealer()
{
    this->print();
    qDebug() << "Company name is : " + this->getComponyName().toLatin1();
    qDebug() << "List of Sold : " + this->getListOfSell().toLatin1();
}

bool Dealer::operator==(Dealer user)
{
    if (this->compony_name == user.compony_name &&
        this->list_of_sell == user.list_of_sell &&
        this->getLevelOfAccess() == user.getLevelOfAccess() &&
        this->getName() == user.getName() &&
        this->getLastName() == user.getLastName() &&
        this->getUserName() == user.getUserName() &&
        this->getEmail() == user.getEmail() &&
        this->getKey() == user.getKey() &&
        this->getPassword() == user.getPassword() &&
        this->getPasswordPower() == user.getPasswordPower() &&
        this->getDateOfCreated() == user.getDateOfCreated() &&
        this->getDateOfLastEnter() == user.getDateOfLastEnter() &&
        this->getDateOfLastExit() == user.getDateOfLastExit() &&
        this->getMoney() == user.getMoney() &&
        this->getListOfBuyBefore() == user.getListOfBuyBefore() &&
        this->getListOfInterest() == user.getListOfInterest() &&
        this->getPostCode() == user.getPostCode() &&
        this->getMobileNumber() == user.getMobileNumber() &&
        this->getAddress() == user.getAddress()
        )
    {
        return true;
    }
    return false;
}

void Dealer::operator=(Dealer user) // Edited By Arash
{
    this->setLevelOfAccess(user.getLevelOfAccess());
    this->setName(user.getName());
    this->setLastName(user.getLastName());
    this->setUserName(user.getUserName());
    this->setEmail(user.getEmail());
    this->setKey(user.getKey());
    this->setPassword(user.getPassword());
    this->setPassswordPower(user.getPassword());
    this->setDateOfCreated(user.getDateOfCreated());
    this->setDateOfLastEnter(user.getDateOfLastEnter());
    this->setDateOfLastExit(user.getDateOfLastExit());
    this->setMoney(user.getMoney());

    this->setListOfBuyBefore(user.getListOfBuyBefore());
    this->setListOfBuyBeforeLinkList(user.getListOfBuyBeforeLinkList());
    this->setListOfBuyBeforeKeyLinkedList(user.getListOfBuyBeforeKeyLinkedList());

    this->setListOfInterest(user.getListOfInterest());
    this->setListOfInterestLinkList(user.getListOfInterestLinkList());
    this->setListOfInterestKeyLinkedList(user.getListOfInterestKeyLinkedList());

    this->setAddress(user.getAddress());
    this->setMobileNumber(user.getMobileNumber());
    this->setPostCode(user.getPostCode());
    this->setState(user.getState());
    this->setCity(user.getCity());

    this->list_of_sell = user.list_of_sell;
    this->list_of_sell_linklist = user.list_of_sell_linklist;
    this->list_of_sell_key_linkedlist = user.list_of_sell_key_linkedlist;

    this->compony_name = user.compony_name;

}

bool Dealer::addKeyToListOfSell(Product product)
{

    QString key_str = QString::number(product.getKey());
    QString user_keys = this->getListOfSell();
    user_keys.append(key_str + " ");
    this->setListOfSell(user_keys);
    this->list_of_sell_key_linkedlist.pushBack(product.getKey());
    this->list_of_sell_linklist.addFront(product);



    this->list_of_sell_linklist.print();
    return true;

}


bool Dealer::deleteProductToListOfSell(Product product)
{
    unsigned long long my_key = product.getKey();
    int my_index = this->getListOfSellLinkList().findIndexByKey(my_key);
    QString my_str = this->getListOfSell();

    if (my_index == -1)
    {
        return false;
    }


    this->list_of_sell_key_linkedlist.dellKey(my_key);
    this->list_of_sell_linklist.remove(my_index);
    int first_index = findKeyInString(my_key, my_str);
    string my_str_copy =my_str.toLocal8Bit().constData();
    my_str_copy.erase(first_index, countDigit(my_key) + 1);
    QString my_str_2 = QString::fromStdString(my_str_copy);
    this->setListOfSell(my_str_2);
    if (first_index == -1)
    {
        return false;
    }
    return true;

}
