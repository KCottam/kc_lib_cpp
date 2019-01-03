#ifndef KC_LISTS_H_
#define KC_LISTS_H_

namespace kc
{
	// A node of a linked list
	template<typename T> class node final
	{
	public:
		// The data of the mode
		T& data;
		// The next node of the linked list
		node* next;
		// The previous node of the linked list
		node* previous;
		// Creates a node with no data
		node(void);
		// Creates a node with data
		explicit node(const T& data);
		~node(void);
	};

	// A doubly-linked list.
	template<typename T> class list final
	{
	private:
		// The header node of a linked list
		node<T>& header_;
	public:
		// Initializes a list with a blank header.
		list(void);
		// Initializes a list with a single element.
		explicit list(const T& data);
		// Initializes a list with multiple elements.
		list(const int length, const T data[]);
		// Gets header variable
		node<T>& get_header(void) const;
		// Gets the length of the list
		int length(void) const;
		// Adds an element to the beginning of the list.
		void push(const T& data);
		// Adds elements to the beginning of the list.
		void push(const int length, const T data[]);
		// Adds an element to the end of the list.
		void append(const T& data);
		// Adds elements to the end of the list.
		void append(const int length, const T data[]);
		// Adds an element to the list at the index.
		void push_at(const int index, const T& data);
		// Adds elements to the list at the index.
		void push_at(const int index, const int length, const T data[]);
		// Gets the data of the list's first node. The node is destroyed.
		T& pull(void);
		// Gets the data of the list's last node. The node is destroyed.
		T& pop(void);
		// Gets the data of the node at the list's specified index. The node is destroyed.
		T& pull_at(const int index);
		// Gets the data of the node at the list's specified index. The node is NOT destroyed.
		T& get_index(const int index);

		// Deletes all of the nodes of the list before deallocation its memory.
		~list(void);
	};
}

#endif // !KC_LISTS_H_