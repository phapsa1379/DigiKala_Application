#include "LinkedListProduct.h"
#include "CurrentTime.h"
#include <QFile>
#include <istream>
#include <fstream>
#include <iostream>
#include <cctype>
#include <QString>
#include <QTextStream>
#include "EnumsProduct.h"
#include "ExternalFunctions.h"
#include "Global.h"

using namespace GlobalNameSpace;



LinkedListProduct::LinkedListProduct() {

    head = tail = nullptr;
    return;
}

LinkedListProduct::LinkedListProduct(const LinkedListProduct& linkedList)
    :head(nullptr)
    , tail(nullptr)
{
    NodeProduct* temp = linkedList.head;

    while (temp != nullptr)
    {
        pushBack(temp->getData());
        temp = temp->getNext();
    }

    return;
}

LinkedListProduct::LinkedListProduct(LinkedListProduct&& linkedList) {

    head = linkedList.head;
    tail = linkedList.tail;
    linkedList.head = linkedList.tail = nullptr;
    return;
}

LinkedListProduct::~LinkedListProduct() {

    NodeProduct* temp = head;
    NodeProduct* t = nullptr;

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

void LinkedListProduct::setHead(NodeProduct* h) {

    head = h;
    return;
}

void LinkedListProduct::setTail(NodeProduct* t) {

    tail = t;
    return;
}

void LinkedListProduct::addFront(Product p) {

    NodeProduct* temp = new NodeProduct();
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

void LinkedListProduct::pushBack(Product p) {

    NodeProduct* temp = new NodeProduct();
    temp->setData(p);

    const int SIZE = this->size();
    if (SIZE > 0) {
        temp->setPreV(tail);
        tail->setNext(temp);
        tail = temp;
    }
    else {
        head = tail = temp;
    }
    return;
}

NodeProduct* LinkedListProduct::getHead() {

    return head;
}
NodeProduct* LinkedListProduct::getTail() {

    return tail;
}

void LinkedListProduct::print() {

    qStdOut() << "\nPrinting LinkedList_Product elements: \n" << endl;
    NodeProduct* temp = head;
    while (temp != nullptr) {
        qStdOut() << "Name: " << temp->getData().getName() << endl;
        qStdOut() << "Code: " << temp->getData().getDateOfRegister() << endl;
        qStdOut() << "Category Name: " << temp->getData().getNameCategory() << endl;
        qStdOut() << "Creator: " << temp->getData().getCreator() << endl;
        qStdOut() << "Description: " << temp->getData().getDescription() << endl;
        qStdOut() << "Date: " << temp->getData().getDateOfRegister() << endl;
        qStdOut() << "Expiry Date: " << temp->getData().getDescription() << endl;
        qStdOut() << "Sell Price: " << temp->getData().getSellPrice() << endl;
        qStdOut() << "Active Condition: " << temp->getData().getActiveCondition() << endl;

        // بقیشو حال ندارم بنویسم
        qStdOut() << "***************************\n";
        temp = temp->getNext();
    }
    qStdOut() << endl;
}

void LinkedListProduct::insertAt(int index, Product p)
{
    if (index == 0) {
        addFront(p);
    }
    else {
        if (index >= size()) {
            pushBack(p);
        }
        else {
            NodeProduct* beforeIndex = head;
            NodeProduct* afterIndex = nullptr;
            NodeProduct* temp = new NodeProduct();
            temp->setData(p);
            for (int i = 0; i < index - 1; i++) {
                beforeIndex = beforeIndex->getNext();
            }

            afterIndex = beforeIndex->getNext();
            beforeIndex->setNext(temp);
            afterIndex->setPreV(temp);
            temp->setPreV(beforeIndex);
            temp->setNext(afterIndex);
        }
    }
    return;
}


int LinkedListProduct::size(){

    NodeProduct* temp = head;
    int i = 0;
    while (temp != nullptr){
        temp = temp->getNext();
        i++;
    }
    return i;
}


Product LinkedListProduct::get(int index) {

    const int SIZE = size();

    if (index < SIZE) {
        NodeProduct* temp = head;

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

void LinkedListProduct::replace(int index, Product c) {

    const int SIZE = size();

    if (index < SIZE) {
        NodeProduct* temp = new NodeProduct();
        temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->getNext();
        }
        temp->setData(c);
    }
    else {
        /*	std::cerr << "Out of Range error: " << "Size Of Product: "
                << SIZE << "\nTagert Index: " << index << '\n';
            exit(1);*/

        cerr << "Out of Range error: " << "Size Of Product: "
             << SIZE << "\nTagert Index: " << index << '\n';
    }
}

void LinkedListProduct::shift(int i, int j) {

    Product temp = get(i);
    replace(i, get(j));
    replace(j, temp);
}



void LinkedListProduct::sortAscending(QString type) {

    const int SIZE = size();

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {

            if (type == NAME_PRODUCT){
                if (get(i).getName().compare(get(j).getName()) > 0)
                    shift(i, j);
            }

            if (type == VIEW_NUMBER){
                if (get(i).getViewNumber() > get(j).getViewNumber())
                    shift(i, j);
            }

            if (type == RATING){
                if (get(i).getRating() > get(j).getRating())
                    shift(i, j);
            }

            if (type == SOLD_NUMBER){
                if (get(i).getSoldNumber() > get(j).getSoldNumber())
                    shift(i, j);
            }

            if (type == REGISTERATION_DATE){
                if (get(i).getDateOfRegister() > get(j).getDateOfRegister())
                    shift(i, j);
            }

            if (type == SELL_PRICE){
                if (get(i).getSellPrice() > get(j).getSellPrice())
                    shift(i, j);
            }

            if (type == COMPLAIN_NUMBER){
                if (get(i).getComplainNumber() > get(j).getComplainNumber())
                    shift(i, j);
            }
        }
    }
}

void LinkedListProduct::sortDescending(QString type) {

    const int SIZE = size();

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {

            if (type == NAME_PRODUCT){
                if (get(i).getName().compare(get(j).getName()) < 0)
                    shift(i, j);
            }

            if (type == VIEW_NUMBER){
                if (get(i).getViewNumber() < get(j).getViewNumber())
                    shift(i, j);
            }

            if (type == RATING){
                if (get(i).getRating() < get(j).getRating())
                    shift(i, j);
            }

            if (type == SOLD_NUMBER){
                if (get(i).getSoldNumber() < get(j).getSoldNumber())
                    shift(i, j);
            }

            if (type == REGISTERATION_DATE){
                if (get(i).getDateOfRegister() < get(j).getDateOfRegister())
                    shift(i, j);
            }

            if (type == SELL_PRICE){
                if (get(i).getSellPrice() < get(j).getSellPrice())
                    shift(i, j);
            }

            if (type == COMPLAIN_NUMBER){
                if (get(i).getComplainNumber() < get(j).getComplainNumber())
                    shift(i, j);
            }
        }
    }
}


void LinkedListProduct::remove(int index) {

    Product p = get(index);

    const int SIZE = size();

    if (index == 0) {

        if (SIZE == 1) {
            delete head;
            head = tail = nullptr;
        }
        else {
            head = head->getNext();
            head->setPreV(nullptr);
            delete head->getPreV();
            head->setPreV(nullptr);
        }
    }
    else if (index == SIZE - 1) {
        tail = tail->getPreV();
        tail->setNext(nullptr);
        delete tail->getNext();
        tail->setNext(nullptr);
    }
    else {
        NodeProduct* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->getNext();
        }

        temp->getPreV()->setNext(temp->getNext());
        temp->getNext()->setPreV(temp->getPreV());
        delete temp;
        temp = nullptr;
    }

    return;
}



