#include "kc_lists.h"

kc::Node::Node(void) : data{ 0 }, next{ 0 }, previous{ 0 }
{
}

kc::Node::Node(void * data) : data{ data }, next{ 0 }, previous{ 0 }
{
}

void * kc::Node::getData(void)
{
	return data;
}

void kc::Node::setData(void * data)
{
	this->data = data;
}

kc::Node * kc::Node::getNext(void)
{
	return next;
}

void kc::Node::setNext(Node * node)
{
	this->next = node;
}

kc::Node * kc::Node::getPrevious(void)
{
	return previous;
}

// Gets data variable
void kc::Node::setPrevious(Node * node)
{
	this->previous = node;
}

kc::Node::~Node(void)
{
}

kc::List::List(void) : header{ new kc::Node() }
{
}

kc::List::List(void * data) : header{ new kc::Node(data) }
{
}

kc::List::List(int length, void * data[]) : header{ new kc::Node{data[0]} }
{
	Node * traversalNode = header;
	for (int i = 1; i < length; i++)
	{
		traversalNode->setNext(new Node(data[i]));
		traversalNode = traversalNode->getNext();
	}
}

kc::Node * kc::List::getHeader(void)
{
	return header;
}

int kc::List::length(void)
{
	Node * traversalNode = header;
	if (!traversalNode)
	{
		return 0;
	}
	traversalNode = traversalNode->getNext();
	int length = 1;
	for (; traversalNode != header; length++)
	{
		traversalNode = traversalNode->getNext();
	}
	return length;
}

void kc::List::push(void * data)
{
	Node * previousHeader = header;
	header = new Node(data);
	if (previousHeader)
	{
		header->setNext(previousHeader);
	}
}

void kc::List::push(int length, void * data[])
{
	for (int i = 0; i < length; i++)
	{
		push_at(i, data);
	}
}

void kc::List::append(void * data)
{
	if (!header)
	{
		push(data);
	}
	Node * traversalNode = header;
	Node * beforeTraversalNode;
	while (traversalNode)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	Node * newNode = new Node(data);
	newNode->setPrevious(beforeTraversalNode);
	beforeTraversalNode->setNext(newNode);
}

void kc::List::append(int length, void * data[])
{
	for (int i = 0; i < length; i++)
	{
		append(data);
	}
}

void kc::List::push_at(int index, void * data)
{
	Node * traversalNode = header;
	for (int i = 0; i < index && traversalNode; i++)
	{
		traversalNode = traversalNode->getNext();
	}
	if (!traversalNode)
	{
		push(data);
	}
	else
	{
		Node * newNode = new Node(data);
		newNode->setPrevious(traversalNode);
		newNode->setNext(traversalNode->getNext());
		newNode->getNext()->setPrevious(newNode);
		traversalNode->setNext(newNode);
	}
}

void kc::List::push_at(int index, int length, void * data[])
{
	for (int i = 0; i < length; i++)
	{
		push_at(index + i, data[i]);
	}
}

void * kc::List::pull(void)
{
	if (!header)
		return 0;
	void * data = header->getData();
	Node * oldHeader = header;
	header = header->getNext();
	delete oldHeader;
	return data;
}

void * kc::List::pop(void)
{
	Node * traversalNode = header;
	Node * beforeTraversalNode;
	while (traversalNode)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	beforeTraversalNode->setNext(0);
	void * data = traversalNode->getData();
	delete traversalNode;
	return data;
}

void * kc::List::pull_at(int index)
{
	Node * traversalNode = header;
	Node * beforeTraversalNode;
	for (int i = 0; i < index && traversalNode; i++)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	if (!traversalNode)
	{
		return pop();
	}
	else
	{
		void * data = traversalNode->getData();
		beforeTraversalNode->setNext(0);
		delete traversalNode;
		return data;
	}
}

void * kc::List::getIndex(int index)
{
	Node * traversalNode = header;
	Node * beforeTraversalNode;
	for (int i = 0; i < index && traversalNode; i++)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	if (!traversalNode)
	{
		return beforeTraversalNode->getData();
	}
	else
	{
		return traversalNode->getData();
	}
}
/*
void kc::List::operator+=(void * data)
{
	append(data);
}

void kc::List::operator+=(void * data[])
{
	int i = 0;
	for (; data[i]; i++) {}
	append(i, data);
}
*/

kc::List::~List(void)
{
	while (header)
	{
		pull();
	}
}