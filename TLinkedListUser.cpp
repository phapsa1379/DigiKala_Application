#include <iostream>
#include "TLinkedListUser.h"
//#include "ExternalFunctions.h"
#include <fstream>
#include <sstream>
#include <TNodeUser.h>
#include "LinkedListProduct.h"
#include "KeyLinkedList.h"
#include "ExternalFunctions.h"
#include "Global.h"
using namespace GlobalNameSpace;
//#include "Users.h"
//#include "Dealer.h"



template <class N>
void TLinkedListUser<N> ::writeToFileUser()
{
	TNodeUser<N>* n_user = this->head;

    ofstream users_file("UsersFile.txt");
	while (n_user)
	{
		N user = n_user->getData();

        //string level_of_access;//1 = admen / 2 = dealer / 3=user
        string name = user.getName().toLocal8Bit().constData();//arbitrary
        string lastname = user.getLastName().toLocal8Bit().constData();//arbitrary
        string username = user.getUserName().toLocal8Bit().constData();//necessary
        string email = user.getEmail().toLocal8Bit().constData();
        string password = user.getPassword().toLocal8Bit().constData();

        string date_of_last_enter = user.getDateOfLastEnter().toLocal8Bit().constData();
        string date_of_last_exit = user.getDateOfLastExit().toLocal8Bit().constData();
        string date_of_created = user.getDateOfCreated().toLocal8Bit().constData();
        string list_of_buy_before = user.getListOfBuyBefore().toLocal8Bit().constData();
        string list_of_interest = user.getListOfInterest().toLocal8Bit().constData();
        string address = user.getAddress().toLocal8Bit().constData();//before
        string mobile_number = user.getMobileNumber().toLocal8Bit().constData();
        string post_code = user.getPostCode().toLocal8Bit().constData();
        string state = user.getState().toLocal8Bit().constData();
        string city = user.getCity().toLocal8Bit().constData();



        //////////////////////////////

		users_file << user.getKey() << endl;
        users_file << name << endl;
        users_file << lastname << endl;
        users_file << username << endl;
		users_file <<to_string(user.getLevelOfAccess()) << endl;
        users_file << email<< endl;
        users_file << mobile_number << endl;
        users_file << password << endl;
		users_file << user.getPasswordPower() << endl;
		users_file << user.getMoney() << endl;
        users_file << post_code << endl;
        users_file << address << endl;
        users_file << date_of_created << endl;
        users_file << date_of_last_enter << endl;
        users_file << date_of_last_exit << endl;

        users_file << list_of_buy_before<< endl;
        users_file << list_of_interest << endl;
        users_file << state <<endl;
        users_file << city<<endl;

		n_user = n_user->getNext();
	}
	users_file.close();

	return;
}

template <>
void TLinkedListUser<Dealer> ::writeToFileUser()
{
	TNodeUser<Dealer>* n_user = this->head;
    ofstream users_file("DealersFile.txt");
	while (n_user)
	{
		Dealer user = n_user->getData();

        string name = user.getName().toLocal8Bit().constData();//arbitrary
        string lastname = user.getLastName().toLocal8Bit().constData();//arbitrary
        string username = user.getUserName().toLocal8Bit().constData();//necessary
        string email = user.getEmail().toLocal8Bit().constData();
        string password = user.getPassword().toLocal8Bit().constData();
        string date_of_last_enter = user.getDateOfLastEnter().toLocal8Bit().constData();
        string date_of_last_exit = user.getDateOfLastExit().toLocal8Bit().constData();
        string date_of_created = user.getDateOfCreated().toLocal8Bit().constData();
        string list_of_buy_before = user.getListOfBuyBefore().toLocal8Bit().constData();
        string list_of_interest = user.getListOfInterest().toLocal8Bit().constData();
        string address = user.getAddress().toLocal8Bit().constData();//before
        string mobile_number = user.getMobileNumber().toLocal8Bit().constData();
        string post_code = user.getPostCode().toLocal8Bit().constData();
        string company_name = user.getComponyName().toLocal8Bit().constData();
        string list_of_sell = user.getListOfSell().toLocal8Bit().constData();
        string state = user.getState().toLocal8Bit().constData();
        string city = user.getCity().toLocal8Bit().constData();

		users_file << user.getKey() << endl;
        users_file << name << endl;
        users_file << lastname << endl;
        users_file << username << endl;
		users_file << to_string(user.getLevelOfAccess()) << endl;
        users_file << email<< endl;
        users_file << mobile_number << endl;
        users_file << password << endl;
		users_file << user.getPasswordPower() << endl;
		users_file << user.getMoney() << endl;
        users_file << post_code << endl;
        users_file << address << endl;
        users_file << date_of_created << endl;
        users_file << date_of_last_enter << endl;
        users_file << date_of_last_exit << endl;
        users_file << list_of_buy_before << endl;
        users_file << list_of_interest << endl;
		
        users_file << company_name << endl;
        users_file << list_of_sell << endl;
        users_file << state <<endl;
        users_file << city << endl;
		
		n_user = n_user->getNext();
	}
	users_file.close();

	return;
}


