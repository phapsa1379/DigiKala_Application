#include "KeyNode.h"



KeyNode::KeyNode()
{
	this->next = this->prev = nullptr;
	return;
}


KeyNode::KeyNode(const KeyNode& node)
{
	this->key = node.key;
	return;
}

KeyNode::KeyNode(KeyNode&& node)
{
	this->key = node.key;
	return;
}

KeyNode::KeyNode(unsigned long long key, KeyNode* next, KeyNode* prev)
{
	this->key = key;
	this->setNext(next);
	this->setPrev(prev);
	return;
	
}

KeyNode::~KeyNode()
{
}



void KeyNode::setKey(unsigned long long key)
{
	this->key = key;
	return;
}

void KeyNode::setNext(KeyNode* next)
{
	this->next = next;
	return;
}

void KeyNode::setPrev(KeyNode* prev)
{
	this->prev = prev;
	return;
}


unsigned long long KeyNode::getKey()
{
	return key;
}

KeyNode* KeyNode::getNext()
{
	return next;
}

KeyNode* KeyNode::getPrev()
{
	return prev;
}




