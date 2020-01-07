#pragma once
#include <iostream>
template <typename T>
class QueueTP
{
private:
	struct Node
	{
		Node* prev;
		Node* next;
		T value;
		Node(T v) { value = v; prev = NULL; next = NULL; }
	};

	Node* m_head;
	Node* m_tail;
public:
	QueueTP();
	~QueueTP();
	void push(const T &);
	void pop(T&);
	void show();
	void rshow();

};


template <typename T>
QueueTP<T>::QueueTP()
{
	m_head = NULL;
	m_tail = NULL;
}

template <typename T>
QueueTP<T>::~QueueTP()
{
	Node* temp;;
	if ((m_head  == m_tail) != NULL)
		delete m_head;
	else if (m_head->next)
	{
		temp = m_head->next;
		while (temp != m_tail)
		{
			delete m_head;
			m_head = temp;
			temp = temp->next;
		}
		delete m_tail;
	}


}

template<typename T>
void QueueTP<T>::push(const T& v)
{
	if (m_head == NULL)
	{
		m_head = new Node(v);
		m_tail = m_head;
	}
	else
	{
		Node* temp = m_tail;
		m_tail->next = new Node(v);
		m_tail = m_tail->next;
		m_tail->prev = temp;

	}
}
template <typename T>
void QueueTP<T>::pop(T& v)
{
	if (m_head == NULL)
		std::cout << "Brak elementow w kolejce\n";
	else if ((m_head == m_tail) != NULL)
	{
		v = m_head->value;
		delete m_head;
		m_head = m_tail = NULL;
	}
	else
	{
		Node* temp = m_tail;
		v = m_tail->value;
		m_tail = m_tail->prev;
		m_tail->next = NULL;
		delete temp;
	}



}
template <typename T>
void QueueTP<T>::show()
{
	Node* temp = m_head;
	while (temp != NULL)
	{
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}
}
template <typename T>
void QueueTP<T>::rshow()
{
	Node* temp = m_tail;
	while (temp != NULL)
	{
		std::cout << temp->value << std::endl;
		temp = temp->prev;
	}
}