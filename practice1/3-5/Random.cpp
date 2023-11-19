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
	srand((unsigned)time(0));//seed값 준 것
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

	cout << "0부터 " << RAND_MAX << "까지의 랜덤 정수 10개 추출 " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << r.next() << ' ';
	}
	cout << endl << endl;

	cout << "2에서 4까지의 랜덤 정수 10개 추출" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << r.nextRange(2, 4) << ' ';
	}
	cout << endl << endl;

	system("pause");
	return 0;
}