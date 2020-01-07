#pragma once
#include <string>
#include <iostream>

class Card
{
private:
	static std::string temp[];
	static std::string cards_figure[];
	std::string m_colour;
	int m_figure;
public:
	Card(std::string colour = "PIK", int figure = 1) :m_colour(colour), m_figure(figure) {}
	void show() const{
		std::cout << "Karta: " << cards_figure[m_figure - 2] << " " << m_colour;
	}
	void set();
	
};
class Person
{
private:
	std::string m_name;
	std::string m_fname;
protected:
	virtual void data()const{ std::cout << "Imie: " << m_name << "\nNazwisko: " << m_fname; }
	virtual void get();
public:
	Person(const std::string& name = "brak", const std::string& fname = "brak") :m_name(name), m_fname(fname) {}
	virtual void show()const { data();}
	virtual void set() { get(); }
};

class Gunslinger :virtual public Person
{
private:
	int m_cut;
	double m_gunTime;
protected:
	virtual void data()const { std::cout << "Liczba naciec: " << m_cut << "\nCzas wyciagniecia pistoletu: " << m_gunTime; }
	virtual void get();
public:
	Gunslinger(const std::string& name = "brak", const std::string& fname = "brak", int cut = 0, int gunTime = 0)
		:Person(name, fname), m_cut(cut), m_gunTime(gunTime) {}
	Gunslinger(const Person& P, int cut, int gunTime) :Person(P), m_cut(cut), m_gunTime(gunTime) {}
	double draw() { return m_gunTime; }
	int cut() { return m_cut; }
	virtual void show()const { Person::data(); std::cout << std::endl; data(); }
	virtual void set() { Person::get(); std::cout << std::endl; get(); }
};


class PokerPlayer :virtual public Person
{
private:
	Card m_card;
protected:
	virtual void data() const { m_card.show(); }
	virtual void get();
public:
	PokerPlayer(const std::string & name = "brak", const std::string& fname = "brak", const std::string& figure = "PIK", int number = 1)
		:Person(name, fname), m_card(figure, number) {}
	PokerPlayer(const Person& p, const std::string& figure = "PIK", int number = 1) :Person(p), m_card(figure, number) {}
	Card draw() { return m_card; }
	virtual void show() const { Person::data(); std::cout << std::endl; data(); }
	virtual void set() { Person::get(), this->get(); }
};

class BadDude : public Gunslinger, public PokerPlayer
{
protected:
	virtual void data()const { Gunslinger::data(); std::cout << std::endl; PokerPlayer::data(); }
	virtual void get();
public:
	BadDude(const std::string& name = "brak", const std::string& fname = "brak", int cut = 0,
		double gunTime = 0, const std::string& figure = "PIK", int number = 1)
		:Person(name, fname), Gunslinger(name,fname,cut, gunTime), PokerPlayer(name,fname,figure, number) {}
	BadDude(const Person& p, int cut = 0,double gunTime = 0, const std::string& figure = "PIK", int number = 1) 
		:Person(p), Gunslinger(p, cut,gunTime), PokerPlayer(p, figure,number) {}
	double gdraw() { return Gunslinger::draw(); }
	Card cdraw() { return PokerPlayer::draw(); }
	virtual void show() const { Person::data(); std::cout << std::endl; data(); }
	virtual void set() { Person::get(); get(); }
};
