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
ListNode<T>::ListNode(ListNode<T> const& other) : Data(other.Data), Next(nullptr), Previous(nullptr)
{
}

template <typename T>
ListNode<T>::ListNode(ListNode<T>&& other) noexcept
{
	Data = other.Data;
	Next = other.Next;
	Previous = other.Previous;
	other.Data = nullptr;
	other.Next = nullptr;
	other.Previous = nullptr;
}

template <typename T>
ListNode<T>::ListNode(T& data) : Data{data}, Next(nullptr), Previous(nullptr)
{
}

template <typename T>
ListNode<T>::~ListNode() = default;

template <typename T>
auto ListNode<T>::operator=(T const& data) -> ListNode<T>&
{
	this->Data = data;
	return *this;
}

template <typename T>
auto ListNode<T>::operator=(ListNode<T> const& other) -> ListNode<T>&
{
	this->Data = other.Data;
	return *this;
}

template <typename T>
auto ListNode<T>::operator=(ListNode<T>&& other) noexcept -> ListNode<T>&
{
	if (this != &other)
	{
		Data = other.Data;
		other.Data = nullptr;
	}
	return *this;
}

template <class T>
LinkedList<T>::LinkedList() : Header{new ListNode<T>()}
{
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T>&& other) noexcept
{
	Header = other.GetHeader();
	other.Pull();
	return *this;
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T> const& other) : Header(new ListNode<T>(other.GetHeader().Data))
{
	auto length = other.Length();
	for (auto i = 1; i < length; i++)
	{
		this->Append(other.GetIndex(i));
	}
}

template <class T>
LinkedList<T>::LinkedList(T& data) : Header{new ListNode<T>(data)}
{
}

template <class T>
LinkedList<T>::LinkedList(const int length, T* data) : Header{new ListNode<T>{data[0]}}
{
	ListNode<T>* traversalNode = Header;
	for (auto i = 1; i < length; i++)
	{
		traversalNode->Next = new ListNode<T>(data[i]);
		traversalNode = traversalNode->Next;
	}
}

template <class T>
auto LinkedList<T>::GetHeader() const -> ListNode<T>&
{
	return Header;
}

template <class T>
auto LinkedList<T>::Length() const -> int
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
auto LinkedList<T>::Push(T& data) -> void
{
	ListNode<T>* previousHeader = Header;
	Header = new ListNode<T>(data);
	if (previousHeader)
	{
		Header->Next = previousHeader;
	}
}

template <class T>
auto LinkedList<T>::Push(const int length, T* data) -> void
{
	for (auto i = 0; i < length; i++)
	{
		PushAt(i, data);
	}
}

template <class T>
auto LinkedList<T>::Append(T& data) -> void
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
auto LinkedList<T>::Append(const int length, T* data) -> void
{
	for (auto i = 0; i < length; i++)
	{
		Append(data);
	}
}

template <class T>
auto LinkedList<T>::PushAt(const int index, T& data) -> void
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
auto LinkedList<T>::PushAt(const int index, const int length, T* data) -> void
{
	for (auto i = 0; i < length; i++)
	{
		PushAt(index + i, data[i]);
	}
}

template <class T>
auto LinkedList<T>::Pull() -> T
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
auto LinkedList<T>::Pop() -> T
{
	ListNode<T>* traversalNode = Header;
	ListNode<T>* beforeTraversalNode = Header;
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
auto LinkedList<T>::PullAt(const int index) -> T
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
		return Pop();
	}
	T data = traversalNode->Data;
	beforeTraversalNode->Next = nullptr;
	delete traversalNode;
	return data;
}

template <class T>
auto LinkedList<T>::GetIndex(const int index) const -> T&
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

template <class T>
auto LinkedList<T>::operator=(LinkedList<T> const& other) -> LinkedList<T>&
{
	while (Header)
	{
		Pull();
	}
	Header = new ListNode<T>(other.GetHeader().Data);
	auto length = other.Length();
	for (auto i = 1; i < length; i++)
	{
		this->Append(other.GetIndex(i));
	}
	return *this;
}

template <class T>
auto LinkedList<T>::operator=(LinkedList<T>&& other) noexcept -> LinkedList<T>&
{
	if (this != &other)
	{
		while (Header)
		{
			Pull();
		}
		Header = new ListNode<T>(other.GetHeader().Data);
		auto length = other.Length();
		for (auto i = 1; i < length; i++)
		{
			this->Append(other.GetIndex(i));
		}
	}
	return *this;
}

template <class T>
auto LinkedList<T>::operator<<(T const& data) -> LinkedList<T>&
{
	Append(data);
	return *this;
}

template <class T>
auto LinkedList<T>::operator >>(T& data) const -> LinkedList<T>&
{
	data = Pull();
	return *this;
}

template <typename T>
auto operator<<(std::ostream& stream, const ListNode<T>& node) -> std::ostream&
{
	std::cout << node.Data;
	return stream;
}

template <typename T>
auto operator<<(std::ostream& stream, const LinkedList<T>& list) -> std::ostream&
{
	auto length = list.Length();
	for (auto i = 0; i < length; i++)
	{
		std::cout << list.GetIndex(i) << std::endl;
	}
	return stream;
}
#endif // !KCLISTS_HPP