bool LinkedListProduct::isEmpty()
{
    return size() == 0 ? true : false;
}

void LinkedListProduct::writeFile() {

    qStdOut() << "Writing LinkedList_Product elements: \n" << endl;

    QFile file("product_file.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qStdOut() << "Couldn't open product_file.txt " << endl;
        return;
    }

    QTextStream out(&file);

    NodeProduct* temp = head;
    while (temp != nullptr) {
        qStdOut() << "Writing LinkedList_Product elements22: \n" << endl;

        out << "Name: " << temp->getData().getName() << endl;
        out << "Code: " << temp->getData().getDateOfRegister() << endl;
        out << "Creator: " << temp->getData().getCreator() << endl;
        out << "Description: " << temp->getData().getDescription() << endl;
        out << "Date Of Creation: " << temp->getData().getDateOfCreation() << endl;
        out << "Color: " + temp->getData().getColor() << endl;
        out << "Sell Price: " << temp->getData().getSellPrice() << endl;

        out << "Pure Sell Price: " << temp->getData().getPureSellPrice() << endl;

        out << "Rating: " << temp->getData().getRating() << endl;
        out << "Off Precent: " << temp->getData().getOffPercent() << endl;
        out << "View Number: " << temp->getData().getViewNumber() << endl;
        out << "Available Number: " << temp->getData().getAvailableNumber() << endl;


        out << "Vote Number: " << temp->getData().getVoteNumber() << endl;


        out << "Active Condition: " << temp->getData().getActiveCondition() << endl;
        out << "Sold Number: " << temp->getData().getSoldNumber() << endl;
        out << "Complain Number: " << temp->getData().getComplainNumber() << endl;
        out << "Key Of Seller: " << temp->getData().getKeySeller() << endl;
        out << "Name Of Category: " << temp->getData().getNameCategory() << endl;
        out << "Key: " << temp->getData().getKey() << endl;
        out << "State: " << temp->getData().getState() << endl;
        out << "***************************" << endl;

        temp = temp->getNext();
    }

    file.close();
    return;
}


