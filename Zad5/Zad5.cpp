#include "emp.h"

int main()
{
	employee em("Tadeusz", "Hubert", "Sprzedawca");
	std::cout << em << std::endl;
	em.showAll();
	std::cout << std::endl;
	Manager ma("Amforiusz", "Smoczewski", "Malarz", 5);
	std::cout << ma << std::endl;
	ma.showAll();
	std::cout << std::endl;
	Fink fi("Maurycy", "Olkuski", "Hydraulik", "Julian Bar");
	std::cout << fi << std::endl;
	fi.showAll();
	std::cout << std::endl;
	HighFink hf(ma, "Jan Kudlaty");
	hf.showAll();
	std::cout << std::endl;
	std::cout << "Wcisnij dowolny przycisk, aby przejsc do nastepnego etapu:\n";
	std::cin.get();
	HighFink hf2;
	//hf2.setAll();
	std::cout << std::endl;
	std::cout << "Uzywa wskaznika abstr_emp * \n";
	abstr_emp* tri[4] = { &em, &fi, &hf,&hf2 };
	for (int i = 0; i < 4; i++)
	{
		tri[i]->showAll();
		std::cout << std::endl;
	}
		
	return 0;
}
