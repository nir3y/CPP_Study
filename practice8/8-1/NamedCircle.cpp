#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius, string name) 
	{
		setRadius(radius);
		this->name = name;
	}
	void show()
	{
		cout << name << "의 반지름은 " << getArea() << "입니다." << endl;

	}
};
int main()
{
	NamedCircle waffle(3, "waffle");
	waffle.show();
	cout << endl;

	system("pause");
	return 0;
}