#include <iostream>
using namespace std;
int add(int a[], int size, int b[]=NULL)
{
	int s = 0;
	for (int i = 0 ; i < size; i++)
	{
		s += a[i];
		if (b != NULL)
			s += b[i];
	}
	return s;
}

int main()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5); // �迭 a�� ������ ��� ���� �� ����
	int d = add(a, 5, b); // �迭 a�� b�� ������ ��� ���� �� ����
	cout << c << endl; // 15 ��� 
	cout << d << endl; // 55 ���
	system("pause");
	return 0;

}

//������ �ڵ� �ξ� ����
//int add(int x[],int size, int y[]=NULL)