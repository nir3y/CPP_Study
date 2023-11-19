#include <iostream>
using namespace std;

class LoopAdder { // �߻� Ŭ����
	string name; // ������ �̸�
	int x, y, sum;
	void read(); // x, y ���� �о� ���̴� �Լ�
	void write(); // sum�� ����ϴ� �Լ�
protected:
	LoopAdder(string name = "") { // ������ �̸��� �޴´�. �ʱ갪�� ""
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0; // ���� ���� �Լ�. ������ ���鼭 ���� ���ϴ� �Լ�
public:
	void run(); // ������ �����ϴ� �Լ�
};

void LoopAdder::read() { // x, y �Է�
	cout << name << ":" << endl;
	cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
	cin >> x >> y;
}
void LoopAdder::write() { // ��� sum ���
	cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�" << endl;
}

void LoopAdder::run() {
	read(); // x, y�� �д´�.
	sum = calculate(); // �������鼭 ����Ѵ�.
	write(); // ��� sum�� ����Ѵ�.
}

class ForLoopAdder : public LoopAdder
{
protected:
	int calculate();
public:
	ForLoopAdder(string name) : LoopAdder() {};
};



int ForLoopAdder::calculate()
{
	int x = getX();



	int y = getY();
	int sum = 0;
	for (; x <= y; x++) sum += x;
	return sum;
}

int main()
{
	ForLoopAdder forLoop("For Loop");
	forLoop.run();

	system("pause");
	return 0;
}