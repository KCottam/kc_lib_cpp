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
	class LinkedList
	{
	protected:
		ListNode<T>* Header;
		int Length;
	public:
		LinkedList();
		LinkedList(LinkedList<T> const& other);
		LinkedList(LinkedList<T>&& other) noexcept;
		LinkedList(int length, T* data);
		~LinkedList();
		explicit LinkedList(T& data);

		auto Begin() const->ListNode<T>&;
		auto End() const->ListNode<T>&;
		auto GetLength() const -> int;
		auto GetIndex(int index) const->T&; // operator[]()

		auto Push(T& data) -> void;
		auto Push(int length, T* data) -> void;
		auto Append(T& data) -> void; // operator<<()
		auto Append(int length, T* data) -> void;
		auto PushAt(int index, T& data) -> void;
		auto PushAt(int index, int length, T* data) -> void;

		auto Pull()->T; // operator>>()
		auto Pop()->T;
		auto PullAt(int index)->T;

		auto operator=(LinkedList<T> const& other)->LinkedList<T>&;
		auto operator=(LinkedList<T>&& other) noexcept->LinkedList<T>&;
		auto operator<<(T const& data)->LinkedList<T>&;
		auto operator >> (T& data) const->LinkedList<T>&;
		auto operator[](unsigned int index) const->T&;
	};

	template <class T>
	class CircleList final : public LinkedList<T>
	{
	public:
		CircleList();
		CircleList(CircleList<T> const& other);
		CircleList(CircleList<T>&& other) noexcept;
		CircleList(LinkedList<T>&& other) noexcept; //move operator for linked list
		CircleList(LinkedList<T> const& other);
		CircleList(int length, T* data);
		~CircleList();
		explicit CircleList(T& data);

		auto Push(T& data) -> void; // operator<<()
		auto Push(int length, T* data) -> void;

		auto Pull()->T; // operator>>()

		auto operator=(LinkedList<T> const& other)-> CircleList<T>&;
		auto operator=(LinkedList<T>&& other) noexcept-> CircleList<T>&;
		auto operator=(CircleList<T> const& other)->CircleList<T>&;
		auto operator=(CircleList<T>&& other) noexcept->CircleList<T>&;
		auto operator<<(T const& data)->LinkedList<T>&;
		auto operator >> (T& data) const->LinkedList<T>&;
		auto operator[](unsigned int index) const->T&;

		auto Begin() const->ListNode<T>& = delete;
		auto End() const->ListNode<T>& = delete;
		auto Pop()->T = delete;
		auto PullAt(int index)->T = delete;
		auto Append(T& data) -> void = delete; // operator<<()
		auto Append(int length, T* data) -> void = delete;
	};
};

#include "KCLists.hpp"

#endif // !KC_LISTS_H_
