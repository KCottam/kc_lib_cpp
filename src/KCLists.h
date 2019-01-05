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

		ListNode();
		explicit ListNode(T& data);
		~ListNode();
		// TODO: Add operator functions such as (T)=
		// const T operator=(const ListNode& node) takes data from node and puts it to T.
		// TODO: Add copy constructor
		// TODO: How to implement copy constructor?
	};

	template <class T>
	class LinkedList final
	{
		ListNode<T>* Header;
	public:
		LinkedList();
		explicit LinkedList(T& data);
		LinkedList(int length, T* data);
		ListNode<T>& GetHeader() const;
		int Length() const;
		void Push(T& data); // operator<<()
		void Push(int length, T* data);
		void Append(T& data);
		void Append(int length, T* data);
		void PushAt(int index, T& data);
		void PushAt(int index, int length, T* data);
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

#endif // !KC_LISTS_H_
