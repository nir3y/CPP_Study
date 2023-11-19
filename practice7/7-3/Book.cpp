#include <iostream>
using namespace std;

class Matrix
{
	int ar[4];
public:

	Matrix();
	Matrix(int a1, int a2, int a3, int  a4);
	void show();

	Matrix operator +(Matrix matrix);
	Matrix& operator +=(Matrix matrix);
	bool operator ==(Matrix matrix);

};
Matrix::Matrix()
{
	for (int i = 0; i < 4; i++)
	{
		ar[i] = 0;
	}
}
Matrix::Matrix(int a1, int a2, int a3, int  a4)
{
	ar[0] = a1;
	ar[1] = a2;
	ar[2] = a3;
	ar[3] = a4;
}
void Matrix::show()
{
	cout << "Matrix = { ";
	for (int i = 0; i < 4; i++) cout << ar[i] << ' ';
	cout << "}" << endl;

}

Matrix Matrix :: operator +(Matrix matrix)
{
	Matrix tmp;
	for (int i = 0; i < 4; i++)
	{
		tmp.ar[i] = matrix.ar[i] + ar[i];
	}
	return tmp;
}

Matrix& Matrix :: operator+=(Matrix matrix)
{
	for (int i = 0; i < 4; i++)
		ar[i] += matrix.ar[i];

	return *this;

}

bool Matrix :: operator==(Matrix matrix)
{
	for (int i = 0; i < 4; i++)
	{
		if (ar[i] == matrix.ar[i])
			return true;
		else
			return false;
	}
}

int main()
{
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;


	cout << endl;
	system("pause");
	return 0;
}