template<class N>
void TLinkedListUser<N> :: readFromFileUser()
{
	this->~TLinkedListUser();
    ifstream users_file("UsersFile.txt");
	
    string key;
	string level_of_access;//1 = admen / 2 = dealer / 3=user
	string name;//arbitrary
	string lastname;//arbitrary
	string username;//necessary
	string email;
	string password;
	string password_power;
	string money;
	string date_of_last_enter;
	string date_of_last_exit;
	string date_of_created;
    //string buy_basket = "";//
    string list_of_buy_before = "";//
   // string list_of_buy_after = "";//
    string list_of_interest = "";//
	string address = "";//before
	string mobile_number = "";
	string post_code;
    string state;
    string city;

    LinkedListProduct buy_before_linkedlist;
    LinkedListProduct interest_linkedlist;

    KeyLinkedList buy_key_before_linkedlist;
    KeyLinkedList interest_key_linkedlist;


		while (getline(users_file, key))
		{
			N user;
			
			getline(users_file, name);
			getline(users_file, lastname);
			getline(users_file, username);
			getline(users_file, level_of_access);
			getline(users_file, email);
			getline(users_file, mobile_number);
			getline(users_file, password);
			getline(users_file, password_power);
			getline(users_file, money);
			getline(users_file, post_code);
			getline(users_file, address);
			getline(users_file, date_of_created);
			getline(users_file, date_of_last_enter);
			getline(users_file, date_of_last_exit);

			getline(users_file, list_of_buy_before);
			getline(users_file, list_of_interest);
            getline(users_file, state);
            getline(users_file , city);

            QString qkey = QString::fromStdString(key);
            QString qlevel_of_access= QString::fromStdString(level_of_access);//1 = admen / 2 = dealer / 3=user
            QString qname= QString::fromStdString(name);//arbitrary
            QString qlastname= QString::fromStdString(lastname);//arbitrary
            QString qusername= QString::fromStdString(username);//necessary
            QString qemail= QString::fromStdString(email);
            QString qpassword= QString::fromStdString(password);
            QString qpassword_power= QString::fromStdString(password_power);
            QString qmoney= QString::fromStdString(money);
            QString qdate_of_last_enter= QString::fromStdString(date_of_last_enter);
            QString qdate_of_last_exit= QString::fromStdString(date_of_last_exit);
            QString qdate_of_created= QString::fromStdString(date_of_created);
            //QString qbuy_basket = QString::fromStdString(buy_basket);
            QString qlist_of_buy_before = QString::fromStdString(list_of_buy_before);
            //QString qlist_of_buy_after = QString::fromStdString(list_of_buy_after);
            QString qlist_of_interest = QString::fromStdString(list_of_interest);
            QString qaddress = QString::fromStdString(address);
            QString qmobile_number = QString::fromStdString(mobile_number);
            QString qpost_code= QString::fromStdString(post_code);
            QString qstate = QString::fromStdString(state);
            QString qcity = QString :: fromStdString(city);

            user.setKey(stoll(key));
			user.setLevelOfAccess(stoi(level_of_access));
            user.setName(qname);
            user.setLastName(qlastname);
            user.setUserName(qusername);
            user.setEmail(qemail);
            user.setPassword(qpassword);
            user.setPassswordPower(qpassword_power);
            user.setDateOfCreated(qdate_of_created);
            user.setDateOfLastEnter(qdate_of_last_enter);
            user.setDateOfLastExit(qdate_of_last_exit);
			user.setMoney(stod(money));
            user.setListOfBuyBefore(qlist_of_buy_before);
            user.setListOfInterest(qlist_of_interest);
            user.setAddress(qaddress);
            user.setPostCode(qpost_code);
            user.setMobileNumber(qmobile_number);
            user.setState(qstate);
            user.setCity(qcity);
            ///////////////////fill key linkedList :
            interest_key_linkedlist = keyConvertStringToLinkedList(qlist_of_interest);
            buy_key_before_linkedlist = keyConvertStringToLinkedList(qlist_of_buy_before);
            ///set key linkedList :
            user.setListOfBuyBeforeKeyLinkedList(buy_key_before_linkedlist);
            user.setListOfInterestKeyLinkedList(interest_key_linkedlist);
            ///////////////////////fill product linkedList :
            buy_before_linkedlist.createLinklistFromKey(buy_key_before_linkedlist , Globals::PRODUCT_LIST);
            interest_linkedlist.createLinklistFromKey(interest_key_linkedlist , Globals::PRODUCT_LIST);
            ///set product linkedList :
            user.setListOfBuyBeforeLinkList(buy_before_linkedlist);
            user.setListOfInterestLinkList(interest_linkedlist);

			
			this->pushBack(user);
	}
		return;
	
}

