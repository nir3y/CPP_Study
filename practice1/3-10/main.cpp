#include <iostream>
using namespace std

int main() {
	Add a;
	Sub s;
	Mul m;
	Div d;

	while (true) {
		cout << "�� ������ �����ڸ� �Է��ϼ���>>";
		int x, y;
		char c;
		cin >> x >> y >> c;
		switch (c) {
		case '+': 	a.setValue(x, y); cout << a.calculate(); break;
		case '-': 	s.setValue(x, y); cout << s.calculate(); break;
		case '*': 	m.setValue(x, y); cout << m.calculate(); break;
		case '/': 	d.setValue(x, y); cout << d.calculate(); break;
		}
		cout << endl;
	}
}
