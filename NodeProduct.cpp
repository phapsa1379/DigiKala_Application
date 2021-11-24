#include "NodeProduct.h"

NodeProduct::NodeProduct() {

    next = preV = nullptr;
    return;
}

NodeProduct::~NodeProduct() {}

void NodeProduct::setNext(NodeProduct* s) {

    next = s;////
    return;
}

void NodeProduct::setPreV(NodeProduct* s) {

    preV = s;
    return;
}

void NodeProduct::setData(Product p) {

    data = p;
}

NodeProduct* NodeProduct::getNext() {

    return next;
}

NodeProduct* NodeProduct::getPreV() {

    return preV;
}

Product NodeProduct::getData() {

    return data;
}
