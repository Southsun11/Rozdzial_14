#include "Wine.h"

Wine::Wine(std::string name, int year) :m_name(name), m_date(std::valarray<int>(year), std::valarray<int>(year))
{}
Wine::Wine(const char* name, int year) : m_name(name), m_date(std::valarray<int>(year), std::valarray<int>(year))
{}
Wine::Wine(const char* name, int y, int year[], int bottles[]) : m_name(name), m_date(std::valarray<int>(year, y), std::valarray<int>(bottles, y))
{}

void Wine::GetBottles()
{
	std::cout << "Podaj  dane o winie " << this->m_name << " dla " << m_date.first().size() << " rocznikow:\n";
	for (int i = 0; i < m_date.first().size(); i++)
	{
		std::cout << "Podaj rocznik: " << std::endl;
		while(!(std::cin >> this->m_date.first()[i]))
			while (std::cin.get() != '\n')
				continue;
		std::cout << "Podaj liczbe butelek: " << std::endl;
		while(!(std::cin >> this->m_date.second()[i]))
			while (std::cin.get() != '\n')
				continue;
		
	}
}
void Wine::Show()
{
	std::cout << "Wino " << this->m_name << std::endl;
	std::cout << "\tRocznik\tButelki\n";
	for (int i = 0; i < this->m_date.first().size(); i++)
	{
		std::cout << "\t" << this->m_date.first()[i] << "\t" << this->m_date.second()[i] << std::endl;
	}
}

int Wine::Sum()
{
	return m_date.second().sum();
}