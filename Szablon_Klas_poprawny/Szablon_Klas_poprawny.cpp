#include <iostream>
#include "Stack.h"
#include <ctime>
#include <cstdlib>
const int NUM = 10;
int main()
{
    std::srand(std::time(0));
    std::cout << "Podaj rozmiar stosu\n";
    int stacksize;
    std::cin >> stacksize;
    Stack<const char*> st(stacksize);
    const char* in[NUM] = { "1: Henryk Gilgamesz","2: Kinga Isztar", "3: Beata Roker","4: Jan Flagranti","5: Wolfgang Mocny","6: Patrucja Kup"
    ,"7: Jacek Almond", "8: Ksawery Papryka","9: Julina Mor","10: Marian Macher" };
    const char* out[NUM];
    int processed = 0;
    int nextin = 0;
    while (processed < NUM)
    {
        if (st.isempty())
            st.push(in[nextin++]);
        else if (st.isfull())
            st.pop(out[processed++]);
        else if (rand() % 2 && nextin < NUM)
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    
    }
    for (int i = 0; i < NUM; i++)
        std::cout << out[i] << std::endl;
}

