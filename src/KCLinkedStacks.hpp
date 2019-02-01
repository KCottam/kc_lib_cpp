#include <iostream>
#include "KCLinkedStacks.h"
using namespace KC;

template <class T>
LinkedStack<T>::LinkedStack() : List<T>()
{
}

template <class T>
LinkedStack<T>::LinkedStack(int length, T const* data) : List<T>(length, data)
{
}

template <class T>
LinkedStack<T>::LinkedStack(T const& data) : List<T>(data)
{
}

template <class T>
LinkedStack<T>::LinkedStack(std::initializer_list<T> data) : List<T>(data)
{
}

template <class T>
LinkedStack<T>::LinkedStack(LinkedStack<T>&& other) noexcept
{
	this->Header = other.Header;
	this->Length = other.Length;
	other.Header = NULL;
	other.Length = 0;
}

template <class T>
LinkedStack<T>::LinkedStack(List<T> const& other) : List<T>(other[0])
{
	for (auto i = 1; i < other.Length; i++)
	{
		this->Push(other[i]);
	}
}

template <class T>
auto LinkedStack<T>::Pop() -> T
{
	T data = this->Header->Data;
	auto old = this->Header;
	this->Header = this->Header->Next;
	delete old;
	return data;
}

