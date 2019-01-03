#ifndef KC_LISTS_H_
#define KC_LISTS_H_

namespace kc
{
	// A node of a linked list 
	template<typename T>
	class Node
	{
	private:
		// The data of the mode
		T& data;
		// The next node of the linked list
		Node& next;
		// The previous node of the linked list
		Node& previous;
	public:
		// Creates a node with no data
		Node(void);
		// Creates a node with data
		Node(const T& data);
		// Gets data variable
		T& getData(void);
		// Sets data variable
		Node& setData(const T& data);
		// Gets next variable
		Node& getNext(void);
		// Sets next variable
		Node& setNext(const Node& node);
		// Gets previous variable
		Node& getPrevious(void);
		// Sets previous variable
		Node& setPrevious(const Node& node);
		// Currently does nothing
		~Node(void);
	};

	// A doubly-linked list.
	template<typename T>
	class List
	{
	private:
		// The header node of a linked list
		Node& header;
	public:
		// Initializes a list with a blank header.
		List(void);
		// Initializes a list with a single element.
		List(const T& data);
		// Initializes a list with multiple elements.
		List(const int length, const T data[]);
		// Gets header variable
		Node& getHeader(void) const;
		// Gets the length of the list
		int length(void);
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
		T& getIndex(const int index);

		// Deletes all of the nodes of the list before deallocating its memory.
		~List(void);
	};
}

#endif // !KC_LISTS_H_