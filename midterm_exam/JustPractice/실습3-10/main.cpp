#include <iostream>
using namespace std;

class Add
{
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};

void Add::setValue(int x, int y)
{
	a = x; b = y;
}

int Add::calculate()
{
	return a + b;
}

class Sub
{
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};

void Sub::setValue(int x, int y)
{
	a = x; b = y;
}

int Sub::calculate()
{
	return a - b;
}

class Mul
{
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};

void Mul::setValue(int x, int y)
{
	a = x; b = y;
}

int Mul::calculate()
{
	return a * b;
}


class Div
{
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};

void Div::setValue(int x, int y)
{
	a = x; b = y;
}

int Div::calculate()
{
	return a / b;
}

int main() {

	Add a;
	Sub s;
	Mul m;
	Div d;

	while (true) {
		cout << "두 정수와 연산자를 입력하세요>>";
		int x, y;
		char c;
		cin >> x >> y >> c;
		switch (c) {
		case '+': 	
			a.setValue(x, y); 
			cout << a.calculate(); 
			break;

		case '-': 	
			s.setValue(x, y);
			cout << s.calculate();
			break;

		case '*': 	
			m.setValue(x, y);
			cout << m.calculate(); 
			break;

		case '/': 
			d.setValue(x, y); 
			cout << d.calculate(); 
			break;

		}
		cout << endl;


	}
	
	return 0;

}