#include <iostream>
#include <string>
using namespace std;

class Mammal
{
public:
	virtual void Speak() = 0;
	std::string Name = "NoName";

	virtual ~Mammal() = default;

	Mammal(const Mammal&) = default;
	Mammal() = default;
	Mammal(const Mammal&) = default;
	Mammal& operator=(const Mammal&) = default;
	Mammal(Mammal&&) = default;
	Mammal& operator=(Mammal&&) = default;
};

class Dog : public Mammal
{
public:
	void Speak() override
	{
		cout << "mung Mung\n";
	}
	int Age = 1;
};

class Cat : public Mammal
{
public:
	void Speak() override
	{
		cout << "Myau\n";
	}
};

int main(int argc, char* argv[])
{

	if (argc <= 1)
	{
		cerr << "give me cat or dog!\n";
		return -1;
	}
	Mammal* ptr_mammal = nullptr;
	if (argv[1][0] == 'c')
		ptr_mammal = new Cat();
	else if(argv[1][0]== 'r')
		ptr_mammal=
}