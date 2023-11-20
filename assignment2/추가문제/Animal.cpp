#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	virtual void speak() = 0;
};

class Dog : public Animal
{
public:
	void speak()  { cout << "�۸�" << endl; }
};

class Cat : public Animal
{
public:
	void speak()  { cout << "�߿�" << endl; }
};


int main()
{
	Animal* a1 = new Dog();
	a1->speak();

	Animal* a2 = new Cat();
	a2->speak();

	system("pause");
	return 0;
}