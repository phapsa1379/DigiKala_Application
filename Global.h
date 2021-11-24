#ifndef GLOBAL_H
#define GLOBAL_H

#include "LinkedListProduct.h"
#include "TLinkedListUser.h"
#include "LinkedListReport.h"
#include "ProductDelegateClass.h"

#include "LinkedListMessage.h"
#include <QVector>


enum target_list_type{ALL_SYSTEM_PRODUCTS, MY_SELL_PRODUCTS,
                      MY_BOUGHT_PRODUCTS, MY_FAVORITE_PRODUCTS}; // Used for showing filtering products: This
//determines which list should be shown at this moment:
// All Products, my sold products or my bought products?

namespace GlobalNameSpace{

class Globals{

public:
    static int TARGET_PRODUCT_LIST;
    static int TYPE_USER;

    static unsigned long long KEY_USER;
    static unsigned long long KEY_PRODUCT;

    static Users THIS_USER;
    static Dealer THIS_DEALER;
    static QVector<QString> LIST_USERNAMES;

    static TLinkedListUser<Users> USER_LIST;
    static TLinkedListUser<Dealer> DEALER_LIST;
    static LinkedListProduct PRODUCT_LIST;
    static LinkedListReport REPORT_LIST;


    static LinkedListMessage MESSAGE_LIST;
    static vector<ProductDelegateClass> DELEGATED_VECTOR_PRODUCT;


    //functions:
    static void setListUsernames();
};
};
#endif // GLOBAL_H
