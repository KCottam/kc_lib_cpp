#ifndef KC_LISTS_H_
#define KC_LISTS_H_

namespace KC
{
	template <typename T>
	class ListNode final
	{
	public:
		T Data;
		ListNode<T>* Next;
		ListNode<T>* Previous;

		ListNode();
		ListNode(ListNode<T> const& other);
		ListNode(ListNode<T>&& other) noexcept;
		~ListNode();
		explicit ListNode(T& data);
		auto operator=(T const& data)->ListNode<T>&;
		auto operator=(ListNode<T> const& other)->ListNode<T>&;
		auto operator=(ListNode<T>&& other) noexcept->ListNode<T>&;
	};

	template <class T>
	class LinkedList final
	{
		ListNode<T>* Header;
		int Length;
	public:
		LinkedList();
		LinkedList(LinkedList<T>&& other) noexcept;
		LinkedList(LinkedList<T> const& other);
		LinkedList(int length, T* data);
		~LinkedList();
		explicit LinkedList(T& data);
		auto GetHeader() const->ListNode<T>&;
		auto GetLength() const -> int;
		auto Push(T& data) -> void;
		auto Push(int length, T* data) -> void; 
		auto Append(T& data) -> void; // operator<<()
		auto Append(int length, T* data) -> void;
		auto PushAt(int index, T& data) -> void;
		auto PushAt(int index, int length, T* data) -> void;
		auto Pull()->T; // operator>>()
		auto Pop()->T;
		auto PullAt(int index)->T;
		auto GetIndex(int index) const->T&; // operator[]()
		auto operator=(LinkedList<T> const& other)->LinkedList<T>&;
		auto operator=(LinkedList<T>&& other) noexcept->LinkedList<T>&;
		auto operator<<(T const& data)->LinkedList<T>&;
		auto operator>>(T& data) const->LinkedList<T>&;
		auto operator[](unsigned int index) const->T&;
	};

	// TODO: Add CircleList class and related functions
};

#include "KCLists.hpp"

#endif // !KC_LISTS_H_
