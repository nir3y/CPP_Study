#include <iostream>
#include <ctime>

using namespace std;

class EvenRandom
{
	int num;
public:
	EvenRandom(); // ���� ���� ����

};

EvenRandom::EvenRandom()
{
	srand((unsigned int)time(0)); //������ seed ����
}
int main()
{
	

	system("pause");
	return 0;
}