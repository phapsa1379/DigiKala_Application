#include "LinkedListMessage.h"

#include <iostream>
#include <QTextStream>
#include <QFile>
#include "ExternalFunctions.h"



LinkedListMessage::LinkedListMessage() {

    head = tail = nullptr;
    return;
}

LinkedListMessage::LinkedListMessage(const LinkedListMessage& linkedList)
    :head(nullptr)
    , tail(nullptr)
{
    NodeMessage* temp = linkedList.head;

    while (temp != nullptr)
    {
        pushBack(temp->getData());
        temp = temp->getNext();
    }

    return;
}

LinkedListMessage::LinkedListMessage(LinkedListMessage&& linkedList) {

    head = linkedList.head;
    tail = linkedList.tail;
    linkedList.head = linkedList.tail = nullptr;
    return;
}

LinkedListMessage::~LinkedListMessage() {

    NodeMessage* temp = head;
    NodeMessage* t = nullptr;

    while (temp != nullptr)
    {
        t = temp->getNext();
        delete temp;
        temp = nullptr;
        temp = t;
    }

    head = tail = nullptr;

    return;
}

void LinkedListMessage::setHead(NodeMessage* h) {

    head = h;
    return;
}

void LinkedListMessage::setTail(NodeMessage* t) {

    tail = t;
    return;
}

void LinkedListMessage::addFront(Message p) {

    NodeMessage* temp = new NodeMessage();
    temp->setData(p);
    if (size() > 0) {
        temp->setNext(head);
        head->setPreV(temp);
        head = temp;
    }
    else {
        tail = head = temp;
    }
    return;
}

void LinkedListMessage::pushBack(Message p) {

    NodeMessage* temp = new NodeMessage();
    temp->setData(p);

    if (size() > 0) {
        temp->setPreV(tail);
        tail->setNext(temp);
        tail = temp;
    }
    else {
        head = tail = temp;
    }
    return;
}

NodeMessage* LinkedListMessage::getHead() {

    return head;
}
NodeMessage* LinkedListMessage::getTail() {

    return tail;
}

void LinkedListMessage::print() {

    qStdOut() << "\nPrinting LinkedListMessage elements: \n" << endl;
    NodeMessage* temp = head;
    while (temp != nullptr) {
        qStdOut() << "Key Sender: " << temp->getData().getKeySender() << endl;
        qStdOut() << "Key Reciever: " << temp->getData().getKeyReciever() << endl;
        qStdOut() << "Text: " << temp->getData().getText() << endl;
        qStdOut() << "Date: " << temp->getData().getDate() << endl;
        qStdOut() << "***************************\n";
        temp = temp->getNext();
    }
    qStdOut() << endl;
}


int LinkedListMessage::size(){

    NodeMessage* temp = head;
    int i = 0;
    while (temp != nullptr){
        temp = temp->getNext();
        i++;
    }
    return i;
}


Message LinkedListMessage::get(int index) {

    const int SIZE = size();

    if (index < SIZE) {
        NodeMessage* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->getNext();
        }
        return temp->getData();
    }
    else {
        std::cerr << "Out of Range error: " << "Size Of Product: "
                  << SIZE << "\nTagert Index: " << index << '\n';
        exit(1);
    }
}


void LinkedListMessage::writeFile() {

    qStdOut() << "Writing LinkedListMessage elements: \n" << endl;

    QFile file("messageFile.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qStdOut() << "Couldn't open product_file.txt " << endl;
        return;
    }

    QTextStream out(&file);

    NodeMessage* temp = head;
    while (temp != nullptr) {

        out << "Text: " << temp->getData().getText() << endl;
        out << "Date: " << temp->getData().getDate() << endl;
        out << "Key Of Sender: " << temp->getData().getKeySender() << endl;
        out << "Key Of Reciever: " << temp->getData().getKeyReciever() << endl;
        out << "***************************" << endl;

        temp = temp->getNext();
    }

    file.close();
    return;
}


void LinkedListMessage::readFile() {

    QFile file("messageFile.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        qStdOut() << "Couldn't open messageFile.txt " << endl;
        return;
    }

    QTextStream in(&file);
    QString str = "";
    QString line = in.readLine();
    while (!line.isNull()) {
        Message p;

        str = line.mid(6);
        p.setText(str);
        line = in.readLine();

        str = line.mid(6);
        p.setDate(str);
        line = in.readLine();

        str = line.mid(15);
        p.setKeySender(str.toULongLong());
        line = in.readLine();

        str = line.mid(17);
        p.setKeyReciever(str.toULongLong());
        line = in.readLine();

        this->pushBack(p);

        line = in.readLine();
    }

    file.close();
    return;
}


void LinkedListMessage::remove(const unsigned long long key1, const unsigned long long key2){

    NodeMessage* temp = head;
    Message data;
    LinkedListMessage tempList;

    while (temp != nullptr){

        data = temp->getData();
        if (!((data.getKeySender() == key1 && data.getKeyReciever() == key2)
              || (data.getKeySender() == key2 && data.getKeyReciever() == key1))){

            tempList.pushBack(data);
        }
        temp = temp->getNext();
    }

    this->~LinkedListMessage();

    temp = tempList.getHead();

    while(temp != nullptr){
        this->pushBack(temp->getData());
        temp = temp->getNext();
    }

}




LinkedListMessage LinkedListMessage::operator=(LinkedListMessage x)
{
    this->~LinkedListMessage();
    NodeMessage* temp = x.getHead();
    while (temp)
    {
        this->pushBack(temp->getData());
        temp = temp->getNext();
    }
    return *this;
}
