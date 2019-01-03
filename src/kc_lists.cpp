#include "kc_lists.h"
/// <summary>
/// Initializes a node of a linked list.
/// </summary>
template<typename T>
kc::Node<T>::Node(void) : data{ 0 }, next{ 0 }, previous{ 0 }
{
}

/// <summary>
/// Initializes a node of a linked list with <see cref="data"/>,
/// </summary>
/// <param name="data">The to-be data of the node.</param>
template<typename T>
kc::Node<T>::Node(const T& data) : data{ data }, next{ 0 }, previous{ 0 }
{
}

/// <summary>
/// Gets the data of a node.
/// </summary>
/// <returns>The node's data</returns>
template<typename T>
T& kc::Node<T>::getData(void)
{
	return data;
}

/// <summary>
/// Sets the data of a node to <see cref="data"/>.
/// </summary>
/// <param name="data">The node's to-be data.</param>
/// <returns>Itself</returns>
template<typename T>
kc::Node<T>& kc::Node<T>::setData(const T& data)
{
	this->data = data;
	return *this;
}

/// <summary>
/// Gets the next node of the linked list.
/// </summary>
/// <returns>The node pointer of the next node in the linked list. 0 if there is none.</returns>
template<typename T>
kc::Node<T>& kc::Node<T>::getNext(void)
{
	return next;
}

/// <summary>
/// Sets the next node of the linked list to <see cref="node"/>.
/// </summary>
/// <param name="node">The node to be set as the next node in the list.</param>
/// <returns>Itself</returns>
template<typename T>
kc::Node<T>& kc::Node<T>::setNext(const Node& node)
{
	this->next = node;
	return *this;
}

/// <summary>
/// Gets the previous node of the linked list.
/// </summary>
/// <returns>The node to be set as the previous node in the list.</returns>
template<typename T>
kc::Node<T>& kc::Node<T>::getPrevious(void)
{
	return previous;
}

/// <summary>
/// Sets the previous node of the linked list to <see cref="node"/>.
/// </summary>
/// <param name="node">The node to be set as the next node in the list.</param>
/// <returns>Itself</returns>
template<typename T>
kc::Node<T>& kc::Node<T>::setPrevious(const Node& node)
{
	this->previous = node;
	return *this;
}

/// <summary>
/// Nothing
/// </summary>
template<typename T>
kc::Node<T>::~Node(void)
{
}

/// <summary>
/// Makes a new list with a header node.
/// </summary>
template<typename T>
kc::List<T>::List(void) : header{ new kc::Node<T>() }
{
}

/// <summary>
/// Makes a new list with a header node that has data.
/// </summary>
/// <param name="data">The input data</param>
template<typename T>
kc::List<T>::List(const T& data) : header{ new kc::Node<T>(data) }
{
}

/// <summary>
/// Makes a new list with data.
/// </summary>
/// <param name="length">How many items are in <see cref="data"/>.</param>
/// <param name="data">The data of a list.</param>
template<typename T>
kc::List<T>::List(const int length, const T data[]) : header{ new kc::Node<T>{data[0]} }
{
	Node& traversalNode = header;
	for (int i = 1; i < length; i++)
	{
		traversalNode->setNext(new Node(data[i]));
		traversalNode = traversalNode->getNext();
	}
}

/// <summary>
/// Gets the header of the list.
/// </summary>
/// <returns>The header of the list.</returns>
template<typename T>
kc::Node<T>& kc::List<T>::getHeader(void) const
{
	return header;
}

/// <summary>
/// Gets the length of the list.
/// </summary>
/// <returns>The length of the list.</returns>
template<typename T>
int kc::List<T>::length(void)
{
	Node& traversalNode = header;
	if (!traversalNode)
	{
		return 0;
	}
	traversalNode = traversalNode->getNext();
	int length = 1;
	for (; traversalNode != header; length++)
	{
		traversalNode = traversalNode->getNext();
	}
	return length;
}

/// <summary>
/// Inserts data at the beginning of the list.
/// </summary>
/// <param name="data">Data</param>
template<typename T>
void kc::List<T>::push(const T& data)
{
	Node& previousHeader = header;
	header = new Node(data);
	if (previousHeader)
	{
		header->setNext(previousHeader);
	}
}

