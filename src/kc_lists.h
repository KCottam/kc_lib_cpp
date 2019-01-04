#ifndef KC_LISTS_H_
#define KC_LISTS_H_

namespace KC
{
	template <typename T>
	class ListNode final
	{
	public:
		T& Data;
		ListNode* Next;
		ListNode* Previous;
		explicit ListNode(const T& data);
		// TODO: Add operator functions such as (T)=
		// const T operator=(const ListNode& node) takes data from node and puts it to T.
		// TODO: Add copy constructor
		// TODO: How to implement copy constructor?
	};

	template <typename T>
	class LinkedList final
	{
		ListNode<T>& Header;
	public:
		LinkedList();
		explicit LinkedList(const T& data);
		LinkedList(int length, const T data[]);
		ListNode<T>& GetHeader() const;
		int Length() const;
		void Push(const T& data); // operator<<()
		void Push(int length, const T data[]);
		void Append(const T& data);
		void Append(int length, const T data[]);
		void PushAt(int index, const T& data);
		void PushAt(int index, int length, const T data[]);
		T Pull(); // operator>>()
		T Pop();
		T PullAt(int index);
		T& GetIndex(int index) const;
		~LinkedList();
		// TODO: Add operator functions such as <<, (ListNode)=, >>
		// TODO: Add copy constructor
	};

	// TODO: Add CircleList class and related functions
	// TODO: Add std::cout overrides
}
#ifdef _IOSTREAM_
#include <iostream>
template<typename T>
std::ostream& operator<<(std::ostream& stream, const KC::ListNode<T>& node);

template<typename T>
std::ostream& operator<<(std::ostream& stream, const KC::LinkedList<T>& list);
#endif // !_IOSTREAM_

#endif // !KC_LISTS_H_
