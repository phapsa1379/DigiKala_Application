#include "TNodeUser.h"
#include "Users.h"
#include "Dealer.h"


template<class U>
void TNodeUser<U>::setData(U user) // Edited By Arash
{
    node_user = user;
    return;
}

template<>
void TNodeUser<Dealer>::setData(Dealer user) // Edited By Arash (CRITICAL)
{
    node_user = user;
    return;
}


/////////////////////////////////////////
template class TNodeUser<Users>;
template class TNodeUser<Dealer>;


template<class U>
TNodeUser<U>::TNodeUser()
{
    this->next = nullptr;
    this->prev = nullptr;
    return;

}

template<class U>
TNodeUser<U>::~TNodeUser()
{

}


template<class U>
TNodeUser<U> ::TNodeUser(const TNodeUser& user)
{
    this->next = user.next;
    this->prev = user.prev;
    return;
}
template<class U>
TNodeUser<U> ::TNodeUser(TNodeUser&& user)
{
    this->next = user.next;
    this->prev = user.prev;
    return;
}

template<class U>
TNodeUser<U>::TNodeUser(U user, TNodeUser* next , TNodeUser* prev)
{
    this->setData(user);
    this->setNext(next);
    this->setPrev(prev);

}



template<class U>
void TNodeUser<U>::setNext(TNodeUser<U>* next)
{
    this->next = next;
    return;
}

template<class U>
void TNodeUser<U>::setPrev(TNodeUser<U>* prev)
{
    this->prev = prev;
    return;
}

template<class U>
TNodeUser<U>* TNodeUser<U>::getNext()
{
    return this->next;
}

template<class U>
TNodeUser<U>* TNodeUser<U>::getPrev()
{
    return this->prev;
}

template<class U>
U TNodeUser<U>::getData()
{
    return this->node_user;
}


template<class U>
void TNodeUser<U>::operator=(TNodeUser<U> user) // Edited By Arash
{
    this->setData(user.getData());
    this->setNext(user.getNext());
    this->setPrev(user.getPrev());
    return;
}