template<>
void TLinkedListUser<Dealer> ::readFromFileUser()
{
	this->~TLinkedListUser();

    ifstream users_file("DealersFile.txt");

	string key;
	string level_of_access;//1 = admen / 2 = dealer / 3=user
	string name;//arbitrary
	string lastname;//arbitrary
	string username;//necessary
	string email;
	string password;
	string password_power;
	string money;
	string date_of_last_enter;
	string date_of_last_exit;
	string date_of_created;
    string list_of_buy_before = "";
    string list_of_interest = "";
    string address = "";
	string mobile_number = "";
	string post_code;
	string companey;
    string list_of_sell;
    string state;
    string city;
    LinkedListProduct buy_before_linkedlist;
    LinkedListProduct interest_linkedlist;
    LinkedListProduct sell_linkedlist;

    KeyLinkedList buy_key_before_linkedlist;
    KeyLinkedList interest_key_linkedlist;
    KeyLinkedList sell_key_linkedlist;


	while (getline(users_file, key))
	{
		Dealer user;

		getline(users_file, name);
		getline(users_file, lastname);
		getline(users_file, username);
		getline(users_file, level_of_access);
		getline(users_file, email);
		getline(users_file, mobile_number);
		getline(users_file, password);
		getline(users_file, password_power);
		getline(users_file, money);
		getline(users_file, post_code);
		getline(users_file, address);
		getline(users_file, date_of_created);
		getline(users_file, date_of_last_enter);
		getline(users_file, date_of_last_exit);

		getline(users_file, list_of_buy_before);
		getline(users_file, list_of_interest);
		getline(users_file, companey);
        getline(users_file, list_of_sell);
        getline(users_file,state);
        getline(users_file,city);

        QString qkey = QString::fromStdString(key);
        QString qlevel_of_access= QString::fromStdString(level_of_access);//1 = admen / 2 = dealer / 3=user
        QString qname= QString::fromStdString(name);//arbitrary
        QString qlastname= QString::fromStdString(lastname);//arbitrary
        QString qusername= QString::fromStdString(username);//necessary
        QString qemail= QString::fromStdString(email);
        QString qpassword= QString::fromStdString(password);
        QString qpassword_power= QString::fromStdString(password_power);
        QString qmoney= QString::fromStdString(money);
        QString qdate_of_last_enter= QString::fromStdString(date_of_last_enter);
        QString qdate_of_last_exit= QString::fromStdString(date_of_last_exit);
        QString qdate_of_created= QString::fromStdString(date_of_created);
        QString qlist_of_buy_before = QString::fromStdString(list_of_buy_before);
        QString qlist_of_interest = QString::fromStdString(list_of_interest);
        QString qaddress = QString::fromStdString(address);
        QString qmobile_number = QString::fromStdString(mobile_number);
        QString qpost_code= QString::fromStdString(post_code);

        QString qcompaney = QString::fromStdString(companey);
        QString qlist_of_sell = QString::fromStdString(list_of_sell);

        QString qstate = QString::fromStdString(state);
        QString qcity = QString :: fromStdString(city);

        user.setKey(stoll(key));
		user.setLevelOfAccess(stoi(level_of_access));
        user.setName(qname);
        user.setLastName(qlastname);
        user.setUserName(qusername);
        user.setEmail(qemail);
        user.setPassword(qpassword);
        user.setPassswordPower(qpassword);
        user.setDateOfCreated(qdate_of_created);
        user.setDateOfLastEnter(qdate_of_last_enter);
        user.setDateOfLastExit(qdate_of_last_exit);
		user.setMoney(stod(money));

        user.setListOfBuyBefore(qlist_of_buy_before);
        user.setListOfInterest(qlist_of_interest);
        user.setAddress(qaddress);
        user.setPostCode(qpost_code);
        user.setMobileNumber(qmobile_number);
        user.setComponyName(qcompaney);
        user.setListOfSell(qlist_of_sell);
        user.setCity(qcity);
        user.setState(qstate);

        ///////////////////fill key linkedList :
        interest_key_linkedlist = keyConvertStringToLinkedList(qlist_of_interest);

        buy_key_before_linkedlist = keyConvertStringToLinkedList(qlist_of_buy_before);
        sell_key_linkedlist = keyConvertStringToLinkedList(qlist_of_sell);
        ///set key linkedList :
        user.setListOfBuyBeforeKeyLinkedList(buy_key_before_linkedlist);
        user.setListOfInterestKeyLinkedList(interest_key_linkedlist);
        user.setListOfSellKeyLinkedList(sell_key_linkedlist);
        ///////////////////////fill product linkedList :

        buy_before_linkedlist.createLinklistFromKey(buy_key_before_linkedlist , Globals::PRODUCT_LIST);
        interest_linkedlist.createLinklistFromKey(interest_key_linkedlist , Globals::PRODUCT_LIST);
        sell_linkedlist.createLinklistFromKey(sell_key_linkedlist ,Globals::PRODUCT_LIST );
        ///set product linkedList :
        user.setListOfBuyBeforeLinkList(buy_before_linkedlist);
        user.setListOfInterestLinkList(interest_linkedlist);
        user.setListOfSellLinkList(sell_linkedlist);


		this->pushBack(user);
	}
	return;

}




