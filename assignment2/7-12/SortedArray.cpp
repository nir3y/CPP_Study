#include <iostream>
using namespace std;

class SortedArray {
	int size; // ���� �迭�� ũ��
	int* p; // ���� �迭�� ���� ������
	void sort(); // ���� �迭�� ������������ ����
public:
	SortedArray(); // p�� NULL�� size�� 0���� �ʱ�ȭ
	SortedArray(SortedArray& src); // ���� ������
	SortedArray(int p[], int size); // ������. ���� �迭�� ũ�⸦ ���޹���
	~SortedArray(); // �Ҹ���
	SortedArray operator + (SortedArray& op2);
	SortedArray& operator = (const SortedArray& op2); // ���� �迭�� op2 �迭�� ����
	void show(); // �迭�� ���� ���
};

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