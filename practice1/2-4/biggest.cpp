#include <iostream>
using namespace std;

double biggest(double x[], int n)
{
	double r;
	r = x[0];
	for (int i = 0; i < n; i++)
	{
		if (r < x[i])
			r = x[i];
	}

	return r;

}
int main()
{
	double a[5];
	cout << "5개의 실수를 입력하라 --> ";
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}

	cout << "제일 큰 수 = " << biggest(a, 5) << endl;


	system("pause");
}