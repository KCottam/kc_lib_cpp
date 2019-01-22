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
ListNode<T>::ListNode(T& data) : Data{ data }, Next(nullptr), Previous(nullptr)
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
LinkedList<T>::LinkedList() : Header{ new ListNode<T>() }, Length(1)
{
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T>&& other) noexcept
{
	Header = other.Header;
	Length = other.Length;
	other.Header = nullptr;
	other.Length = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T> const& other) : Header(new ListNode<T>(other.Begin().Data)), Length(1)
{
	auto length = other.GetLength();
	for (auto i = 1; i < length; i++)
	{
		this->Append(other.GetIndex(i));
	}
}

template <class T>
LinkedList<T>::LinkedList(T& data) : Header{ new ListNode<T>(data) }, Length(1)
{
}

template <class T>
LinkedList<T>::LinkedList(const int length, T* data) : Header{ new ListNode<T>{data[0]} }, Length(length)
{
	ListNode<T>* traversalNode = Header;
	for (auto i = 1; i < length; i++)
	{
		traversalNode->Next = new ListNode<T>(data[i]);
		traversalNode = traversalNode->Next;
	}
}

template <class T>
auto LinkedList<T>::Begin() const -> ListNode<T>&
{
	return Header;
}

template <class T>
auto LinkedList<T>::End() const -> ListNode<T>&
{
	ListNode<T>* traversalNode = Header;
	while (traversalNode->Next)
	{
		traversalNode = traversalNode->Next;
	}
	return traversalNode;
}

template <class T>
auto LinkedList<T>::GetLength() const -> int
{
	return Length;
}

template <class T>
auto LinkedList<T>::Push(T& data) -> void
{
	ListNode<T>* previousHeader = Header;
	Header = new ListNode<T>(data);
	if (previousHeader)
	{
		Header->Next = previousHeader;
		previousHeader->Previous = Header;
	}
	Length++;
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
	ListNode<T>* beforeEndNode = End().Previous;
	auto newNode = new ListNode<T>(data);
	newNode->Previous = beforeEndNode;
	beforeEndNode->Next = newNode;
	Length++;
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
		return;
	}
	ListNode<T>* newNode = new ListNode<T>(data);
	newNode->Previous = traversalNode;
	newNode->Next = traversalNode->Next;
	newNode->Next->Previous = newNode;
	traversalNode->Next = newNode;
	Length++;
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
	Length--;
	return data;
}

