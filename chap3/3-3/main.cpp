#include <iostream>
using namespace std;
#include "Circle.h"

int main()
{
	Circle donut;
	double area = donut.getArea();
	cout << "���� ������ " << area << "�Դϴ�." << endl;
	cout << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "���� ������ " << area << "�Դϴ�." << endl;
	cout << endl;

	system("pause");
}