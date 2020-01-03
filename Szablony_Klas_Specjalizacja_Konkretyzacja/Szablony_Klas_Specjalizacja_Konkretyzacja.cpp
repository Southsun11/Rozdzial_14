#include "Nagłówek.h"
#include <iostream>

int main()
{

    /*
    const char* temp1 = "Ciag 1";
    const char* temp2 = "Zapis2";
    Pair<int, int> t1(2, 5);
    Pair<const char*, const char* > t2(temp1, temp2);
    Pair<double, const char*>t3(3, temp1);
    if (t1.compare() < 0)
        std::cout << "Pierwsza wartosc wieksza";
    else if (t1.compare() == 0)
        std::cout << "Te samo wartosci";
    else if (t1.compare() > 0)
        std::cout << "Druga wartosc wieksza";
    std::cout << "\nKoniec" << std::endl;
    if (t2.compare() < 0)
        std::cout << "Pierwsza wartosc wieksza";
    else if (t2.compare() == 0)
        std::cout << "Te samo wartosci";
    else if (t2.compare() > 0)
        std::cout << "Druga wartosc wieksza";
    std::cout << "\nKoniec" << std::endl;
    if (t3.compare() < 0)
        std::cout << "Pierwsza wartosc wieksza";
    else if (t3.compare() == 0)
        std::cout << "Te samo wartosci";
    else if (t3.compare() > 0)
        std::cout << "Druga wartosc wieksza";
        */
    int* a = new int(3);
    int* b = new int(3);
   
    Pair<int*, int*> t4(a, b);
    std::cout << t4.compare();

}
