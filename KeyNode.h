#ifndef KeyNode_232332
#define KeyNode_232332

class KeyNode
{
private:
    unsigned long long key;
	KeyNode* next;
	KeyNode* prev;
	
public:
	KeyNode();
	~KeyNode();
	KeyNode(const KeyNode&);
	KeyNode(KeyNode&&);
    KeyNode(unsigned long long key, KeyNode* next, KeyNode* prev);



    void setKey(unsigned long long key);
	void setNext(KeyNode* next);
	void setPrev(KeyNode* prev);

    unsigned long long getKey();
	KeyNode* getNext();
	KeyNode* getPrev();
	
	
};

#endif // KeyNode_232332
