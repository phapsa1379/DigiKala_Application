#ifndef TLinkedListUser_ASDFGHJK
#define TLinkedListUser_ASDFGHJK
#include "TNodeUser.h"
#include "Users.h"
#include "Dealer.h"
//#pragma warning (disable : 4996)
using namespace std;

template<class N>
class TLinkedListUser
{
	TNodeUser<N>* head;
	TNodeUser<N>* tail;

public:
    template<class N1>friend ostream& operator<< (ostream & out , TLinkedListUser<N1> );


	TLinkedListUser();
    ~TLinkedListUser(); // Edited By Arash
	TLinkedListUser(const TLinkedListUser& list);
	TLinkedListUser(TLinkedListUser&& list);


	void setHead(TNodeUser<N>* head);
	void setTail(TNodeUser<N>* tail);
	TNodeUser<N>* getHead();
	TNodeUser<N>* getTail();


	void pushBack(N newData);
	void addFront(N newData);
	bool removeKey(unsigned long long key);
	N pop();//delete first Node of linkedList
	N popEnd();//delete last node of linkedList
  //  N findUserByKey(int key);
   // bool replaceUserByKey(long long key , N user);

	TLinkedListUser<N> operator=(TLinkedListUser<N> list);
	TLinkedListUser<N> operator+(TLinkedListUser<N> list);
	TLinkedListUser<N> operator+(N value);
	TLinkedListUser<N> operator-(N value); //can't delete value from linklist because not exist two Node whit same Key
    TNodeUser<N>& operator[](int index);// if index bigger than real max of index -> create new Node

	
	//TLinkedListUser<N> readFromeFileUser();
    void writeToFileUser();
    void readFromFileUser();
    long long isInclude(QString username , QString password);
	//void appendToFileUser(const string& file_name);
	
      // N operator[](int index);// if index bigger than real max of index -> create new Node

       TNodeUser<N>& getByKey(unsigned long long key);
       int size();



	
};
//template<class T>
//ostream& operator<< (ostream& out , TLinkedListUser<T> list);


#endif
