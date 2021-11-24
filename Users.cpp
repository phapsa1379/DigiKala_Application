#include "Users.h"
#include <iostream>
#include <QString>
#include <cctype>
#include <fstream>
#include<ctime>
#include<QDebug>
#include "ExternalFunctions.h"
#include "Global.h"


using namespace std;

Users::Users()
{


    this->username = "Username";
    this->email = "something@example.com";
    this->date_of_created = NowTime();

}



Users::~Users()
{

}

Users::Users(const Users& user)
{
    this->level_of_access = user.level_of_access;
    this->name = user.name;
    this->lastname = user.lastname;
    this->username = user.username;
    this->email = user.email;
    this->key = user.key;
    this->password = user.password;
    this->password_power = user.password_power;
    this->date_of_created = user.date_of_created;
    this->date_of_last_enter = user.date_of_last_enter;
    this->date_of_last_exit = user.date_of_last_exit;
    this->money = user.money;

    this->list_of_buy_before = user.list_of_buy_before;
    this->list_of_buy_before_linklist = user.list_of_buy_before_linklist;
    this->list_of_buy_before_key_linkedlist = user.list_of_buy_before_key_linkedlist;

    this->list_of_interest = user.list_of_interest;
    this->list_of_interest_linklist = user.list_of_interest_linklist;
    this->list_of_interest_key_linkedlist = user.list_of_interest_key_linkedlist;

    this->address = user.address;
    this->mobile_number = user.mobile_number;
    this->post_code = user.post_code;
    this->city = user.city;
    this->state = user.state;
    return;


}

Users::Users(Users&& user)
{
    this->level_of_access = user.level_of_access;
    this->name = user.name;
    this->lastname = user.lastname;
    this->username = user.username;
    this->email = user.email;
    this->key = user.key;
    this->password = user.password;
    this->password_power = user.password_power;
    this->date_of_created = user.date_of_created;
    this->date_of_last_enter = user.date_of_last_enter;
    this->date_of_last_exit = user.date_of_last_exit;
    this->money = user.money;


    this->list_of_buy_before = user.list_of_buy_before;
    this->list_of_buy_before_linklist = user.list_of_buy_before_linklist;
    this->list_of_buy_before_key_linkedlist = user.list_of_buy_before_key_linkedlist;

    this->list_of_interest = user.list_of_interest;
    this->list_of_interest_linklist = user.list_of_interest_linklist;
    this->list_of_interest_key_linkedlist = user.list_of_interest_key_linkedlist;

    this->address = user.address;
    this->mobile_number = user.mobile_number;
    this->post_code = user.post_code;
    this->city = user.city;
    this->state = user.state;
    return;
}

void Users::setAddress(const QString & address)
{
    this->address = address;
    return;
}

void Users::setMobileNumber(const QString & mobileNum)
{
    this->mobile_number = mobileNum;
    return;
}

void Users::setPostCode(const QString& pc)
{
    this->post_code = pc;
    return;
}

void Users::setKey(unsigned long long key)
{
    this->key = key;
    return;
}


void Users::setLevelOfAccess(int a)
{
    this->level_of_access = a;
}

void Users::setMoney(double money)
{
    this->money = money;
}

void Users::setName(const QString& name)
{
    this->name = name;
}

void Users::setLastName(const QString& lastname)
{
    this->lastname = lastname;
    return;
}

void Users::setUserName(const QString& username)
{
    this->username = username;
    return;
}

void Users::setDateOfLastEnter(const QString& date)
{
    this->date_of_last_enter = date;
    return;
}

void Users::setDateOfLastExit(const QString& date)
{
    this->date_of_last_exit = date;
    return;
}

void Users::setDateOfCreated(const QString& date)
{
    this->date_of_created = date;
    return;
}


void Users::setListOfBuyBefore(const QString& list)
{
    this->list_of_buy_before = list;
    return;
}

void Users::setListOfBuyBeforeKeyLinkedList(KeyLinkedList list)
{
    this->list_of_buy_before_key_linkedlist = list;
    return;
}

void Users::setListOfBuyBeforeLinkList(LinkedListProduct list)
{
    this->list_of_buy_before_linklist = list;
    return;
}




