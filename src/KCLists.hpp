#include <iostream>
#include "KCLists.h"
using namespace KC;

template <typename T>
ListNode<T>::ListNode() : Next(nullptr), Previous(nullptr)
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
ListNode<T>::ListNode(T const& data) : Data{ data }, Next(nullptr), Previous(nullptr)
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
List<T>::List() : Header{ nullptr }, Length(0)
{
}

template <class T>
List<T>::List(List<T>&& other) noexcept
{
	Header = other.Header;
	Length = other.Length;
	other.Header = nullptr;
	other.Length = 0;
}

template <class T>
auto List<T>::GetHeader() const -> ListNode<T>&
{
	return *Header;
}

template <class T>
List<T>::List(List<T> const& other) : Header(new ListNode<T>(other.Header->Data)), Length(1)
{
	auto length = other.GetLength();
	for (auto i = 1; i < length; i++)
	{
		this->Push(other.GetIndex(i));
	}
}

template <class T>
List<T>::List(T const& data) : Header{ new ListNode<T>(data) }, Length(1)
{
}

template <class T>
List<T>::List(std::initializer_list<T> data) : Header(new ListNode<T>(*(data.end() -1))), Length(1)
{
	auto length = data.size() - 1;
	this->Push(length, data.begin());
}

template <class T>
List<T>::List(const int length, T const* data) : Header{ new ListNode<T>{data[0]} }, Length(1)
{
	for (auto i = 1; i < length; i++)
	{
		Push(data[i]);
	}
}

template <class T>
auto List<T>::GetLength() const -> int
{
	return Length;
}

template <class T>
auto List<T>::Push(T const& data) -> void
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
auto List<T>::Push(const int length, T const* data) -> void
{
	for (auto i = length - 1; i >= 0; --i)
	{
		Push(data[i]);
	}
}

template <class T>
auto List<T>::Push(std::initializer_list<T> data) -> void
{
	auto length = data.size();
	Push(length, data.begin());
}

template <class T>
auto List<T>::Pull() -> T
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
auto List<T>::GetIndex(const int index) const -> T&
{
	ListNode<T>* traversalNode = Header;
	for (auto i = 0; i < index && traversalNode->Next; i++)
	{
		traversalNode = traversalNode->Next;
	}
	return traversalNode->Data;
}

template <class T>
List<T>::~List()
{
	while (Header)
	{
		Pull();
	}
}

template <class T>
auto List<T>::operator=(List<T> const& other) -> List<T>&
{
	while (Header)
	{
		Pull();
	}
	Header = new ListNode<T>(other.Header->Data);
	auto length = other.Length;
	for (auto i = length; i > 1; --i)
	{
		this->Push(other.GetIndex(i));
	}
	return *this;
}

template <class T>
auto List<T>::operator=(List<T>&& other) noexcept -> List<T>&
{
	if (this != &other)
	{
		Header = other.Header;
		Length = other.Length;
		other.Header = nullptr;
		other.Length = 0;
	}
	return *this;
}

template <class T>
auto List<T>::operator<<(T const& data) -> List<T>&
{
	Push(data);
	return *this;
}

template <class T>
auto List<T>::operator >> (T& data) -> List<T>&
{
	data = Pull();
	return *this;
}

template <class T>
auto List<T>::operator<<(std::initializer_list<T> data) -> List<T>&
{
	Push(data);
	return *this;
}

template <class T>
auto List<T>::operator[](const int index) const -> T&
{
	if ((Length - 1) > index)
	{
		throw std::out_of_range("Index is greater than the length of list!");
	}
	return GetIndex(index);
}

template <typename T>
auto operator<<(std::ostream& stream, const ListNode<T>& node) -> std::ostream&
{
	std::cout << node.Data;
	return stream;
}

template <typename T>
auto operator<<(std::ostream& stream, const List<T>& list) -> std::ostream&
{
	auto length = list.GetLength();
	for (auto i = 0; i < length; i++)
	{
		std::cout << "[" << (i) << ":$" << &list.GetIndex(i) << "] " << list.GetIndex(i) << std::endl;
	}
	return stream;
}
