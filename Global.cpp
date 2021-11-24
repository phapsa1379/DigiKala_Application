#include "Global.h"

using namespace std;
using namespace GlobalNameSpace;


int Globals::TARGET_PRODUCT_LIST = 0;
int Globals::TYPE_USER = 0;
unsigned long long Globals::KEY_USER = 0;
unsigned long long Globals::KEY_PRODUCT = 0;

Users Globals::THIS_USER;
Dealer Globals::THIS_DEALER;
QVector<QString> Globals::LIST_USERNAMES;

TLinkedListUser<Users> Globals::USER_LIST;
TLinkedListUser<Dealer> Globals::DEALER_LIST;

LinkedListMessage Globals::MESSAGE_LIST;;
LinkedListProduct Globals::PRODUCT_LIST;
LinkedListReport Globals::REPORT_LIST;
vector<ProductDelegateClass> Globals::DELEGATED_VECTOR_PRODUCT;


void Globals::setListUsernames()
{

    TNodeUser<Users> * temp = Globals::USER_LIST.getHead();
    while (temp)
    {
        Users temp_u = temp->getData();
        QString user_n = temp_u.getUserName();
        Globals::LIST_USERNAMES.push_back(user_n);
        temp = temp->getNext();

    }

    TNodeUser<Dealer> * temp2 = Globals::DEALER_LIST.getHead();
    while (temp2)
    {
        Dealer temp_d = temp2->getData();
        QString user_ = temp_d.getUserName();
        Globals::LIST_USERNAMES.push_back(user_);
        temp2 = temp2->getNext();

    }

}

