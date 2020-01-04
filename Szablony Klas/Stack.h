#pragma once
template <typename T>
class Stack
{
	enum { MAX = 10 };
	T items[MAX];
	int top;
public:
	Stack();
	bool isempty();
	bool isfull();
	bool push(const T & item);
	bool pop(T & item);
};

template <typename T>
Stack<T>::Stack()
{
	top = 0;
}

template <typename T>
bool Stack<T>::isempty()
{
	return top == 0;
}

template <typename T>
bool Stack<T>::isfull()
{
	return top == MAX;
}

template<typename T>
bool Stack<T>::push(const T & item )
{
	if (isfull())
		return false;
	items[top++] = item;
	return true;
}

template<typename T>
bool Stack<T>::pop(T & item )
{
	if (isempty())
		return false;
	item = items[--top];
	return true;
}