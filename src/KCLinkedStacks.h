#ifndef KCLINKEDSTACKS_H
#define KCLINKEDSTACKS_H
#include "KCLists.h"

template <class T>
class LinkedStack final : public List<T>
{
public:
	LinkedStack();
	LinkedStack(int length, T const* data);
	explicit LinkedStack(T const& data);
	LinkedStack(std::initializer_list<T> data);

	LinkedStack(LinkedStack<T> const& other) = delete;
	LinkedStack(LinkedStack<T>&& other) noexcept;

	LinkedStack(List<T> const& other);

	auto Pull() = delete; 
	auto Pop()->T; // operator>>()

	auto operator<<(T const& data)->LinkedStack<T>&;
	auto operator<<(std::initializer_list<T> data)->LinkedStack<T>&;

	~LinkedStack();
};
#include "KCLinkedStacks.hpp"

#endif // KCLINKEDSTACKS_H
