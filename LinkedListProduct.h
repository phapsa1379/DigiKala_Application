#ifndef _LinkedListProduct_
#define _LinkedListProduct_

#include "NodeProduct.h"
#include "KeyLinkedList.h"





class LinkedListProduct {

private:

    NodeProduct* head;
    NodeProduct* tail;

public:

    LinkedListProduct();
    LinkedListProduct(const LinkedListProduct& linkedList);
    LinkedListProduct(LinkedListProduct&& linkedList);
    ~LinkedListProduct();

    void setHead(NodeProduct* h);
    void setTail(NodeProduct* t);
    void addFront(Product p);
    void pushBack(Product p);
    void print();

    void insertAt(int index, Product p); // insert object p in index and shift the other elemetns one step forward:
    // For example:
    // insert(1, p) in {p2, p3, p4, p5} results in {p2, p1, p3, p4, p5}
    void sortAscending(QString type);
    void sortDescending(QString type);
    void replace(int i, Product c);
    void shift(int i, int j);
    bool isEmpty();

    void remove(int index);
    Product get(int i);
    NodeProduct& getByKey(unsigned long long key);

    int findIndexByKey(unsigned long long key);
    int size();
    int indexOf(QString name);

    NodeProduct* getHead();
    NodeProduct* getTail();

    void writeFile();
    void readFile();




    // ADDED BY NAVID:
    void operator=(LinkedListProduct x);
    bool operator==(LinkedListProduct x);
    LinkedListProduct createLinklistFromKey(KeyLinkedList key_list , LinkedListProduct main_list);

};

#endif

