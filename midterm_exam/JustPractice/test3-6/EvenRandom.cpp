#include <iostream>
#include <ctime>

using namespace std;

class EvenRandom
{
	int num;
public:
	EvenRandom(); // 랜덤 숫자 생성

};

EvenRandom::EvenRandom()
{
	srand((unsigned int)time(0)); //임의의 seed 생성
}
int main()
{
	

	system("pause");
	return 0;
}