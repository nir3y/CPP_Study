#include <iostream>
using namespace std;

class Circle
{
public:
	int radius;
	double getCircle();
};

double Circle::getCircle()
{
	return 3.14 * radius*radius;
}

int main()
{
	Circle donut;
	donut.radius = 1;
	double area = donut.getCircle();
	cout << "������ ������" << area << "�Դϴ�." << endl;

	Circle pizza;
	pizza.radius = 30;
	area = pizza.getCircle();
	cout << "������ ������" << area << "�Դϴ�." << endl;

	system("pause");
	return 0;

}