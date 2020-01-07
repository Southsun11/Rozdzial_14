#include "Wine.h"

Wine::Wine(std::string name, int year) :std::string(name), Pair(std::valarray<int>(year), std::valarray<int>(year))
{}
Wine::Wine(const char* name, int year) : std::string(name), Pair(std::valarray<int>(year), std::valarray<int>(year))
{}
Wine::Wine(const char* name, int y, int year[], int bottles[]) : std::string(name), Pair(std::valarray<int>(year, y), std::valarray<int>(bottles, y))
{}

void Wine::GetBottles()
{
	std::cout << "Podaj  dane o winie " << (std::string)*this << " dla " << Pair::first().size() << " rocznikow:\n";
	for (int i = 0; i < Pair::first().size(); i++)
	{
		std::cout << "Podaj rocznik: " << std::endl;
		while(!(std::cin >> Pair::first()[i]))
			while (std::cin.get() != '\n')
				continue;
		std::cout << "Podaj liczbe butelek: " << std::endl;
		while(!(std::cin >> Pair::second()[i]))
			while (std::cin.get() != '\n')
				continue;
		
	}
}
void Wine::Show()
{
	std::cout << "Wino " << (std::string)*this << std::endl;
	std::cout << "\tRocznik\tButelki\n";
	for (int i = 0; i < Pair::first().size(); i++)
	{
		std::cout << "\t" << Pair::first()[i] << "\t" << Pair::second()[i] << std::endl;
	}
}

int Wine::Sum()
{
	return Pair::second().sum();
}