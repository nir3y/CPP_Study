#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	//char str[50];
	string str; //string ����� �����ͼ� �ۼ��� �ڵ�

	cout << "���ڿ� �Է� ==>";

	//cin.getline(str, 50);
	getline(cin, str);

	//int len = strlen(str);
	int len = str.length();


	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <=i; j++)
		{
			cout << str[j];
		}
		cout << endl;
	}


	system("pause");
}