#include <iostream>
#include <string>
using namespace std;

class printer
{
protected:
	string model, manufacturer; //�𵨸�, ������
	int printCount, availableCount; //�μ�ż�, �μ����� �ܷ�
public:
	printer(string model, string manufacturer, int printCount, int availableCount); //���� �𵨸�, ������, �μ�ż�, �μ����� �ܷ�
	bool print(int pages); //pages��ŭ �μ����� �ܷ� ����
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

bool printer::print(int pages)
{
	if (availableCount < pages) {
		cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		return false; 
	}
	else {
		availableCount -= pages;
		return true;
	}
}

void printer::status()
{
	cout << model << ", " << manufacturer << " ,���� ����" << availableCount;
}


class InkJetPrinter : public printer
{
	int availableInk; //��ũ�ܷ�
public:
	InkJetPrinter(string model, string manufacturer, int printCount,
		int availableCount, int availableInk);
	bool printInkJet(int pages);
	void status();
};

//������
InkJetPrinter::InkJetPrinter(string model, string manufacturer, int printCount,
	int availableCount, int availableInk) : printer(model, manufacturer, printCount, availableCount)
{
	this->availableInk = availableInk;
}

bool InkJetPrinter::printInkJet(int pages)
{
	bool TorF = print(pages);
	//������ ��ũ�� ����� ��, print()�Լ��� availableCount ����. availableInk ���� 
	if (TorF && availableInk >= pages) { 
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
		availableInk -= pages; 
		return true; 
	}
	
	//������ ��ũ �� �� ������ ��, ���� �����ϴٰ� ��Ÿ���� ���� ���
	else if (!TorF)
	{
		if (availableInk < pages) { 
			
			cout << "��ũ�� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
			return false;
		}
		//������ ������ ��
		return false; 
	}

	//��ũ�� �����ϳ� ������ ����� �� -> print()�Լ� ������ pages��ŭ availableCount ���� ������.
	//else�� ������ availableCount �� ����
	else
	{
		availableCount += pages;
		cout << "��ũ�� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		return false;

	}
	
}

void InkJetPrinter::status()
{
	cout << "��ũ�� : ";
	printer::status();
	cout << ", ���� ��ũ " << availableInk << endl;
}

class LaserPrinter : public printer
{
	int availableToner; //����ܷ�
public:
	LaserPrinter(string model, string manufacturer, int printCount,
		int availableCount, int availableToner);
	bool printLaser(int pages);
	void status();
};

//������
LaserPrinter::LaserPrinter(string model, string manufacturer, int printCount,
	int availableCount, int availableToner) :printer(model, manufacturer, printCount, availableCount)
{
	this->availableToner = availableToner;
}

bool LaserPrinter::printLaser(int pages)
{
	bool TorF = print(pages);
	//������ ��ʵ� ����� ��, print()�Լ��� availableCount ����. availableToner ���� 
	if (TorF && availableToner >= pages) {
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
		availableToner -= pages;
		return true;
	}

	//������ ��� �� �� ������ ��, ���� �����ϴٰ� ��Ÿ���� ���� ���
	else if (!TorF){
		if (availableToner < pages) {
			cout << "��ʰ� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
			return false;
		}
		//������ ������ ��
		else{ return false; }
	}

	//��ʸ� �����ϳ� ������ ����� �� -> print()�Լ� ������ pages��ŭ availableCount ���� ������.
	//else�� ������ availableCount �� ����
	else{
		availableCount += pages;
		cout << "��ʰ� �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
		return false;
	}
}

void LaserPrinter::status()
{
	cout << "������ : ";
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

	InkJetPrinter* inkjet = new InkJetPrinter("Officejet V40", "HP", 0, 5, 4 );
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
	delete inkjet;
	delete laser;
	system("pause");
	return 0;
}