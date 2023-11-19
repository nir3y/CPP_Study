#include <iostream>
using namespace std;
#include "Circle.h"


//구현 part
Circle::Circle()//circle에 있는 circle이라는 생성자 호출
{
	radius = 1;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;//계산 값
}


