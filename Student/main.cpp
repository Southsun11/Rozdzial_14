#include "Student.h"

void set(Student& sa, int n);
const int pupils = 3;
const int quizzes = 5;
int main()
{
    Student ada[pupils] = { Student(quizzes),Student(quizzes),Student(quizzes) };
    int i;
    for (i = 0; i < pupils; ++i)
        set(ada[i], quizzes);
    std::cout << "\nLista studentow\n";
    for (i = 0; i < pupils; ++i)
        std::cout << ada[i].name() << std::endl;
    std::cout << "\nWyniki:";
    for (i = 0; i < pupils; ++i)
    {
        std::cout << ada[i];
        std::cout << "srednia: " << ada[i].average() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Gotowe\n";
    return 0;

}

void set(Student& sa, int n)
{
    std::cout << "Podaj imie i nazwisko\n";
    getline(std::cin, sa);
    std::cout << "Podaj " << n << " wynikow testow\n";
    for (int i = 0; i < n; i++)
        std::cin >> sa[i];
    while (std::cin.get() != '\n')
        continue;
}