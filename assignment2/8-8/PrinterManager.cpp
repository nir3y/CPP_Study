#include <iostream>
#include <string>
using namespace std;

/*
		--해결해야 할 것---
 용지 수만 부족할때, 토너와 잉크 줄어들지 않게 수정하기
 동적 할당 해제하는 소멸자 코드 작성하기
*/


class printer
{
protected:
	string model, manufacturer; //모델명, 제조사
	int printCount, availableCount; //인쇄매수, 인쇄종이 잔량
public:
	printer(string model, string manufacturer, int printCount, int availableCount); //각각 모델명, 제조사, 인쇄매수, 인쇄종이 잔량
	void print(int pages); //pages만큼 인쇄종이 잔량 차감
	void status(); //현재 프린터 정보 및 상태를 출력하는 함수
};

//생성자
printer::printer(string model, string manufacturer, int printCount, int availableCount)
{
	this->model = model;
	this->manufacturer = manufacturer;
	this->printCount = printCount;
	this->availableCount = availableCount;
}

void printer::print(int pages)
{
	if (availableCount < pages) { cout << "용지가 부족하여 프린트 할 수 없습니다." << endl; }
	else {
		cout << "프린트하였습니다." << endl;
		availableCount -= pages;
	}
}

void printer::status()
{
	cout << "잉크젯 : " << model << ", " << manufacturer << " ,남은 종이" << availableCount;
}


class InkJetPrinter : public printer
{
	int availableInk; //잉크잔량
public:
	InkJetPrinter(string model, string manufacturer, int printCount,
		int availableCount, int availableInk);
	void printInkJet(int pages);
	void status();
};

//생성자
InkJetPrinter::InkJetPrinter(string model, string manufacturer, int printCount,
	int availableCount, int availableInk) : printer(model, manufacturer, printCount, availableCount)
{
	this->availableInk = availableInk;
}

void InkJetPrinter::printInkJet(int pages)
{
	if (availableInk < pages) { cout << "잉크가 부족하여 프린트 할 수 없습니다." << endl; }
	else {
		print(pages);
		availableInk -= pages;
	}
}

void InkJetPrinter::status()
{
	printer::status();
	cout << " ,남은 잉크 " << availableInk << endl;
}

class LaserPrinter : public printer
{
	int availableToner; //토너잔량
public:
	LaserPrinter(string model, string manufacturer, int printCount,
		int availableCount, int availableToner);
	void printLaser(int pages);
	void status();
};

//생성자
LaserPrinter::LaserPrinter(string model, string manufacturer, int printCount,
	int availableCount, int availableToner) :printer(model, manufacturer, printCount, availableCount)
{
	this->availableToner = availableToner;
}

void LaserPrinter::printLaser(int pages)
{
	if (availableToner < pages) { cout << "토너가 부족하여 프린트 할 수 없습니다." << endl; }
	else {
		print(pages);
		availableToner -= pages;
	}
}

void LaserPrinter::status()
{
	printer::status();
	cout << ", 남은 토너 " << availableToner << endl;
}

void run()
{
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
}
int main()
{
	int printer, pages; //프린터 선택, 매수 입력받을 변수
	string YorN; //y 또는 n을 입력받을 변수

	InkJetPrinter* inkjet = new InkJetPrinter("Officejet V40", "HP", 0, 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 0, 3, 20);
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
	inkjet->status();
	laser->status();

	while (true)
	{
		cout << endl;
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력 >>";
		cin >> printer >> pages;
		if (printer == 1) { inkjet->printInkJet(pages); }
		else if (printer == 2) { laser->printLaser(pages); }
		else {
			cout << "잘못된 입력입니다. 1,2만 입력 가능합니다." << endl;
			continue;
		}

		inkjet->status();
		laser->status();
		cout << "계속 프린트 하시겠습니까?(y/n) >>";
		cin >> YorN;
		if (YorN == "y") { continue; }
		else if (YorN == "n") { break; }
		else {
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}

	cout << endl;
	cout << "프로그램을 종료합니다." << endl;
	system("pause");
	return 0;
}