template class TLinkedListUser<Users>;
template class TLinkedListUser<Dealer>;




template<class N>
TLinkedListUser<N>::TLinkedListUser()
{
	this->head = nullptr;
	this->tail = nullptr;
	return;

}

template<class N>
TLinkedListUser<N>::~TLinkedListUser<N>() // Edited By Arash
{
    TNodeUser<N>* temp = head;
    TNodeUser<N>* temp2 = nullptr;

	while (temp)
	{
        temp2 = temp->getNext();
        delete temp;
		temp = nullptr;		
		temp = temp2;
	}

    head = tail = nullptr;
	return;
}

template<class N>
TLinkedListUser<N>::TLinkedListUser(const TLinkedListUser& list)
	: head(nullptr) , 
	tail(nullptr)
{
	TNodeUser<N>* temp = list.head;
	while (temp)
	{
		this->pushBack(temp->getData());
		temp = temp->getNext();
	}
	return;
}

template<class N>
TLinkedListUser<N>::TLinkedListUser(TLinkedListUser&& list)
{
	this->head = list.head;
	this->tail = list.tail;
	list.head = list.tail = nullptr;
	return;
}


//////////////set and get functions

template<class N>
void TLinkedListUser<N>::setHead(TNodeUser<N>* head)
{
	this->head = head;
	return;
}

template<class N>
void TLinkedListUser<N>::setTail(TNodeUser<N>* tail)
{
	this->tail = tail;
	return;
}

template<class N>
TNodeUser<N>* TLinkedListUser<N>::getHead()
{
	return this->head;
}

template<class N>
TNodeUser<N>* TLinkedListUser<N>::getTail()
{
	return this->tail;
}



/////////////other functions


template<class N>
void TLinkedListUser<N>::addFront(N newData)
{
	TNodeUser<N>* temp = new TNodeUser<N>(newData, this->head, nullptr);
	
	this->head = temp;
	if (this->tail == nullptr)
	{
		this->tail = temp;
	}
	else
	{
		temp->getNext()->setPrev(temp);
	}
	return;
}


template<class N>
void TLinkedListUser<N>::pushBack(N newData)
{
	if (this->head == nullptr)
	{
		addFront(newData);
		return;
	}


	TNodeUser<N>* temp = new TNodeUser<N>(newData, nullptr, this->tail);
	this->tail->setNext(temp);
	this->tail = temp;
	return;

}

template<class N>
N TLinkedListUser<N>::pop()
{
	TNodeUser<N>* temp1 = this->head;
	TNodeUser<N>* temp2 = this->head->getNext();
	N t = temp1->getData();
	temp1 = nullptr;
	delete temp1;
	temp2->setPrev(nullptr);
	this->head = temp2;

	return t;
}

