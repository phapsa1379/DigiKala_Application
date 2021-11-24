#ifndef _NodeMessage_
#define _NodeMessage_

#include "Message.h"

class NodeMessage {

private:

    NodeMessage* next;
    NodeMessage* preV;
    Message data;

public:

    NodeMessage();
    ~NodeMessage();
    void setNext(NodeMessage*);
    void setPreV(NodeMessage*);
    void setData(Message p);

    NodeMessage* getNext();
    NodeMessage* getPreV();
    Message getData();
};

#endif
