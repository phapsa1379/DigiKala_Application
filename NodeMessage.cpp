#include "NodeMessage.h"

NodeMessage::NodeMessage() {

    next = preV = nullptr;
    return;
}

NodeMessage::~NodeMessage() {}

void NodeMessage::setNext(NodeMessage* s) {

    next = s;////
    return;
}

void NodeMessage::setPreV(NodeMessage* s) {

    preV = s;
    return;
}

void NodeMessage::setData(Message p) {

    data = p;
}

NodeMessage* NodeMessage::getNext() {

    return next;
}

NodeMessage* NodeMessage::getPreV() {

    return preV;
}

Message NodeMessage::getData() {

    return data;
}
