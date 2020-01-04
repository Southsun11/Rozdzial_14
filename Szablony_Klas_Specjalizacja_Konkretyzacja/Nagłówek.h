#pragma once
#include <string>
template <typename T1, typename T2> 
class Pair
{
private:
	T1 a;
	T2 b;
public:
	Pair() {};
	Pair(T1 a1, T2 b1) :a(a1), b(b1) {}
	int compare();
};

template <typename T1,typename T2>
int Pair<T1,T2>::compare()
{
	if (a > b)
		return -1;
	else if (a == b)
		return 0;
	else
		return 1;
}

template<>  int Pair<const char*, const char*>::compare()
{
	return std::strcmp(a, b);
};

template <typename T1>
class Pair<T1, const char *>
{
private:
	T1 a;
	const char * b;
public:
	Pair() {};
	Pair(T1 a1, const char * b1) :a(a1), b(b1) {}
	int compare();
};


template <typename T>
int Pair<T, const char *>::compare()
{
	//std::cout << "Nie mozna porownac liczby z ciagiem" << std::endl;
	return INFINITY;
}

template <typename T1, typename T2>
class Pair<T1 *,T2 *>
{
private:
	T1 * a;
	T2 * b;
public:
	Pair() {};
	Pair(T1 * a1, T2 * b1) :a(a1), b(b1) {}
	int compare();
};


template <typename T1,typename T2>
int Pair<T1*, T2*>::compare()
{
	{
		if (*a > *b)
			return -1;
		else if (*a == *b)
			return 0;
		else if (*a < * b)
			return 1;
	}
}