void Users::setListOfInterest(const QString& list)
{
    this->list_of_interest = list;
    return;
}

void Users::setListOfInterestKeyLinkedList(KeyLinkedList list)
{
    this->list_of_interest_key_linkedlist = list;
    return;
}

void Users::setListOfInterestLinkList(LinkedListProduct list)
{
    this->list_of_interest_linklist = list;
    return;
}

void Users::setPassword(const QString& pass)
{
    this->password = pass;
    int percent_of_pass = ComputePassPow(pass);
    this->password_power = percent_of_pass;
    return;
}

void Users::setPassswordPower(QString pass)
{
    int percent_of_pass = ComputePassPow(pass);
    this->password_power = percent_of_pass;
    return;
}

void Users::setEmail(const QString& email)
{
    this->email = email;
    return;
}

void Users::setState(const QString &state)
{
    this->state = state;
    return;
}

void Users::setCity(const QString &city)
{
    this->city = city;
    return;
}

unsigned long long Users::getKey()
{
    return this->key;
}

int Users::getLevelOfAccess()
{
    return this->level_of_access;
}

double Users::getMoney()
{
    return this->money;
}

QString Users::getName()
{
    return this->name;
}

QString Users::getLastName()
{
    return this->lastname;
}

QString Users::getUserName()
{
    return this->username;
}

QString Users::getDateOfLastEnter()
{
    return this->date_of_last_enter;
}

QString Users::getDateOfLastExit()
{
    return this->date_of_last_exit;
}

QString Users::getDateOfCreated()
{
    return this->date_of_created;
}


QString Users::getListOfBuyBefore()
{
    return this->list_of_buy_before;
}

KeyLinkedList Users::getListOfBuyBeforeKeyLinkedList()
{
    return this->list_of_buy_before_key_linkedlist;
}

LinkedListProduct Users::getListOfBuyBeforeLinkList()
{
    return this->list_of_buy_before_linklist;

}


QString Users::getListOfInterest()
{
    return this->list_of_interest;
}

KeyLinkedList Users::getListOfInterestKeyLinkedList()
{
    return this->list_of_interest_key_linkedlist;
}

LinkedListProduct Users::getListOfInterestLinkList()
{
    return this->list_of_interest_linklist;

}
QString Users::getAddress()
{
    return this->address;
}

QString Users::getMobileNumber()
{
    return this->mobile_number;
}

QString Users::getPostCode()
{
    return this->post_code;
}


QString Users::getPassword()
{
    return this->password;
}

int Users::getPasswordPower()
{
    return this->password_power;
}

QString Users::getEmail()
{
    return this->email;
}

QString Users::getCity()
{
    return this->city;
}

QString Users::getState()
{
    return this->state;
}
//other functions in class:

void Users::print()
{
    qDebug() << "Name : " +this->getName().toLatin1() ;
    qDebug () << "LastName : " + this->getLastName().toLatin1();
    qDebug () << "UserName : "+this->getUserName().toLatin1();
    qDebug () << "Email : " + this->getEmail().toLatin1();
    qDebug () << "Date of create account : " + this->getDateOfCreated().toLatin1();
    cerr << "Password Power :" << this->getPasswordPower()<< "\n" ;
    cerr << "Money : " << this->getMoney() << endl;
    qDebug () << "List of buy before : " + this->getListOfBuyBefore().toLatin1() ;
    qDebug () << "List of interesting : " + this->getListOfInterest().toLatin1() ;
    cerr << "Level of access : " << this->getLevelOfAccess()<<endl ;
    qDebug () <<"Address : " + this->getAddress().toLatin1();
    qDebug () << "Mobile Number : " + this->getMobileNumber().toLatin1() ;
    qDebug () << "Post Code : " + this->getPostCode().toLatin1();
    qDebug () << "State : "+ this->getState().toLatin1();
    qDebug () << "City :" + this->getCity().toLatin1();
}


bool Users::addKeyToListOfBuyBefore(Product product)
{
    QString key_str = QString::number(product.getKey());
    QString user_keys = this->getListOfBuyBefore();
    user_keys.append(key_str + " ");
    this->setListOfBuyBefore(user_keys);
    this->list_of_buy_before_key_linkedlist.pushBack(product.getKey());
    this->list_of_buy_before_linklist.pushBack(product);
    return true;

}

