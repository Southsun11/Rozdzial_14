#include "Student.h"
double Student::average()
{
    if (ArrayDb::size() == 0)
        return 0;
    else
        return ArrayDb::sum() / ArrayDb::size();
}

 const std::string &  Student::name() const  // sprawdzic bez modyfikatora const zwracananego
{
    (std::string&)(*this) = "hej";
    return (const std::string&)(*this);
}
std::istream& operator>>(std::istream& os, Student& s)
{
    os >> (std::string&)(s);
    return os;
}
std::istream& getline(std::istream& os, Student& s)
{
    getline(os, (std::string&)(s));
    return os;
}
std::ostream& operator<<(std::ostream& os, const Student& s)
{
    os << (std::string&)s;
    return os;
}