#ifndef KC_LISTS_H_
#define KC_LISTS_H_

namespace kc
{
	// A node of a linked list 
	class Node
	{
	private:
		// The data of the mode
		void * data;
		// The next node of the linked list
		Node * next;
		// The previous node of the linked list
		Node * previous;
	public:
		// Creates a node with no data
		Node(void);
		// Creates a node with data
		Node(const void * data);
		// Gets data variable
		const void * getData(void);
		// Sets data variable
		Node setData(const void * data);
		// Gets next variable
		Node * getNext(void);
		// Sets next variable
		Node setNext(const Node * node);
		// Gets previous variable
		Node * getPrevious(void);
		// Sets previous variable
		Node setPrevious(const Node * node);
		// Currently does nothing
		~Node(void);
	};

	// A doubly-linked list.
	class List
	{
	private:
		// The header node of a linked list
		Node * header;
	public:
		// Initializes a list with a blank header.
		List(void);
		// Initializes a list with a single element.
		List(void * data);
		// Initializes a list with multiple elements.
		List(int length, void * data[]);
		// Gets header variable
		Node * getHeader(void);
		// Gets the length of the list
		int length(void);
		// Adds an element to the beginning of the list.
		void push(void * data);
		// Adds elements to the beginning of the list.
		void push(int length, void * data[]);
		// Adds an element to the end of the list.
		void append(void * data);
		// Adds elements to the end of the list.
		void append(int length, void * data[]);
		// Adds an element to the list at the index.
		void push_at(int index, void * data);
		// Adds elements to the list at the index.
		void push_at(int index, int length, void * data[]);
		// Gets the data of the list's first node. The node is destroyed.
		void * pull(void);
		// Gets the data of the list's last node. The node is destroyed.
		void * pop(void);
		// Gets the data of the node at the list's specified index. The node is destroyed.
		void * pull_at(int index);
		// Gets the data of the node at the list's specified index. The node is NOT destroyed.
		void * getIndex(int index);
		// I don't know how to do this yet so I am commenting it out.
		// I also want a bracket accessor. List[x] is getIndex(x). void operator [] (int index)?
		//void operator += (void * data);
		//void operator += (void * data[]);
		//List operator + (List list);
		//List operator + (void * data);
		//List operator + (void * data[]);
		//void operator -= (int index);
		//void operator - (int index);

		// Deletes all of the nodes of the list before deallocating its memory.
		~List(void);
	};

	//TODO: CircleList
	class CircleList
	{
	private:
		Node * header;
	public:
		CircleList(void);
		CircleList(List list);
		CircleList(void * data);
		CircleList(int length, void * data[]);
		void push(void * data);
		void pull(void * data);
		void transverse(int number);
		void operator = (List list);
		void operator += (void * data);
		void operator += (void * data[]);
		void operator -= (int index);
		~CircleList(void);
	};
}

#endif // !KC_LISTS_H_