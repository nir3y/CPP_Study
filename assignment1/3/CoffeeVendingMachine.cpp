#include <iostream>
using namespace std;

//---- Container Ŭ���� ����� ----
class Container // �� �ϳ��� ��Ÿ���� class
{
	int size;

public:
	Container() { size = 10; }
	void fill() { size = 10; }
	bool consume(int n);
	int getSize() { return size; }
};

////---- Container Ŭ���� ������ ----
bool Container::consume(int n)
{
	if (size < n)
	{
		return false;
	}
	else
	{
		size -= n;
		return true;
	}
}

//---- CoffeeVendingMachine Ŭ���� ����� ----
class CoffeeVendingMachine
{
	Container tong[3];
	void fill();
	void selectEspresso();
	void selectAmericano();
	void selectSugarCoffee();
	void show();
	bool checkInputError(int s);


public:
	void run();
};

//---- CoffeeVendingMachine Ŭ���� ������ ----
void CoffeeVendingMachine::fill()
{
	for (int i = 0; i < 3; i++)
	{
		tong[i].fill();
	}
}

void CoffeeVendingMachine::selectEspresso()
{
	if (tong[0].consume(1) && tong[1].consume(1))
	{
		cout << "���������� �弼��" << endl;
	}
	else
	{
		cout << "��ᰡ �����մϴ�." << endl;
	}

}

void CoffeeVendingMachine::selectAmericano()
{
	if (tong[0].consume(1) && tong[1].consume(2))
	{
		cout << "�Ƹ޸�ī�� �弼��" << endl;
	}
	else
	{
		cout << "��ᰡ �����մϴ�." << endl;
	}
}

void CoffeeVendingMachine::selectSugarCoffee()
{
	if (tong[0].consume(1) && tong[1].consume(2) && tong[2].consume(1))
	{
		cout << "����Ŀ�� �弼��" << endl;
	}
	else
	{
		cout << "��ᰡ �����մϴ�." << endl;
	}
}

void CoffeeVendingMachine::show()
{
	cout << "Ŀ�� " << tong[0].getSize() << "," << " �� " << tong[1].getSize() << "," << " ���� " << tong[2].getSize() << endl;
}

bool CoffeeVendingMachine::checkInputError(int s)
{
	if (s < 0 || s > 5)
	{
		cout << "�߸��� �Է��Դϴ�. 1 ~ 5 ������ ���ڸ� �����ּ���." << endl;
		return true;
	}
	return false;
}

void CoffeeVendingMachine::run()
{
	int select;
	cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;
	while (1)
	{
		cout << "�޴��� �����ּ��� (1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���) >>";
		cin >> select;


		if (checkInputError(select)) //�߸��� ���ڸ� ������ �ٽ� �Է¹ޱ�
		{
			continue;
		}

		switch (select)
		{

		case 1:
			selectEspresso();
			break;
		case 2:
			selectAmericano();
			break;
		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
		}

	}
}


int main()
{
	CoffeeVendingMachine a;
	a.run();

	system("pause");
	return 0;

}