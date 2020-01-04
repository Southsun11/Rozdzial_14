#include <iostream>
#include <string>
template <typename T1, typename T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1& first();
	T2& second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1& aval, const T2& bval) :a(aval), b(bval) {}
	Pair() {}
};

template <typename T1,typename T2>
T1 & Pair<T1, T2>::first()
{
	return a;
}

template <typename T1,typename T2>
T2& Pair<T1, T2>::second()
{
	return b;
}

int main()
{
	Pair<std::string, int> ratings[4] =
	{
		Pair<std::string,int>("Pod Czerwonym Baronem",5),
		Pair<std::string, int>("Szybko i Tanio", 4),
		Pair<std::string,int>("Suflety Magdy",5),
		Pair<std::string,int>("U Gerda",3)
	};
	int joints = sizeof(ratings) / sizeof(Pair <std::string, int>);
	std::cout << "Ocena:\tRestauracja:\n";
	for (int i = 0; i < joints; i++)
	{
		std::cout << ratings[i].second() << ":\t" << ratings[i].first() << std::endl;
	}
	std::cout << "Uwaga zmiana oceny\n";
	ratings[3].second() = 6;
	ratings[3].first() = "U Gerda";
	std::cout << ratings[3].second() << ":\t" << ratings[3].first() << std::endl;
	return 0;

}