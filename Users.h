#ifndef Users_ABCDEFG
#define Users_ABCDEFG
//#include <string>
//#include <QString>I
//#include <iostream>
#include "LinkedListProduct.h"
#include "KeyLinkedList.h"
using namespace std;

enum user_type{/*ADMIN, */DEALER, USER};

class Users
{
private:
	unsigned long long int key = 0;
	int level_of_access = 3;//1 = admen / 2 = dealer / 3=user
    QString name="";//arbitrary
    QString lastname = "";//arbitrary
    QString username = "";//necessary
    QString email = "";
    QString password = "";
	int password_power=0;
	double money = 0.0;
    QString date_of_last_enter = "";
    QString date_of_last_exit = "";
    QString date_of_created = "";
	

    QString list_of_buy_before = "";
	KeyLinkedList list_of_buy_before_key_linkedlist;
	LinkedListProduct list_of_buy_before_linklist;
	

	
    QString list_of_interest = "";
	KeyLinkedList list_of_interest_key_linkedlist;
	LinkedListProduct list_of_interest_linklist;
	
    QString address = "";//before
    QString mobile_number = "";
    QString post_code = "";
    QString state = "";
    QString city = "";



public:
	Users();
	~Users();
	Users(const Users& user);
	Users(Users&& user);
	//set functions
    void setAddress(const QString& address);
    void setMobileNumber(const QString& mobileNum);
    void setPostCode(const QString& pc);
	void setKey(unsigned long long key);
	void setLevelOfAccess(int a);
	void setMoney(double money);
    void setName(const QString& name);
    void setLastName(const QString& lastname);
    void setUserName(const QString& username);
    void setDateOfLastEnter(const QString& date);
    void setDateOfLastExit(const QString& date);
    void setDateOfCreated(const QString& date);
	
//    void setBuyBasket(const QString& list);
//	void setBuyBasketkeyLinkedList(KeyLinkedList list);
//	void setBuyBasketLinkList(LinkedListProduct list);
	
    void setListOfBuyBefore(const QString& list);
	void setListOfBuyBeforeKeyLinkedList(KeyLinkedList list);
	void setListOfBuyBeforeLinkList(LinkedListProduct list);
	
//    void setListOfBuyAfter(const QString& list);
//	void setListOfBuyAfterKeyLinkedList(KeyLinkedList list);
//	void setListOfBuyAfterLinkList(LinkedListProduct list);
	
    void setListOfInterest(const QString& list);
	void setListOfInterestKeyLinkedList(KeyLinkedList list);
	void setListOfInterestLinkList(LinkedListProduct list);
	
    void setPassword(const QString& pass);
    void setPassswordPower(QString pass);
    void setEmail(const QString& email);
    //void setCountry(const QString& country);
    void setState(const QString & state);
    void setCity(const QString & city);



	//get functions
	unsigned long long getKey();
	int getLevelOfAccess();
	double getMoney();
    QString getName();
    QString getLastName();
    QString getUserName();
    QString getDateOfLastEnter();
    QString getDateOfLastExit();
    QString getDateOfCreated();
	
//    QString getBuyBasket();
//	KeyLinkedList getBuyBasketKeyLinkedList();
//	LinkedListProduct getBuyBasketLinkList();
	
    QString getListOfBuyBefore();
	KeyLinkedList getListOfBuyBeforeKeyLinkedList();
	LinkedListProduct getListOfBuyBeforeLinkList();
	
//    QString getListOfBuyAfter();
//	KeyLinkedList getListOfBuyAfterKeyLinkedList();
//	LinkedListProduct getListOfBuyAfterLinkList();
	
    QString getListOfInterest();
	KeyLinkedList getListOfInterestKeyLinkedList();
	LinkedListProduct getListOfInterestLinkList();
	
    QString getAddress();
    QString getMobileNumber();
    QString getPostCode();
    QString getPassword();
	int getPasswordPower();
    QString getEmail();
    //QString getCountry();
    QString getCity();
    QString getState();


	//other functions
    void print();
	bool operator==(Users user);
    void operator=(Users user); // Edited By Arash


    //bool addKeyToBuyBasket(Product product);
	bool addKeyToListOfBuyBefore(Product product);
    //bool addkeyToListOfBuyAfter(Product product);
	bool addKeyToListOfInterest(Product product);


    //bool deleteProductFromBuyBasket(Product product);
	bool deleteProductFromListOfBuyBefore(Product product);
    //bool deleteProductFromListOfBuyAfter(Product product);
	bool deleteProductToListOfInterest(Product product);
	
};

#endif
