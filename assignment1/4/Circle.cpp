#include <iostream>
using namespace std;

// ---- Circle Ŭ���� ����� ----
class Circle
{
	int radius;
	string name;
public:
	void setCircle(string name, int radius); //�̸��� ������ ����
	double getArea(); 
	string getName();
};

// ---- Circle Ŭ���� ������ ----
void Circle::setCircle(string name, int radius)
{
	this->name = name;
	this->radius = radius;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

string Circle::getName()
{
	return name;
}



// ---- CircleManager Ŭ���� ����� ----
class CircleManager
{
	Circle* p;
	int size;
public:
	CircleManager(int size);
	~CircleManager() { delete[] p; }
	void searchByName();
	void searchByArea();
};

// ---- CircleManager Ŭ���� ������ ----
CircleManager::CircleManager(int size)
{
	p = new Circle[size];
	this->size = size;
	string name;
	int radius;

	for (int i = 0; i < size; i++)
	{
		cout << "�� " << i+1 << "�� �̸��� ������ >> ";
		cin >> name >> radius;
		p[i].setCircle(name, radius); //����ڰ� �Է��� ���� ����
	}
	searchByName();
	searchByArea();
}

void CircleManager::searchByName()
{
	string searchName;

	cout << "�˻��ϰ��� �ϴ� ���� �̸� >>";
	cin >> searchName;

	for (int i = 0; i < size; i++)
	{
		if (p[i].getName() == searchName)
		{
			cout << searchName << "�� ������ " << p[i].getArea() << endl;
			return;
		}
	}
	cout << "�������� �ʴ� ���Դϴ�." << endl;
}

void CircleManager::searchByArea()
{
	int searchArea;
	int count = 0;

	cout << "�ּ� ������ ������ �Է��ϼ��� >>";
	cin >> searchArea;
	cout << searchArea << "���� ū ���� �˻��մϴ�." << endl;

	for (int i = 0; i < size; i++)
	{
		if (p[i].getArea() > searchArea)
		{
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << "  ";
			count++;
		}
	}
	cout << endl;

	if (count == 0)
	{
		cout << searchArea << "���� ū ���� �������� �ʽ��ϴ�." << endl;
	}
}

int main()
{
	int n;
	cout << "���� ���� >> ";
	cin >> n;

	CircleManager run(n);
	
	system("pause");
	return 0;
	
}