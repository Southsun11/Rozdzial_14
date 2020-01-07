#include "Person.h"

std::string Card::temp[] = { "Pik","Trefl","Kier","Karo" };
std::string Card::cards_figure[] = { "2","3","4","5","6","7","8","9","10","J","D","K","A" };

void Card::set()
{
	std::cout << "Podaj kolor karty\n";
	std::cout << "Pik Trefl Kier Karo\n";
	getline(std::cin, m_colour);
	while (m_colour != "Pik" && m_colour != "Trefl" && m_colour != "Kier" && m_colour != "Karo")
	{
		std::cout << "Podaj kolor karty\n";
		std::cout << "Pik Trefl Kier Karo\n";
		getline(std::cin, m_colour);
	}
	std::cout << "Podaj numer karty od 2 do 14(AS)\n";
	for (int i = 0; i < 14; i++)
		std::cout << cards_figure[i] << " ";
	while (!(std::cin >> m_figure) || m_figure < 2 || m_figure > 14)
	{
		std::cout << "Musisz podaj liczbe od 2 do 14\n";
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	while (std::cin.get() != '\n')
		continue;
}
void Person::get()
{
	std::cout << "Podaj imie: \n";
	getline(std::cin, m_name);
	std::cout << "Podaj nazwisko\n";
	getline(std::cin,m_fname);
	
}

void Gunslinger::get()
{
	std::cout << "Podaj liczbe naciec na rewolwerze\n";
	while (!(std::cin >> m_cut))
	{
		std::cout << "Musisz podaj liczbe\n";
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	while (std::cin.get() != '\n')
		continue;
	std::cout << "Podaj czas wyciagniecia rewolwera w formacie 0.00\n";
	while (!(std::cin >> m_gunTime))
	{
		std::cout << "Musisz podaj liczbe\n";
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	while (std::cin.get() != '\n')
		continue;

}

void PokerPlayer::get()
{
	m_card.set();
}

void BadDude::get()
{
	Gunslinger::get();
	PokerPlayer::get();
}