template <class T>
auto LinkedList<T>::Pop() -> T
{
	auto endNode = End();
	auto beforeEndNode = endNode.Previous;
	T data = endNode.Data;
	delete &endNode;
	beforeEndNode.Next = nullptr;
	Length--;
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
	traversalNode->Next->Previous = beforeTraversalNode;
	beforeTraversalNode->Next = traversalNode->Next;
	delete traversalNode;
	Length--;
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
	Header = new ListNode<T>(other.Begin().Data);
	auto length = other.GetLength();
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
		Header = new ListNode<T>(other.Begin().Data);
		auto length = other.GetLength();
		for (auto i = 1; i < length; i++)
		{
			Append(other.GetIndex(i));
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
auto LinkedList<T>::operator >> (T& data) const -> LinkedList<T>&
{
	data = Pull();
	return *this;
}

template <class T>
auto LinkedList<T>::operator[](const unsigned int index) const -> T&
{
	if ((GetLength() - 1) > index)
	{
		throw std::out_of_range("Index is greater than the length of linked list!");
	}
	return GetIndex(index);
}

template <class T>
CircleList<T>::CircleList()
{
}

template <class T>
CircleList<T>::CircleList(CircleList<T> const& other)
{
	this->Header = other.Header;
	auto length = other.GetLength();
	for (auto i = 1; i < length; i++)
	{
		this->Append(other.GetIndex(i));
	}
}

template <class T>
CircleList<T>::CircleList(CircleList<T>&& other) noexcept
{
	this->Header = other.Header;
	this->Length = other.Length;
	other.Header = nullptr;
	other.Length = nullptr;
}

template <class T>
CircleList<T>::CircleList(LinkedList<T> const& other) : LinkedList<T>(other)
{
	this->Begin()->Previous = this->End();
	this->End()->Next = this->Begin();
}

template <class T>
CircleList<T>::CircleList(const int length, T* data) : LinkedList<T>(length, data)
{
	this->Begin()->Previous = this->End();
	this->End()->Next = this->Begin();
}

template <class T>
CircleList<T>::~CircleList()
{
}

template <class T>
CircleList<T>::CircleList(T& data) : LinkedList<T>(data)
{
	this->Begin()->Previous = this->End();
	this->End()->Next = this->Begin();
}

template <class T>
auto CircleList<T>::Push(T& data) -> void
{
	ListNode<T>* previousHeader = this->Header;
	this->Header = new ListNode<T>(data);
	this->Header->Next = this->Header;
	this->Header->Previous = this->Header;
	if (previousHeader)
	{
		this->Header->Previous = previousHeader->Previous;
		previousHeader->Previous->Next = this->Header;
		this->Header->Next = previousHeader;
		previousHeader->Previous = this->Header;
	}
	++this->Length;
}

template <class T>
auto CircleList<T>::Push(const int length, T* data) -> void
{
	for (auto i = 0; i < length; i++)
	{
		Push(data);
	}
}

template <class T>
auto CircleList<T>::Pull() -> T
{
	if (!this->Header)
		return 0;
	T data = this->Header->Data;
	ListNode<T>* oldHeader = this->Header;
	this->Header = this->Header->Next;
	delete oldHeader;
	--this->Length;
	return data;
}

template <class T>
auto CircleList<T>::operator=(LinkedList<T> const& other) -> CircleList<T>&
{
	while (this->Header)
	{
		Pull();
	}
	this->Header = new ListNode<T>(other.Begin().Data);
	auto length = other.GetLength();
	for (auto i = 1; i < length; i++)
	{
		Push(other.GetIndex(i));
	}
	this->Begin()->Previous = this->End();
	this->End()->Next = this->Begin();
	return *this;
}

template <class T>
auto CircleList<T>::operator=(LinkedList<T>&& other) noexcept -> CircleList<T>&
{
	this->Header = other.Header;
	this->Length = other.Length;
	other.Header = nullptr;
	other.Length = nullptr;
	return *this;
}

template <class T>
auto CircleList<T>::operator=(CircleList<T> const& other) -> CircleList<T>&
{
	while (this->Header)
	{
		Pull();
	}
	this->Header = new ListNode<T>(other.Begin().Data);
	auto length = other.GetLength();
	for (auto i = 1; i < length; i++)
	{
		Push(other.GetIndex(i));
	}
	return *this;
}

template <class T>
auto CircleList<T>::operator=(CircleList<T>&& other) noexcept -> CircleList<T>&
{
	this->Header = other.Header;
	this->Length = other.Length;
	other.Header = nullptr;
	other.Length = nullptr;
	return *this;
}

template <class T>
auto CircleList<T>::operator<<(T const& data) -> LinkedList<T>&
{
	Push(data);
	return *this;
}

template <class T>
auto CircleList<T>::operator>>(T& data) const -> LinkedList<T>&
{
	data = Pull();
	return *this;
}

template <class T>
auto CircleList<T>::operator[](unsigned int const index) const -> T&
{
	return this->GetIndex(index);
}

template <class T>
CircleList<T>::CircleList(LinkedList<T>&& other) noexcept : Header{ other.Header }, Length{ other.Length }
{
	other.End().Next = other.Begin();
	other.Begin().Previous = other.End();
	other.Header = nullptr;
	other.Length = 0;
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
	auto length = list.GetLength();
	for (auto i = 0; i < length; i++)
	{
		std::cout << "(" << (i + 1) << ") " << list.GetIndex(i) << std::endl;
	}
	return stream;
}

template <typename T>
auto operator<<(std::ostream& stream, const CircleList<T>& list) -> std::ostream&
{
	auto length = list.GetLength();
	for (auto i = 0; i < length; i++)
	{
		std::cout << "(" << (i + 1) << ") " << list.GetIndex(i) << std::endl;
	}
	return stream;
}
#endif // !KCLISTS_HPP
