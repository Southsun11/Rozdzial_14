#include <iostream>

class Frabjous
{
private:
    char fab[20];
public:
    Frabjous(const char* s = "C++") { strncpy_s(fab, s, 20); }
    virtual void tell() { std::cout << fab; }
};

class Gloam:private Frabjous
{
private:
    int glip;
    
public:
    Gloam(int g = 0, const char* s = "C++");
    Gloam(int g, const Frabjous& f);
    void tell();
};

Gloam::Gloam(int g, const char* s) :Frabjous(s)
{
    this->glip = g;
}

Gloam::Gloam(int g, const Frabjous& f) : Frabjous(f)
{
    this->glip = g;
}

void Gloam::tell()
{
    std::cout << this->glip << std::endl;;
    Frabjous::tell();
}
int main()
{
    Gloam g(10, "Hej");
    g.tell();
}


