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
	int c = add(a, 5); // 배열 a의 정수를 모두 더한 값 리턴
	int d = add(a, 5, b); // 배열 a와 b의 정수를 모두 더한 값 리턴
	cout << c << endl; // 15 출력 
	cout << d << endl; // 55 출력
	system("pause");
	return 0;

}

//교수님 코드 훨씬 간단
//int add(int x[],int size, int y[]=NULL)