void LinkedListProduct::readFile() {

    QFile file("product_file.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        qStdOut() << "Couldn't open product_file.txt " << endl;
        return;
    }

    QTextStream in(&file);
    QString str = "";
    QString line = in.readLine();
    while (!line.isNull()) {
        Product p;

        str = line.mid(6);
        p.setName(str);
        line = in.readLine();

        str = line.mid(6);
        p.setDateOfRegister(str);
        line = in.readLine();


        str = line.mid(9);
        p.setCreator(str);
        line = in.readLine();

        str = line.mid(13);
        p.setDescription(str);
        line = in.readLine();

        str = line.mid(18);
        p.setDateOfCreation(str);
        line = in.readLine();

        str = line.mid(7);
        p.setColor(str);
        line = in.readLine();

        str = line.mid(12);
        p.setSellPrice(str.toDouble());
        line = in.readLine();

        str = line.mid(17);
        p.setPureSellPrice(str.toDouble());
        line = in.readLine();

        str = line.mid(8);
        p.setRating(str.toFloat());
        line = in.readLine();

        str = line.mid(13);
        p.setOffPercent(str.toFloat());
        line = in.readLine();

        str = line.mid(13);
        p.setViewNumber(str.toFloat());
        line = in.readLine();

        str = line.mid(18);
        p.setAvailableNumber(str.toUInt());
        line = in.readLine();

        str = line.mid(13);
        p.setVoteNumber(str.toUInt());
        line = in.readLine();

        str = line.mid(18);
        p.setActiveCondition(str.toInt());
        line = in.readLine();

        str = line.mid(13);
        p.setSoldNumber(str.toUInt());
        line = in.readLine();

        str = line.mid(17);
        p.setComplainNumber(str.toUInt());
        line = in.readLine();

        str = line.mid(15);
        p.setKeySeller(str.toULongLong());
        line = in.readLine();

        str = line.mid(18);
        p.setNameCategory(str);
        line = in.readLine();

        str = line.mid(5);
        p.setKey(str.toULongLong());
        line = in.readLine();

        str = line.mid(7);
        p.setState(str);
        line = in.readLine();

        this->pushBack(p);

        line = in.readLine();
    }


    file.close();
    return;
}


int LinkedListProduct::findIndexByKey(unsigned long long key) {

    int i = 0;
    NodeProduct* temp = head;

    while (temp != nullptr) {

        if (temp->getData().getKey() == key) {
            return i;
        }
        i++;
        temp = temp->getNext();
    }

    return -1;
}



void LinkedListProduct::operator=(LinkedListProduct x)
{

    this->~LinkedListProduct();
    NodeProduct* temp = x.getHead();
    while (temp)
    {
        this->pushBack(temp->getData());
        temp = temp->getNext();
    }
    return;
}

bool LinkedListProduct::operator==(LinkedListProduct x)
{

    if (this->size() != x.size()) {
        return false;
    }
    NodeProduct* temp = this->getHead();
    NodeProduct* temp_2 = x.getHead();

    while (temp && temp_2)
    {
        if (temp->getData() == temp_2->getData())
        {
            temp = temp->getNext();
            temp_2 = temp_2->getNext();
        }
        else {
            return false;
        }
    }

    return true;
}

NodeProduct& LinkedListProduct::getByKey(unsigned long long key){

    NodeProduct *temp = head;
    while(temp != nullptr){
        if (temp->getData().getKey() == key){
            return *temp;
        }
        temp = temp->getNext();
    }

    cerr << "No product found with key '" << key << "'." << endl;
    exit(1);
}



LinkedListProduct LinkedListProduct::createLinklistFromKey(KeyLinkedList key_list , LinkedListProduct main_list)
{



    this->~LinkedListProduct();
    NodeProduct* temp = main_list.getHead();

    while (temp)
    {
        Product p = temp->getData();
        KeyNode* temp_key = key_list.getHead();
        while (temp_key)
        {
            if (p.getKey() == temp_key->getKey())
            {
                this->pushBack(p);
                break;
            }
            temp_key = temp_key->getNext();
        }
        temp = temp->getNext();
    }

    return *this;
}

QTextStream& qStdOut2()
{
    static QTextStream ts( stdout );
    return ts;
}
