#include <iostream>
#include "Stack.h"
#include <string>
#include <cctype>
int main()
{
    Stack<std::string> st;
    char ch;
    std::string po;
    std::cout << "Wpisz D, aby dodac zamowienie\n"
        << "P, aby przetworzyc zamowienie\n"
        << "Z aby zakonczyc\n";
    while (std::cin >> ch && std::toupper(ch) != 'Z')
    {
        while (std::cin.get() != '\n')
            continue;
        if (!std::isalpha(ch))
            std::cout << '\a';
        switch (ch)
        {
            case 'D':
            case 'd':
                 std::cout << "Podaj nowy numer zamowienia:\n";
                 std::getline(std::cin, po);
                 if (!st.push(po))
                        std::cout << "Stos pelny\n";
                 break;
            case 'P':
            case 'p':
                if (!st.pop(po))
                    std::cout << "Stos pusty\n";
                else
                    std::cout << "Numer zamowienia " << po << " zdjety\n";
                break;
        }
        std::cout << "Wpisz D, aby dodac zamowienie\n"
            << "P, aby przetworzyc zamowienie\n"
            << "Z aby zakonczyc\n";
     

    }
    std::cout << "Koniec\n";
}
