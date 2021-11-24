#ifndef KeyLinkedList_12323
#define KeyLinkedList_12323
#include "KeyNode.h"
class KeyLinkedList
{
private:
	KeyNode* head;
	KeyNode* tail;   
public:
	KeyLinkedList();
	~KeyLinkedList();
	KeyLinkedList(const KeyLinkedList&);
	KeyLinkedList(KeyLinkedList&&);

	void setHead(KeyNode* head);
	void setTail(KeyNode* tail);

	KeyNode* getHead();
	KeyNode* getTail();

    
    void pushBack(unsigned long long  key);
    void addFront(unsigned long long  key);
    bool dellKey(unsigned long long  key);
    void print();
    bool containsKey(unsigned long long key); // Added By Arash
    int size();
    unsigned long long get(int index);

    void operator=(KeyLinkedList x);
    
};

#endif 

