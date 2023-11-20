#include <iostream>
#include <string>
using namespace std;

class printer
{
protected:
	string model, manufacturer; //모델명, 제조사
	int printCount, availableCount; //인쇄매수, 인쇄종이 잔량
public:
	printer(string model, string manufacturer, int printCount, int availableCount); //각각 모델명, 제조사, 인쇄매수, 인쇄종이 잔량
	bool print(int pages); //pages만큼 인쇄종이 잔량 차감
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

bool printer::print(int pages)
{
	if (availableCount < pages) {
		cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
		return false; 
	}
	else {
		availableCount -= pages;
		return true;
	}
}

void printer::status()
{
	cout << model << ", " << manufacturer << " ,남은 종이" << availableCount;
}


class InkJetPrinter : public printer
{
	int availableInk; //잉크잔량
public:
	InkJetPrinter(string model, string manufacturer, int printCount,
		int availableCount, int availableInk);
	bool printInkJet(int pages);
	void status();
};

//생성자
InkJetPrinter::InkJetPrinter(string model, string manufacturer, int printCount,
	int availableCount, int availableInk) : printer(model, manufacturer, printCount, availableCount)
{
	this->availableInk = availableInk;
}

bool InkJetPrinter::printInkJet(int pages)
{
	bool TorF = print(pages);
	//용지도 잉크도 충분할 때, print()함수로 availableCount 감소. availableInk 감소 
	if (TorF && availableInk >= pages) { 
		cout << "프린트하였습니다." << endl;
		availableInk -= pages; 
		return true; 
	}
	
	//용지와 잉크 둘 다 부족할 때, 각각 부족하다고 나타내는 문장 출력
	else if (!TorF)
	{
		if (availableInk < pages) { 
			
			cout << "잉크가 부족하여 프린트 할 수 없습니다." << endl;
			return false;
		}
		//용지만 부족할 때
		return false; 
	}

	//잉크만 부족하나 용지는 충분할 때 -> print()함수 내에서 pages만큼 availableCount 값이 감소함.
	//else문 내에서 availableCount 값 복구
	else
	{
		availableCount += pages;
		cout << "잉크가 부족하여 프린트 할 수 없습니다." << endl;
		return false;

	}
	
}

void InkJetPrinter::status()
{
	cout << "잉크젯 : ";
	printer::status();
	cout << ", 남은 잉크 " << availableInk << endl;
}

class LaserPrinter : public printer
{
	int availableToner; //토너잔량
public:
	LaserPrinter(string model, string manufacturer, int printCount,
		int availableCount, int availableToner);
	bool printLaser(int pages);
	void status();
};

//생성자
LaserPrinter::LaserPrinter(string model, string manufacturer, int printCount,
	int availableCount, int availableToner) :printer(model, manufacturer, printCount, availableCount)
{
	this->availableToner = availableToner;
}

bool LaserPrinter::printLaser(int pages)
{
	bool TorF = print(pages);
	//용지도 토너도 충분할 때, print()함수로 availableCount 감소. availableToner 감소 
	if (TorF && availableToner >= pages) {
		cout << "프린트하였습니다." << endl;
		availableToner -= pages;
		return true;
	}

	//용지와 토너 둘 다 부족할 때, 각각 부족하다고 나타내는 문장 출력
	else if (!TorF){
		if (availableToner < pages) {
			cout << "토너가 부족하여 프린트 할 수 없습니다." << endl;
			return false;
		}
		//용지만 부족할 때
		else{ return false; }
	}

	//토너만 부족하나 용지는 충분할 때 -> print()함수 내에서 pages만큼 availableCount 값이 감소함.
	//else문 내에서 availableCount 값 복구
	else{
		availableCount += pages;
		cout << "토너가 부족하여 프린트 할 수 없습니다." << endl;
		return false;
	}
}

void LaserPrinter::status()
{
	cout << "레이저 : ";
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

	InkJetPrinter* inkjet = new InkJetPrinter("Officejet V40", "HP", 0, 5, 4 );
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
	delete inkjet;
	delete laser;
	system("pause");
	return 0;
}