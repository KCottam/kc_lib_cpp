#include "kc_lists.h"
template<typename T> kc::node<T>::node(void) : data{ nullptr }, next{ nullptr }, previous{ nullptr } {}

template<typename T> kc::node<T>::node(const T& data) : data{ data }, next{ nullptr }, previous{ nullptr } {}

template<typename T> kc::node<T>::~node(void) {}

template<typename T> kc::list<T>::list(void) : header_{ new kc::node<T>() } {}

template<typename T> kc::list<T>::list(const T& data) : header_{ new kc::node<T>(data) } {}

template<typename T> kc::list<T>::list(const int length, const T data[]) : header_{ new kc::node<T>{data[0]} }
{
	node<T>* traversal_node = header_;
	for (auto i = 1; i < length; i++)
	{
		traversal_node->setNext(new node<T>(data[i]));
		traversal_node = traversal_node->getNext();
	}
}

template<typename T> kc::node<T>& kc::list<T>::get_header(void) const { return header_; }

template<typename T> int kc::list<T>::length(void) const
{
	node<T>* traversal_node = header_;
	if (!traversal_node)
	{
		return 0;
	}
	traversal_node = traversal_node->getNext();
	int length = 1;
	for (; traversal_node != header_; length++)
	{
		traversal_node = traversal_node->getNext();
	}
	return length;
}

template<typename T> void kc::list<T>::push(const T& data)
{
	node<T>* previous_header = header_;
	header_ = new node<T>(data);
	if (previous_header)
	{
		header_->setNext(previous_header);
	}
}

template<typename T> void kc::list<T>::push(const int length, const T data[])
{
	for (auto i = 0; i < length; i++)
	{
		push_at(i, data);
	}
}

template<typename T> void kc::list<T>::append(const T& data)
{
	if (!header_)
	{
		push(data);
	}
	node<T>* traversal_node = header_;
	node<T>* before_traversal_node;
	while (traversal_node)
	{
		before_traversal_node = traversal_node;
		traversal_node = traversal_node->getNext();
	}
	node<T>* new_node = new node<T>(data);
	new_node->setPrevious(before_traversal_node);
	before_traversal_node->setNext(new_node);
}

template<typename T> void kc::list<T>::append(const int length, const T data[])
{
	for (auto i = 0; i < length; i++)
	{
		append(data);
	}
}

template<typename T> void kc::list<T>::push_at(const int index, const T& data)
{
	node<T>* traversal_node = header_;
	for (auto i = 0; i < index && traversal_node; i++)
	{
		traversal_node = traversal_node->getNext();
	}
	if (!traversal_node)
	{
		push(data);
	}
	else
	{
		node<T> * new_node = new node<T>(data);
		new_node->setPrevious(traversal_node);
		new_node->setNext(traversal_node->getNext());
		new_node->getNext()->setPrevious(new_node);
		traversal_node->setNext(new_node);
	}
}

template<typename T> void kc::list<T>::push_at(const int index, const int length, const T data[])
{
	for (auto i = 0; i < length; i++)
	{
		push_at(index + i, data[i]);
	}
}

template<typename T> T& kc::list<T>::pull(void)
{
	if (!header_)
		return 0;
	void * data = header_->getData();
	node<T> * old_header = header_;
	header_ = header_->getNext();
	delete old_header;
	return data;
}

template<typename T> T& kc::list<T>::pop(void)
{
	node<T>* traversal_node = header_;
	node<T> before_traversal_node;
	while (traversal_node)
	{
		before_traversal_node = traversal_node;
		traversal_node = traversal_node->getNext();
	}
	before_traversal_node->setNext(0);
	T& data = traversal_node->getData();
	delete traversal_node;
	return data;
}

template<typename T> T& kc::list<T>::pull_at(int index)
{
	node<T>* traversal_node = header_;
	node<T>* before_traversal_node;
	for (auto i = 0; i < index && traversal_node; i++)
	{
		before_traversal_node = traversal_node;
		traversal_node = traversal_node->getNext();
	}
	if (!traversal_node)
	{
		return pop();
	}
	else
	{
		T& data = traversal_node->getData();
		before_traversal_node->setNext(0);
		delete traversal_node;
		return data;
	}
}

template<typename T> T& kc::list<T>::get_index(int index)
{
	node<T>* traversal_node = header_;
	node<T> before_traversal_node;
	for (int i = 0; i < index && traversal_node; i++)
	{
		before_traversal_node = traversal_node;
		traversal_node = traversal_node->getNext();
	}
	if (!traversal_node)
	{
		return before_traversal_node->getData();
	}
	else
	{
		return traversal_node->getData();
	}
}

template<typename T> kc::list<T>::~list(void)
{
	while (header_)
	{
		pull();
	}
}