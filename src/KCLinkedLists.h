#ifndef KCLINKEDLISTS_H
#define KCLINKEDLISTS_H

#include "KCLists.h"

template <class T>
class LinkedList final : public List<T>
{
	using List<T>::GetHeader;
public:
	LinkedList();
	LinkedList(int length, T const* data);
	explicit LinkedList(T const& data);
	explicit LinkedList(std::initializer_list<T> data);

	auto Begin() const -> ListNode<T>&;
	auto End() const -> ListNode<T>&;

	auto Append(T const& data) -> void; // operator<<()
	auto Append(int length, T const* data) -> void;
	auto Append(std::initializer_list<T> data) -> void;

	auto PushAt(int index, T const& data) -> void;
	auto PushAt(int index, int length, T const* data) -> void;
	auto PushAt(int index, std::initializer_list<T> data) -> void;

	auto Pop() -> T;
	auto PullAt(int index) -> T;

	auto operator<<(T const& data) -> LinkedList<T>&;
	auto operator<<(std::initializer_list<T> data)->LinkedList<T>&;
};

#include "KCLinkedLists.hpp"

#endif // !KCLINKEDLISTS_H
