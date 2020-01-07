#pragma once
#include <iostream>
#include <string>
#include <valarray>

template <typename T1, typename T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1& first();
	T2& second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1& aval, const T2& bval) :a(aval), b(bval) {}
	Pair() {}
};

template <typename T1, typename T2>
T1& Pair<T1, T2>::first()
{
	return a;
}

template <typename T1, typename T2>
T2& Pair<T1, T2>::second()
{
	return b;
}



class Wine:private std::string,private Pair<std::valarray<int>,std::valarray<int>>
{
public:
	Wine(std::string name = "brak", int year = 0); 
	Wine(const char* name, int year);
	Wine(const char* name,int y, int year[], int bottles[]);
	void GetBottles();
	void Show();
	int Sum();
	std::string Label() { return (std::string) * this; }
};


