#include "LinkedListReport.h"
#include "CurrentTime.h"
#include <QFile>
#include "EnumsProduct.h"
#include <istream>
#include <fstream>
#include <iostream>
#include <cctype>
#include <QString>
#include <QTextStream>
#include "ExternalFunctions.h"


LinkedListReport::LinkedListReport() {

    head = tail = nullptr;
    return;
}

LinkedListReport::LinkedListReport(const LinkedListReport& linkedList)
    :head(nullptr)
    , tail(nullptr)
{
    NodeReport* temp = linkedList.head;

    while (temp != nullptr)
    {
        pushBack(temp->getData());
        temp = temp->getNext();
    }

    return;
}

LinkedListReport::LinkedListReport(LinkedListReport&& linkedList) {

    head = linkedList.head;
    tail = linkedList.tail;
    linkedList.head = linkedList.tail = nullptr;
    return;
}

LinkedListReport::~LinkedListReport() {

    NodeReport* temp = head;
    NodeReport* t = nullptr;

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

void LinkedListReport::setHead(NodeReport* h) {

    head = h;
    return;
}

void LinkedListReport::setTail(NodeReport* t) {

    tail = t;
    return;
}

void LinkedListReport::addFront(Report p) {

    NodeReport* temp = new NodeReport();
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

void LinkedListReport::pushBack(Report p) {

    NodeReport* temp = new NodeReport();
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

NodeReport* LinkedListReport::getHead() {

    return head;
}
NodeReport* LinkedListReport::getTail() {

    return tail;
}

void LinkedListReport::print() {


    qStdOut() << "\nPrinting LinkedListReport elements: \n" << endl;
    NodeReport* temp = head;
    while (temp != nullptr) {
        qStdOut() << "Key Of Product: " << temp->getData().getKeyProduct() << endl;
        qStdOut() << "Reason: " << temp->getData().getReason() << endl;
        qStdOut() << "Date: " << temp->getData().getDate() << endl;
        qStdOut() << "***************************\n";

        temp = temp->getNext();
    }
    qStdOut() << endl;
}

Report LinkedListReport::get(int index) {

    const int SIZE = size();

    if (index < SIZE) {
        NodeReport* temp = head;

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


int LinkedListReport::size() {

    int i = 0;
    NodeReport* temp = head;
    while (temp != nullptr) {
        i++;
        temp = temp->getNext();
    }
    return i;
}

bool LinkedListReport::isEmpty()
{
    return size() == 0 ? true : false;
}

void LinkedListReport::writeFile() {

    QFile file("report_file.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qStdOut() << "Couldn't open report_file.txt " << endl;
        return;
    }

    QTextStream out(&file);

    NodeReport* temp = head;
    while (temp != nullptr) {

        out << "Key Of Product: " << temp->getData().getKeyProduct() << endl;
        out << "Reason: " << temp->getData().getReason() << endl;
        out << "Date: " << temp->getData().getDate() << endl;
        out << "***************************" << endl;

        temp = temp->getNext();
    }

    file.close();
    return;
}


void LinkedListReport::readFile() {

    QFile file("report_file.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        qStdOut() << "Couldn't open report_file.txt" << endl;
        return;
    }

    QTextStream in(&file);
    QString str = "";
    QString line = in.readLine();
    while (!line.isNull()) {
        Report r;

        str = line.mid(16);
        r.setKeyProduct(str.toULongLong());
        line = in.readLine();

        str = line.mid(8);
        r.setReason(str);
        line = in.readLine();

        str = line.mid(6);
        r.setDate(str);
        line = in.readLine();

        this->pushBack(r);

        line = in.readLine();
    }

    file.close();
    return;
}




