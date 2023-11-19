#include <iostream> 
#include <string>
using namespace std;

class Dept {
	int size; // scores �迭�� ũ��
	int* scores; // ���� �Ҵ� ���� ���� �迭�� �ּ�
public:
	Dept(int size) { // ������
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& dept); // ���������
	~Dept() ; // �Ҹ���
	int getSize() { return size; }
	void read(); // size ��ŭ Ű���忡�� ������ �о� scores �迭�� ����
	bool isOver60(int index); // index�� �л��� ������ 60���� ũ�� true ����
};

Dept::Dept(const Dept& dept)
{
	size = dept.size;
	scores = new int[size];

	for (int i = 0; i < size; i++)
	{
		scores[i] = dept.scores[i];
	}
}

Dept::~Dept() {
	if (scores != NULL)
		delete[] scores;
}

void Dept::read()
{
	cout << size << "�� ���� �Է�>> ";

	for (int i = 0; i < size; i++)
	{
		cin >> scores[i];
	}
}

bool Dept::isOver60(int index) {
	if (scores[index] > 60) return true;
	else return false;
}








int countPass(Dept dept) { // dept �а��� 60�� �̻� �л��� �� ����
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10); // �� 10���� �ִ� �а� com
	com.read(); // 10���� ������ Ű����κ��� �о� scores �迭�� ����
	int n = countPass(com); // com �а��� 60�� �̻� �л��� ���� ����
	cout << "60�� �̻��� " << n << "��";
	system("pause");
	return 0;
}


