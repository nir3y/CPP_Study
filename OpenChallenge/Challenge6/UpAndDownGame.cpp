#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Person {
	string name;
public:
	Person(string name) { this->name = name; }
	string getName() { return name; }
	bool go(); // 정수를 입력받고 정답이면 이김, true 리턴
};




class UpAndDownGame {
	static int answer;
	static int top;
	static int bottom;
private:
	static void init(); // answer 변수 랜덤 초기화
	static void msg(); // top과 bottom 출력
public:
	static void run(); // 게임 진행
	static bool check(int answer); // top과 bottom을 조절하고, 정답을 맞추었으면 true 리턴
};

int UpAndDownGame::answer = 9;
int UpAndDownGame::top = 99;
int UpAndDownGame::bottom = 0;

void UpAndDownGame::init()
{
	srand((unsigned)time(0)); 	
	int n = rand();
	answer = n % 100;

}



void UpAndDownGame::msg() {
	cout << "답은 " << bottom << "과 " << top << "사이에 있습니다." << endl;
}

void UpAndDownGame::run()
{
	Person players[2] = { Person("김인수"), Person("오은경") };
	cout << "up & down 게임을 시작합니다. " << endl;
	init();

	int i = 0;
	while (1)
	{
		msg();//top, bottom 출력
		if (players[i].go())
		{
			cout << players[i].getName() << "이 이겼습니다!" << endl;
			break;
		}
		i++;
		i = i % 2;
	}
}

bool UpAndDownGame::check(int a) { // top과 bottom을 조절하고, 정답을 맞추었으면 true 리턴
	if (a < bottom || a > top) return false; // 범위를 벗어난 잘못된 입력
	if (answer == a) return true; // win!!

	if (a > answer) top = a;
	else bottom = a;
	return false;
}


bool Person::go()
{
	int number;
	cout << name << ">> ";
	cin >> number;
	return UpAndDownGame::check(number);
}


int main() {
	UpAndDownGame::run();
	system("pause");
	return 0;
}
