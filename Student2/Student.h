#pragma once
#include <iostream>
#include <valarray>
#include <string>
class Student : private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	std::ostream& arr_out(std::ostream& os) const;
public:
	Student() :std::string("Brak"), ArrayDb() {}
	explicit Student(const std::string& s) :std::string(s), ArrayDb() {}
	explicit Student(int n) :std::string("Brak"), ArrayDb(n) {}
	Student(const std::string& s, int n) :std::string(s), ArrayDb(n) {}
	Student(const std::string& s, const ArrayDb& d) :std::string(s), ArrayDb(d) {}
	Student(const char * s, const double* pd, int n):std::string(s), ArrayDb(pd, n) {}
	~Student() {}
	double average();

	using std::valarray<double>::operator[];
	using std::valarray<double>::min;

	const std::string & name() const;
	friend std::istream& operator>>(std::istream& os, Student& s);
	friend std::istream& getline(std::istream & os,Student& s);
	friend std::ostream& operator<<(std::ostream&, const Student& s);

};

