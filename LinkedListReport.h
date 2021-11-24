#ifndef LINKEDLISTREPORT_H
#define LINKEDLISTREPORT_H

#include "NodeReport.h"


class LinkedListReport {

private:

    NodeReport* head;
    NodeReport* tail;

public:

    LinkedListReport();
    LinkedListReport(const LinkedListReport& linkedList);
    LinkedListReport(LinkedListReport&& linkedList);
    ~LinkedListReport();

    void setHead(NodeReport* h);
    void setTail(NodeReport* t);
    void addFront(Report p);
    void pushBack(Report p);
    void print();


    void writeFile();
    void readFile();
    bool isEmpty();
    Report get(int i);
    int size();

    NodeReport* getHead();
    NodeReport* getTail();
};


#endif // LINKEDLISTREPORT_H
