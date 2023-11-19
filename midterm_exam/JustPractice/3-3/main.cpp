#include <iostream>
using namespace std;

#include "Circle.h"

int main()
{

	Circle donut; // 매개 변수 없는 생성자 호출
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza(30); // 매개 변수 있는 생성자 호출
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;



	system("pause");
	return 0;
}