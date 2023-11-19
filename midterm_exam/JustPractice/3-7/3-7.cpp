#include <iostream>
using namespace std;

class Circle
{
public:
	int radius;

	Circle();
	Circle(int r);
	~Circle();
};

Circle::Circle():Circle(1){}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << "인 원 생성" << endl;

}

Circle::~Circle()
{
	cout << "반지름 " << radius << "인 원 소멸" << endl;

}

int main()
{
	Circle donut;
	Circle Pizza(30);

	return 0;
}