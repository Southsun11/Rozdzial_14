#include <iostream>
#include <string>
template <typename T>
class HasFriend
{
    T  m_item;
public:
    HasFriend(const T& item) :m_item(item) {};
    template <typename C, typename D> friend void show(C&, D&);

};

template <typename C,typename D>
void show(C& c1, D & d1)
{
    std::cout << c1.m_item << " " << d1.m_item << std::endl;
}

int main()
{
    HasFriend<int> h1(20);
    HasFriend<double> h2(14.123);
    HasFriend<std::string> h3("napis");
    show(h1,h2);
    show(h2,h3);
}