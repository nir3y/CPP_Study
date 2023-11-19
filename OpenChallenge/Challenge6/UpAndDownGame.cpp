#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Person {
	string name;
public:
	Person(string name) { this->name = name; }
	string getName() { return name; }
	bool go(); // ������ �Է¹ް� �����̸� �̱�, true ����
};




class UpAndDownGame {
	static int answer;
	static int top;
	static int bottom;
private:
	static void init(); // answer ���� ���� �ʱ�ȭ
	static void msg(); // top�� bottom ���
public:
	static void run(); // ���� ����
	static bool check(int answer); // top�� bottom�� �����ϰ�, ������ ���߾����� true ����
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
	cout << "���� " << bottom << "�� " << top << "���̿� �ֽ��ϴ�." << endl;
}

void UpAndDownGame::run()
{
	Person players[2] = { Person("���μ�"), Person("������") };
	cout << "up & down ������ �����մϴ�. " << endl;
	init();

	int i = 0;
	while (1)
	{
		msg();//top, bottom ���
		if (players[i].go())
		{
			cout << players[i].getName() << "�� �̰���ϴ�!" << endl;
			break;
		}
		i++;
		i = i % 2;
	}
}

bool UpAndDownGame::check(int a) { // top�� bottom�� �����ϰ�, ������ ���߾����� true ����
	if (a < bottom || a > top) return false; // ������ ��� �߸��� �Է�
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
