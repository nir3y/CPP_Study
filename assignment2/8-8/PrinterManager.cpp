#include <iostream>
#include <string>
using namespace std;

/*
		--�ذ��ؾ� �� ��---
 ���� ���� �����Ҷ�, ��ʿ� ��ũ �پ���� �ʰ� �����ϱ�
 ���� �Ҵ� �����ϴ� �Ҹ��� �ڵ� �ۼ��ϱ�
*/


class printer
{
protected:
	string model, manufacturer; //�𵨸�, ������
	int printCount, availableCount; //�μ�ż�, �μ����� �ܷ�
public:
	printer(string model, string manufacturer, int printCount, int availableCount); //���� �𵨸�, ������, �μ�ż�, �μ����� �ܷ�
	void print(int pages); //pages��ŭ �μ����� �ܷ� ����
	void status(); //���� ������ ���� �� ���¸� ����ϴ� �Լ�
};

//������
printer::printer(string model, string manufacturer, int printCount, int availableCount)
{
	this->model = model;
	this->manufacturer = manufacturer;
	this->printCount = printCount;
	this->availableCount = availableCount;
}

void printer::print(int pages)
{
	if (availableCount < pages) { cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl; }
	else {
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
		availableCount -= pages;
	}
}

void printer::status()
{
	cout << "��ũ�� : " << model << ", " << manufacturer << " ,���� ����" << availableCount;
}


class InkJetPrinter : public printer
{
	int availableInk; //��ũ�ܷ�
public:
	InkJetPrinter(string model, string manufacturer, int printCount,
		int availableCount, int availableInk);
	void printInkJet(int pages);
	void status();
};

//������
InkJetPrinter::InkJetPrinter(string model, string manufacturer, int printCount,
	int availableCount, int availableInk) : printer(model, manufacturer, printCount, availableCount)
{
	this->availableInk = availableInk;
}

void InkJetPrinter::printInkJet(int pages)
{
	if (availableInk < pages) { cout << "��ũ�� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl; }
	else {
		print(pages);
		availableInk -= pages;
	}
}

void InkJetPrinter::status()
{
	printer::status();
	cout << " ,���� ��ũ " << availableInk << endl;
}

class LaserPrinter : public printer
{
	int availableToner; //����ܷ�
public:
	LaserPrinter(string model, string manufacturer, int printCount,
		int availableCount, int availableToner);
	void printLaser(int pages);
	void status();
};

//������
LaserPrinter::LaserPrinter(string model, string manufacturer, int printCount,
	int availableCount, int availableToner) :printer(model, manufacturer, printCount, availableCount)
{
	this->availableToner = availableToner;
}

void LaserPrinter::printLaser(int pages)
{
	if (availableToner < pages) { cout << "��ʰ� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl; }
	else {
		print(pages);
		availableToner -= pages;
	}
}

void LaserPrinter::status()
{
	printer::status();
	cout << ", ���� ��� " << availableToner << endl;
}

void run()
{
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
}
int main()
{
	int printer, pages; //������ ����, �ż� �Է¹��� ����
	string YorN; //y �Ǵ� n�� �Է¹��� ����

	InkJetPrinter* inkjet = new InkJetPrinter("Officejet V40", "HP", 0, 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 0, 3, 20);
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
	inkjet->status();
	laser->status();

	while (true)
	{
		cout << endl;
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է� >>";
		cin >> printer >> pages;
		if (printer == 1) { inkjet->printInkJet(pages); }
		else if (printer == 2) { laser->printLaser(pages); }
		else {
			cout << "�߸��� �Է��Դϴ�. 1,2�� �Է� �����մϴ�." << endl;
			continue;
		}

		inkjet->status();
		laser->status();
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n) >>";
		cin >> YorN;
		if (YorN == "y") { continue; }
		else if (YorN == "n") { break; }
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
	}

	cout << endl;
	cout << "���α׷��� �����մϴ�." << endl;
	system("pause");
	return 0;
}