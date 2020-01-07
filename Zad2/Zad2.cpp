#include <iostream>
#include "Wine.h"
int main()
{
    std::cout << "Podaj nazwe Wina: ";
    char label[50];
    std::cin.getline(label, 50);
    std::cout << "Podaj liczbe rocznikow:";
    int yrs;
    while (!(std::cin >> yrs))
        while (std::cin.get() != '\n')
            continue;
    Wine holding(label, yrs);
    holding.GetBottles();
    holding.Show();
    const int YRS = 3;
    int y[YRS] = { 1993,1995,1998 };
    int b[YRS] = { 48,60,72 };
        Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    std::cout << "Łaczna liczba butelek wina: " << more.Label() << "\t" << more.Sum() << std::endl;
}