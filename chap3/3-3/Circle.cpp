#include <iostream>
using namespace std;
#include "Circle.h"


//���� part
Circle::Circle()//circle�� �ִ� circle�̶�� ������ ȣ��
{
	radius = 1;
	cout << "������ " << radius << "�� �� ����" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "������ " << radius << "�� �� ����" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;//��� ��
}


