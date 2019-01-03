#include "kc_lists.h"
template<typename T>
kc::Node<T>::Node(void) : data{ 0 }, next{ 0 }, previous{ 0 }
{
}

template<typename T>
kc::Node<T>::Node(const T& data) : data{ data }, next{ 0 }, previous{ 0 }
{
}

template<typename T>
T& kc::Node<T>::getData(void)
{
	return data;
}

template<typename T>
kc::Node<T>& kc::Node<T>::setData(const T& data)
{
	this->data = data;
	return *this;
}

template<typename T>
kc::Node<T>& kc::Node<T>::getNext(void)
{
	return next;
}

template<typename T>
kc::Node<T>& kc::Node<T>::setNext(const Node& node)
{
	this->next = node;
	return *this;
}

template<typename T>
kc::Node<T>& kc::Node<T>::getPrevious(void)
{
	return previous;
}

template<typename T>
kc::Node<T>& kc::Node<T>::setPrevious(const Node& node)
{
	this->previous = node;
	return *this;
}

template<typename T>
kc::Node<T>::~Node(void)
{
}

template<typename T>
kc::List<T>::List(void) : header{ new kc::Node<T>() }
{
}

template<typename T>
kc::List<T>::List(const T& data) : header{ new kc::Node<T>(data) }
{
}

template<typename T>
kc::List<T>::List(const int length, const T data[]) : header{ new kc::Node<T>{data[0]} }
{
	Node& traversalNode = header;
	for (int i = 1; i < length; i++)
	{
		traversalNode->setNext(new Node(data[i]));
		traversalNode = traversalNode->getNext();
	}
}

template<typename T>
kc::Node<T>& kc::List<T>::getHeader(void) const
{
	return header;
}

template<typename T>
int kc::List<T>::length(void)
{
	Node& traversalNode = header;
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

template<typename T>
void kc::List<T>::push(const T& data)
{
	Node& previousHeader = header;
	header = new Node(data);
	if (previousHeader)
	{
		header->setNext(previousHeader);
	}
}

template<typename T>
void kc::List<T>::push(const int length, const T data[])
{
	for (int i = 0; i < length; i++)
	{
		push_at(i, data);
	}
}

template<typename T>
void kc::List<T>::append(const T& data)
{
	if (!header)
	{
		push(data);
	}
	Node& traversalNode = header;
	Node& beforeTraversalNode;
	while (traversalNode)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	Node& newNode = new Node(data);
	newNode->setPrevious(beforeTraversalNode);
	beforeTraversalNode->setNext(newNode);
}

template<typename T>
void kc::List<T>::append(const int length, const T data[])
{
	for (int i = 0; i < length; i++)
	{
		append(data);
	}
}

template<typename T>
void kc::List<T>::push_at(int index, const T& data)
{
	Node& traversalNode = header;
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

template<typename T>
void kc::List<T>::push_at(const int index, const int length, const T data[])
{
	for (int i = 0; i < length; i++)
	{
		push_at(index + i, data[i]);
	}
}

template<typename T>
T& kc::List<T>::pull(void)
{
	if (!header)
		return 0;
	void * data = header->getData();
	Node * oldHeader = header;
	header = header->getNext();
	delete oldHeader;
	return data;
}

template<typename T>
T& kc::List<T>::pop(void)
{
	Node& traversalNode = header;
	Node& beforeTraversalNode;
	while (traversalNode)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	beforeTraversalNode->setNext(0);
	T& data = traversalNode->getData();
	delete traversalNode;
	return data;
}

template<typename T>
T& kc::List<T>::pull_at(int index)
{
	Node& traversalNode = header;
	Node& beforeTraversalNode;
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
		T& data = traversalNode->getData();
		beforeTraversalNode->setNext(0);
		delete traversalNode;
		return data;
	}
}

template<typename T>
T& kc::List<T>::getIndex(int index)
{
	Node& traversalNode = header;
	Node& beforeTraversalNode;
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

template<typename T>
kc::List<T>::~List(void)
{
	while (header)
	{
		pull();
	}
}
