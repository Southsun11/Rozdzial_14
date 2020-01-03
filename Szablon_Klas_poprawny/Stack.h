#pragma once
template <typename T>
class Stack
{
private:
	enum { MAX = 10 };
	int stacksize;
	T * items;
	int top;
public:
	explicit Stack(int ss = SIZE);
	Stack(const Stack& st);
	~Stack() { delete[] items; }
	bool isempty() { return top == 0; }
	bool isfull() { return top == stacksize; }
	bool push(const T& item);
	bool pop(T& item);
	Stack& operator=(const Stack & st);
};

template <typename T>
Stack<T>::Stack(int ss):stacksize(ss), top(0)
{\
	items = new T[stacksize];
}

template <typename T>
Stack<T>::Stack(const Stack<T>& st)
{
	this->stacksize = st.stacksize;
	this->top = st.top;
	this->items = new T[stacksize];
	for (int i = 0; i < top; i++)
		this->items[i] = st.items[i];
}

template <typename T>
bool Stack<T>::push(const T& item)
{
	if (isfull())
		return false;
	this->items[top++] = item;
	return true;
}

template <typename T>
bool Stack<T>::pop(T& item)
{
	if (isempty())
		return false;
	item = items[--top];
	return true;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> & st)
{
	if (this == &st)
		return *this;
	delete[] this->items;
	this->stacksize = st.stacksize;
	this->top = st.top;
	this->items = new T[stacksize];
	for (int i = 0; i < top; i++)
		this->items[i] = st.items[i];
	return *this;
}