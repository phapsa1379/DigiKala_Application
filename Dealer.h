#ifndef Dealer_ADFGHJM
#define Dealer_ADFGHJM
#include "Users.h"


class Dealer : public Users
{
    QString compony_name;
    QString list_of_sell = "";
    KeyLinkedList list_of_sell_key_linkedlist;
    LinkedListProduct list_of_sell_linklist;

public:
	Dealer();
	~Dealer();
	Dealer(Dealer& user);
	Dealer(Dealer&& user);
    void setComponyName(const QString& c_name);
    QString getComponyName() const;
    //////////
    void setListOfSell(QString list);
    void setListOfSellKeyLinkedList(KeyLinkedList list);
    void setListOfSellLinkList(LinkedListProduct list);

    QString getListOfSell();
    KeyLinkedList getListOfSellKeyLinkedList();
    LinkedListProduct getListOfSellLinkList();
    ////////////
    void printDealer();
	bool operator== (Dealer user);
    void operator=(Dealer d);// Edited By Arash

    bool addKeyToListOfSell(Product product);
    bool deleteProductToListOfSell(Product product);


};




#endif
