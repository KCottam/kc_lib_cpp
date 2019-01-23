#include <iostream>
#include "KCLinkedLists.h"
using namespace KC;

template <class T>
LinkedList<T>::LinkedList() : List<T>()
{
}

template <class T>
LinkedList<T>::LinkedList(const int length, T const* data) : List<T>(data[0])
{
	for (auto i = 1; i < length; i++)
	{
		Append(data[i]);
	}
}

template <class T>
LinkedList<T>::LinkedList(T const& data) : List<T>(data)
{
}

template <class T>
LinkedList<T>::LinkedList(std::initializer_list<T> data) : List<T>(data)
{
}

template <class T>
auto LinkedList<T>::Begin() const -> ListNode<T>&
{
	return this->Header;
}

template <class T>
auto LinkedList<T>::End() const -> ListNode<T>&
{
	ListNode<T>* traversalNode = this->Header;
	while (traversalNode->Next)
	{
		traversalNode = traversalNode->Next;
	}
	return *traversalNode;
}

template <class T>
auto LinkedList<T>::Append(T const& data) -> void
{
	if (!this->Header)
	{
		this->Push(data);
		return;
	}
	auto newNode = new ListNode<T>(data);
	newNode->Previous = &this->End();
	this->End().Next = newNode;
	++this->Length;
}

template <class T>
auto LinkedList<T>::Append(const int length, T const* data) -> void
{
	for (auto i = 0; i < length; i++)
	{
		Append(data[i]);
	}
}

template <class T>
auto LinkedList<T>::Append(std::initializer_list<T> data) -> void
{
	auto length = data.size();
	Append(length, data.begin());
}

template <class T>
auto LinkedList<T>::PushAt(const int index, T const& data) -> void
{
	ListNode<T>* traversalNode = this->Header;
	for (auto i = 0; i < (index - 1) && traversalNode; i++)
	{
		traversalNode = traversalNode->Next;
	}
	if (!traversalNode)
	{
		Append(data);
		return;
	}
	auto newNode = new ListNode<T>(data);
	newNode->Previous = traversalNode;
	newNode->Next = traversalNode->Next;
	newNode->Next->Previous = newNode;
	traversalNode->Next = newNode;
	++this->Length;
}

template <class T>
auto LinkedList<T>::PushAt(const int index, const int length, T const* data) -> void
{
	for (auto i = 0; i < length; i++)
	{
		PushAt(index + i, data[i]);
	}
}

template <class T>
auto LinkedList<T>::PushAt(int index, std::initializer_list<T> data) -> void
{
	auto length = data.size();
	PushAt(index, length, data.begin());
}

//vatin.singla@wsu.edu

template <class T>
auto LinkedList<T>::Pop() -> T
{
	auto endNode = &this->End();
	auto beforeEndNode = endNode->Previous;
	T data = endNode->Data;
	delete endNode;
	beforeEndNode->Next = nullptr;
	--this->Length;
	return data;
}

template <class T>
auto LinkedList<T>::PullAt(const int index) -> T
{
	ListNode<T>* traversalNode = this->Header;
	ListNode<T>* beforeTraversalNode = this->Header;
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
	traversalNode->Next->Previous = beforeTraversalNode;
	beforeTraversalNode->Next = traversalNode->Next;
	delete traversalNode;
	--this->Length;
	return data;
}

template <class T>
auto LinkedList<T>::operator<<(T const& data) -> LinkedList<T>&
{
	Append(data);
	return *this;
}

template <class T>
auto LinkedList<T>::operator<<(std::initializer_list<T> data) -> LinkedList<T>&
{
	Append(data);
	return *this;
}
