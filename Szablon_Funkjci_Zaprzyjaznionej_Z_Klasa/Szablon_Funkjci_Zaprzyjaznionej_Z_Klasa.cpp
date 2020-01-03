#include <iostream>

template <typename T> void count();
template <typename T> void reports(const T&);

template <typename T>
class HasFriend
{
private:
    T m_item;
    static int m_ct;
public:
    HasFriend(const T& item) :m_item(item) { m_ct++; }
    ~HasFriend() { m_ct--; }
    friend void count<T>();
    friend void reports<>(const HasFriend<T>&);
};

template <typename T>
int HasFriend<T>::m_ct = 0;

template <typename T>
void count<T>()
{
    std::cout << "Szablon sizoef: " << sizeof(HasFriend<T>) << ": ";
    std::cout << "wartosc ct: " << HasFriend<T>::m_ct << std::endl;
}

template <typename T>
void reports<>(const T& temp)
{
    std::cout << temp.m_item << std::endl;
}


int main()
{
    count<int>();
    HasFriend<int> hfi1(10);
    HasFriend<int> hfi2(20);
    HasFriend<double> hfdb(10.5);
    reports(hfi1);
    reports(hfi2);
    reports(hfdb);
    std::cout << "Wynik dzialania count<int>\n";
    count<int>();
    std::cout << "Wynik dzialania count<double>\n";
    count<double>();
}

