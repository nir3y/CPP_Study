#include <iostream>
#include <ctime>
using namespace std;

class Random {
public:
	Random();
	int next();
	int nextRange(int low, int high);
};

Random::Random()
{
	srand((unsigned)time(0));//seed�� �� ��
}

int Random::next()
{
	return rand();
}

int Random::nextRange(int low, int high)
{
	int range = rand() % (high - low + 1);
	return range + low;
}

int main()
{
	Random r;

	cout << "0���� " << RAND_MAX << "������ ���� ���� 10�� ���� " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << r.next() << ' ';
	}
	cout << endl << endl;

	cout << "2���� 4������ ���� ���� 10�� ����" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << r.nextRange(2, 4) << ' ';
	}
	cout << endl << endl;

	system("pause");
	return 0;
}