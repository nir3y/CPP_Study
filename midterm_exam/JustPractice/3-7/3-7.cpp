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
	cout << "������ " << radius << "�� �� ����" << endl;

}

Circle::~Circle()
{
	cout << "������ " << radius << "�� �� �Ҹ�" << endl;

}

int main()
{
	Circle donut;
	Circle Pizza(30);

	return 0;
}