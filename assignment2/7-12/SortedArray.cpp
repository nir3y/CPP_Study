#include <iostream>
using namespace std;

class SortedArray {
	int size; // ���� �迭�� ũ��
	int* p; // ���� �迭�� ���� ������
	void sort(); // ���� �迭�� ������������ ����
public:
	SortedArray() { p = NULL; size = 0; }; // p�� NULL�� size�� 0���� �ʱ�ȭ
	SortedArray(const SortedArray& src); // ���� ������
	SortedArray(int p[], int size); // ������. ���� �迭�� ũ�⸦ ���޹���
	~SortedArray() { delete []p; }
	SortedArray operator + (SortedArray& op2);
	SortedArray& operator = (const SortedArray& op2); // ���� �迭�� op2 �迭�� ����
	void show(); // �迭�� ���� ���
};

void SortedArray::sort()
{
	int tmp;
	for (int i = 0; i < this->size; i++){
		for (int j = 0; j < this->size - i - 1; j++) {
			if (p[j] > p[j + 1]) { 
				tmp = p[j]; 
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}

//���� ������
SortedArray::SortedArray(const SortedArray& src)
{
	this->size = src.size;
	this->p = new int[size];
	for (int i = 0; i < size; i++) { this->p[i] = src.p[i]; }
	sort();
}

SortedArray::SortedArray(int p[], int size)
{
	this->size = size;
	this->p = new int[size];
	for (int i = 0; i < size; i++) { this->p[i] = p[i]; }
	sort();
}

SortedArray SortedArray :: operator + (SortedArray& op2)
{
	SortedArray tmp;
	tmp.size = this->size + op2.size;
	tmp.p = new int[tmp.size];

	for (int i = 0; i < this->size; i++) {
		tmp.p[i] = this->p[i];
	}

	for (int i = 0; i < op2.size; i++) {
		tmp.p[i + (this->size)] = op2.p[i];
	}
	tmp.sort();
	return tmp;
}

SortedArray& SortedArray :: operator = (const SortedArray& op2)
{
	delete[]p;
	this->size = op2.size;
	this->p = new int[this->size];
	for (int i = 0; i < this->size; i++) { this->p[i] = op2.p[i]; }
	return *this;
}

void SortedArray::show()
{
	cout << "�迭 ��� : ";
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b; // +, = ������ �ۼ� �ʿ�
	// + �����ڰ� SortedArray ��ü�� �����ϹǷ� ���� ������ �ʿ�

	a.show();
	b.show();
	c.show();

	system("pause");
	return 0;

}