#include <iostream>
#include "Person.h"

int main()
{
    Person* persons[5];
    char choice;
    int i;
    std::cout << "Tworzenie pracownikow\n";
    for (i = 0; i < 5; i++)
    {
        std::cout << "o)Osoba\nr)Rewolwerowiec\np)Pokerzysta\nz)Zla osoba\nk)koniec\n";
        std::cin.get(choice);
        while (std::cin.get() != '\n')
            continue;
        while(!(strchr("oOrRpPzZkK",choice)))
        { 
            std::cout << "o)Osoba\nr)Rewolwerowiec\np)Pokerzysta\nz)Zla osoba\nk)koniec\n";
            std::cin.get(choice);
            while (std::cin.get() != '\n')
                continue;
        }

        switch (choice)
        {
        case 'o':
        case 'O':
            persons[i] = new Person();
            break;
        case 'r':
        case 'R':
            persons[i] = new Gunslinger();
            break;
        case 'p':
        case 'P':
            persons[i] = new PokerPlayer();
            break;
        case 'z':
        case 'Z':
            persons[i] = new BadDude();
            break;  
        }
        if (choice == 'k' || choice == 'K')
            break;
        persons[i]->set();
        
    }

    std::cout << "Lista pracownikow\n";
    for (int j = 0; j < i; j++)
    {
        persons[j]->show();
        std::cout << "\n\n";
    }
        
}
