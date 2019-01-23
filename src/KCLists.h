#ifndef KC_LISTS_H
#define KC_LISTS_H

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
		explicit ListNode(T const& data);

		auto operator=(T const& data) -> ListNode<T>&;
		auto operator=(ListNode<T> const& other) -> ListNode<T>&;
		auto operator=(ListNode<T>&& other) noexcept -> ListNode<T>&;
	};

	template <class T>
	class List
	{
	protected:
		ListNode<T>* Header;
		int Length;
	public:
		List();
		List(int length, T const* data);
		explicit List(T const& data);
		explicit List(std::initializer_list<T> data);

		List(List<T> const& other);
		List(List<T>&& other) noexcept;

		auto GetHeader() const -> ListNode<T>&;
		auto GetIndex(int index) const -> T&;
		auto GetLength() const -> int;

		auto Push(T const& data) -> void; // operator<<()
		auto Push(int length, T const* data) -> void;
		auto Push(std::initializer_list<T> data) -> void;

		auto Pull() -> T; // operator>>()

		auto operator=(List<T> const& other) -> List<T>&;
		auto operator=(List<T>&& other) noexcept -> List<T>&;

		auto operator<<(T const& data) -> List<T>&;
		auto operator<<(std::initializer_list<T> data) -> List<T>&;
		auto operator>>(T& data) -> List<T>&;

		auto operator[](int index) const -> T&;

		~List();
	};
};

#include "KCLists.hpp"

#endif // !KC_LISTS_H
