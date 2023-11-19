#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	Circle(int r, int k);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::Circle(int r, int k) {
	radius = r + k;
	cout << "������ ���� radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "�Ҹ��� ���� radius = " << radius << endl;
}

int main()
{
	Circle* pArray = new Circle[3]{ 1,{2,4},3 };

	//pArray[0].setRadius(10);
	//pArray[1].setRadius(20);
	//pArray[2].setRadius(30);

	cout << endl;
	for (int i = 0; i < 3; i++) {
		cout << pArray[i].getArea() << endl;
	}

	cout << endl;
	Circle* p = pArray; // ������ p�� �迭�� �ּҰ����� ����
	for (int i = 0; i < 3; i++) {
		cout << p->getArea() << endl;
		p++; // ���� ������ �ּҷ� ����
	}

	cout << endl;
	delete[] pArray; // ��ü �迭 �Ҹ�

	system("pause");
	return 0;
}