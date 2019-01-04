#include "kc_lists.h"

template <typename T>
KC::ListNode<T>::ListNode(const T& data) : Data{data}
{
}

template <typename T>
KC::LinkedList<T>::LinkedList() : Header{new ListNode<T>()}
{
}

template <typename T>
KC::LinkedList<T>::LinkedList(const T& data) : Header{new ListNode<T>(data)}
{
}

template <typename T>
KC::LinkedList<T>::LinkedList(const int length, const T data[]) : Header{new ListNode<T>{data[0]}}
{
	ListNode<T>* traversalNode = Header;
	for (auto i = 1; i < length; i++)
	{
		traversalNode->setNext(new ListNode<T>(data[i]));
		traversalNode = traversalNode->getNext();
	}
}

template <typename T>
KC::ListNode<T>& KC::LinkedList<T>::GetHeader() const { return Header; }

template <typename T>
int KC::LinkedList<T>::Length() const
{
	ListNode<T>* traversalNode = Header;
	if (!traversalNode)
	{
		return 0;
	}
	traversalNode = traversalNode->getNext();
	auto length = 1;
	for (; traversalNode != Header; length++)
	{
		traversalNode = traversalNode->getNext();
	}
	return length;
}

template <typename T>
void KC::LinkedList<T>::Push(const T& data)
{
	ListNode<T>* previousHeader = Header;
	Header = new ListNode<T>(data);
	if (previousHeader)
	{
		Header->setNext(previousHeader);
	}
}

template <typename T>
void KC::LinkedList<T>::Push(const int length, const T data[])
{
	for (auto i = 0; i < length; i++)
	{
		PushAt(i, data);
	}
}

template <typename T>
void KC::LinkedList<T>::Append(const T& data)
{
	if (!Header)
	{
		Push(data);
	}
	ListNode<T>* traversalNode = Header;
	ListNode<T>* beforeTraversalNode;
	while (traversalNode)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	ListNode<T>* newNode = new ListNode<T>(data);
	newNode->setPrevious(beforeTraversalNode);
	beforeTraversalNode->setNext(newNode);
}

template <typename T>
void KC::LinkedList<T>::Append(const int length, const T data[])
{
	for (auto i = 0; i < length; i++)
	{
		Append(data);
	}
}

template <typename T>
void KC::LinkedList<T>::PushAt(const int index, const T& data)
{
	ListNode<T>* traversalNode = Header;
	for (auto i = 0; i < index && traversalNode; i++)
	{
		traversalNode = traversalNode->getNext();
	}
	if (!traversalNode)
	{
		Push(data);
	}
	else
	{
		ListNode<T>* newNode = new ListNode<T>(data);
		newNode->setPrevious(traversalNode);
		newNode->setNext(traversalNode->getNext());
		newNode->getNext()->setPrevious(newNode);
		traversalNode->setNext(newNode);
	}
}

template <typename T>
void KC::LinkedList<T>::PushAt(const int index, const int length, const T data[])
{
	for (auto i = 0; i < length; i++)
	{
		PushAt(index + i, data[i]);
	}
}

template <typename T>
T KC::LinkedList<T>::Pull()
{
	if (!Header)
		return 0;
	T data = Header->getData();
	ListNode<T>* oldHeader = Header;
	Header = Header->getNext();
	delete oldHeader;
	return data;
}

template <typename T>
T KC::LinkedList<T>::Pop()
{
	ListNode<T>* traversalNode = Header;
	ListNode<T> beforeTraversalNode;
	while (traversalNode)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	beforeTraversalNode->setNext(nullptr);
	T data = traversalNode->getData();
	delete traversalNode;
	return data;
}

template <typename T>
T KC::LinkedList<T>::PullAt(const int index)
{
	ListNode<T>* traversalNode = Header;
	ListNode<T>* beforeTraversalNode;
	for (auto i = 0; i < index && traversalNode; i++)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	if (!traversalNode)
	{
		return Pop();
	}
	T data = traversalNode->getData();
	beforeTraversalNode->setNext(nullptr);
	delete traversalNode;
	return data;
}

template <typename T>
T& KC::LinkedList<T>::GetIndex(const int index) const
{
	ListNode<T>* traversalNode = Header;
	ListNode<T> beforeTraversalNode;
	for (auto i = 0; i < index && traversalNode; i++)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	if (!traversalNode)
	{
		return beforeTraversalNode->getData();
	}
	return traversalNode->getData();
}

template <typename T>
KC::LinkedList<T>::~LinkedList()
{
	while (Header)
	{
		Pull();
	}
}
