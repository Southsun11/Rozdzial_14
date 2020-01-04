#include <iostream>

template <typename T>
class Beta
{
private:
    template<typename V>    //sprawdzic U
    class hold;
    hold<T> q;
    hold<int> n;
public:
    Beta(T t, int i):q(t), n(i) {}
    template<typename U>
    U blab(U u, T t);
    void show() const { q.show(); n.show(); }
};

template<typename T>
template<typename V>
class Beta<T>::hold
{
private:
    V value;
public:
    hold(V v = 0) :value(v) {}
    void show() const { std::cout << value << std::endl; }
    V Value() const { return value; }
};

template <typename T>
template <typename U>
U Beta<T>::blab(U u, T t)
{
    return (n.Value() + q.Value()) * u / t;
}


int main()
{
    Beta <double > guy(3.5, 3);
    std::cout << "T okreslone jako double\n";
    guy.show();
    std::cout << "Najpierw V okreslono jako T,czyli double,a nastepnie jaki int\n";
    std::cout << guy.blab(10, 2.3) << std::endl;
    std::cout << "U okreslono jako int\n";
    std::cout << guy.blab(10.0, 2.3) << std::endl;
    std::cout << "U okreslono jako double\n";
    std::cout << "Koniec" << std::endl;
    return 0;
}
