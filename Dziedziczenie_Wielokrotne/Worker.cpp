#include "Worker.h"
#include <iostream>
void Worker::set()
{
	std::cout << "Podaj imie i nazwisko pracownika\n";
	getline(std::cin, m_fullname);
	std::cout << "Podaj numer identyfikacyjny pracownika\n";
	std::cin >> m_id;
	while (std::cin.get() != '\n')
		continue;

}

void Worker::show() const
{
	std::cout << "Imie i nazwisko: " << m_fullname << std::endl;
	std::cout << "Numer identyfikacyjny: " << m_id << std::endl;
}

void Waiter::set()
{
	Worker::set();
	std::cout << "Podaj poziom elegancji kelnera\n";
	std::cin >> m_pancache;
	while (std::cin.get() != '\n')
		continue;

}
const char* Singer::pv[] = { "inny","alt","kontraly","sopran","bas","baryton","tenor" };

void Waiter::show() const
{
	std::cout << "Kategoria Kelner" << std::endl;
	Worker::show();
	std::cout << "Poziom elegancji pracownika: " << m_pancache << std::endl;
}
void Singer::set()
{
	Worker::set();
	std::cout << "Podaj numer skali glosu piosenkarza\n";
	int i;
	for (i = 0; i < Vtypes; i++)
		std::cout << i << ": " << pv[i] << std::endl;
	while (std::cin >> m_voice && (m_voice < 0 || m_voice >= Vtypes))
		std::cout << "Podaj wartosc nieujemna, mniejsza od " << Vtypes << std::endl;
	while (std::cin.get() != '\n')
		continue;
}
void Singer::show() const
{
	std::cout << "Kategoria piosenkarz";
	Worker::show();
	std::cout << "Skala glosy: " << pv[m_voice];
}
