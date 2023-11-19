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
	cout << "도넛의 면적은" << area << "입니다." << endl;

	Circle pizza;
	pizza.radius = 30;
	area = pizza.getCircle();
	cout << "피자의 면적은" << area << "입니다." << endl;

	system("pause");
	return 0;

}