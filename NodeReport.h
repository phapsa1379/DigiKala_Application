#ifndef NODEREPORT_H
#define NODEREPORT_H
#include "Report.h"

class NodeReport {

private:

    NodeReport* next;
    NodeReport* preV;
    Report data;

public:

    NodeReport();
    ~NodeReport();
    void setNext(NodeReport*);
    void setPreV(NodeReport*);
    void setData(Report p);

    NodeReport* getNext();
    NodeReport* getPreV();
    Report getData();
};

#endif // NODEREPORT_H