template<class N>
N TLinkedListUser<N>::popEnd()
{
	TNodeUser<N>* temp1 = this->tail;
	TNodeUser<N>* temp2 = this->tail->getPrev();
	N t = temp1->getData();
	temp1 = nullptr;
	delete temp1;
	temp2->setNext(nullptr);
	this->tail = temp2;
    return t;
}



template<class N>
bool TLinkedListUser<N>::removeKey(unsigned long long key)
{
	TNodeUser<N>* temp = this->head;
	while (temp)
	{
		N t = temp->getData();
		if (t.getKey() == key)
		{
			if (!temp->getNext() && temp->getPrev())
			{
				this->popEnd();
				return true;
			}
			else if (temp->getNext() && !temp->getPrev())
			{
				this->pop();
				return true;
			}
			TNodeUser<N>* temp_prev = temp->getPrev();
			TNodeUser<N>* temp_next = temp->getNext();
			temp = nullptr;
			delete temp;
			temp_prev->setNext(temp_next);
			return true;

		}
		temp = temp->getNext();
	}


	return false;
}



template<class N>
TLinkedListUser<N> TLinkedListUser<N>::operator=(TLinkedListUser<N> list)
{
	this->~TLinkedListUser();
	TNodeUser<N>* temp = list.head;
	
	while (temp)
	{
		this->pushBack(temp->getData());
		temp = temp->getNext();	
	}

	return *this;
}

template<class N>
TLinkedListUser<N> TLinkedListUser<N>::operator+(TLinkedListUser<N> list)
{
	TNodeUser<N>* temp = this->head;
	TLinkedListUser<N> newlist;
	while (temp)
	{
		newlist.pushBack(temp->getData());
		temp = temp->getNext();
	}
	temp = list.getHead();
	while (temp)
	{
		newlist.pushBack(temp->getData());
		temp = temp->getNext();
	}
	return newlist;

}

template<class N>
TLinkedListUser<N> TLinkedListUser<N>::operator+(N value)
{
	TLinkedListUser<N> newlist;
	TNodeUser<N>* temp = this->getHead();
	while (temp)
	{
		newlist.pushBack(temp->getData());
		temp = temp->getNext();
	}
	newlist.pushBack(value);
	return newlist;
}


template<class N> 
TLinkedListUser<N> TLinkedListUser<N>::operator-(N value)
{

	
		TLinkedListUser<N> newlist;
		TNodeUser<N>* temp = this->head;
		while (temp)
		{
			if (temp->getData() == value)
			{
				temp = temp->getNext();
				continue;
			}
			newlist.pushBack(temp->getData());
			temp = temp->getNext();

		}
		return newlist;

	
}

template<class N> // Added By Arash
TNodeUser<N>& TLinkedListUser<N>::operator[](int index)
{
    TNodeUser<N>* temp = this->head;
        int i = 0;
        int IsTrue = 0;

        while (temp)
        {
            if (i == index)
            {
                IsTrue++;
                //break;
                return *temp;
            }
            TNodeUser<N>* temp2 = temp->getNext();

            if (!temp2)
            {
                N E;
                this->pushBack(E);

            }
            temp = temp->getNext();
            i++;
        }
        N E;
        this->pushBack(E);
        return *this->head;
}




template<class N>
long long TLinkedListUser<N> :: isInclude(QString username , QString password)
{
	TNodeUser<N>* temp = this->head;
	
	while (temp)
	{
		N data = temp->getData();
		if(username == data.getUserName())
		{
			if (password == data.getPassword())
			{
                return data.getKey();
			}
			
		}
		
		temp = temp->getNext();
	}
    return -1;
}
template<class N> // Added By Arash
int TLinkedListUser<N>::size(){

    int i = 0;
    TNodeUser<N>* temp = head;
    while (temp != nullptr) {
        i++;
        temp = temp->getNext();
    }
    return i;
}

template<class N> // Added By Arash
TNodeUser<N>& TLinkedListUser<N>::getByKey(unsigned long long key)
{

    TNodeUser<N>* temp =this->head;

    while(temp != nullptr)
    {
        if (temp->getData().getKey() == key)
        {
            return *temp;
        }
        temp = temp->getNext();
    }

    std::cerr << "No User found with key \'" << key << "\'";
    exit(0);
}


