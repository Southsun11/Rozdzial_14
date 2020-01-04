#include <iostream>


template <typename T>
class HasFriend
{
private:
    T item;
    static int c;
public:
    HasFriend(const T& t) :item(t) { c++; }
    ~HasFriend() {};
    friend void counts();
    friend void reports(HasFriend<T>& item);
};

template<typename T>
int HasFriend<T>::c = 0;

void counts()
{
    std::cout << "Konkretyzacja int: " <<  HasFriend<int>::c;
    std::cout << "Konkretyzacja double: " << HasFriend<double>::c;
}

void reports(HasFriend<int>& item)
{
    std::cout << "HasFriend<int>: " << item.item;
}
void reports(HasFriend<double>& item)
{
    std::cout << "HasFriend<double>: " << item.item;
}

int main()
{
    std::cout << "Brak zadeklarowanych obiektow\n";
    counts();
    HasFriend<int> hfi1(10);
    std::cout << "\nPo deklaracji hfil\n";
    counts();
    HasFriend<int> hfi2(20);
    std::cout << "\nPo deklaracji hfil\n";
    counts();
    HasFriend<double> hfdb(10.5);
    std::cout << "\nPo deklaracji hfdb";
    counts();
    reports(hfi1);
    reports(hfi2);
    reports(hfdb);


}
