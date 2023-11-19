#include <iostream>
using namespace std;

class AbstractGate { // �߻� Ŭ����
protected:
	bool x, y;
public:
	AbstractGate(bool x = false, bool y = false) : x(x), y(y) {}
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0; // ���� ���� �Լ�
};

class ORGate : public AbstractGate
{
public:
	bool operation()
	{
		if (x || y)
			return true;
		else
			false;
	}

};

class XORGate : public AbstractGate
{
public:
	bool operation()
	{
		return x ^ y;
	}
};

class ANDGate : public AbstractGate
{
public:
	bool operation()
	{
		if (x && y)
			return true;
		else
			false;
	}
};

int main()
{
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);
	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl; // AND ����� false
	cout << orGate.operation() << endl; // OR ����� true
	cout << xorGate.operation() << endl; // XOR ����� true


	system("pause");
	return 0;
}