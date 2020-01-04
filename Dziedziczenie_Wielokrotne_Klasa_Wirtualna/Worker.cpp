#include "Worker.h"
#include <iostream>
Worker::~Worker() {}

void Worker::data() const
{
	std::cout << "Imie i nazwisko: " << m_fullname << std::endl;
	std::cout << "Numer identyfikacyjny: " << m_id << std::endl;
}

void Worker::get()
{
	std::cout << "Podai imie i nazwisko";
	getline(std::cin, m_fullname);
	std::cout << "Podaj numer identyfikacyjny";
	std::cin >> m_id;
	while (std::cin.get() != '\n')
		continue;
}

void Waiter::data() const
{
	std::cout << "Elegancja: " << m_panache << std::endl;
}

void Waiter::get()
{
	std::cout << "Podaj poziom elegancji";
	std::cin >> m_panache;
	while (std::cin.get() != '\n')
		continue;
}

void Waiter::set()
{
	Worker::get();
	Waiter::get();
}

void Waiter::show()const
{
	Worker::data();
	Waiter::data();
}


const char* Singer::m_pv[Singer::Vtypes] = { "inny","alt","kontralt","sopran","bas","baryton","tenor" };

void Singer::data() const
{
	std::cout << "Skala glosu: " << m_pv[m_voice] << std::endl;
}

void Singer::get()
{
	std::cout << "Podaj numer dla skali glosu piosenkarza\n";
	for (int i = 0; i < Vtypes; i++)
		std::cout << i  << ": " << m_pv[i] << std::endl;
	std::cin >> m_voice;
	while (std::cin.get() != '\n')
		continue;
}

void Singer::show() const
{
	Worker::data();
	Singer::data();
}

void Singer::set()
{
	Worker::get();
	Singer::get();
}

void SingingWaiter::data() const
{
	Waiter::data();
	Singer::data();
}

void SingingWaiter::get()
{
	Waiter::get();
	Singer::get();
}

void SingingWaiter::show() const
{
	Worker::data();
	SingingWaiter::data();
}

void SingingWaiter::set()
{
	Worker::get();
	SingingWaiter::get();
}