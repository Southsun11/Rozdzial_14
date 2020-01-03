#include "Student.h"
std::ostream& Student::arr_out(std::ostream & os)const
{
	int i;
	int size = this->m_scores.size();
	if (size <= 0)
		os << "Tablica jest pusta\n";
	else
	{
		for (i = 0; i < size; i++)
		{
			std::cout << m_scores[i] << " ";
			if (i % 5 == 4)
				os << std::endl;

		}
		if(i % 5 != 0)
			os << std::endl;
	}
	return os;
}
double Student::average() const
{
	if (this->m_scores.size() > 0)
		return this->m_scores.sum() / this->m_scores.size();
	else
		return 0;
}
const std::string& Student::name() const
{
	return this->m_name;
}
double& Student::operator[](int n)
{
	return this->m_scores[n];
}
const double & Student::operator[](int n)const
{
	return this->m_scores[n];
}
std::istream& operator>>(std::istream& is, Student& s)
{
	is >> s.m_name;
	return is;
}
std::istream& getline(std::istream& is, Student& s)
{
	std::getline(is, s.m_name);
	return is;
}
std::ostream& operator<<(std::ostream& os, Student& s)
{
	os << s.m_name << std::endl;
	s.arr_out(os);
	return os;
}