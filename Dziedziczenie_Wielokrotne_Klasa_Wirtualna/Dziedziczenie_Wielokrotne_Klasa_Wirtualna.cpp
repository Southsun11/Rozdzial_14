#include <iostream>
#include <string>
#include "Worker.h"
const int SIZE = 3;
int main()
{
Worker * lolas[SIZE];
int ct;
for(ct = 0; ct < SIZE;ct++)
	{
		char choice;
		std::cout << "Podaj kategorie pracownika:\n"
			<< "k) kelner\n" << "p) piosenkarz\n"
			<< "s) spiewajacy kelner\n" << "w) wyjscie\n";
		std::cin >> choice;
		while (std::strchr("kpsw", choice) == NULL)
		{
			std::cout << "Wpisz k s p lub w" << std::endl;
			std::cin >> choice;
		}
		if (choice == 'w')
			break;
		switch (choice)
		{
		case 'k':
			lolas[ct] = new Waiter();
			break;
		case 'p':
			lolas[ct] = new Singer();
			break;
		case 's':
			lolas[ct] = new SingingWaiter();
			break;
		}
		std::cin.get();
		lolas[ct]->set();

	}
	std::cout << "\n\n\n\Lista Pracownikow";
	for (int i = 0; i < ct; i++)
	{
		lolas[i]->show();
	}
	for (int i = 0; i < ct; i++)
		delete lolas[i];
	return 0;
}