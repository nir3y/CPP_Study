#include <iostream>
using namespace std;

//---- Container 클래스 선언부 ----
class Container // 통 하나를 나타내는 class
{
	int size;

public:
	Container() { size = 10; }
	void fill() { size = 10; }
	bool consume(int n);
	int getSize() { return size; }
};

////---- Container 클래스 구현부 ----
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

//---- CoffeeVendingMachine 클래스 선언부 ----
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

//---- CoffeeVendingMachine 클래스 구현부 ----
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
		cout << "에스프레소 드세요" << endl;
	}
	else
	{
		cout << "재료가 부족합니다." << endl;
	}

}

void CoffeeVendingMachine::selectAmericano()
{
	if (tong[0].consume(1) && tong[1].consume(2))
	{
		cout << "아메리카노 드세요" << endl;
	}
	else
	{
		cout << "재료가 부족합니다." << endl;
	}
}

void CoffeeVendingMachine::selectSugarCoffee()
{
	if (tong[0].consume(1) && tong[1].consume(2) && tong[2].consume(1))
	{
		cout << "설탕커피 드세요" << endl;
	}
	else
	{
		cout << "재료가 부족합니다." << endl;
	}
}

void CoffeeVendingMachine::show()
{
	cout << "커피 " << tong[0].getSize() << "," << " 물 " << tong[1].getSize() << "," << " 설탕 " << tong[2].getSize() << endl;
}

bool CoffeeVendingMachine::checkInputError(int s)
{
	if (s < 0 || s > 5)
	{
		cout << "잘못된 입력입니다. 1 ~ 5 사이의 숫자를 눌러주세요." << endl;
		return true;
	}
	return false;
}

void CoffeeVendingMachine::run()
{
	int select;
	cout << "***** 커피자판기를 작동합니다. *****" << endl;
	while (1)
	{
		cout << "메뉴를 눌러주세요 (1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기) >>";
		cin >> select;


		if (checkInputError(select)) //잘못된 숫자를 누르면 다시 입력받기
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