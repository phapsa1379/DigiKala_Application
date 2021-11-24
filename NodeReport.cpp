#include "NodeReport.h"

NodeReport::NodeReport() {

    next = preV = nullptr;
    return;
}

NodeReport::~NodeReport() {}

void NodeReport::setNext(NodeReport* s) {

    next = s;
    return;
}

void NodeReport::setPreV(NodeReport* s) {

    preV = s;
    return;
}

void NodeReport::setData(Report p) {

    data = p;
    return;
}

NodeReport* NodeReport::getNext() {

    return next;
}

NodeReport* NodeReport::getPreV() {

    return preV;
}

Report NodeReport::getData() {

    return data;
}
