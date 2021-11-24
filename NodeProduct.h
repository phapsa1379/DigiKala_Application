#ifndef _NodeProduct_
#define _NodeProduct_

#include "Product.h"

class NodeProduct {

private:

    NodeProduct* next;
    NodeProduct* preV;
    Product data;

public:

    NodeProduct();
    ~NodeProduct();
    void setNext(NodeProduct*);
    void setPreV(NodeProduct*);
    void setData(Product p);

    NodeProduct* getNext();
    NodeProduct* getPreV();
    Product getData();
};

#endif