bool Users::addKeyToListOfInterest(Product product)
{
    QString key_str = QString::number(product.getKey());
    QString user_keys = this->getListOfInterest();
    user_keys.append(key_str + " ");
    this->setListOfInterest(user_keys);
    this->list_of_interest_key_linkedlist.pushBack(product.getKey());
    this->list_of_interest_linklist.pushBack(product);
    return true;

}


bool Users::deleteProductFromListOfBuyBefore(Product product)
{


        long long int my_key = product.getKey();
        int my_index = this->getListOfBuyBeforeLinkList().findIndexByKey(my_key);
        QString my_str = this->getListOfBuyBefore();

        if (my_index == -1)
        {
            return false;
        }


        this->list_of_buy_before_key_linkedlist.dellKey(my_key);
        this->list_of_buy_before_linklist.remove(my_index);
        long long first_index = findKeyInString(my_key, my_str);
        string my_str_copy =my_str.toLocal8Bit().constData();
        my_str_copy.erase(first_index, countDigit(my_key) + 1);
        QString my_str_2 = QString::fromStdString(my_str_copy);
        this->setListOfBuyBefore(my_str_2);
        if (first_index == -1)
        {
            return false;
        }
        return true;







}


bool Users::deleteProductToListOfInterest(Product product)
{
    long long int my_key = product.getKey();
    int my_index = this->getListOfInterestLinkList().findIndexByKey(my_key);
    QString my_str = this->getListOfInterest();

    if (my_index == -1)
    {
        return false;
    }


    this->list_of_interest_key_linkedlist.dellKey(my_key);
    this->list_of_interest_linklist.remove(my_index);
    long long first_index = findKeyInString(my_key, my_str);
    string my_str_copy =my_str.toLocal8Bit().constData();
    my_str_copy.erase(first_index, countDigit(my_key) + 1);
    QString my_str_2 = QString::fromStdString(my_str_copy);
    this->setListOfInterest(my_str_2);
    if (first_index == -1)
    {
        return false;
    }
    return true;

}

bool Users::operator==(Users user)
{
    if (this->level_of_access == user.level_of_access && this->name == user.name && this->lastname == user.lastname &&
        this->username == user.username &&
        this->email == user.email &&
        this->key == user.key &&
        this->password == user.password &&
        this->password_power == user.password_power &&
        this->date_of_created == user.date_of_created &&
        this->date_of_last_enter == user.date_of_last_enter &&
        this->date_of_last_exit == user.date_of_last_exit &&
        this->money == user.money &&

        this->list_of_buy_before == user.list_of_buy_before &&
        this->list_of_interest == user.list_of_interest &&
        this->address == user.address &&
        this->mobile_number == user.mobile_number&&
        this->post_code == user.post_code &&
        this->city == user.city && this->state == user.state)
    {
        return true;
    }
    return false;
}

void Users::operator=(Users user) // Edited By Arash
{
    this->level_of_access = user.level_of_access;
    this->name = user.name;
    this->lastname = user.lastname;
    this->username = user.username;
    this->email = user.email;
    this->key = user.key;
    this->password = user.password;
    this->password_power = user.password_power;
    this->date_of_created = user.date_of_created;
    this->date_of_last_enter = user.date_of_last_enter;
    this->date_of_last_exit = user.date_of_last_exit;
    this->money = user.money;


    this->list_of_buy_before = user.list_of_buy_before;
    this->list_of_buy_before_linklist = user.list_of_buy_before_linklist;
    this->list_of_buy_before_key_linkedlist = user.list_of_buy_before_key_linkedlist;

    this->list_of_interest = user.list_of_interest;
    this->list_of_interest_linklist = user.list_of_interest_linklist;
    this->list_of_interest_key_linkedlist = user.list_of_interest_key_linkedlist;

    this->address = user.address;
    this->mobile_number = user.mobile_number;
    this->post_code = user.post_code;
    this->state = user.state;
    this->city = user.city;

    return;
}

