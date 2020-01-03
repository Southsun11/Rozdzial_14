#include <iostream>
#include "..\Szablony Klas\Stack.h"

template <template<typename T> typename Thing>
class Crab
{
private:
    Thing <int> s1;
    Thing <double> s2;
public:
    Crab() {};
    bool push(int a, double d) { return s1.push(a) && s2.push(d); }
    bool pop(int& a, double& d) { return s1.pop(a) && s2.pop(d); }
};
int main()
{
    Crab<Stack> nebula;
    int ni;
    double nd;
    std::cout << "Podaj pary int i double w postaci 4 3.5( 0 0 koczny wprowadzanie):\n";
    while(std::cin >> ni >> nd && (ni != 0 || nd != 0))
        if(!nebula.push(ni,nd))
            break;
    while (nebula.pop(ni, nd))
        std::cout << "int: " << ni << "   double: " << nd << std::endl;
    return 0;

}
