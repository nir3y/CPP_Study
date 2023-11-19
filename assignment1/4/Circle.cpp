#include <iostream>
using namespace std;

// ---- Circle 클래스 선언부 ----
class Circle
{
	int radius;
	string name;
public:
	void setCircle(string name, int radius); //이름과 반지름 생성
	double getArea(); 
	string getName();
};

// ---- Circle 클래스 구현부 ----
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



// ---- CircleManager 클래스 선언부 ----
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

// ---- CircleManager 클래스 구현부 ----
CircleManager::CircleManager(int size)
{
	p = new Circle[size];
	this->size = size;
	string name;
	int radius;

	for (int i = 0; i < size; i++)
	{
		cout << "원 " << i+1 << "의 이름과 반지름 >> ";
		cin >> name >> radius;
		p[i].setCircle(name, radius); //사용자가 입력한 정보 저장
	}
	searchByName();
	searchByArea();
}

void CircleManager::searchByName()
{
	string searchName;

	cout << "검색하고자 하는 원의 이름 >>";
	cin >> searchName;

	for (int i = 0; i < size; i++)
	{
		if (p[i].getName() == searchName)
		{
			cout << searchName << "의 면적은 " << p[i].getArea() << endl;
			return;
		}
	}
	cout << "존재하지 않는 원입니다." << endl;
}

void CircleManager::searchByArea()
{
	int searchArea;
	int count = 0;

	cout << "최소 면적을 정수로 입력하세요 >>";
	cin >> searchArea;
	cout << searchArea << "보다 큰 원을 검색합니다." << endl;

	for (int i = 0; i < size; i++)
	{
		if (p[i].getArea() > searchArea)
		{
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << "  ";
			count++;
		}
	}
	cout << endl;

	if (count == 0)
	{
		cout << searchArea << "보다 큰 원이 존재하지 않습니다." << endl;
	}
}

int main()
{
	int n;
	cout << "원의 개수 >> ";
	cin >> n;

	CircleManager run(n);
	
	system("pause");
	return 0;
	
}