#ifndef KC_LISTS_HPP_
#define KC_LISTS_HPP_
#include <iostream>
#include "KCLists.h"
using namespace KC;

template <typename T>
ListNode<T>::ListNode() : Data(nullptr), Next(nullptr), Previous(nullptr)
{
}

template <typename T>
ListNode<T>::ListNode(T& data) : Data{ data }, Next(nullptr), Previous(nullptr)
{
}

template <typename T>
ListNode<T>::~ListNode() = default;

template <class T>
LinkedList<T>::LinkedList() : Header{ new ListNode<T>() }
{
}

template <class T>
LinkedList<T>::LinkedList(T& data) : Header{ new ListNode<T>(data) }
{
}

template <class T>
LinkedList<T>::LinkedList(const int length, T* data) : Header{ new ListNode<T>{ data[0] } }
{
	ListNode<T>* traversalNode = Header;
	for (auto i = 1; i < length; i++)
	{
		traversalNode->Next = new ListNode<T>(data[i]);
		traversalNode = traversalNode->Next;
	}
}

template <class T>
ListNode<T>& LinkedList<T>::GetHeader() const
{
	return Header;
}

template <class T>
int LinkedList<T>::Length() const
{
	ListNode<T>* traversalNode = Header;
	if (!traversalNode)
	{
		return 0;
	}
	auto length = 0;
	for (; traversalNode != nullptr; length++)
	{
		traversalNode = traversalNode->Next;
	}
	return length;
}

template <class T>
void LinkedList<T>::Push(T& data)
{
	ListNode<T>* previousHeader = Header;
	Header = new ListNode<T>(data);
	if (previousHeader)
	{
		Header->Next = previousHeader;
	}
}

template <class T>
void LinkedList<T>::Push(const int length, T* data)
{
	for (auto i = 0; i < length; i++)
	{
		PushAt(i, data);
	}
}

template <class T>
void LinkedList<T>::Append(T& data)
{
	if (!Header)
	{
		Push(data);
		return;
	}
	ListNode<T>* traversalNode = Header;
	ListNode<T>* beforeTraversalNode = nullptr;
	while (traversalNode)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->Next;
	}
	ListNode<T>* newNode = new ListNode<T>(data);
	newNode->Previous = beforeTraversalNode;
	beforeTraversalNode->Next = newNode;
}

template <class T>
void LinkedList<T>::Append(const int length, T* data)
{
	for (auto i = 0; i < length; i++)
	{
		Append(data);
	}
}

template <class T>
void LinkedList<T>::PushAt(const int index, T& data)
{
	ListNode<T>* traversalNode = Header;
	for (auto i = 0; i < index && traversalNode; i++)
	{
		traversalNode = traversalNode->Next;
	}
	if (!traversalNode)
	{
		Push(data);
	}
	else
	{
		ListNode<T>* newNode = new ListNode<T>(data);
		newNode->Previous = traversalNode;
		newNode->Next = traversalNode->Next;
		newNode->Next->Previous = newNode;
		traversalNode->Next = newNode;
	}
}

template <class T>
void LinkedList<T>::PushAt(const int index, const int length, T* data)
{
	for (auto i = 0; i < length; i++)
	{
		PushAt(index + i, data[i]);
	}
}

template <class T>
T LinkedList<T>::Pull()
{
	if (!Header)
		return 0;
	T data = Header->Data;
	ListNode<T>* oldHeader = Header;
	Header = Header->Next;
	delete oldHeader;
	return data;
}

template <class T>
T LinkedList<T>::Pop()
{
	ListNode<T>* traversalNode = Header;
	ListNode<T> beforeTraversalNode;
	while (traversalNode)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->Next;
	}
	beforeTraversalNode->Next = nullptr;
	T data = traversalNode->Data;
	delete traversalNode;
	return data;
}

template <class T>
T LinkedList<T>::PullAt(const int index)
{
	ListNode<T>* traversalNode = Header;
	ListNode<T>* beforeTraversalNode;
	for (auto i = 0; i < index && traversalNode; i++)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->Next;
	}
	if (!traversalNode)
	{
		return Pop();
	}
	T data = traversalNode->Data;
	beforeTraversalNode->Next = nullptr;
	delete traversalNode;
	return data;
}

template <class T>
T& LinkedList<T>::GetIndex(const int index) const
{
	ListNode<T>* traversalNode = Header;
	ListNode<T>* beforeTraversalNode = Header;
	for (auto i = 0; i < index && traversalNode; i++)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->Next;
	}
	if (!traversalNode)
	{
		return beforeTraversalNode->Data;
	}
	return traversalNode->Data;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	while (Header)
	{
		Pull();
	}
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const KC::ListNode<T>& node)
{
	std::cout << node.Data;
	return stream;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const KC::LinkedList<T>& list)
{
	auto length = list.Length();
	for (auto i = 0; i < length; i++)
	{
		std::cout << list.GetIndex(i) << std::endl;
	}
	return stream;
}
#endif // !KCLISTS_HPP
