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
		// TODO: Add operator functions
		// How to implement operator functions?
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
		void Push(const T& data);
		void Push(int length, const T data[]);
		void Append(const T& data);
		void Append(int length, const T data[]);
		void PushAt(int index, const T& data);
		void PushAt(int index, int length, const T data[]);
		T Pull();
		T Pop();
		T PullAt(int index);
		T& GetIndex(int index) const;
		~LinkedList();
		// TODO: Add operator functions
	};

	// TODO: Add CircleList class and related functions

	// TODO: Add std::cout overrides
}

#endif // !KC_LISTS_H_
