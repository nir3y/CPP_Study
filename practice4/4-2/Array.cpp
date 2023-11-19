#include <iostream>
using namespace std;

int main()
{
	int* p = new int[5];
	cout << "정수 5개 입력 >> ";
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> p[i];
		sum += p[i];
	}
	
	cout << "평균 : " << sum / 5 << endl;
	

	system("pause");
	return 0;
}