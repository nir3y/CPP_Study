#include <iostream>
#include <ctime>

using namespace std;

// ---- SelectableRandom Ŭ���� ����� ----
class SelectableRandom
{
	bool select;
public:
	SelectableRandom(bool a);
	SelectableRandom();
	int next();
	int nextInRange(int low, int high);
};

// ---- SelectableRandom Ŭ���� ������ ----
SelectableRandom::SelectableRandom() : SelectableRandom(true) {}

SelectableRandom::SelectableRandom(bool a)
{
	select = a;
	srand((unsigned int)time(0));
}

int SelectableRandom::next()
{
	if (select == true)
	{
		while (1)
		{
			int n = rand();
			if (n % 2 == 0)
				return n;
		}
	}
	else
	{
		while (1)
		{
			int n = rand();
			if (n % 2 != 0)
				return n;
		}
	}


}

int SelectableRandom::nextInRange(int low, int high)
{
	if (select == true)
	{
		while (1)
		{
			int range = rand() % (high - low + 1);
			if (range % 2 == 0)
				return range + low;
		}



	}
	else
	{
		while (1)
		{
			int range = rand() % (high - low + 1);
			if (range % 2 != 0)
				return range + low;
		}

	}
}


int main()
{
	SelectableRandom evenRandom;
	cout << "--- 0����" << RAND_MAX << "������ ¦�� ���� ���� 10�� ---" << endl;
	for (int i = 0; i < 10; i++)
	{
		int n = evenRandom.next();
		cout << n << ' ';
	}
	SelectableRandom oddRandom(false);
	cout << endl << endl << "--- 2���� " << "9 ������ ���� Ȧ�� ���� 10�� ---" << endl;
	for (int i = 0; i < 10; i++)
	{
		int n = oddRandom.nextInRange(2, 9);
		cout << n << ' ';
	}
	cout << endl << endl;

	system("pause");
	return 0;
}
