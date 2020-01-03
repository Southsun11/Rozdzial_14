#pragma once
#include <iostream>
#include <string>
#include <valarray>
class Student
{
private:
	std::string m_name;
	std::valarray<double> m_scores;
	std::ostream& arr_out(std::ostream & os)const;
public:
	Student() :m_name("brak"), m_scores() {}
	explicit Student(const std::string& s) :m_name(s), m_scores() {}
	explicit Student(int n) :m_name("brak"), m_scores(n) {}
	Student(const std::string& s, int n) :m_name(s), m_scores(n) {}
	Student(const std::string& s, const std::valarray<double>& db) :m_name(s), m_scores(db) {}
	Student(const char* str, const double* pd, int n) :m_name(str), m_scores(pd, n) {}
	~Student() {}
	double average() const;
	const std::string& name() const;
	double & operator[](int n);
	const double & operator[](int n)const;
	friend std::istream& operator>>(std::istream& is, Student& s);
	friend std::istream& getline(std::istream& is, Student& s);
	friend std::ostream& operator<<(std::ostream& os, Student& s);


};

