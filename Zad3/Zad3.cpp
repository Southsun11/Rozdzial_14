#include <iostream>
#include "QueueTP.h"
int main()
{
    QueueTP<int> kolejka;
    int a;
    kolejka.push(10);
    kolejka.pop(a);
    std::cout << a;
    kolejka.push(11);
    kolejka.push(12);
    kolejka.push(13);
    kolejka.push(14);
    kolejka.push(15);
    kolejka.push(12);

    kolejka.pop(a);
    std::cout << a;
    
    kolejka.rshow();
    kolejka.show();
    //
    //std::cout << a;
}
