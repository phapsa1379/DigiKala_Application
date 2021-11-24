#ifndef _LinkedListMessage_
#define _LinkedListMessage_

#include "NodeMessage.h"





class LinkedListMessage {

private:

    NodeMessage* head;
    NodeMessage* tail;

public:

    LinkedListMessage();
    LinkedListMessage(const LinkedListMessage& linkedList);
    LinkedListMessage(LinkedListMessage&& linkedList);
    ~LinkedListMessage();

    void setHead(NodeMessage* h);
    void setTail(NodeMessage* t);
    void addFront(Message p);
    void pushBack(Message p);
    void print();

    // For example:
    // insert(1, p) in {p2, p3, p4, p5} results in {p2, p1, p3, p4, p5}
    bool isEmpty();

    Message get(int i);

    int size();

    NodeMessage* getHead();
    NodeMessage* getTail();

    void writeFile();
    void readFile();

    void remove(const unsigned long long key1, const unsigned long long key2);

    LinkedListMessage operator=(LinkedListMessage x);


};

#endif