/// <summary>
/// Inserts data at the beginning of the list.
/// </summary>
/// <param name="length">How many items are in <see cref="data"/>.</param>
/// <param name="data">Data</param>
template<typename T>
void kc::List<T>::push(const int length, const T data[])
{
	for (int i = 0; i < length; i++)
	{
		push_at(i, data);
	}
}

/// <summary>
/// Inserts data at the end of the list.
/// </summary>
/// <param name="data">Data</param>
template<typename T>
void kc::List<T>::append(const T& data)
{
	if (!header)
	{
		push(data);
	}
	Node& traversalNode = header;
	Node& beforeTraversalNode;
	while (traversalNode)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	Node& newNode = new Node(data);
	newNode->setPrevious(beforeTraversalNode);
	beforeTraversalNode->setNext(newNode);
}

/// <summary>
/// Inserts data at the end of the list.
/// </summary>
/// <param name="length">How many items are in <see cref="data"/>.</param>
/// <param name="data">Data</param>
template<typename T>
void kc::List<T>::append(const int length, const T data[])
{
	for (int i = 0; i < length; i++)
	{
		append(data);
	}
}

/// <summary>
/// Inserts data at the specified <see cref="index"/> of the list.
/// </summary>
/// <param name="data">Data</param>
/// <param name="index"></param>
template<typename T>
void kc::List<T>::push_at(int index, const T& data)
{
	Node& traversalNode = header;
	for (int i = 0; i < index && traversalNode; i++)
	{
		traversalNode = traversalNode->getNext();
	}
	if (!traversalNode)
	{
		push(data);
	}
	else
	{
		Node * newNode = new Node(data);
		newNode->setPrevious(traversalNode);
		newNode->setNext(traversalNode->getNext());
		newNode->getNext()->setPrevious(newNode);
		traversalNode->setNext(newNode);
	}
}

/// <summary>
/// Inserts data at the specified <see cref="index"/> of the list.
/// </summary>
/// <param name="index">Specified index of the list.</param>
/// <param name="length">How many items are in <see cref="data"/>.</param>
/// <param name="data">Data</param>
template<typename T>
void kc::List<T>::push_at(const int index, const int length, const T data[])
{
	for (int i = 0; i < length; i++)
	{
		push_at(index + i, data[i]);
	}
}

/// <summary>
/// Gets data from the beginning of the list and destroys the node.
/// </summary>
/// <returns>Data</returns>
template<typename T>
T& kc::List<T>::pull(void)
{
	if (!header)
		return 0;
	void * data = header->getData();
	Node * oldHeader = header;
	header = header->getNext();
	delete oldHeader;
	return data;
}

/// <summary>
/// Gets data from the end of the list and destroys the node.
/// </summary>
/// <returns>Data</returns>
template<typename T>
T& kc::List<T>::pop(void)
{
	Node& traversalNode = header;
	Node& beforeTraversalNode;
	while (traversalNode)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	beforeTraversalNode->setNext(0);
	T& data = traversalNode->getData();
	delete traversalNode;
	return data;
}

/// <summary>
/// Gets data from the specified <see cref="index"/> of the list and destroys the node.
/// </summary>
/// <param name="index">Specified index</param>
/// <returns>Data</returns>
template<typename T>
T& kc::List<T>::pull_at(int index)
{
	Node& traversalNode = header;
	Node& beforeTraversalNode;
	for (int i = 0; i < index && traversalNode; i++)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	if (!traversalNode)
	{
		return pop();
	}
	else
	{
		T& data = traversalNode->getData();
		beforeTraversalNode->setNext(0);
		delete traversalNode;
		return data;
	}
}

/// <summary>
/// Gets data of the specified <see cref="index"/> of the list and does not destroy the node.
/// </summary>
/// <param name="index">Specified index</param>
/// <returns>Data</returns>
template<typename T>
T& kc::List<T>::getIndex(int index)
{
	Node& traversalNode = header;
	Node& beforeTraversalNode;
	for (int i = 0; i < index && traversalNode; i++)
	{
		beforeTraversalNode = traversalNode;
		traversalNode = traversalNode->getNext();
	}
	if (!traversalNode)
	{
		return beforeTraversalNode->getData();
	}
	else
	{
		return traversalNode->getData();
	}
}

/// <summary>
/// Deletes nodes before deallocation.
/// </summary>
template<typename T>
kc::List<T>::~List(void)
{
	while (header)
	{
		pull();
	}
}
