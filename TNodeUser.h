#ifndef TNodeUser_ADSFDSA
#define TNodeUser_ADSFDSA
//#include "Users.h"
//#include "Dealer.h"
//#include "Admin.h"
template<class U>
class TNodeUser
{
	U node_user;
	TNodeUser* next;
	TNodeUser* prev;



public:
	TNodeUser();
	~TNodeUser();
    TNodeUser(const TNodeUser& node);
	TNodeUser(TNodeUser&& node);
	TNodeUser(U user, TNodeUser* next, TNodeUser* prev);
	/////////////
    void operator=(TNodeUser user); // Edited By Arash

	////////////
    void setData(U user); // Edited By Arash
	void setNext(TNodeUser<U>* next);
	void setPrev(TNodeUser<U>* prev);
	TNodeUser<U>* getNext();
	TNodeUser<U>* getPrev();
	U getData();
	///////////

};


#endif

