#include "emp.h"

abstr_emp::~abstr_emp() {}

void abstr_emp::showAll() const
{
	std::cout << "Imie: " << m_fname << std::endl;
	std::cout << "Nazwisko: " << m_lname << std::endl; 
	std::cout << "Praca: " << m_job << std::endl;
}

void abstr_emp::setAll()
{
	while (std::cin.get() != '\n')
		continue;
	std::cout << "Podaj imie\n";
	getline(std::cin, m_fname);
	std::cout << "Podaj nazwisko\n";
	getline(std::cin, m_lname);
	std::cout << "Podaj prace\n";
	getline(std::cin, m_job);
}
std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << "Imie: " << e.m_fname << std::endl;
	os << "Nazwisko: " << e.m_lname << std::endl;
	os << "Praca: " << e.m_job << std::endl;
	return os;
}

void employee::showAll()const
{
	abstr_emp::showAll();
}
void employee::setAll()
{
	abstr_emp::setAll();
}

void Manager::showAll() const
{
	abstr_emp::showAll();
	std::cout << "Zarzadza " << m_inchargeof << " osobami\n";
}

void Manager::setAll()
{
	abstr_emp::setAll();
	std::cout << "Podaj liczbe osob ktorymi zarzadza\n";
	while (!(std::cin >> m_inchargeof))
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Podaj liczbe osob ktorymi zarzadza\n";
	}
	while (std::cin.get() != '\n')
		continue;
}

void Fink::showAll() const
{
	abstr_emp::showAll();
	std::cout << "Donosi do: " << m_reportsTo << std::endl;
}

void Fink::setAll()
{
	abstr_emp::setAll();
	std::cout << "Podaj osobe do ktorej donosi\n";
	getline(std::cin, m_reportsTo);
}




HighFink::HighFink() :abstr_emp(), Manager(), Fink() {}

HighFink::HighFink(const std::string& fname, const std::string& lname, const std::string& job, const std::string& reportsTo, int inchargeof)
		:abstr_emp(fname, lname, job), Manager(fname, lname, job, inchargeof), Fink(fname, lname, job, reportsTo) {}

HighFink::HighFink(const abstr_emp& e, const std::string& reportsTo, int inchargeof)
		:abstr_emp(e), Manager(e, inchargeof), Fink(e, reportsTo) {}

HighFink::HighFink(const Fink& f, int inchargeof)
	: abstr_emp(f), Manager(f, inchargeof), Fink(f) {}

HighFink::HighFink(const Manager& m, const std::string& reportsTo)
		:abstr_emp(m), Manager(m), Fink(m, reportsTo) {}

void HighFink::showAll() const
{
	abstr_emp::showAll();
	std::cout << "Zarzadza " << Manager::inChargeof() << " osobami\n";
	std::cout << "Donosi do: " << Fink::reportsTo() << std::endl;
}
void HighFink::setAll()
{
	abstr_emp::setAll();

	std::cout << "Podaj liczbe osob ktorymi zarzadza\n";
	while (!(std::cin >> Manager::inChargeof()))
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Podaj liczbe osob ktorymi zarzadza\n";
	}
	while (std::cin.get() != '\n')
		continue;
	std::cout << "Podaj osobe do ktorej donosi\n";
	getline(std::cin, Fink::reportsTo());
}