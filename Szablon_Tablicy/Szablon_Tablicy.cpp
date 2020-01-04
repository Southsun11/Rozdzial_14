#include "Nagłówek.h"
#include <iostream>

int main()
{
    ArrayTP<int, 10> sum;
    ArrayTP<double, 10> aves;
    ArrayTP<ArrayTP<int, 5>, 10> twodee;
    int i, j;
    for (i = 0; i < 10; i++)
    {
        sum[i] = 0;
        for (j = 0; j < 5; j++)
        {
            twodee[i][j] = (i + 1) * (j + 1);
            sum[i] += twodee[i][j];
        }
        aves[i] = (double)sum[i] / 5;
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            std::cout.width(2);
            std::cout << twodee[i][j] << " ";

        }
        std::cout << ": sum = ";
        std::cout.width(3);
        std::cout << sum[i] << ", srednia = " << aves[i] << std::endl;
    }
    std::cout << "Koniec";




    /*
    ArrayTP<double, 2> temp(10);
    ArrayTP<ArrayTP<double, 2>, 3> tablica(ArrayTP<double, 2> (10));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
            std::cout << tablica[i][j] << " ";
        std::cout << std::endl;
    }
    */
}
