#include <iostream>
using namespace std;

#include "Circle.h"


//구현부
Circle ::Circle():Circle(1){}

/*
Circle::Circle()
{
	radius = 1;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}
*/

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

