#include "KeyLinkedList.h"
#include <QDebug>

KeyLinkedList::KeyLinkedList()
{
    this->head = this->tail = nullptr;
    return;
}




KeyLinkedList::KeyLinkedList(const KeyLinkedList& list)
    : head(nullptr) ,
      tail(nullptr)
{
    KeyNode* temp = list.head;
    while (temp)
    {
        this->pushBack(temp->getKey());

        temp = temp->getNext();
    }

    return;

}

KeyLinkedList::KeyLinkedList(KeyLinkedList&& list)
{
    this->head = list.head;
    this->tail = list.tail;
    list.head = list.tail = nullptr;
    return;
}

KeyLinkedList::~KeyLinkedList() // Edited By Arash
{
    KeyNode* temp = this->head;
    KeyNode* t = nullptr;

    while (temp)
    {
        t = temp->getNext();
        delete temp;
        temp = nullptr;
        temp = t;
    }

    head = tail = nullptr;
    return;
}


void KeyLinkedList::setHead(KeyNode* head)
{
    this->head = head;
    return;
}

void KeyLinkedList::setTail(KeyNode* tail)
{
    this->tail = tail;
    return;
}


KeyNode* KeyLinkedList::getHead()
{
    return this->head;

}
KeyNode* KeyLinkedList::getTail()
{
    return  this->tail;

}

void KeyLinkedList::pushBack(unsigned long long  key)
{

    if(this->head == nullptr)
    {
        addFront(key);
        return;
    }
    KeyNode* new_node = new KeyNode(key, nullptr, this->tail);
    this->tail->setNext(new_node);
    this->tail = new_node;
    return;
}

void KeyLinkedList::addFront(unsigned long long  key)
{
    KeyNode* new_node = new KeyNode(key, this->head, nullptr);
    if(this->head)
        this->head->setPrev(new_node);
    this->head = new_node;
    if(this->tail == nullptr)
    {
        this->tail = new_node;
    }

    return;
}

bool KeyLinkedList::dellKey(unsigned long long  key)
{//????????????????????
    if(this->head->getKey() == key)
    {
        KeyNode* temp = this->head;
        this->head = temp->getNext();
        temp = nullptr;
        delete temp;
        return true;

    }
    else if (this->tail->getKey() == key)
    {
        KeyNode* temp = this->tail;
        this->tail = temp->getPrev();
        temp = nullptr;
        delete temp;
        return true;
    }


    KeyNode* temp = this->head->getNext();
    while (temp)
    {
        if(temp->getKey() == key)
        {
            KeyNode* temp_next = temp->getNext();
            KeyNode* temp_prev = temp->getPrev();
            temp_prev->setNext(temp_next);
            temp_next->setPrev(temp_prev);
            temp = nullptr;
            delete temp;
            return true;
        }



        temp = temp->getNext();
    }
    return false;
}


void KeyLinkedList::operator=(KeyLinkedList x)
{
    this->~KeyLinkedList();
    KeyNode* t = x.getHead();
    while (t)
    {
        this->pushBack(t->getKey());
        t = t->getNext();
    }
    return;
}


unsigned long long KeyLinkedList::get(int index){

    const int SIZE = size();

    if (index < SIZE) {
        KeyNode* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->getNext();
        }
        return temp->getKey();
    }
    else {

        exit(1);
    }
}



int KeyLinkedList::size(){ // Added By Arash

    KeyNode* temp = head;

    int i = 0;
    while (temp != nullptr){

        temp = temp->getNext();
        i++;
    }

    return i;
}



// Added By Arash
bool KeyLinkedList::containsKey(unsigned long long key){

    KeyNode *temp = head;
    while (temp != nullptr){
        if (temp->getKey() == key)
            return true;
        temp = temp->getNext();
    }
    return false;
}

void KeyLinkedList::print()
{

    KeyNode *temp = head;
    while (temp)
    {

        temp = temp->getNext();
    }
}



